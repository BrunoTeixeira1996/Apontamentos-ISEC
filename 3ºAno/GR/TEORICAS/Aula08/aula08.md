# Aula 03/01/2022
## NM - Ferramentas e Sistemas

### Bit Error Rate

- Ferramente de monitorização da camada fisica
- Gera e deteta bits
- O BER (Bit Error Rate) é calculado por comparação entre o padrão gerado e o padrão recebido

![image](https://user-images.githubusercontent.com/12052283/147968053-50719511-1fd0-47a2-baff-82ba6ee6e31e.png)


### Ferramentas de Software

- Podem ser dividas em 3 grandes grupos
  - Status monitoring tools
	- ![image](https://user-images.githubusercontent.com/12052283/147968248-c95388f5-b827-43cd-8ae4-4c94e4ec22f7.png)
  - Traffic monitoring tools
	- ![image](https://user-images.githubusercontent.com/12052283/147968305-38f3e489-c96b-4e72-a934-b4e45bf8a069.png)
  - Route monitoring tools
	- ![image](https://user-images.githubusercontent.com/12052283/147968348-efe67d45-73ec-476f-991a-f4b3dfacec57.png)

### Ferramentas de Rede

- SNMP Command Tools
  - ![image](https://user-images.githubusercontent.com/12052283/147968459-9c4736dc-9812-4b76-bc67-14d1cb1bf5bd.png)

- MIB Walk
- MIB Browser
- snmpsniff

### Protocol Analyzar

- Analisa todos os dados a todos os niveis protocolares
- As medições são feitas localmente ou remotamente

![image](https://user-images.githubusercontent.com/12052283/147969783-d539a0a3-cc38-4a17-ac4a-89676340e0fe.png)

### Componentes NMS

![image](https://user-images.githubusercontent.com/12052283/147969983-8bce4731-cb12-45dd-86a7-43d3a9bc0e30.png)

### Configuração Multi-NMS

![image](https://user-images.githubusercontent.com/12052283/147970064-f44cdc5a-bf53-4d0e-bbc1-a9005d21d590.png)

### Configuração da Rede

- Configurar os Agentes
- Configurar os Sistemas de Gestão
- Parâmetros de administração da comunidade:
  - Community name
  - MIB VIew
  - Trap targets
- Auto-discovery : Scope

### Monitorização da Rede

![image](https://user-images.githubusercontent.com/12052283/147970154-ccab5cb4-4290-4bc5-a6ec-d23cd2be3206.png)

## Descoberta de máquinas numa rede

- Dado um denreço IP e a mascara de rede, encontrar as máquinas na mesma rede

- **Principais abordagens**
  - Utilizar o **ICMP Echo** para inquirir todas as potenciais máquinas
  - Utilizar o **SNMP** para inquirir a tabela ARP de uma máquina conhecida

### Utilizando ICMP Echo

![image](https://user-images.githubusercontent.com/12052283/147970338-99b78c78-e352-4a0e-b8b3-52a9ad5feb9c.png)

### Utilizando SNMP

![image](https://user-images.githubusercontent.com/12052283/147970370-69ddd671-4d5a-4f39-b9e4-9251fe08e89f.png)

## Network Discovery

![image](https://user-images.githubusercontent.com/12052283/147970417-128bb78d-bcea-4c39-b4ee-e600afb24c11.png)

### Algoritmo Network Discovery

![image](https://user-images.githubusercontent.com/12052283/147970459-1b14b990-8dd9-4c77-8aac-cbcfa67ec28f.png)

![image](https://user-images.githubusercontent.com/12052283/147970485-8f801baf-b366-4b65-9a48-1f62dc873e51.png)
