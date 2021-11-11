# Aula 08/11/2021 (Rascunho)

- O Razor é a mistura entre C# e html

## MVC

- Permite ter a sepração em 3 camadas que nos permite construir codigo escalavel

### Models

- São os nossos dados
- É aquilo que define o que sao os dados e o acesso a esses dados
- Por exemplo o modelo é a nossa classe que trabalha com uma BD

### View

- Serve para mostrar ao utilizador a informação
- Dentro das vista temos a vista em si e a pasta `shared` onde contem a estrutura da nossa aplicação
- Por omissão quando retornamos uma view, a view tem de ter o mesmo nome que o método, por isso se quisermos retornar uma vista com um nome diferente do método que queremos chamar, fazemos `return View("<nome do metodo>");` em vez de `return View();`

### Controllers

- É o intermediário entre o utilizador e o código
- Normalmente existe um controller e depois uma pasta nas vistas com esse mesmo nome

- Dentro do `HomeController.cs`
  - O método Index devolve a vista Index
  - Entao ele vai retornar o ficheiro index.cshtml que está em views/Home/
  
  - O método Privacy devolve a vinda Privacy
  - Entao ele vai retornar o ficheiro privacy.cshtml que está em views/Home/

## Notas

![image](https://user-images.githubusercontent.com/12052283/140767392-25dce33a-735e-4ad4-a8e9-ebe0cfa73de5.png)

- Operações CRUD é Create Read Update e Delete , são operações a uma base de dados

## Como fazer o ex4

- Criamos uma ASP.NET Core Web App MVC

![image](https://user-images.githubusercontent.com/12052283/141285920-d5db81eb-5522-4654-b354-716a0e4f31ad.png)

- Ao criarmos uma Web App MVC convem começarmos pelos Models (`Code First`)
- Entao criamos um Model vazio (`UCs.cs`) e colocamos os atributos dessa classe com um construtor

![image](https://user-images.githubusercontent.com/12052283/141286476-736733b5-7ea1-45ee-97f2-00a25c9ec819.png)


- Depois adicionamos à BD esse modelo
  - `Add-Migration "Inicial"`
  - `Update-Database`

- Depois vamos criar um Controlador para fazer todas as operações CRUD, então criamos um `MVC Controller with views,using entity Framework`

![image](https://user-images.githubusercontent.com/12052283/141287355-14f40bb3-3e7f-4622-9d30-3fbdde7ef276.png)

- Depois disto, temos novamente de fazer uma nova migração
  - `Add-Migration "UCs"`
  - `Update-Database`
