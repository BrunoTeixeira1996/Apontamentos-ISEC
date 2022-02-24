# Aula T 15/11/2021

## Tipo Nullable

![image](https://user-images.githubusercontent.com/12052283/142724950-35ba1fa1-b9d0-4d9e-b60b-027490b925de.png)

![image](https://user-images.githubusercontent.com/12052283/142725022-b57401f2-9c14-4f19-9620-9d7f91446724.png)

## Operador Null-Coalescing

- Permite especificar um valor por omissão se o operando à esquerda for nulo

![image](https://user-images.githubusercontent.com/12052283/142725208-ae69882a-fde2-4ab3-b296-3c7566c7cc36.png)

![image](https://user-images.githubusercontent.com/12052283/142725360-2ca2493a-5cde-4a54-bff5-d4f8c76f4f4b.png)

![image](https://user-images.githubusercontent.com/12052283/142725518-36159e4f-c67f-4433-8db0-cd541923df03.png)

![image](https://user-images.githubusercontent.com/12052283/142725621-b835c2ab-7c10-4cd9-8978-7f91c969ea03.png)

## LINQ

- Permite efetuar pesquisar em C# ou VB a conjuntos de dados

- A diferença entre LINQ e Entity Framework é
  - A Entity Framework é para construir a base de dados
  - O LINQ é para fazer pesquisas nessas bases de dados

### Arquitetura - LINQ to Entities

![image](https://user-images.githubusercontent.com/12052283/142725668-48b327d6-1b91-4bce-92b6-57289dfd8d51.png)

- O SQL Server não entende Query LINQ, só entende SQL Querys
- Então a Query LINQ tem de ser traduzida para SQL
  - A camada a meio (`LINQ`) faz a transformação

### Query Syntax

- Semelhante À linguagem SQL
- Inicia com a palavra chave **from** para especificar de onde os dados provem e termina com a clausula *select* ou *group*

![image](https://user-images.githubusercontent.com/12052283/142725803-74c37bd2-dba3-45c6-b711-3c02a084f8e3.png)

### Extension Methods - mais moderno

- Usa uma extensão de métodos e expressões Lambda

![image](https://user-images.githubusercontent.com/12052283/142725823-49850270-aa34-4fae-af45-db6afa6b33f6.png)

### Com LINQ vs Sem LINQ

![image](https://user-images.githubusercontent.com/12052283/142725947-54c17403-54a4-40b1-8c99-6ad31e4d1d8e.png)

### Operadores LINQ

![image](https://user-images.githubusercontent.com/12052283/142725972-237cf226-e9b2-4e00-9fbd-bc02dfe9bee2.png)

### LINQ - case insensitive

![image](https://user-images.githubusercontent.com/12052283/142726053-7cb18c24-6c45-49cd-8025-d331fba2fe57.png)

### LINQ - regex

![image](https://user-images.githubusercontent.com/12052283/142726135-3425a18e-24e9-400f-8561-d18f68c8b139.png)

### LINQ - Exemplo

![image](https://user-images.githubusercontent.com/12052283/142726166-a85d17da-48e7-413c-b2a2-d489c9a2bd46.png)

- **Selecionar todos os alunos com idade entre 18 e 23 com Query Syntax**

![image](https://user-images.githubusercontent.com/12052283/142726198-471d240f-3068-47b7-98f6-f50f71a2ba79.png)

- **Será possível especificar a restrição num bloco à parte?** (`SIM`)

![image](https://user-images.githubusercontent.com/12052283/142726257-b13f24c8-90bc-40aa-83cf-bb275be65a79.png)

- **Usando o delegate**

- **Selecionar todos os alunos com idade entre 18 e 23 com Extension Methods**

![image](https://user-images.githubusercontent.com/12052283/142726338-2689d96b-2978-42f3-ace4-588e7a91d8d8.png)

### LINQ - Where

![image](https://user-images.githubusercontent.com/12052283/142726423-31366674-0274-4a1c-8986-4d11846b9792.png)

### LINQ - Exercicios

![image](https://user-images.githubusercontent.com/12052283/142726455-07ceb32e-68b2-4c80-9074-f279d4a63842.png)

![image](https://user-images.githubusercontent.com/12052283/142726473-6a7c69fa-7c9c-4015-a8fd-26fb12fe9867.png)

![image](https://user-images.githubusercontent.com/12052283/142726507-26fc0f40-0387-4c86-92d4-23f53ca19982.png)

### LINQ - OrderBy

- Permite ordenar uma *collection* por um determinado valor
- O **OrderByDescending()** permite ordenar de forma descendente

![image](https://user-images.githubusercontent.com/12052283/142726595-6bb5e803-2c8e-48ea-bd39-dcdd851ee28f.png)

![image](https://user-images.githubusercontent.com/12052283/142726602-347b8e52-7756-403d-9e35-d0d48eff48b0.png)

### LINQ - ThenBy

- Permite ordenação de outros campos

![image](https://user-images.githubusercontent.com/12052283/142726629-a30a483b-0e90-443a-85a6-73b7fa1d8498.png)

### LINQ - Projeção (Select() e SelectMany())

![image](https://user-images.githubusercontent.com/12052283/142726652-078fdf31-1bd9-451f-8308-7d19ad078516.png)

![image](https://user-images.githubusercontent.com/12052283/142726875-a380b882-e5ff-4fb4-8d9d-3555049fc846.png)

![image](https://user-images.githubusercontent.com/12052283/142727627-d7b123ae-d13b-435e-b8fd-db6c899efe6c.png)

![image](https://user-images.githubusercontent.com/12052283/142726899-94c6ec9b-4f9b-4bf4-9e32-9e20c106c792.png)

![image](https://user-images.githubusercontent.com/12052283/142727548-e93638c2-8b9d-481d-92e4-90f61be5fae3.png)

### LINQ - GroupBy

![image](https://user-images.githubusercontent.com/12052283/142726960-db2ef95a-93bf-498b-bae9-7d61730d7e9b.png)

![image](https://user-images.githubusercontent.com/12052283/142727035-80b0092d-4c11-4386-9ae3-bec2647824fe.png)
