# Aula 03/01/2022

## Entity Framework (EF)

- Aumentar a produtividade do programador, reduzindo tarefas redundantes para persistência de dados

- Basicamente a **EF Core** é uma versão leve, extensivel e multiplataforma do **EF**

- O **EF Core** introduz muitas melhorias e novos recursos quando comparado com as versões anteriores

- Então o **EF Core** serve como uma espécie de *object relational mapper* para conseguirmos usar modelos de .NET e esses modelos representarem uma tabela de uma base de dados

### Tipos de carregamentos de objetos

- **Eagerly Loading**
- **Lazy Loading**
- **Explicity Loading**

### Formas para especificar o modelo de dados

- **Code First**
  - Parte-se das classes do domínio e a **EF** gera a base de dados
  
- **Database First**
  - Parte-se da base de dados para obter as classes de domínio


## Code First

- Conjunto de regras que permite configurar de forma automática um modelo conceptual, a partir do modelo de classes

### Utilização da Entity Framework em Code First

![image](https://user-images.githubusercontent.com/12052283/150798427-eed91326-400d-439c-ad96-7e8d8800b636.png)

- **Então basicamente o que fazemos é**
  - Criamos uma classe que representa o nosso modelo(tabela)
  - Depois colocamos uma definição desse modelo no nosso DBCcontext

![image](https://user-images.githubusercontent.com/12052283/150799100-b66ae116-1e3a-46da-89f5-59ea5456733c.png)

  - Registamos o DBContext como um serviço no *ConfigureServices* do **Startup.cs**

![image](https://user-images.githubusercontent.com/12052283/150799196-f6b84ab5-eb62-4658-8e5f-017f1460304a.png)
  
  - Especificamos a *connection string* no ficheiro **appsettings.json**

![image](https://user-images.githubusercontent.com/12052283/150799425-10523fcc-fd4f-42b7-b1c7-8f1a915d19b4.png)

  - Depois aplicamos a migração e atualizamos a base de dados

- Se quisermos fazer uma grande alteração num site, o melhor seria usar o database first porque no fundo não queremos alterar o que ja contem na base de dados, queremos manter esses dados

- Antes de fazermos as Migrations temos de fazer Build


![image](https://user-images.githubusercontent.com/12052283/146753512-68162584-cf7e-4e3c-9f2b-88bb359e8a0d.png)

![image](https://user-images.githubusercontent.com/12052283/146755455-33fbdefb-c393-40a4-8fe1-94b90353d91a.png)

### Mas qual o motivo das migrações?

- A EF Core constroi o modelo EF Core a partir das classes de dominio e as migrações EF Core criarão ou atualizarão o esquema da base de dados com base no modelo EF Core

- Sempre que as classes de domínio são alteradas, é preciso executar uma migração para manter o esquema da base de dados atualizado

### Como recuperar de um erro de uma migração?

- **Não convem remover a migração, alteramos o modelo e criamos uma nova migração**


### Code-First Conventions por omissão

![image](https://user-images.githubusercontent.com/12052283/150801112-1ad6a584-0101-4a13-bac0-ee626cfb0efd.png)



## DataAnnotations vs Fluent API

- **DataAnnotations**
  - Mais simples de especificar
  - Menos fléxivel
  - Útil para anotações simples como obrigatórios, tamanhos maximos, etc
  
  ![image](https://user-images.githubusercontent.com/12052283/150801884-bd1132f8-fce4-4a0b-b71c-13cd1e723c9e.png)

  
- **FluentAPI**
  - Permite a configuração de relacionamentos entre classes mais complexas
  - Permite a separação de concerns

![image](https://user-images.githubusercontent.com/12052283/150802144-12cd8855-9077-4fce-8554-a05753e3497b.png)

![image](https://user-images.githubusercontent.com/12052283/150802232-6eb904ab-2c5a-4f57-99a7-2b95170a29bc.png)


- O entity framework é utilizado quer para o database first quer para o code first


### Fluent API

- O código deve ser aplicado no método **OnModelCreating(DbModelBuilder modelBuilder)** da class que deriva do DbContext

- **Por exemplo para alterar o nome de uma tabela**

![image](https://user-images.githubusercontent.com/12052283/150803184-5dd0438b-f703-440e-a493-074c3a18e878.png)

- **Por exemplo para criar uma PK**

![image](https://user-images.githubusercontent.com/12052283/150803291-3e922fd0-817a-4c50-b07a-21e9dcef74f9.png)

- **Relacionamentos**

![image](https://user-images.githubusercontent.com/12052283/150803494-bf9693fc-6984-4b09-a16f-7dc1a00baba4.png)

![image](https://user-images.githubusercontent.com/12052283/150803584-c36175f9-827b-42f8-9dc7-e195c7ebfaca.png)

![image](https://user-images.githubusercontent.com/12052283/150803742-847b5825-29a1-4e57-ac97-a982200d146e.png)


## Entity Framework - Database First

![image](https://user-images.githubusercontent.com/12052283/147920447-982fd65c-1157-400a-8ad4-9e357ded7e70.png)

![image](https://user-images.githubusercontent.com/12052283/147920676-334e6b21-317c-4c14-aa9d-526ed70dd0af.png)

![image](https://user-images.githubusercontent.com/12052283/147921068-8dfc479f-a26b-483a-b889-ef05858f1a61.png)

- **Para usarmos o Database First temos de ter previamente uma Base de Dados, e para isso podemos usar o SQL Server do Visual Studio**

- Basicamente aqui temos uma base de dados e depois fazemos o Scaffold para gerar os modelos

## Identity Framework

- **Autenticação**
  - Processo de verificação de identidade de um utilizador ou computador
- **Autorização**
  - Processo para determinar o que é que o utilizador pode aceder num determinado computador, rede, ...

- Então o Identity Framework é uma ferramente de **autenticação** e **autorização** para aplicações ASP.NET Core
- O mesmo facilita a escrita de testes unitários
- Permite login externo (**OAuth 2.0**)
- **Ao fazer login, a informação fica armazenada num cookie**

### Formas de autenticação

- **No authentication**
  - Como o nome indica, sem autorização

- **Individual User Accounts**
  - Tipicamente utilizado para websites
  - Permite a criação de utilizadores locais

### Arquitetura

![image](https://user-images.githubusercontent.com/12052283/150809237-a72a4a77-f4a2-4ab1-9382-5134d6c2c8cf.png)

![image](https://user-images.githubusercontent.com/12052283/150809500-9e48071e-da4c-4417-8b40-353c7b3a45fd.png)
