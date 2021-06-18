# Exercicio 1

```
ir ao router que vai fazer o nat (Router Sede)-> conf t ... ip nat inside source static 10.1.1.2 213.85.204.1 (atencao que nao pode ser uma rede que exista na rede privada)
ir à interface local -> conf t ... int eth1/1 ... ip nat inside
ir à interface da rede exterior -> conf t ... int se0/0/0 ... ip nat outside
```

# Exercicio 2

```
ir ao router que vai fazer o nat (Router Sede)
Criar a access list -> conf t ... access-list 1 permit 192.168.0.0 0.0.255.255
Dar bind da access list com a interface -> ip nat inside source list 1 interface <interface> overload
ir a todas interfaces locais -> conf t ... int <interface> ... ip nat inside
ir à interface da rede exterior -> conf t ... int se0/0/0 ... ip nat outside
```


# Exercicio 2 com uma NAT Pool

```
ir ao router que vai fazer o nat (Router Sede)
Criar a access list -> conf t ... access-list 1 permit 192.168.0.0 0.0.255.255
Criar uma pool de NAT -> conf t ... ip nat pool OLA 213.85.204.1 213.85.204.5 netmask 255.255.255.224
Dar bind da Pool com a Access List -> ip nat inside source list 1 pool OLA overload
ir a todas interfaces locais -> conf t ... int <interface> ... ip nat inside
ir à interface da rede exterior -> conf t ... int se0/0/0 ... ip nat outside
```
