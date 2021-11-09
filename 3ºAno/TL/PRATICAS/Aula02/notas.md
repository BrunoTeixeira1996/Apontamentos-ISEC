# Aula 19/10/2021

- Topologia feita no GNS3

## Notas

- Os cabos entre pc e switch são **cabos diretos**

- Os cabos entre switches são **cabos cruzados**

- Os cabos rollover são usados para acedermos à consola do equipamento

- Há sempre uma vlan por omissão e normalmente não usamos esta vlan, chamada normalmente de vlan1

- **switchport mode access** na porta e0/0 -> é onde vai estar ligado um PC

- Ao fazermos o **switchport access vlan 10** caso a mesma não exista o switch cria por nós

- Para apagarmos a vlan no gns3 fazemos **delete unix:vlan.dat** e depois **reload**

- **switchport mode trunk** -> Colocar as portas no modo que suporta tudo, ou seja, suporta todas as vlans, normalmente é na porta de saída do switch

- Ao colocarmos uma porta em modo **trunk** irá dar um erro uma vez que a porta é **Auto**, logo temos de alguma forma marcar os pcs que estao em vlans e querem sair para outro lado, para isso fazemos **switchport trunk encapsulation 802.1q** (isto no GNS3, no equipamento é só **switchport mode trunk**)

- Temos de colocar em modo **trunk** nas portas entre switches

## Comandos feitos

### Comando no switch sobre vlans

```console
en
conf t
hostname SW1
enable secret cisco
copy running-config startup-config
sh vlan brief -> mostra as vlans que já existem
vlan 33 -> cria a vlan 33
name trintaetres -> dá nome à vlan
no vlan 33 -> apaga a vlan 33
```

### Configuração do switch1 (GNS3)

```console
en
conf t
hostname SW1
enable secret cisco
int e0/0
switchport mode access
switchport access vlan 10
wr

int e0/1
switchport mode access
sw acc
sw acc access vlan 20
wr

int e0/2
switchport mode access
sw acc
sw acc access vlan 30
wr

int e1/0
switchport trunk encapsulation dot1q
switport trunk allowed vlan 10,20,30
switchport mode trunk
wr
```
