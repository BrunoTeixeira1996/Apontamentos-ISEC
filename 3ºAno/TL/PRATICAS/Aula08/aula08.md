# Aula 07/12/2021

## No ROUT (Router de saida)

- Pedir dhcp
- Configurar o NAT
- Configurar ip na interface s2/1
- Configurar o RIP
- Configurar DNS Server

```console

int e0/0
ip add dhcp
no shut
exit

access-list 10 permit any
int e0/0
ip nat outside
int s2/1
ip nat inside
exit
ip nat inside source list 10 int e0/0 overload

int s2/1
ip add 172.16.10.2 255.255.255.0
no shut

router rip
version 2
network 172.16.0.0
default-information originate

ip dns server

```

## No R3

- Configurar ip na interfce s2/1
- Configurar o RIP
- Configurar VLAN 30 e 99
- Configurar o DNS para apontar para o ROUT
- Configurar o servidor de DHCP para a 40,50,60 e 70

```console
int s2/1
ip add 172.16.10.1 255.255.255.0
no shut

router rip
version 2
network 0.0.0.0

int e0/1
no shut
int e0/1.30
encapsulation dot1q 30
ip add 192.168.30.254 255.255.255.0
int e0/1.99
encapsulation dot1q 99 native
ip add 192.168.99.3 255.255.255.0

ip dns server
ip name-server 172.16.10.2

ip dhcp pool pool40
network 192.168.40.0 255.255.255.0
default-router 192.168.40.254
dns-server 192.168.99.3

ip dhcp pool pool50
network 192.168.50.0 255.255.255.0
default-router 192.168.50.254
dns-server 192.168.99.3

ip dhcp pool pool60
network 192.168.60.0 255.255.255.0
default-router 192.168.60.254
dns-server 192.168.99.3

ip dhcp pool pool70
network 192.168.70.0 255.255.255.0
default-router 192.168.70.254
dns-server 192.168.99.3
```

## No R1

- Configurar VLAN 10 e 99
- Configurar o RIP
- Configurar o FR

```console
int e0/0
no shut
int e0/0.10
encapsulation dot1q 10
ip add 192.168.10.254 255.255.255.0
int e0/0.99
encapsulation dot1q 99 native
ip add 192.168.99.1 255.255.255.0


router rip
version 2
network 0.0.0.0

int s2/0
encapsulation frame-relay
ip add 192.168.100.1 255.255.255.0
no shut
```

## No SR2

- Configurar os access
- Criar a vlan 99
- Configurar a vlan 20
- Configurar a vlan 99
- Criar os trunks
- Configurar o RIP


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
exit

vlan 99 

int vlan 20
ip add 192.168.20.254 255.255.255.0
no shut

int vlan 99
ip add 192.168.99.2 255.255.255.0
no shut

int range e0/0-1
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

router rip
version 2
network 0.0.0.0
```


## No R4

- Configurar interface e0/0
- Configurar o RIP
- Configurar o s2/0 usando o FR com point-to-point

```console
int e0/0
ip add 192.168.40.254 255.255.255.0
ip helper-address 192.168.99.3
no shut

router rip
version 2
network 0.0.0.0


int s2/0
encapsulation frame-relay
no shut
exit
int s2/0.400 point-to-point
frame-relay interface-dlci 401
ip add 192.168.100.4 255.255.255.0
```


## No R5

- Configurar o RIP
- Configurar interface e0/0
- Configurar o s2/0
- Criar as subinterface


```console
router rip
version 2
network 0.0.0.0

int e0/0
ip add 192.168.50.254 255.255.255.0
ip helper-address 192.168.99.3
no shut

int se2/0
encapsulation frame-relay
no shut
exit

int s2/0.510 point-to-point
frame-relay interface-dlci 105
ip add 192.168.100.5 255.255.255.0
exit
int s2/0.520 point-to-point
frame-relay interface-dlci 305
ip add 192.168.200.5 255.255.255.0
```

## No R3

- Configurar o FR na s2/0

```console
int s2/0
encapsulation frame-relay
no shut
int s2/0.300 multipoint
frame-relay interface-dlci 305
frame-relay interface-dlci 307
```

## No R6

- Configurar a e0/0
- Configurar o rip
- Configurar o FR
- Se quisermos pingar deste para o R4 nao conseguimos(**porque é uma especie de estrela entao o R4 nunca conhece o R6 e vice versa**), entao temos de o ajudar com o seguinte comando
  - nao tivemos de fazer isto no R4 porque o R4 está em point to point e só tem uma hipoteses de sair, no R6 estamos a usar multipoint e aqui ja temos de fazer
  - isto foi feito para do R6-R4 e R6-R5
- Desligar o split-horizon

```console
int e0/0
ip add 192.168.60.254 255.255.255.0
ip helper-address 192.168.99.3
no shut

router rip
version 2
network 0.0.0.0

int s2/0
encapsulation frame-relay
no shut
int s2/0.600 multipoint
frame-relay interface-dlci 601
frame-relay interface-dlci 607
ip add 192.168.100.6 255.2555.255.0

int s2/0.600
frame-relay map ip 192.168.100.4 601 broadcast
frame-relay map ip 192.168.100.5 601 broadcast

int s2/0.600 multipoint
no ip split-horizon
```

## No R7

- Configurar a interface e0/0
- Configurar o RIP
- Configurar a s2/0 com o FR

```console
int e0/0
ip add 192.168.70.254 255.255.255.0
ip helper-address 192.168.99.3

route rip
version 2
network 0.0.0.0

int s2/0
encapsulation frame-relay
no shut
int s2/0.710 point-to-point
ip add 192.168.100.7 255.255.255.0
frame-relay interface-dlci 706
int s2/0.730 point-to-point
ip add 192.168.200.7 255.255.255.0
frame-relay interface-dlci 703
```


## Notas

- **Atenção que se tem de apagar a configuração do SR2**

### FrameRelay

- PVC quer dizer, Permanent Virtual Circuit

- No esquema da aula existem **6 PVCs**

![image](https://user-images.githubusercontent.com/12052283/145990584-58eb331f-6b0e-4aee-bab4-e441a30351e7.png)

- Então fisicamente temos de ligar assim 

![image](https://user-images.githubusercontent.com/12052283/145064023-e9f22a03-99bd-4a9c-8b05-db755eab87e8.png)

- Depois temos de dar numeros às portas

![image](https://user-images.githubusercontent.com/12052283/145990962-ae09ef93-0268-47f6-b6a6-b53701a72e03.png)


- Depois temos de ir a cada FR e definir os PVCs
  - No FR1
  
![image](https://user-images.githubusercontent.com/12052283/145999434-543c4293-5d21-4e1c-807c-6938e22775c9.png)


  - No FR2

![image](https://user-images.githubusercontent.com/12052283/145066515-673ffa5d-8a44-4b36-9d90-dc957b393e76.png)

  -  No FR3

![image](https://user-images.githubusercontent.com/12052283/145067048-35f374fc-192b-4e61-84bd-af7be1c65557.png)


- Depois fazermos a configuração das portas

![image](https://user-images.githubusercontent.com/12052283/145997512-ef432f63-7d9c-4b0d-b1a3-5d83358802b5.png)


- `sh frame-relay pvc` -> para ver os pvcs que estão ligados
- `sh fam map` -> tambem util mas nem sei para que

- **Tivemos de desligar o split-horizon no R6 porque se nao o R7 nunca recebe o resto das rotas de cima porque o R6 so tem uma porta e nao consegue enviar as rotas que recebe. Atenção que isto só acontece se a interface for multipoint.**
