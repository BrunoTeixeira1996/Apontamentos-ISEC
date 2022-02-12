# Aula T 08/11/2021

## SNMPv1 - Modelos de Organização e de Informação

![image](https://user-images.githubusercontent.com/12052283/142196604-216a3a2c-24e5-4299-952f-7ed5baa2e8b6.png)

### Modelo de Organização Two-Tier

- No modelo de organização 2-tier, um network manager gere um network element através de um agente de gestão.
- O agente e o gestor comunicam entre si através de SNMP.
- A necessidade de configurações com mais detalhe poder requerer a presença de um NMS do fabricante, com mais
conhecimento sobre o objecto a ser gerido do que outros NMS.
- Além disso, o gestor do fabricante pode ser capaz de identificar falhas até ao nível de componentes no PCB.

![image](https://user-images.githubusercontent.com/12052283/142196838-d3496ab4-6219-46c3-a9e8-7fc509f419a9.png)

### Modelo de Organização Three-Tier:RMON

- No modelo two-tier, o gestor recebe dados em bruto dos agentes e precisa de processá-la. No entanto, às vezes é benéfico que o gestor receba dados já pré-processados.
  - Por exemplo, poderemos querer ver estatísticas de tráfego, como o no de pacotes/segundo que entraram e saíram de um determinado interface como uma função do tempo.
  - Ou poderemos querer saber o tráfego numa LAN. Assim, em vez de o gestor estar sempre a monitorizar os eventos e efectuar os cálculos, um agente intermediário (RMON) é inserido entre o gestor e o elemento a gerir. Esta é a arquitectura three-tier.

![image](https://user-images.githubusercontent.com/12052283/142197042-13e48cd3-43fc-45f7-9500-3f5dd20939a2.png)

### Modelo de Organização Three-Tier:Proxy

- A gestão pura usando SNMP consiste em Agentes e Gestores SNMP.
- No entanto, um agente SNMP também pode efectuar a gestão de elementos de rede que não contenham um agente SNMP. Para tal, utiliza-se um proxy como elemento intermediário.

![image](https://user-images.githubusercontent.com/12052283/142197299-e2b8927f-26b5-4319-b6a9-2eebe8359512.png)

### Arquitetura do Sistema SNMP

![image](https://user-images.githubusercontent.com/12052283/142197465-d5e54770-aefd-422e-a30d-a3fd6fa8cbb6.png)

### Serviços SNMP

- Quatro serviços
  - Get, Set, GetNext, Trap

- Cinco Mensagens SNMP
  - GetRequest -> **obtem os valores dos objectos na MIB do agente** 
  - SetRequest -> **ajusta os valores do objeto na MIB do agente**
  - GetNextRequest -> **obtem os valores dos objetos seguintes na MIB do agente**
  - GetResponse -> **resposta**
  - Trap -> **alerta o gestor para acontecimentos extraordinarios**

![image](https://user-images.githubusercontent.com/12052283/142197630-1476fa1a-038c-42e2-8187-0d5c8f69caa3.png)

![image](https://user-images.githubusercontent.com/12052283/142197716-a5efa5be-0858-4eda-8b80-23ef5a8096e6.png)

## Modelo de Informação

### Objeto Gerido

- Um objecto gerido é composto por pelo tipo do Objecto e pela instancia do objecto.

![image](https://user-images.githubusercontent.com/12052283/142198386-2caffd13-c266-4796-ab10-7ca90757b849.png)

- Em situações que existam múltiplos objectos idênticos (por exemplo, vários switchs cisco numa mesma rede), apenas existirá um *object type* e várias instâncias desse objecto.

![image](https://user-images.githubusercontent.com/12052283/142198580-bcdbcfd9-9f84-4812-8d8f-b71665010edc.png)

### Nome do Objecto

- Cada tipo de objecto é identificado de forma única pelo **DESCRIPTOR** e pelo **OBJECT IDENTFIER** (em maiúsculas, dado que são keywords do ASN.1).
- O **DESCRITPOR** definindo o nome é uma mnemónica e em letras minúsculas,ou pelo menos começa com letra minúscula. Letras maiúsculas podem ser usadas para ajudar na identificação, desde que não sejam a primeira letra.

- **OBJECT IDENTIFIER** é um nome e número único na MIT tree (ou MIB).

![image](https://user-images.githubusercontent.com/12052283/142201402-db56cfee-975b-47e1-aef7-6e05ef736777.png)

### Internet sub-nós

![image](https://user-images.githubusercontent.com/12052283/142201522-95987dce-4ee8-4a29-87f6-075fcc09fae9.png)

### Defined or Application Data Type

- A categoria opaque é utilizada para especificar octetos de informação binária. 
- Está presente com a intenção de adicionar novos tipos base para a SMI do SNMP.

![image](https://user-images.githubusercontent.com/12052283/142201719-ffc9c2c6-6c92-4cfe-9103-991d997e0dec.png)

### Constructor ou Structured Data Type

![image](https://user-images.githubusercontent.com/12052283/142201845-ecf3a34a-a3ac-4a18-8be5-ba93fc7d205f.png)

- Permite por exemplo construir a sequência dada como exemplo, composta por exemplo de construção de uma lista IpAddrEntry

![image](https://user-images.githubusercontent.com/12052283/142201965-eee27f55-13fe-49a1-a2d1-4ebd994efbc2.png)


![image](https://user-images.githubusercontent.com/12052283/142202014-95e01a80-dd29-4426-9335-32d69b82c5e7.png)


### SNMP Data Types e Tags

![image](https://user-images.githubusercontent.com/12052283/142202069-b2584017-9ca9-4f07-bc31-62639a41bc45.png)

### Objetos geridos: Structure

- Um objecto gerido, como vimos anteriormente tem 5 parâmetros: **textual name, syntax, definition, access and status**, tal como definido na RFC 1155

![image](https://user-images.githubusercontent.com/12052283/142202303-106a8db7-9e91-41d9-ad8a-d6dfc8490552.png)

### Objetos Agregados

- É um grupo de objetos relacionados
- Também chamados de **tabular objects**
- Podem ser representados numa tabela com **objetos como colunas** ou **instancias como linhas**

![image](https://user-images.githubusercontent.com/12052283/142202467-f5828bf6-6a0c-4b3a-b5b2-29c07e1276e3.png)

- Operações SNMP aplicam-se unicamente a objectos escalares. Ou seja, apenas um único objecto escalar é obtido ou editado com cada operação.
- Contudo, os objectos geridos tem múltiplas instâncias e precisam de ser representados formalmente. Um objecto agrupado compreende um ou mais subtipos. 
- Cada subtipo pode ter múltiplas instâncias, com um valor associado a cada instância. 
- É assim conveniente definir uma estrutura tabular para objectos com múltiplas instâncias

![image](https://user-images.githubusercontent.com/12052283/142202645-a8e23649-bfd6-4319-ba10-9bd9ecbbe58c.png)


![image](https://user-images.githubusercontent.com/12052283/142202741-f2dfa22f-1147-4bb8-bc23-cf604e4238bb.png)

![image](https://user-images.githubusercontent.com/12052283/142202787-bba6109b-3019-44f7-ad18-137fa561088a.png)

## MIB-II

- É um super conunto da MIB-I
- Objetos relacionados são agrupados em grupos de objetos
- Um módulo MIB consiste no nome do módulo, importações de outros módulos e definições do módulo corrente

![image](https://user-images.githubusercontent.com/12052283/142203074-948fb24c-05c4-4c22-93eb-08527f12c79e.png)

![image](https://user-images.githubusercontent.com/12052283/142203172-1c363851-d0a0-4edc-83fa-5e6fc84c8421.png)


![image](https://user-images.githubusercontent.com/12052283/142203225-e7f295d3-7f7d-47eb-9131-c2c57a51b86b.png)

### System Group

![image](https://user-images.githubusercontent.com/12052283/142203296-8a377edf-986a-4db8-b44b-4640563253cf.png)

### Interfaces Group

![image](https://user-images.githubusercontent.com/12052283/142203358-7ef829b4-159a-4933-9b42-b90e765f26ac.png)

### IP Group

![image](https://user-images.githubusercontent.com/12052283/142203412-d0e469b5-a24b-43eb-ba87-9cf6dee4c574.png)

### IP Address Table

![image](https://user-images.githubusercontent.com/12052283/142203466-2aac9b9b-a416-41bd-9fbc-236a94c1dd9c.png)

### IP Routing Table

![image](https://user-images.githubusercontent.com/12052283/142203539-f5bd07e8-8473-4c26-820b-65fc6852e152.png)

### IP Address Translation Table

![image](https://user-images.githubusercontent.com/12052283/142203620-310bbcaa-307c-4f33-b32e-772d691ab66d.png)

### ICMP Group

![image](https://user-images.githubusercontent.com/12052283/142203657-ed9446be-a376-4244-a5fc-da50d9019f8b.png)

### TCP Group

![image](https://user-images.githubusercontent.com/12052283/142203700-a7b16cb9-dd08-4138-bc1a-d0035958a767.png)

### UDP Group

![image](https://user-images.githubusercontent.com/12052283/142203758-e52ccdc1-85f3-4afb-b3ca-6fa41fb0b51f.png)
