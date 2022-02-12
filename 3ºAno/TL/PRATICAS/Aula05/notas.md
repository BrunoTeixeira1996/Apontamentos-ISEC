# Aula 09/11/2021

- Topologia 5 PVLAN


## Configuração da topologia na sala

1I - PC3 (f0/3)
2I - PC4 (f0/2)
3I - Servidor (f0/4)
SR3-SR2 (f0/1)


## Notas

- As VLANs isoladas só conseguem comunicar com as primárias e não conseguem comunicar entre si
- As VLANs comunitárias conseguem comunicar entre si

- Só é possivel ter uma isolada por cada vlan privada
- É possivel haver mais do que uma comunitária por vlan privada

- Quando temos DHCP numa vlan privada, nao precisamos de ter uma pool para essa vlan privada, precisamos sim de ter uma pool para a vlan principal

- O conceito de `router on a stick` é quando pego no link entre switch e router , coloco a porta do switch em trunk e coloco a porta do router com sub interfaces para passarem várias vlans

- Promiscuo -> toda a gente pode la ir
- Comunitario -> consegue comunicar com quem for comunitario e com as promiscuas
- Isoladas -> consegue só comunicar com as promiscuas
