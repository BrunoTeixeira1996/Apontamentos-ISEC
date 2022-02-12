# Aula T 09/11/2021

## Configuração da Topologia 5 no GNS3

### No R1

- Configurar a interface externa para ganhar IP por DHCP
- Configurar o NAT e levantar a interface e1/1 (`atenção que a rede 192.168.100.0/24 é a rede entre o R1 e o SW2`)
- Configurar servidor de DNS
- Criar pools de DHCP (10 e 20)
- Configurar o RIP

```console
conf t
int e0/0
ip add dhcp
no shut

exit
access-list 10 permit any
int e0/0
ip nat outside
int e1/1
ip nat inside
ip nat inside source list 10 int e0/0 overload
ip add 192.168.100.1 255.255.255.0
no shut
exit

ip dns server
ip domain lookup

ip dhcp pool POOL_10
network 192.168.10.0 255.255.255.0
default-router 192.168.10.254
dns-server 192.168.100.1
ip dhcp pool POOL_20
network 192.168.20.0 255.255.255.0
default-router 192.168.20.254
dns-server 192.168.100.1
ip dhcp excluded-address 192.168.10.250
ip dhcp excluded-address 192.168.10.254
ip dhcp excluded-address 192.168.20.250
ip dhcp excluded-address 192.168.20.254

router rip
network 0.0.0.0
default-information originate
```

### No SR2

- Configurar e criar a VLAN 20 visto que é este que fica responsável por ela
- Configurar e criar a VLAN99 para comunicar com o SR3
- Configurar o trunk entre SR2 e SR3
- Configurar o RIP
- Configurar a rede `.100` de modo a desligar o L2 do switch para passarmos de nível 2 para nível 3
- Configurar as private vlans
  - configurar a vlan 10 como primaria
  - associar as secundárias (11 e 12) à primária (10)
  - configurar a 11 como comunitária
  - configurar a 12 como isolada
  - configurar a vlan 20 como primária 
  - associar as secundárias (21 e 22) à primária (20)
  - configurar a 21 como comunitária
  - configurar a 22 como isolada
- Configurar a porta de cima como modo promiscuo
  - dizer qual é a primaria(10) e as secundárias(11,12)
- Configurar os pcs para as private vlans
  - Colocamos o pc na vlan privada 11 (e0/1)
  - Colocamos o pc na vlan privada 22 (e0/2)
- Colocar o DHCP a funcionar nas vlans

```console
conf t
ip routing
vlan 20
int vlan 20
ip add 192.168.20.254 255.255.255.0
no shut
exit

vlan 99
int vlan 99
ip add 192.168.99.2 255.255.255.0
no shut

int e1/0
sw trunk encapsulation dot1q
sw mode trunk

exit
router rip
network 0.0.0.0

int e1/1
no switchport
ip add 192.168.100.2 255.255.255.0
no shut
exit

vtp mode transparent
vlan 10
private-vlan primary
private-vlan association 11,12
vlan 11
private-vlan community
vlan 12
private-vlan isolated
vlan 20
private-vlan primary
private-vlan association 21,22
vlan 21
private-vlan community
vlan 22
private-vlan isolated

int e0/0
sw mode private-vlan promiscuous
sw private-vlan mapping 10 11,12

int e0/1
sw mode private-vlan host
sw private-vlan host-association 10 11
int e0/2
sw mode private-vlan host
swprivate-vlan host-association 20 22

int vlan 20
private-vlan mapping add 21,22
ip helper-address 192.168.100.1
```

### No SR3

- Configurar e criar a VLAN 10 visto que é este que fica responsável por ela
- Configurar e criar a VLAN99 para comunicar com o SR2 
- Configurar o trunk entre SR3 e SR2
- Configurar o RIP
- Configurar as private vlans
  - configurar a vlan 10 como primaria
  - associar as secundárias (11 e 12) à primária (10)
  - configurar a 11 como comunitária
  - configurar a 12 como isolada
  - configurar a vlan 20 como primária 
  - associar as secundárias (21 e 22) à primária (20)
  - configurar a 21 como comunitária
  - configurar a 22 como isolada
- Configurar as portas de cima como modo promiscuo
  - dizer qual é a primaria(20) e as secundárias(21,22)
- Configurar os pcs para as private vlans
  - Colocamos o pc na vlan privada 11 (e0/1)
  - Colocamos o pc na vlan privada 21 (e0/2)
- Colocar o DHCP a funcionar nas vlans

```console
conf t
ip routing
vlan 10
int vlan 10
ip add 192.168.10.254 255.255.255.0
no shut
exit

vlan 99
int vlan 99
ip add 192.168.99.3 255.255.255.0
no shut
exit

int e1/0
sw trunk encapsulation dot1q
sw mode trunk
exit

router rip
network 0.0.0.0

vtp mode transparent
vlan 10
private-vlan primary
private-vlan association 11,12
vlan 11
private-vlan community
vlan 12
private-vlan isolated
vlan 20
private-vlan primary
private-vlan association 21,22
vlan 21
private-vlan community
vlan 22
private-vlan isolated

int e0/0
sw mode private-vlan promiscuous
sw private-vlan mapping 20 21,22

int e0/1
sw mode private-vlan host
sw private-vlan host-association 10 11
int e0/2
sw mode private-vlan host
sw private-vlan host-association 20 21


int vlan 10
private-vlan mapping add 11,12
ip helper-address 192.168.100.1
```

### Explicação sobre a confusão entre interface vlan 99 e vlan 99 nativa

- Ao fazermos `interface vlan 99` entre os Switches de L3, estamos a criar uma rede entre switches por onde passam as vlans. Aqui como atribuidos um ip à interface tambem pode ser usada para acedermos ao equipamento por telnet
  - Outra coisa é a vlan nativa do trunk, ou seja, podemos ter a vlan 999 que é a nativa e associar essa ao trunk , no entanto temos de a criar na mesma com o comando `vlan 999` e fazer isto em todos os trunks existentes na rede


### Notas

- `sh vlan private-vlan` -> mostra as associações entre vlans privadas

- Para os PCs terem dhcp nas vlans privadas fizemos os comandos que têm o `ip helper-address`

- Só podemos criar uma vlan isolada numa vlan primária

### Notas sobre tipos de ligaçoes

- Por exemplo, se tivermos num link a passar 3 vlans temos de criar 3 sub interfaces no router e fazer o comando `encapsulation dot1q <nr da vlan> ` e depois adicionar um ip a essa subinterface

- Se tivermos um router que é o DG de uma vlan ja temos de ter um ip para a interface fazendo `ip add <ip> <mask>` dentro da interface especifica e no switch que liga a ele, configurar essa ligação como access com aquela vlan especifica fazendo `sw mode access` e depois `sw access vlan <nr da vlan>`

- Se tivermos um router ligado a um switch e nao quisermos ter nenhuma vlan no router e quisermos ter uma rede com o switch temos de desligar o switchport para passar de L2 para L3 fazendo `no switchport` depois de ter entrado na respetiva interface

- Se quisermos dizer que um switch L3 é DG de uma certa vlan fazemos `ip routing` `vlan <nr da vlan>` `int vlan <nr da vlan>` `ip add <ip> <mask>` e `no shut`
