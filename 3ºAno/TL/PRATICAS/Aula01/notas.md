# Aula 12/10/2021 - Prática

## Ver para usar cabo serial para usb

* https://www.cyberciti.biz/faq/find-out-linux-serial-ports-with-setserial/

* https://unix.stackexchange.com/questions/22545/how-to-connect-to-a-serial-port-as-simple-as-using-ssh

* http://tio.github.io/

## Diferença entre HUB e Switch

* O HUB envia as mensagens para toda a gente mesmo que essa "pessoa" não tenha "pedido", ao contrário do switch que só envia para quem "perguntou"


- **Mostrar tabela de macs do switch** (No Packet Tracer)
	- ```conf t```
	- ```sh mac-address-table```
- **Mudar a tabela de macs do switch de dinâmico para estático** (No Packet Tracer)
	- ```conf t```
	- ```mac-address-table static 1111.2222.3333 vlan 1 int f0/1```

![image](https://user-images.githubusercontent.com/12052283/136990313-b203910f-581a-492e-b11e-f08c84fd1448.png)

- **Podemos mudar de DYNAMIC para STATIC e isto é bom caso queiramos dizer que naquela porta (neste caso FA0/1) só é aceite um determinado mac address**

- **As entradas DYNAMIC têm um lease time ou seja, entram e saiem**

- **Apagar a configuração de um router**
	- ```erase startup-config```

- **Apagar a configuração de um switch**
	- **No switch temos de apagar a configuração e as VLANs**

	- **Limpar no Packet Tracer**
	- ```erase startup-config```
	- ```delete flash:vlan.dat```

	- **Limpar no GNS3**
	- ```erase startup-config```
	- ```delete unix:vl```
