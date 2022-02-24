# Aula 06/12/2021

- Existe o conceito Code First
  - Maior controlo
  - Conseguimos gerir mais facilmente as alterações no codigo pelo sistema de versões
- Existe o conceito database First
  - Este conceito foi o usado nesta aula
  - Somos nós que criamos a base de dados e a base de dados é gerida à parte
  - Tem o problema de controlo de versões, uma vez que é mais trabalhoso e mais dificil
  
## Database First

- Criamos um projeto MVC
- Criamos uma base de dados dentro da pasta `App_Data`
  - Depois vamos a `Server Explorer` > `Data Connections` > `Change` > `Microsoft SQL Server Database File`

![image](https://user-images.githubusercontent.com/12052283/145717311-defbd3e7-b01d-4246-ad09-68c8c3b1edab.png)

- Depois vamos criar uma tabela

![image](https://user-images.githubusercontent.com/12052283/145717384-43718cc3-d33b-4c8d-bb8b-c12370d9a625.png)

![image](https://user-images.githubusercontent.com/12052283/145717428-ef6b925a-58e6-4d30-8d94-7a4179229d37.png)

- Depois temos de ir ao `Package Manager Console` e colocar os seguintes comandos
  - `Install-Package Microsoft.VisualStudio.Web.CodeGeneration.Design -Version 5.0.2`
  - `Install-Package Microsoft.EntityFrameworkCore.Tools -Version 5..0.12`
  - `Install-Package Microsoft.EntityFrameworkCore.SqlServer -Version 5.0.12`
  - E por fim usamos o Scaffold para criar os nossos models
	- `Scaffold-DbContext "Server=<caminho do localdb>;Database=<caminho da base de dados>" Microsoft.EntityFrameworkCore.SqlServer -OutputDir Models -Verbose`

- Depois temos de criar os controllers
  - Para isso utilizo o MVC Controller with views, using Entity Framework

![image](https://user-images.githubusercontent.com/12052283/145717687-dbf00be0-af10-4cca-a131-f9dcf672e431.png)

- Depois é preciso ir ao nosso ficheiro gerado pelo `Scaffold` com o nome `DbContext.cs` nos models, copiar a string que começa com `Server=<caminho do localdb>;Database ....`, ir ao `appsettings.json` e acrescentar isto ...

![image](https://user-images.githubusercontent.com/12052283/145717826-77f44162-f114-4a55-96e4-90bbb7d34b38.png)
 
- Depois vamos ao `Startup.cs` e vamos ao método `ConfigureServices` e adicionamos isto ...

![image](https://user-images.githubusercontent.com/12052283/145717864-91a8c9ac-12e5-49eb-a9fc-0c55d406989e.png)

## Ficha 6

### Alinea C)

- Pra criar o botão de pesquisa criou-se um `Html.BeginForm` no `_Layout.cshtml` de modo a passar o input do utilizador para depois ser feita uma query à base de dados
- No `Html.BeginForm` dizemos o método onde vamos executar (`Index`) , qual o controlador (`Categorias`) e qual o tipo de método (`Get`)

![image](https://user-images.githubusercontent.com/12052283/145719399-ed2cf23d-b0f5-4612-8b89-fe0f56b70b31.png)

- Depois no `CategoriasController` criamos um método index que vai pesquisar na base de dados

![image](https://user-images.githubusercontent.com/12052283/145719525-f2631750-365d-46df-84af-7f93906e58b9.png)
