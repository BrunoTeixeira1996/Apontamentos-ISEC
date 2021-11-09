# Aula T 02/11/2021

- **Atenção que os equipamentos têm de ser limpos**

- **Na primeira experiencia apenas o Ipterm-1 nao consegue pingar o resto, nao sei porque**

## Configurações

- Colocou-se IPs nos VPCs e nos Ipterms

### No R1

- Este router é "pai" da VLAN40
- E tem tambem a VLAN99
- E é tambem servidor de DHCP
- E colocamos tambem DNS que vem do R2
- Ativar o RIP

```console
conf t
hostname R1

int e1/3
ip add 192.168.40.254 255.255.255.0
no shut

int e0/0
ip add 192.168.99.11 255.255.255.0
no shut

exit
ip dhcp pool pool_VLAN
network 192.168.40.0 255.255.255.0
default-router 192.168.40.254
dns-server 192.168.99.12

router rip
network 0.0.0.0
```

### SW1

- Configuramos as VLANs nos primeiros 3 comandos
- Configuramos a vlan40 na e1/3
- Configuramos a vlan99 na e2/0
- Configuramos em modo trunk na e0/3 porque o R2 tem a VLAN99 VLAN10 e VLAN20 , logo enviamos tráfego marcado porque só temos 1 cabo, logo temos de criar sub interfaces virtuais. Tem de ser trafego marcado (trunk) para suportar várias vlans
- Configuramos uma VLAN nativa no trunk (neste caso configuramos a vlan 99)
- Configurar o trunk para baixo e como é entre switches temos de meter a nativa tambem
- Usa-se este comando (`int vlan 99` e depois `ip add 192.168.99.1 255.255.255.0`) para por exemplo fazer telnet no entanto nao é necessário


```console
int e0/0
sw mode access
sw access vlan 10

int e0/1
sw mode access
sw access vlan 20

int e0/2
sw mode access
sw access vlan 40

int e1/3
sw mode access
sw access vlan 40

int e2/0
sw mode access
sw access vlan 99

int e0/3
sw trunk encapsulation dot1q
sw mode trunk

int e0/3
switchport trunk native vlan 99
vlan 99

int e1/0
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

int vlan 99
ip add 192.168.99.1 255.255.255.0
```

### No R2

- Configuramos dhcp
- Configuramos o NAT outside
- Configuramos aqui as subinterfaces
  - Na porta fisica fazemos `no shut`
  - Depois criamos 3 subinterfaces , uma para cada VLAN
  - Depois temos de ter atenção à VLAN nativa do trunk (ver notas em baixo)
  - Se tivessemos mudado a nativa para vlan 99 tinhamos de fazer o comando la em baixo que diz `dot1q 99 native`
- Colocar NAT inside
- Ativar o RIP

```console
int e0/0
ip add dhcp
no shut

int e0/0
ip nat outside

int e0/3
no shut
int e0/3.10
encapsulation dot1q 10
ip add 192.168.10.254 255.255.255.0
int e0/3.20
encapsulation dot1q 20
ip add 192.168.20.254 255.255.255.0
int e0/3.99
encapsulation dot1q 99
ip add 192.168.99.12 255.255.255.0

int e0/3.99
encapsulation dot1q 99 native

int e0/3.10
ip nat inside
int e0/3.20
ip nat inside
int e0/3.99
ip nat inside
exit
access-list 10 permit any
ip nat inside source list 10 interface e0/0 overload

router rip
network 0.0.0.0
default-information originate
```

## No SW2

- Configurar a VLAN nativa com o trunk
- Criar vlans
- Configurar mode access para as vlans
- Configurar trunk para o lado direito
- Configurar a VLAN30 (`começa no ip routing`) uma vez que o SW2 vai ser o *default gateway* da vlan 30
- Configurar router para acesso telnet por exemplo  (nao é necessário)
- Configurar o RIP


```console
int e1/0
sw trunk encapsulation dot1q
sw mode trunk
sw trunk nativ vlan 99

vlan 10
vlan 30
vlan 40
vlan 99

int e0/0
sw mode acc
sw acc vlan 10
int e0/1
sw mode acc
sw acc vlan 30
int e0/2
sw mode acc
sw acc vlan 40

int e1/1
sw tru encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

ip routing
interface vlan 30
ip add 192.168.30.254 255.255.255.0
no shut

interface vlan 99
ip add 192.168.99.2 255.255.255.0
no shut

router rip
network 0.0.0.0
```

### No SW3

- Configurar o trunk
- Criar VLANs
- Configurar interfaces para VLANs
- Configurar para aceder em telnet por exemplo (nao é necessário)


```console
int e1/1
sw tru encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

vlan 10
vlan 20
vlan 30
vlan 99

int e0/0
sw mode acc
sw acc vlan30
int e0/1
sw mode acc
sw acc vlan20
int e0/2
sw mode acc
sw acc vlan30


int vlan 99
ip add 192.168.99.3 255.255.255.0
```


## Notas

- Se der erros de `full duplex` e `not full duplex` entre o Switch  e os routers fazemos:

```console
int e1/3
duplex full
```

- Quando se fala num trunk temos de pensar na VLAN nativa
  - Um trunk tem sempre uma vlan nativa
  - A VLAN nativa é uma vlan que não está associada explicitamente a nenhuma tag, ou seja, não tem marcação
  - **É importante mudar a vlan nativa dos trunks**

- Na configuração da VLAN30 nao podemos colocar ips nas portas do switch porque as mesmas sao de L2 então temos de criar uma interface virtual
  - `ip routing`
  - `interface vlan 30`
  - `ip add 192.168.30.254 255.255.255.0`
  - `no shut`

### Dividir a VLAN 30 (Private VLAN)

- O VTP tem de estar desligado
  - O **VTP mode transparent** está a trabalhar mas não recebe as vlans
- Depois temos de dizer quais são as vlans primárias e secundárias 
  - Vamos colocar o servidor na vlan primaria e os pcs na vlan secundária
  - A vlan secundária pode ser isolada e comunitária
	Se colocarmos pcs numa isolada eles nao comunicam entre si, se colocarmos numa comunitária eles comunicam entre si

#### No SW3

- Colocar o vtp em modo transparente
- Colocar a vlan 30 a privada
- Criar a vlan31 como isolada e associamos à vlan 30
- Associar a interface e0/2 para a vlan privada 
- Associar a interface e0/0 para a vlan isolada

```console
conf t
vtp mode transparent

vlan 30
private-vlan primary

vlan 31
private-vlan isolated
private-vlan association 31
exit

int e0/2
switchport mode private-vlan
switchport private-vlan promiscuous
sw private-vlan mapping 30 31

int e0/0
switchport mode private-vlan
switchport private-vlan host-association
sw private-vlan mapping 30 31
```

#### No SW2

- Dizer que a vlan 30 é primaria e associar com a 31
- Dizer que a vlan 31 é isolada e associar à 30
- Criar a vlan31 e dizer que ela é privada e isolada
- Associar a interface e0/1 à 

```console
conf t
vtp mode transparent
vlan 30
private-vlan primary
private-vlan association 31

vlan31
private-vlan isolated
exit

int e0/1
switchport mode private-vlan
switchport private-vlan host-association 30 31
```
