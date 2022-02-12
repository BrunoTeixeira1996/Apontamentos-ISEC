# Aula 04/01/2022

- Sede a vermelho
- Filial a verde
- No meio está um provider com MPLS
- Saida azul para o exterior

## No ROUT 

- Pedir DHCP na porta de saída
- Configurar e1/1 
- Configurar o NAT
- Configurar o OSPF para a empresa conseguir sair la para fora
- Colocar DNS
- Colocar DHCP

```console
conf t
int e0/0
ip add dhcp
no shut
ip nat outside


int e1/1
ip add 192.168.200.1 255.255.255.0
no shut
ip nat inside

access-list 20 permit any
ip nat inside list 20 interface e0/0 overload

router ospf 1
network 192.162.168.200.0 0.0.0.255 area 0
default-information originate

ip dns server

ip dhcp pool POOL10
network 192.168.11.0 255.255.255.0
default-router 192.168.11.254
dns-server 192.168.200.1
ip dhcp pool POOL20
network 192.168.21.0 255.255.255.0
default-router 192.168.21.254
dns-server 192.168.200.1
ip dhcp pool POOL30
network 192.168.31.0 255.255.255.0
default-router 192.168.31.254
dns-server 192.168.200.1
```

## No CE6

- Colocar o equipamento a L3 e configurar o IP que liga ao ROUT
- Configurar o OSPF
- Configurar as portas com as VLANs respetivas
- Configurar este SWL3 como DG das VLANs 10,20,30
- Criar a Loopback e acrescentar no OSPF
- Configurar o trunk

```console
conf t
ip routing
no switchport
int e1/1
ip add 192.168.200.2 255.255.255.0
no shut

router ospf 1
network 192.168.200.0 0.0.0.255 area 0
network 192.168.11.0 0.0.0.255 area 0
network 192.168.21.0 0.0.0.255 area 0
network 192.168.31.0 0.0.0.255 area 0



int e0/0
sw mode acc
sw acc vlan 10
int e0/1
sw mode acc
sw acc vlan 20
int e0/2
sw mode acc
sw acc vlan 30

int vlan 10
ip add 192.168.11.254 255.255.255.0
ip helper-address 192.168.200.1
no shut
int vlan 20
ip add 192.168.21.254 255.255.255.0
ip helper-address 192.168.200.1
no shut
int vlan 30
ip add 192.168.31.254 255.255.255.0
ip helper-address 192.168.200.1
no shut

int loopback 0
ip add 10.10.10.6 255.255.255.255
router ospf 1
net 10.10.10.6 0.0.0.0 area 0

conf t
vlan 99
int e1/0
sw trunk encapsulation dot1q
sw mode trunk 
sw trunk native vlan 99
int vlan 99
ip add 192.168.99.6 255.255.255.0
no shut
router ospf 1
net 192.168.99.0 0.0.0.255 area 0
```

## No CE1

- Configurar as VLANs
- Configurar as interface vlans
- Configurar a vlan 100
- Configurar o OSPF
- Criar a loopback e adicionar no OSPF
- Criar int vlan 100 para ter ligação com o PE2

```console
int e0/0
sw mode acc
sw acc vlan 10
int e0/1
sw mode acc
sw acc vlan 20
int e0/2
sw mode acc
sw acc vlan 30

int vlan 10
ip add 192.168.10.254 255.255.255.0
no shut
int vlan 20
ip add 192.168.20.254 255.255.255.0
no shut
int vlan 30
ip add 192.168.30.254 255.255.255.0
no shut

int e1/0
sw mode acc
sw acc vlan 100

router ospf 1
net 192.168.10.0 0.0.0.255 area 0
net 192.168.20.0 0.0.0.255 area 0
net 192.168.30.0 0.0.0.255 area 0

int loopback 0
ip add 10.10.10.1 255.255.255.255
router ospf 1
net 10.10.10.1 0.0.0.0 area 0

int vlan 100
ip add 192.168.100.1 255.255.255.0
no shut
exit
vlan 100
router ospf 1
net 192.168.100.0 0.0.0.0.255 area 0
```

## No PE2

- Configurar e1/0 como Access logo metemos lá um IP
- Criar a int loopback 0
- Configurar o OSPF
- Configurar o link para o P3
- Configurar o MPLS

