# Aula 26/10/2021

## Pequenos comandos

- Mostrar todas as VLANs

```console
sh vlan brief
```

- Mudar nome a VLAN

```console
conf t
vlan 20
name <Nome>
```

- Retirar VLAN da porta

```console
conf t
default interface e0/1
```

- Mostrar interfaces que estão em trunk

```console
show interfaces trunk
```

- Mostra estado do VTP

```console
show vtp status
```

## Configuração1

### Configuração1 no SW1

- As portas e0/0 e0/1 e e0/2 tem de estar na VLAN 10 VLAN20 e VLAN40 respetivamente porque ligam ao PC1 PC2 e PC3

- A porta e0/2 está ligada ao R1(DHCP Server que está na VLAN40) então tem de estar na VLAN40

- As portas e2/1 e2/2 e e2/3 tem de estar na VLAN10 VLAN20 e VLAN30 respetivamente entao temos de as configurar com o `mode access`

- A porta e2/0 tem de estar na VLAN40 porque o router quer receber pacotes da VLAN40

```console
en
conf t
hostname SW1
line console 0
exec-timeout 0

int e0/0
switchport mode access
switchport access vlan 10

int e0/1
switchport mode access
switchport access vlan 20

int e0/2
switchport mode access
switchport access vlan 40

int e2/0
switchport mode access
switchport access vlan 40

int e2/1
switchport mode access
switchport access vlan 10

int e2/2
switchport mode access
switchport access vlan 20

int e2/3
switchport mode access
switchport access vlan 30
```


### Configuração1 no R1

- Atribuimos ip à interface e0/0 porque o mesmo vai ser o DHCP Server

- Criamos uma POOL para a VLAN40

```console
en
conf t
hostname R1
line console 0
exec-timeout 0

int e0/0
ip add 192.168.40.254 255.255.255.0
no shut

ip dhcp pool POOL_VLAN40
network 192.168.40.0 255.255.255.0
default-router 192.168.40.254
ip dhcp excluded-address 192.168.40.250 192.168.40.254
```

### Configuração1 no R2

- O R2 tem de ser DG da VLAN 10,20 e 30 daí ter 3 ligações

```console
en
conf t
hostname R12
line console 0
exec-timeout 0

int e1/1
ip add 192.168.10.254 255.255.255.0
no shut

int e1/2
ip add 192.168.20.254 255.255.255.0
no shut

int e1/3
ip add 192.168.30.254 255.255.255.0
no shut

```


## Configuração2

### Configuração2 no SW1

- Aqui criamos a VLAN99 entre R1 e R2 logo na e3/0 e e3/1 temos de colocar em modo access

```console
conf t
vlan 99
int range e3/0-1
switchport mode access
switchport access vlan 99
```

### Configuração2 no R1

- Aqui damos IP à e1/0

- Criamos RIP no R1 dizendo que o mesmo conhece a rede `.40.0` e `.99.0`

```console
conf t
int e1/0
ip add 192.168.99.11 255.255.255.0
no shut
exit
router rip
version 2
network 192.168.40.0
network 192.168.99.0
```

### Configuração2 no R2

- Fazemos exatamente o mesmo que fizemos no R1

```console
conf t
int e1/0
ip add 192.168.99.12 255.255.255.0
no shut
exit
router rip
version 2
network 192.168.10.0
network 192.168.20.0
network 192.168.30.0
network 192.168.99.0
```


## Configuração3

### Configuração3 no SW1

- Colocamos a interface de saida do SW1 como modo trunk

```console
conf t
int e1/0
switchport trunk encapsulation dot1q
switchport mode trunk
```

### Configuração3 no SW2

- Colocamos a interface de saida do SW2 como modo trunk, tanto a e1/0 como a e1/1

- Criamos as VLANs necessárias

