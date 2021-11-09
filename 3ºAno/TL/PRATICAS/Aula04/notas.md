# Aula P 02/11/2021

## Configuração do SW2 na sala

2I -> pc host
2G -> pc host
1I -> pc host

1G -> pc consola

f0/1 -> pc4
f0/5 -> pc5
f0/2 -> pc6

f0/21-> sw2 para sw3
f0/22 -> sw2 para o sw1

- Criar VLAN numa interface num switch (neste caso tivemos de criar a 30 e a 99)
  - Como as portas não são nivel 3, temos de criar desta maneira
  - **A vlan 30 tem de estar criada**

```code
conf t
ip routing
int vlan 30
ip add 192.168.30.254 255.255.255.0
no shut

exit
int vlan 99
ip add 192.168.99.2 255.255.255.0
no shut
```


## Configuração do R2

- Neste router temos de passar 3 VLANs por uma única porta então fazemos o seguinte

```console
conf t
int e0/3
no shut
int e0/3.10
encapsulation dot1q 10 # aqui estamos agarrar a VLAN10
ip add 192.168.10.254 255.255.255.0 # aqui estamos a dar ip à interface

int e0/3.20
encapsulation dot1q 20 # aqui estamos agarrar a VLAN20
ip add 192.168.20.254 255.255.255.0 # aqui estamos a dar ip à interface

int e0/3.99
encapsulation dot1q 99 # aqui estamos agarrar a VLAN99
ip add 192.168.99.12 255.255.255.0 # aqui estamos a dar ip à interface

## se a 99 for a nativa temos de fazer isto e colocar no switch que a 99 é a nativa

int e0/3.99
encapsulation dot1q 99 native
ip add 192.168.99.12 255.255.255.0
```

- Para dar NAT ao Router temos sempre de meter nas portas que têm IP então colocamos nas que foram criadas em cima que têm IP

```console
conf t
int e0/0
ip nat outside

int e0/3.10
ip nat inside

int e0/3.20
ip nat inside

int e0/3.99
ip nat inside

exit
access-list 10 permit any
ip nat inside source list 10 interface e0/0 overload
```

- Depois fazemos o rip

```console
conf t
router rip
network 0.0.0.0
```
