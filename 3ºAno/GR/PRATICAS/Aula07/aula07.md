# Aula 10/12/2021

- Ativar snmp no router
  - `snmp-server community public ro`

## Na aula

- Configurar o nome, ip de um pc host e a localização

- `conf t` ... `location <locations_name>`

`snmpget -v 1 -c public -d <router_ip> OID`

## Pacote SNMP

### Sending

Sending 41 bytes to UDP: [192.168.1.254]:161->[0.0.0.0]
0000: 30 27 02 01  00 04 06 70  75 62 6C 69  63 A0 1A 02    0'.....public..
0016: 02 33 B1 02  01 00 02 01  00 30 0E 30  0C 06 08 2B    .3±......0.0...+
0032: 06 01 02 01  01 05 00 05  00                          .........

-» 30 27 - características da mensagem
0x30 -> representa que é uma mensagem SNMP (sequência) 
0x27 -> tamanho em Hexadecimal da mensagem - 39 bytes 


Identifier Tamanho
-» 02        01       
02 -> representa um inteiro
01 -> tamanho - 1 byte
00 -> conteúdo - 0 que é versão do SNMP (SNMPv1)

Identifier Tamanho 
-» 04        06     
04 -> representa uma string - 'public'
06 -> 6 bytes
70 -> p
75 -> u
62 -> b
6C -> l
69 -> i
63 -> c

Identifier Tamanho 
-» A0        1A
A0 -> get request
1A -> 26 bytes 
	
-> Dentro deste get request com 26bytes temos
	-> 02 (um inteiro) com 02 bytes que é o 33 e B1
	-> 02 (um inteiro) com 01 bytes que é o 00
	-> 02 (um inteiro) com 01 bytes que é o 00
	-> 30 (uma sequência) com 0E (14)bytes 
	-> 30 (uma sequência) com 0C (12)bytes
		->  Identifier Tamanho 
			 06        08 
			 06 -> representa object identifier
			 08 -> tamanho - 8 bytes
			 2B -> .1.3
			 06 -> .6
			 01 -> .1
			 02 -> .2
			 01 -> .1 
			 01 -> .1
			 05 -> .5
			 00 -> .0

		-> 05 00 -> NULL



### Received

Received 54 bytes from UDP: [192.168.1.254]:161->[0.0.0.0]
0000: 30 34 02 01  00 04 06 70  75 62 6C 69  63 A2 27 02    04.....public¢'.
0016: 02 33 B1 02  01 00 02 01  00 30 1B 30  19 06 08 2B    .3±......0.0...+
0032: 06 01 02 01  01 05 00 04  0D 52 46 49  4C 41 44 41    .........RFILADA
0048: 46 52 45 4E  54 45

-» Mensagem SNMP (0x30) com 0x34 bytes 
-» Inteiro (0x2) com o tamanho de 0x1 byte que representa a versão: 0 versão 1 do snmp (SNMPv1)
-» String (0x4) com o tamanho de 0x6 byte que representa a string public
-» Get Response (0xA2) com o tamanho de 0x27 bytes 
	-> Dentro do Get Response
		- Inteiro (0x2) com o tamanho de 0x2 bytes com o valor de 0x33 0xB1
		- Inteiro (0x2) com o tamanho de 0x1 bytes com o valor de 0x00
		- Inteiro (0x2) com o tamanho de 0x1 bytes com o valor de 0x00
		- Sequencia (0x30) com o tamanho de 0x1B bytes
		- Sequencia (0x30) com o tamanho de 0x19 bytes
		- Objet identifier (0x06) com o tamanho de 0x08 bytes
			- Com o valor .1.3.6.1.2.1.1.5.0 (0x2B06010201010500)
		- String (0x04) com o tamanho 0x0D bytes que representa a string RFILADA (0x5246494c4144414652454E5445)
