# Aula 22/10/2021

- Esquema feito no GNS3

## Encaminhamento

- OSPF com área 0

## Tomadas

PC1 - 2G (PC normal)
PCBruno - 2A (PC de configuração)

R1-R2 (Serial0/0)
R1-R3 (Serial1/0)
R1-PC1 (E0/0)

## Comandos no R1

### R1-PC1

```console
conf t
int e0/0
ip add 192.168.10.254 255.255.255.0
no shut
```

### R1-R2

```console
conf t
int se0/0
ip add 10.0.0.9 255.255.255.252
no shut
```

### R1-R3

```console
conf t
int se0/1
ip add 10.0.0.5 255.255.255.252
no shut
```

### OSPF

```console
router ospf 1
router-id 9.9.9.1
network 192.168.10.0 0.0.0.255 area 
network 10.0.0.4 0.0.0.3 area 0
network 10.0.0.8 0.0.0.3 area 0
passive-interface e0/0
```

### Ativar SNMP-Server no R1

```console
conf t
snmp-server community private rw
snmp-server community public ro
```
