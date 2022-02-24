# Aula 06/12/2021

## MVC

### Model

![image](https://user-images.githubusercontent.com/12052283/148753079-96d202ba-c3cf-4dd6-a0a3-8aa5d0121813.png)

### View

- Interface do utilizador para apresentação dos ados, isto é, representa a UI da aplicação

![image](https://user-images.githubusercontent.com/12052283/148753131-6f13491c-0c2e-472a-a3fd-405e350659ec.png)

### Controller

- Traduz as ações do utilizador em operações apropriadas
- **Cérebro da operação**, responsável por tratar do pedido HTTP

### Routing

- A framework ASP.NET Core recorre a URLs amigáveis que permitem descrever melhor a ação do user

![image](https://user-images.githubusercontent.com/12052283/148753375-1040d348-eb8c-4508-a348-87badb952eef.png)

## Estrutura ASP.NET Core

### Estrutura de diretórios

- **App_Data**
  - Base de dados
  
- **App_Code**
  - Classes onde se pode incluir código
  
- **Content**
  - Ficheiros CSS,imagens

- **Controllers**
  - Controladores

- **packages.config**
  - Utilizador pelo *NuGet package* e permite gerir as dependências da aplicação

![image](https://user-images.githubusercontent.com/12052283/148753733-61f9c54a-00a3-44a4-8494-03a4d488caf7.png)

![image](https://user-images.githubusercontent.com/12052283/148753759-31949174-1f46-4e77-be53-c8add546800e.png)

## Action Methods

- Todos os métodos públicos da classe *Controller* são designados como **Action methods**

![image](https://user-images.githubusercontent.com/12052283/148753900-37922227-cebd-4c4f-ad80-d9f62f57f013.png)

![image](https://user-images.githubusercontent.com/12052283/148753934-2e96da22-63a3-4d2d-91ba-13a10d582c0f.png)

- Os controladores podem ter um método action por omissão, especificado no **RouteConfig**

![image](https://user-images.githubusercontent.com/12052283/148754025-91d733c7-b115-446c-84c4-a34d53f463c8.png)

### Action Selectors

- São atributos que podem ser aplicados aos *Action Methods*

- Permitem o mecanismo de routing identificar o action correto para manipular determinado pedido

![image](https://user-images.githubusercontent.com/12052283/148754245-1fef4ac3-6b77-424c-ba1a-f402a70a4d68.png)

![image](https://user-images.githubusercontent.com/12052283/148754294-f2ad361a-f571-4de2-9e80-b5ebf957ea89.png)

## GET vs POST vs PUT vs DELETE

- **GET**
  - Método genérico para qualquer pedido que **obtem** dados do servidor
  
- **POST**
  - Método genérico para qualquer pedido que **envia** dados para o servidor

- **PUT**
  - Método especifico para atualização de dados no servidor

![image](https://user-images.githubusercontent.com/12052283/148754576-3f41fa18-1f86-4002-b5e8-a7d5dc4573ac.png)

- **DELETE**
  - Método especifico para remoção de dados no servidor

![image](https://user-images.githubusercontent.com/12052283/148754597-236eaf0b-6978-46de-ac60-b5be1f18ac8e.png)

## O que é uma action?

![image](https://user-images.githubusercontent.com/12052283/148756386-e5b756d3-4d4f-4bd1-90a6-d50b14d6c99f.png)

## Um pedido a /clientes/remover/5 por conveção é manipulado por?

![image](https://user-images.githubusercontent.com/12052283/148755304-e5e566de-be40-41cf-a3bb-b50256f20aff.png)

## Personalziar o Routing de forma a aceitar o que se pretende

![image](https://user-images.githubusercontent.com/12052283/148755781-41b343dc-5187-428a-b2c3-0a249f2509cd.png)

![image](https://user-images.githubusercontent.com/12052283/148755955-097c07bf-a3c6-40b8-88e1-e040f48837c1.png)

![image](https://user-images.githubusercontent.com/12052283/148756095-f5ea0445-7459-4a28-8924-2e1356e2d893.png)

## Convention Based Routing

![image](https://user-images.githubusercontent.com/12052283/148756198-8a67dd91-6a2d-44b9-a524-7ad13ac67c7f.png)