```console
conf t
int e1/0
ip add 192.168.100.2 255.255.255.0
no shut

int loopback 0
ip add 10.10.10.2 255.255.255.255

router ospf 1
net 10.10.10.2 0.0.0.0 area 0
net 192.168.100.0 0.0.0.255 area 0

int e1/1
ip add 192.168.23.2 255.255.255.0
no shut
router ospf 1
net 192.168.23.0 0.0.0.255 area 0

conf t
mpls label range 200 299
router ospf 1
mpls ldp autoconfig
```

## No PE3

- Configurar a e1/1 que é o link com o PE2
- Configurar a e1/0 que é o link com o P4
- Configurar a loopack
- Configurar o mpls e o ospf


```console
int e1/1
ip add 192.168.23.3 255.255.255.0
no shut

int e1/0
ip add 192.168.34.3 255.255.255.0
no shut

int loopback 0
ip add 10.10.10.3 255.255.255.255

mpls label range 300 399
router ospf 1
net 10.10.10.3 0.0.0.0 area 0
net 192.168.23.0 0.0.0.255 area 0
net 192.168.34.0 0.0.0.255 area 0
mpls ldp autoconfig
```

## No P4

- Configurar o e1/0 e o e1/1
- Criar a loopback 0
- Configurar o mpls e o ospf

```console
int e1/0
ip add 192.168.34.4 255.255.255.0
no shut
int e1/1
ip add 192.168.45.4 255.255.255.0
no shut

int loopback 0
ip add 10.10.10.4 255.255.255.255

conf t
mpls label range 400 499
router osfp 1
net 10.10.10.4 0.0.0.0 area 0
net 192.168.34.0 0.0.0.255 area 0
net 192.168.45.0 0.0.0.255 area 0
mpls ldp autoconfig
```

## No PE5

- Configurar o link para cima
- Criar a loopback
- Configurar o OSPF
- Configurar o mpls

```console
int e1/1
ip add 192.168.45.5 255.255.255.0
no shut

int loopback 0
ip add 10.10.10.5 255.255.255.255

int e1/0
no shut
int e1/0.99
encapsulation dot1q 99 native
ip add 192.168.99.5 255.255.255.0

router ospf 1
net 10.10.10.5 0.0.0.0 area 0
net 192.168.45.0 0.0.0.255 area 0
net 192.168.99.0 0.0.0.255 area 0

conf t
mpsl label range 500 599
router osfp 1
mpls ldp autoconfig
```

----------CONFIG PARA O ATOM-------------

## No PE5

- Temos de criar a vlan que vamos partilhar
- Agora temos de criar um tunel do PE5 para o PE2

```console
conf t
int e1/0.30
encapsulation dot1q 30

int e1/0.30
xconnect 10.10.10.2 30 encapsulation mpls
```

- Temos de transformar o Access Data VLAN entre CE1 e PE2 em Trunk para funcionar

## No PE2

- Retirar o Access Data VLAN e configurar a nativa 100 e a vlan 30
- Agora temos de criar um tunel do PE2 para o PE5

```console
conf t
default interface e1/0
int e1/0
no shut
int e1/0.100
encapsulation dot1q 100 native
ip add 192.168.100.2 255.255.255.0
int e1/0.30
encapsulation dot1q 30

int e1/0.30
xconnect 10.10.10.5 30 encapsulation mpls
```

## No CE1

- Transformar o Access para Trunk

```console
conf t
default int e1/0
int e1/0
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 100
```


## Notas

- CE (Customer Edge)
  - Equipamentos que estão no limite, ou seja, sao os que se ligam ao MPLS

- Se dizemos que é uma Access VLAN


- **Temos de ver sempre o IP destino no comando sh mpls ldp bindings**
- O local é "qual é a label que o Router local usa quando aparece um pacote para a rede X"
- O remote binding quer dizer que o router vizinho vai usar a label X
- Quando temos **imp-null** significa que essa rede termina ali
- Se quisermos forçar o null, usamos o **explicit null**

- Any Transport Over MPLS (ATOM) é uma forma de transportar VLANs em cima de MPLS

- **sh mpls l2transport binding** mostra as labels mpls do tunnel ATOM