```console
conf t
int e1/0
switchport trunk encapsulation dot1q
switch mode trunk

int e0/0
switchport mode access
switchport access vlan 10

int e0/1
switchport mode access
switchport access vlan 30

int e0/2
switchport mode access
switchport access vlan 40

int e1/1
switchport trunk encapsulation dot1q
switchport mode trunk
```

### Configuração3 no SW3

- Criamos as VLANs necessárias

- Colocamos a interface de saida do SW3 como modo trunk

```console
conf t
int e0/0
sw mode access
sw acc vlan 30

int e0/1
sw mode access
sw acc vlan 20

int e0/2
sw mode access
sw acc vlan 40

int e1/1
switchport trunk encapsulation dot1q
switchport mode trunk
```


## Notas


- Até à `configuração 1` o PC1 ja comunica com o PC2 no entanto ainda não comunica com o PC3 porque o R2 só tem a VLAN 10, 20 e 30 e não tem a 40. Na proxima configuração já resolvemos este problema

- Na `configuração 2` criamos um link do R1-Switch e um do R2-Switch para o R1-R2 estarem ligados(`criada a rede 192.168.99.0/24`)
  - Aqui já conseguimos pingar do R1 para o R2
  - Tambem já conseguimos pingar do PC1 para o PC3 depois de ter configurado o RIP

- Na `configuração 3` vamos começar a descer para comunicar a parte de cima com a parte debaixo
  - `Se quisermos comunicar do PC8 para o PC1 por exemplo não funciona porque o SW2 não conhece a VLAN20 (VLAN do PC8)`
	- Para resolver isto basta irmos ao SW2 e criamos a VLAN 20
  
- Comunicação do PC4 para o PC2
  - Trafego nao marcado do PC4 para o SW2
  - Trafego marcado com a VLAN10 do SW2 para o SW1
  - Trafego nao marcado do SW1 para o R2
  - Trafego nao marcado do R2 para o SW1
  - Trafego nao marcado do SW1 para o PC2
  - Trafego nao marcado do PC2 para o SW1
  - Trafego marcado com a VLAN10 do SW1 para o SW2
  - Trafego nao marcado do SW2 para o PC4

- Do `switch` para o `pc` mete-se em `access mode` e é `trafego nao marcado`
- Do `switch` para outro `router` é `tráfego não marcado`
- Do `switch` para outro `switch` é `tráfego marcado`

- DTP (`Dinamic Trunking Protocol`)
  - Serve para criar trunks entre switches
  - Com este protocolo não precisamos de criar trunks entre switches
  - As portas podem acordar em vários modos ... é relativo
  
![image](https://user-images.githubusercontent.com/12052283/138929016-8ccbbe60-a721-4528-9fcf-ae2ca0840568.png) 

- VTP (`Vlan Trunking Protocol`) , isto serve para não termos de criar vlans que nao existem em switches só para esse switch conhecer a respetiva vlan
  - Basta que um switch contenha o VTP ligado para "infetar" os outros switches todos no entanto isto pode ser bastante mau
  - Para colocar um nome usamos `vtp domain <Nome>`
  - **Se tivermos um switch com varias VLANs e outro sem VLANs , se ligarmos o VTP no switch que nao tem VLANs o switch com várias VLANs vai ficar sem nenhuma porque ficou "infetado"**
  - **Por este problema existir convém termos em todos os switches o VTP configurado fazendo com que assim nenhum VTP externo danifique as VLANs de outro switch**
  - O `configuration revision` é o número que mostra qual VTP tem maior prioridade, no entanto este número vai aumentando consoante o tempo
  - Sempre que criarmos uma nova VLAN o `configuration revision` aumenta
  - `vtp pruning` faz com que apenas as VLANs ligadas ao switch apareçam no `sh int trunk`
	- O mesmo não aceita tráfegos de VLANs que não sejam necessários em certos sítios
  - **Por fim convem então criarmos sempre um VTP em todos os switches com nomes e passwords e convem ligarmos o pruning**
	  - `vtp domain <Nome>`
	  - `vtp password <Password>`
	  - `vtp pruning`
