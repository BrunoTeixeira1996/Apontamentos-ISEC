# Teste02

## Pergunta 1

- Nº do PC
  - **ver o nr do pc da sala**

- Endereço IP do PC
  - **ipconfig**

- Endereço IP do Router
  - **ipconfig** na parte do Default Gateway

- Nome do Router
  - **snmpget -v 2c -c cisco 'ip do router' sysName.0**

## Pergunta 2

- Nome da interface e ip das interfaces do router a que estamos ligados
  - **snmpwalk -v 2c -c cisco 'ip do router' ipAddrTable**
  - **snmpwalk -v 2c -c cisco 'ip do router' ifTable**

- Descobrir as interfaces que existem num router
  - **snmpwalk -v 2c -c cisco 'ip do router' IfDescr**


## Pergunta 3

- Protocolo de encaminhamento e edes presentes na tabela de encaminhamento
  - **snmpwalk -v 2c -c cisco 'ip do router' ipRouteTable**
 

## Pergunta 4

- Preencher a tabela com os IPs das interfaces de cada um dos routers
  - Se usarmos o next-hop é aqui que descobrimos tudo, conseguimos saltar para os outros routers
	- **snmpwalk -v 2c -c cisco 'ip do router' ipRouteNextHop**

