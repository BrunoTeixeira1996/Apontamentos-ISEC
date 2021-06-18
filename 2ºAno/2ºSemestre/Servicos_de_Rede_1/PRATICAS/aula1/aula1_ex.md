# Alguns comandos do exercicio 1 da aula pratica 1

## Mudar o nome do router

`conf t ... hostname sr1-cbr-2021`

## Mudar a password de enable

`conf t ... enable password sr12021`

## Endereços na Rede Local 1 (LAN 1) 192.168.1.xx /24

* Router -> `conf t ... in fa0/0 ... ip address 192.168.1.254 255.255.255.0 ... description LAN1 ... no shut`
* PC 0 -> `Carregar no pc ... ir a Desktop ... carregar em Ip Configuration e configurar`
* PC 1 -> `Carregar no pc ... ir a Desktop ... carregar em Ip Configuration e configurar`


## Endereços na Rede Local 2 (LAN 2) 192.168.2.xx /24

* Router -> `conf t... in fa0/1 ... ip address 192.168.2.254 255.255.0 ... description LAN2 ... no shut`
* PC 4 -> `Carregar no pc ... ir a Desktop ... carregar em Ip Configuration e configurar`

### Nota

```
Nesta LAN, foi obrigatorio usar um cross-over cable do PC4 para o Router
porque estou a ligar diretamente dois equipamentos de rede.
```

## Criar acesso Telnet de um PC ao route da LAN 1

* Temos de criar primeiro um utilizador -> `conf t ... username brun0 password ola`
* Acedemos à line vty usando 0 4 para dizer que so deixamos aceder de 0 a 4 pessoas -> `line vty 0 4`
* Usamos login local para pedir um username e uma password configurado no 1º ponto -> `login local`
* Podemos dar o privilegio maximo dessa conexao telnet -> `privilege level 15`

## Colocar um banner

`conf t ... banner motd #Cuidado que esta num sistema seguro#`

## Escreva uma palavra sem significado na configuração. O que acontece?

`O router tenta resolver aquela palavra para algum nome usando o DNS por defeito`

## Anule a funcionalidade nativa dos routers para fazer a resolução de nomes

`conf t ... no ip domain-lookup`

### O que acontece?
    
`Como agora o router em o DNS desligado, aparece uma mnesagem a dizer que  nao reconhece o comando`


[![Alt text](https://i.imgur.com/VlyQZJ6.png)](brun0)


# Alguns comandos do exercicio 2 da aula pratica 1
