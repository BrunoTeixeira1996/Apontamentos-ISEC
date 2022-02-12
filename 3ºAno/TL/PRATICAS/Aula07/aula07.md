# Aula 30/11/2021

## Switch Security and Monitoring

### No R2

- Pedir dhcp ao NAT
- Configurar NAT
- Configurar IP na e0/1
- Configurar servidor de dns
- Configurar RIP

```code

int e0/0
ip add dhcp
no shut

int e0/0
ip nat outside
int e0/1
ip nat inside
exit
access-list 10 permit any
ip nat inside source list 10 interface e0/0 overload

int e0/1
ip add 172.16.10.2 255.255.255.0
no shut

ip dns server

router rip
network 0.0.0.0
default-information originate
```


### No R1

- Configurar IP na e0/1
- Configurar a default route e DNS
- Criar servidor DNS para dentro da empresa
- Criar a vlan 10 e 30 e as subinterfaces visto que só tem 1 cabo
- Ativar o RIP

```code

int e0/1
ip add 172.16.10.1 255.255.255.0
no shut

exit
ip name-server 172.16.10.2

ip dns server

int e0/0
no shut
int e0/0.10
encapsulation dot1q 10
ip add 192.168.10.254 255.255.255.0
no shut
int e0/0.3
encapsulation dot1q 30
ip add 192.168.30.254 255.255.255.0
int e0/0.99
encapsulation dot1q 99 native
ip add 192.168.99.1 255.255.255.0

router rip
network 0.0.0.0
```


### No SW2

- Mudar largura de banda para 100 Mbps e colocar em trunk
- Configurar STP
- Criar o port channel (SW2-SR1)
- Alterar o custo da porta e1/0 para ser RP
- Ativar o vtp e criar vlans para emitir para todos os outros switches
- Configurar o access

```console
int range e0/2-3,e1/0
bandwidth 100000
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99
exit

spanning-tree vlan 1,10,20,30,99 priority 57344

int range e0/2,e0/3
channel-group 1 mode active

int e1/0
spanning-tree cost 7

vtp domain SEC
vlan 10
vlan 20
vlan 30
vlan 99

int e0/0
sw mode acc
sw acc vlan 10
```

### No SW3

- Mudar largura de banda para 100 Mbps e colocar em trunk
- Configurar STP
- Alterar a porta e1/1 para Gigabit
- Criar os access

```console
int range e1/0-2
bandwidth 100000
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

spanning-tree vlan 1,10,20,30,99 priority 32768

int e1/1
bandwidth 1000000

int e0/0
sw mode acc
sw acc vlan 20
```

### No SW4

- Mudar largura de banda para 100 Mbps e colocar em trunk
- Configurar STP
- Alterar a porta e1/1 para Gigabit
- Configurar o mode access na e0/0


```console
int range e1/0-1,e2/0
bandwidth 100000
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

spanning-tree vlan 1,10,20,30,99 priority 45056

int e1/1
bandwidth 1000000

int e0/0
sw mode acc
sw access vlan 20
spanning-tree portfast
```

### No SW5 (Este é o RB)

- Mudar largura de banda para 100 Mbps e colocar em trunk
- Configurar STP
- Mudar o peso da porta(baixar para 64) para alterar a porta primaria
- Criar o access

```console
int range e1/0-1,e1/3
bandwidth 100000
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

spanning-tree vlan 1,10,20,30,99 priority 8192

int e1/3
spanning-tree port-priority 64

int e0/0
sw mode acc
sw acc vlan 10
```

### No SR1

- Mudar largura de banda para 100 Mbps e colocar em trunk
- Configurar STP
- Criar o port channel (SR1-SW2)
- Este é o DG da vlan 20 e da 99
- Ativar o RIP
- Configurar SSH
- Criar o mode access

```console
int range e0/2-3,e1/1-3
bandwidth 100000
sw trunk encapsulation dot1q
sw mode trunk
sw trunk native vlan 99

spanning-tree vlan 1,10,20,30,99 priority 20480

int range e0/2,e0/3
channel-group 2 mode active

ip routing
int vlan 20
ip add 192.168.20.254 255.255.255.0
no shut
int vlan 99
ip add 192.168.99.254 255.255.255.0
no shut

router rip
network 0.0.0.0

ip domain-name TL_SECURITY #dar nome ao dominio
username admin privilege 15 secret cisco #criar utilizador
line vty 0 4 #ativar o ssh na line0, line1, line2, line3 e line4
privilege level 15
login local
transport input ssh
exit
crypto key generate rsa usage-keys modulus 1024 # gerar o par de chaves RSA

int e0/0
sw mode acc
sw acc vlan 30
```


### Notas

- Mudamos a porta e1/0 do SW2 para ser root port com o `spanning-tree cost 7`

- Caso exista uma ligação primaria/secundaria podemos alterar o `port-priority` do vizinho de modo a escolher qual a primaria/secundaria
  - No caso do SR1-SW5 fizemos com `port-priority` no entanto podiamos mudar o custo da ligação que queremos que seja primaria para menor

- Atenção que subtituimos o PC3 por um Ipterm para testar o SSH

- `spanning-tree portfast` só pode ser feito nas portas viradas para os PCs

- `Segurança em portas trunk`
  - A primeira coisa que devemos fazer um switch novo é colocar todas as portas em access
	- `sw mode access`
  - `sw nonegotiate` -> comando para desligar o DTP (No GNS3 não funciona)
  - `storm-control broadcast level 10` -> comando sobre o storm control (No GNS3 não funciona)

  - Para garantir que um switch é uma RB (é uma forma mais facil de configurar o STP, é mesmo o minimo dos minimos)
	- `spanning-tree vlan 1 root primary`

  - Para garantir que um switch é RB secundária caso o RB primário vá à vida
   - `spanning-tree vlan 1 root secondary`

  - Colocamos root guard nas portas que nao sao root ports para garantir que nenhuma dessas portas (root gard) se tornem root ports -> Este comando só se coloca nas DP
   - `int e3/3 ... spanning-tree guard root`
   - Quer dizer que esta porta nunca poderá transformar-se em root port
