# Aula06 06/12/2021

## SNMPv3

### Arquitetura

![image](https://user-images.githubusercontent.com/12052283/145233411-f315f894-474d-41cc-8d89-dfed64a4ede6.png)

### Dispatcher

![image](https://user-images.githubusercontent.com/12052283/145233652-23ea17e5-2837-46c7-a902-3218b6671b59.png)

- Receber e enviar mensagens de/para a rede
- Determinar a versão SNMP da mensagem e interagir com o Message Processing Model correspondente
- Fornecer um interface abstrato para as aplicações SNMP poderem receber um PDU ou enviar um PDU a uma entidade remota


![image](https://user-images.githubusercontent.com/12052283/145233727-fdaf3609-2665-48c6-a582-b4efd2c08aab.png)

### Message Processing Subsystem

![image](https://user-images.githubusercontent.com/12052283/145233801-fbeeef57-86a7-47e8-8788-6ce897f8b45e.png)

### Security e Access Control

![image](https://user-images.githubusercontent.com/12052283/145233936-9b1c4ce7-c26a-4ca7-9e5f-67ca5b97174c.png)

### Abstract Services Interface

![image](https://user-images.githubusercontent.com/12052283/145234024-0100d6be-6ee4-41d3-91dc-e40a762c0561.png)

### Aplications

![image](https://user-images.githubusercontent.com/12052283/145234088-29bbb3a8-3e48-4b72-a425-3361e6bbee6c.png)

### Command Generator ou Notification Generator

![image](https://user-images.githubusercontent.com/12052283/145234494-60c17b3a-7f34-4528-9eb1-8d3ec3b2d946.png)


- O `command generator` é usado para gerar mensagens *get-request*, *get-next-request*, *get-bulk* e *set-request*
- Tambem processa a resposta ao comando enviado e é tipicamente associado ao processo de gestão

- O `notification generator` funciona de forma similar ao command generator, mas é usado para gerar *traps* ou *inform messages*
- Precisa no entanto de descobrir para onde enviar a mensagem e que versão de SNMP usar e os parâmetros de segurança

### Command Responder

![image](https://user-images.githubusercontent.com/12052283/145234678-70138b3d-3e72-45c9-80d0-c3f3acdf3aa8.png)

- Processa os *get* e *set* dirigidos a ele
- Antes de poder responder, este tem de estar registado com o SNMP engine, o que é conseguido através da primitiva *registerContextEngineID*

### Security Threats

![image](https://user-images.githubusercontent.com/12052283/145234860-4d4cf1a4-88c0-4833-9423-154b8129cd94.png)

### Security Services

![image](https://user-images.githubusercontent.com/12052283/145234898-76488e89-33a9-4451-829b-797dee1a8acc.png)

### SNMPv3 Security

![image](https://user-images.githubusercontent.com/12052283/145234962-b01b23cd-c913-4be4-9a0e-cf3f2121b30f.png)

### Mensagem SNMPv3

![image](https://user-images.githubusercontent.com/12052283/145235048-c913b680-dad0-45d5-b671-f62e134b9e28.png)

### User-Based Security Model

![image](https://user-images.githubusercontent.com/12052283/145235140-aa983eb1-a027-4aa7-b18e-12e351d9cdb7.png)

### Protocolos de Autenticação

![image](https://user-images.githubusercontent.com/12052283/145235198-0c23a29e-69c6-4663-bb03-ef1cc8bb9d93.png)

### Access Control

![image](https://user-images.githubusercontent.com/12052283/145235276-e7073d47-519d-4546-80e3-8710f4247c6f.png)

![image](https://user-images.githubusercontent.com/12052283/145235321-cd094eb4-e08a-4abc-9362-44b9847bb506.png)
