# Aula 21/12/2021


## Na aula

### No RCN1head

```console
conf t
int f0/0
no shut
int f0/0.10
encapsulation dot1q 10
ip add 192.168.1.11 255.255.255.0
int f0/1
ip add 192.168.10.254 255.255.255.0
no shut
ip route 192.168.20.0 255.255.255.0 192.168.1.12
```

### No SWCN1head

```console
int f0/2
sw mode acc
sw acc vlan 10
int f0/3
sw mode trunk
sw trunk native vlan 99
exit
vlan 99
```

### No ISP2

- Tunel para os switches
  - 501 -> para o verde
  - 502 -> para o vermelho

- Trunk para os routers e entre ISPs

```
deis-l01c02a
!deis2021_L=!
```

## Notas

- A 501 não pinga com a 502, passa no mesmo ISP mas nao comunicam as duas e é este o objetivo do QinQ
