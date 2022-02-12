# Aula 14/12/2021

## Esquema do FR

![image](https://user-images.githubusercontent.com/12052283/146033238-2718b069-bd97-4173-8d4a-158d8f2d9b94.png)

## No FR

- **Atenção que ha 2 portas do R3 para o ROUT(R9)**

![image](https://user-images.githubusercontent.com/12052283/146053888-a1ff9e42-1655-41b8-8cd9-76798fb3ec07.png)

- Depois disto ligamos as portas e damos IPs

![image](https://user-images.githubusercontent.com/12052283/146034942-85e8969a-7d35-4c50-94e7-194cbdf05c06.png)


## No R1

- Criar a subinterface para a vlan 10
- Criar a subinterface para a vlan 99
- Criar a subinterface para a vlan 30
- Configurar o RIP
- Configurar o FR com o multipoint
- Transformar o FR em PPPoFR (PPP over FrameRelay)


```console
int e0/0
no shut
int e0/0.10
encapsulation dot1q 10
ip add 192.168.10.254 255.255.255.0

int e0/0.99
encapsulation dot1q 99 native
ip add 192.168.99.1 255.255.255.0

int e0/0.30
encapsulation dot1q 30
ip add 192.168.30.254 255.255.255.0

router rip
network 0.0.0.0

int s2/0
encapsulation frame-relay
no shut
exit
int s2/0.100 multipoint
frame-relay interface-dlci 104
frame-relay interface-dlci 105
ip add 192.168.100.1 255.255.255.0

int s2/0.100
no ip add
int virtual-template 10
ip add 192.168.100.1 255.255.255.0
int s2/0.100
no frame-relay interface-dlci 104
no frame-relay interface-dlci 105
frame-relay interface-dlci 104 ppp virtual-Template 10
frame-relay interface-dlci 105 ppp virtual-Template 10
```

## No SR2

- Configurar as vlans
- Configurar a vlan 99
- Criar a vlan 20 porque é este o DG da mesma
- Configurar o RIP
- Configurar a e0/0 com o trunk e com a vlan nativa
- Passar a interface e0/1 de L2 para L3 e configurar rede entre SR2 e R3
- 

```console
int e1/0
sw mode acc
sw acc vlan 10
int e1/1
sw mode acc
sw acc vlan 20
int e1/2
sw mode acc
sw acc vlan 30

vlan 99
int vlan 99
ip add 192.168.99.2 255.255.255.0
no shut

int vlan 20
ip add 192.168.20.254 255.255.255.0
no shut

router rip
network 0.0.0.0

int e0/0
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

int e0/1
no switchport
ip add 192.168.23.2 255.255.255.0
no shut
```

## No R3

- Configurar a e0/1 (**aqui não é preciso criar subinterfaces porque o link que vem de SR2 já é L3**)
- Configurar o RIP
- Tranformar o Multilink FR em Multilink PPPoFR

```console
int e0/1
ip add 192.168.23.3 255.255.255.0
no shut

router rip
network 0.0.0.0

int s2/0
encapsulation frame-relay
no shut
exit
int s2/0.39 point-to-point
frame-relay interface-dlci 319 ppp virtual-Template 10
exit
int virtual-template 10
no ip
exit
int multilink 10
ppp multilink group 10
ip add 192.168.200.3 255.255.255.0
no shut
exit
int virtual-template 10
ppp multilink group 10
exit
int s2/1
encapsulation frame-relay
no shut
exit
int s2/1.39 point-to-point
frame-relay interface-dlci 329 ppp virtual-Template 10
```

## No ROUT (Chamamos este router de 9)

- Pedir DHCP
- Configurar multilink PPPoFR
- Configurar o NAT
- Configurar o RIP

```console
int e0/0
ip add dhcp
no shut
exit

int s2/0
encapsulation frame-relay
no shut
frame-relay interface-dlci 913 ppp virtual-Template 10
no shut
exit
int multilink 10
ip add 192.168.200.9 255.255.255.0
ppp multilink
ppp multilink group 10
exit
int virtual-template 10
ppp multilink
ppp multilink group 10
exit
int s2/1
encapsulation frame-relay
no shut
frame-relay interface-dlci 923 ppp virtual-Template 10

conf t
int e0/0
ip nat outside
exit
int multilink 10
ip nat inside
exit
access-list 10 permit any
ip nat inside source list 10 interface e0/0 overload

router rip
network 192.168.200.0
default-information originate
```

## No R4

- Configurar a e0/0
- Configurar o framerelay (tem de ser numa subinterface, porque só assim é que colocamos aquela interface a L2)
- Configurar o RIP
- Transformar o FR em PPPoFR (PPP over FrameRelay)

```console
int e0/0
ip add 192.168.40.254 255.255.255.0
no shut

int s2/0
encapsulation frame-relay
no shut
exit
int s2/0.100 point-to-point
frame-relay interface-dlci 401
ip add 192.168.100.4 255.255.255.0

router rip
network 0.0.0.0

int s2/0.100
no ip add
no frame-relay interface-dlci 401
frame-relay interface-dlci 401 ppp virtual-Template 14
exit
exit
int virtual-template 14
ip add 192.168.100.4 255.255.255.0
```

## No R5

- Configurar a e0/0
- Configurar o framerelay (**Aqui nao é preciso fazer o interface-dlci porque nao é nem p2p nem multipoint, é uma inteface fisica**)
- Configurar o RIP
- Criar o group multilink e dar IP
- Criamos ppp multilink na s2/1 e na s2/2(**basicamente metade do trafego vai para um lado e outra metade vai pelo outro**)
- Ativar o chap
- Transformar o FR em PPPoFR (PPP over FrameRelay)
- Configurar a s2/3 com pap


```console
int e0/0
ip add 192.168.50.254 255.255.255.0
no shut

int s2/0
encapsulation frame-relay
no shut
ip add 192.168.100.5 255.255.255.0

router rip
network 0.0.0.0

int multilink 10
ip 192.168.58.5 255.255.255.0
no shut
ppp multilink
ppp multilink group 10

int s2/1
no shut
encapsulation ppp
ppp multilink
ppp multilink group 10
int s2/2
no shut
encapsulation ppp
ppp multilink
ppp multilink group 10
exit

username R8 password passentreR5eR8
int multilink 10
ppp authentication chap

int s2/0
no ip add
int virtual-template 15
ip add 192.168.100.5 255.255.255.0
int s2/0
frame-relay interface-dlci 501 ppp virtual-Template 15

conf t
username R6 password ola
int s2/3
encapsulation ppp
ppp authentication PAP
ppp pap sent-username R5 password ola
no shut
ip add 192.168.56.5 255.255.255.0
```

## No R6

- Configurar a e0/0
- Configurar o RIP
- Usar o PPP na s2/0
- Configurar a s2/3

```console
int e0/0
ip add 192.168.60.254 255.255.255.0
no shut

router rip
network 0.0.0.0

int s2/0
encapsulation ppp
ip add 192.168.67.6 255.255.255.0
no shut
compress mppc

conf t
username R5 password ola
int s2/3
encapsulation ppp
ip add 192.168.56.6 255.255.255.0
no shut
ppp authentication pap
ppp pap sent-username R6 password ola
```

## No R7

- Configurar a e0/0
- Configurar o RIP
- Usar o PPP na s2/0


```console
int e0/0
ip add 192.168.70.254 255.255.255.0
no shut

router rip
network 0.0.0.0

int s2/0
encapsulation ppp
ip add 192.168.67.7 255.255.255.0
no shut
compress mppc
```

## No R8

- Configurar a e0/0
- Configurar o RIP
- Configurar o multilink para ligar ao R5
- Configurar o chap

```console
int e0/0
ip add 192.168.80.254 255.255.255.0
no shut

router rip
network 0.0.0.0

int multilink 11
ip add 192.168.58.8 255.255.255.0
no shut
ppp multilink
ppp multilink group 11
exit
int s2/1
no shut
encapsulation ppp
ppp multilink
ppp multilink group 11
int s2/2
no shut
encapsulation ppp
ppp multilink
ppp multilink group 11

username R5 password passentreR5eR8
int multilink 11
ppp authentication chap
```

## Notas

- **Routed link** é um link de L3 então não consigo passar por aqui VLANs (`fazer isto no projeto`)
  - **No exemplo da aula, o R3 é um routed link**

- **Router on a stick** é quando temos uma ligação entre um router e um switch e temos o switch com vlans e queremos que o router também as tenha
  - para isso fazemos subinterfaces para o router receber o tráfego nível 2(vlans)
  - para o switch receber tráfego dos routers, de nível 3, fazemos interfaces vlans
  - **No exemplo da aula, o R1 é um router on a stick**

- O **PPP** é um point to point protocol
  - **Point-to-Point Protocol (PPP) is a TCP/IP protocol that is used to connect one computer system to another. Computers use PPP to communicate over the telephone network or the Internet. ... It also allows multiple network communication protocols to use the same physical communication line.**

- **chap** é um protocolo de autenticação
  - criamos um hostname com o nome do Router da outra ponta
  - o username é o hostname do Router atual e a password tem de ser a mesma

- Quando temos PPPoFR na interface que leva o FR não pomos nenhum IP

- **ip tcp header-compression** -> 
