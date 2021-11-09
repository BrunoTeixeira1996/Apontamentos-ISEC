# Aula T 25/10/2021

## CMIP (Common Management Information)

- Protocolo construido com base nos serviços CMIS(Common Managment Information Services) que especifica os vários serviços necessários para implementar as várias funções

- Aborda todas as 7 camadas do modelo OSI e as especificações são orientadas a objetos

## Modelo de Gestão OSI

- **Modelo organizacional** que descreve os componentes do sistema de gestão e as suas relações

- **Modelo de informação** que lida com a estrutura e organização da informação de gestão

- **Modelo de comunicação** que é constituido por 3 componentes (aplicações dos processos de gestão, camada de gestão entre camadas e operação entre camadas)

- **Modelo funcional** que lida com os requerimentos de gestão orientados ao utilizador

### Modelo Organizacional

![image](https://user-images.githubusercontent.com/12052283/139537681-0b64bdc3-d70c-4b62-839a-cbdda9e758ac.png)

- Modelo three-tier
  - A camada intermédia actua como Agente e Gestor em simultâneo. Como gestor, recolhe dados dos elementos de rede, processa-os e guarda-os na sua base de dados. Como agente, transmite informação ao gestor do nível superior. Por exemplo, um sistema intermédio é utilizado para criar informação estatística da rede e passar a informação consoante as necessidades para o gestor de nível superior. Ou alternativamente, um gestor intermédio pode ser local e o gestor de topo pode ser remoto
  
  
![image](https://user-images.githubusercontent.com/12052283/139537746-61fb89d8-4847-4d88-8c1c-a1e50c70b056.png)

- Gestão com MoM (Manager of Manager)
  - Domínios podem ser geridos localmente e uma vista global destes pode ser monitorizada por um MoM. Esta configuração utiliza um sistema de gestão de redes empresarial e é geralmente aplicável a empresas com várias filiais distribuídas por diferentes cidades

![image](https://user-images.githubusercontent.com/12052283/139537795-92438681-fcf4-442b-96d0-fa8bb4d32b42.png)

### Modelo de Informação

#### Modelo SMI (Structure of Management Information)

- Define a sintaxe e a semântica da informação de gestão armazenada na MIB (Management Information Base)

- A MIB é utilizada pelo agente e pelo processo de gestão para guardar/trocar informações sobre gestão

- Existe o agente MIB que é associada apenas à informação local do agente

- E existe tambem o manager MIB que consiste em informações sobre todos os componentes de rede que este gero

![image](https://user-images.githubusercontent.com/12052283/139537915-b1b11ec2-f8bb-4dec-bd97-9a8f295e4f52.png)

#### Management Information Trees

- Os  objetos geridos são definidos de forma única por uma estrutura em árvore especificada pelo modelo OSI e usada no modelo da Internet

![image](https://user-images.githubusercontent.com/12052283/139538077-ea59a325-fa51-4deb-a6a2-61e54f510c65.png)

## Tipos de Objetos e Instâncias

- Cada objeto possui um identificador (Object Identifier) e nome (Descriptor) únicos

![image](https://user-images.githubusercontent.com/12052283/139538319-b912fadb-2e6b-43e6-9933-847339b2084b.png)

## Objetos Geridos pela Internet vs Objectos Geriodos pelo OSI

![image](https://user-images.githubusercontent.com/12052283/139538388-7ca11ba4-09e8-4ec7-94fe-ae8cac54b6c3.png)

![image](https://user-images.githubusercontent.com/12052283/139538402-be2731df-0a71-4545-9c99-8afb046dfa3b.png)

## Modelo de Comunicação

- Associado com a forma como a informação é trocada entre sistemas

![image](https://user-images.githubusercontent.com/12052283/139538469-5ca84c27-d1c5-4dd3-beeb-318d380017d8.png)

### Modelo Comunicação - Protocolos de Transferência

![image](https://user-images.githubusercontent.com/12052283/139538563-2a89de44-9718-4ac2-a81d-bc55d2c509a4.png)

## ASN.1 (Abstract Syntax Notation One)

- ASN.1 é mais que uma sintax, é uma linguagem

- Abstract sintax é o conjunto de regras que especificam os tipos de dados e a estrutura para guardar a informação

- Transfer sintax é o conjunto de regras para comunicação de informação entre sistemas

- A ASN.1 permite a geração de código máquina (BER é usado nos módulos de gestão)

### Tipos de Dados e Valor e Subtipos

![image](https://user-images.githubusercontent.com/12052283/139538695-b536000e-9d23-4cdf-913a-2951000d60ee.png)

![image](https://user-images.githubusercontent.com/12052283/139538713-e40ad507-cc2f-4568-ad25-53a0a84bda40.png)

![image](https://user-images.githubusercontent.com/12052283/139538731-5c8d2443-69d7-47c8-b4b6-b80cc8c15b2b.png)

### Tipos de dados ASN.1

#### Tipos Básicos

![image](https://user-images.githubusercontent.com/12052283/139538754-3061fb31-16cb-42e0-bf60-f65ef5e875b8.png)


#### Tipos Construidos

![image](https://user-images.githubusercontent.com/12052283/139538762-75368bed-3cb0-4522-b695-13a5ee0c1bf7.png)

#### Exemplo 1

```console
Married ::= BOOLEAN
Age ::= INTEGER
Picture ::= BIT STRING

Form ::= SEQUENCE {
    name PrintableString,
	age Age,
	married Married,
	marriage-certificate Picture
}
```

#### Exemplo 2

```console
Payment-method ::= CHOICE{
    check Check-number,
	credit-card SEQUENCE {
	    number Card-number,
		expiry-date Date
	}
}
```

### Nome de Objetos

![image](https://user-images.githubusercontent.com/12052283/139539031-41e583ef-6141-47c6-8066-97e01dfc77ab.png)

### Modulo ASN.1

```console
<module name>DEFINITIONS ::= BEGIN
<name> ::= <definition>
<name> ::= <definition>
...
<name> ::= <definition>
END
```

![image](https://user-images.githubusercontent.com/12052283/139539110-714d97d0-fd5d-4072-8723-47e9ce4410bb.png)


### ASN.1 Keywords

![image](https://user-images.githubusercontent.com/12052283/139539156-958122ab-46e7-4846-a553-d969131225e1.png)

### ASN.1 Símbolos

![image](https://user-images.githubusercontent.com/12052283/139539174-8e2e8719-97bf-4ace-8658-6c7bca10045e.png)

### ASN.1 Convenções

![image](https://user-images.githubusercontent.com/12052283/139539194-e356c05f-8126-46d4-9002-e5d407f0a257.png)


### Estrutura e Tag

- Estruturas definem como os tipos de dados são construidos

- Tag identificam o objeto de forma única

![image](https://user-images.githubusercontent.com/12052283/139539256-b8b5998e-0028-46c1-8790-764927d39efc.png)

### Descrição informal de um registo de pessoal

![image](https://user-images.githubusercontent.com/12052283/139539318-23f2b476-071d-4cbe-b7fa-1db67351c180.png)

### Descrição da estrutura do registo usando ASN.1

![image](https://user-images.githubusercontent.com/12052283/139539347-46a94709-79ef-44b7-a54d-8ac84153c923.png)


### Descrição ASN.1 de um registo

![image](https://user-images.githubusercontent.com/12052283/139539367-51eb2ec3-adfe-491d-a64a-030f8c9e78bf.png)

## Codigicação BER 

![image](https://user-images.githubusercontent.com/12052283/139539380-4cad5806-f950-452e-bd41-e7268919e4a6.png)


![image](https://user-images.githubusercontent.com/12052283/139539389-ed090417-95a2-477c-8af9-279ad7bfc117.png)


![image](https://user-images.githubusercontent.com/12052283/139539400-2475915a-b789-41a0-a4f8-ab2bc4e287fd.png)

### Universal Class Tag

![image](https://user-images.githubusercontent.com/12052283/139539413-aa69834c-18a4-4dd0-a95f-7cc9bccc2856.png)

![image](https://user-images.githubusercontent.com/12052283/139539421-da6527de-d347-42a5-9cc6-9b5e46af7d9a.png)

### Campo Length

![image](https://user-images.githubusercontent.com/12052283/139539440-886ff822-358e-4c63-afad-d06423023f19.png)

### Exemplo 1

![image](https://user-images.githubusercontent.com/12052283/139539461-ad428838-6b6f-4f14-9b88-e828a05dfb1f.png)

### Exemplo de Mensagem SNMP

![image](https://user-images.githubusercontent.com/12052283/139539471-283bc612-bdd6-40fa-a10a-26e794905842.png)

## Modelo Funcional

![image](https://user-images.githubusercontent.com/12052283/139539495-f6ac0fe5-ab9d-4ee6-ba2b-a1dc00e9ddbe.png)

## Referências

- *Network Management - Principles and Pratice, 2nd Edition* Mani Subramanian, Addison Wesley, 2010, Chapter 3

- https://www.youtube.com/watch?v=EccHushRhWs

- https://www.youtube.com/watch?v=OStr5K2R5oo
