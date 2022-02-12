# Aula T 15/11/2021

## Modelos de Comunicação Funcional

### Arquitetura SNMP

![image](https://user-images.githubusercontent.com/12052283/142613932-3460a635-c9a6-4bd1-be37-d67e03190131.png)


### Mensagens SNMP

![image](https://user-images.githubusercontent.com/12052283/142614063-f4d06bc2-5e57-4b57-835f-c6adf3c26a6a.png)

## Modelo Administrativo

- Baseado numa community e policy profiles

![image](https://user-images.githubusercontent.com/12052283/142614192-1775d5cc-dd33-454d-9ec2-4b95b9056af5.png)

### SNMP Community

- A segurança no SNMPv1 é efetuada com base na community
- Esquema d eautenticação presentes no gestor e no gente
- Duas aplicações na mesma community comunicam uma com a outra
- As aplicações podem ter multiplas community names
- A segurança no SNMPv1 nao é segura - **não existe encriptação**


![image](https://user-images.githubusercontent.com/12052283/142614375-8d38bc07-327f-422b-9bc5-49964a801c9f.png)


![image](https://user-images.githubusercontent.com/12052283/142614417-29ff92a6-ff66-49f5-8fe4-7c75c8cc123f.png)

### Perfil da Community

- **MIB View**
  - Um agento é programado para visualizar apenas um sub-conjunto dos elementos geridos na rede
- **Access mode**
  - A cada community name é atribuido um mood de acesso -> **Read Only e Read Write**
- **Community Profile = MIB VIew + Access Mode**

![image](https://user-images.githubusercontent.com/12052283/142614634-57b918e3-7179-496c-987a-6c442c14a12a.png)

### Access Policy

- O modelo de administração define a SNMP Access Policy
- SNMP community emparelhada com a SNMP community profile define então a Access Policy


![image](https://user-images.githubusercontent.com/12052283/142614758-35eb599c-413d-45b9-b573-3a0008feaf64.png)

### Proxy Access Policy

- A Policy SNMP pode ser aplicada além de comunidades SNMP, utilizando agentes proxy

![image](https://user-images.githubusercontent.com/12052283/142615061-5d337052-60f7-448f-856e-d1090e83bcac.png)

## Modelo de Administração Generalizado

- Esta figura pode reflectir o exemplo de uma companhia com sede em Nova York e domínios ou redes em Nova York e São Francisco
- Por exemplo, o Gestor1 e a Comunidade 1 podem estar em são Francisco e o gestor 2 e a comunidade 2 estão em Nova York
- O Gestor 3, em Nova York possui os 2 community profiles

![image](https://user-images.githubusercontent.com/12052283/142614808-ad23802c-133d-4031-8e8d-2bd9769c5496.png)


## Protocol Entities

- Os processos emparelhados que implemento o SNMP e suportam a aplicação SNMP são tb chamados de Protocolo Entities
- Suportam as Aplication entities
- Comunicação entre pares remotos
- A mensagem é composta por
  - Identificador da versão
  - Community name
  - PDU
- A mensagem é entao encapsulada e transmitida

![image](https://user-images.githubusercontent.com/12052283/142615204-bb3dfcd0-c5ca-44b7-94aa-c2b5c9400538.png)

- **As portas UDP por omissão no SNMP são a 162 no Manager e a 161 no Agente**

![image](https://user-images.githubusercontent.com/12052283/142615344-4aab6f79-5f82-4bb8-aeae-bdca3a64e8a8.png)

## Mensagem SNMP

![image](https://user-images.githubusercontent.com/12052283/142615533-2ed80589-05e8-47de-bd8a-ac77b6d09190.png)

## SNMP PDU

![image](https://user-images.githubusercontent.com/12052283/142615603-9d004c9a-06e2-4f20-b057-0bdd4da8896d.png)

- **Ver depois o error-status e o error-index**

### Trap PDU

![image](https://user-images.githubusercontent.com/12052283/142615739-f042ad9b-ede3-472f-931f-c958f14c7882.png)

- **Ver depois o Trap Type**

### Exemplo de Generic Trap

![image](https://user-images.githubusercontent.com/12052283/142615837-c83fcbf0-f306-4576-9f29-eb94b0d79406.png)

## Enterprise Specific Traps

![image](https://user-images.githubusercontent.com/12052283/142615923-69cf9d96-12ab-4765-9fa7-76461a639b9f.png)

![image](https://user-images.githubusercontent.com/12052283/142615949-2688de58-5bf0-48d3-8044-1e9123291ef2.png)


![image](https://user-images.githubusercontent.com/12052283/142616033-c57e3eb7-b9f1-4a84-a1b1-372fad509208.png)

## Ordem Lexicográfica

![image](https://user-images.githubusercontent.com/12052283/142616159-f0d9d2a4-2549-49fc-994c-d31a6a9ddd3c.png)

## Get-Next Requests com Indices

![image](https://user-images.githubusercontent.com/12052283/142616376-4d213e09-0a7b-4e24-97db-b3493b81c81b.png)

## SNMP Get-Request exemplo

![image](https://user-images.githubusercontent.com/12052283/142616457-729e7e87-cf1a-4c5d-9c3e-57a89f547078.png)

## SNMP Get-Response exemplo

![image](https://user-images.githubusercontent.com/12052283/142616513-1d052458-56c6-43de-87db-93e32119724e.png)

## SNMP Trap exemplo

![image](https://user-images.githubusercontent.com/12052283/142616552-67b86ec1-0b46-456b-afe2-4ba562cb34f8.png)
