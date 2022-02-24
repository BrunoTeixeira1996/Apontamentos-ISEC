# Aula 20/12/2021

## Passagem de dados (Controlador - Vista - Controlador)

- A passagem de dados do **Controlador** à **Vista**, e ao próximo request, pode ser efetuada de outras formas para além da passagem de dados através de um argumento da View
  - **Podem ser usados dados fortemente tipados: Viewmodel**
  - **Podem ser usados dados fracamente tipados: ViewData e ViewBag**

### Para dados fortemente tipados (viewmodel)

![image](https://user-images.githubusercontent.com/12052283/148756966-24830aa1-037f-4688-b95b-23182f601921.png)


### Para dados fracamente tipados (viewdata e viewbag)

![image](https://user-images.githubusercontent.com/12052283/148757119-1fe1a4f8-95b6-46b9-b8a7-dc92e56ce18b.png)

![image](https://user-images.githubusercontent.com/12052283/148757185-eb9e0534-1ec6-4cf7-b305-3b3de7facb13.png)

![image](https://user-images.githubusercontent.com/12052283/148757298-f2aa4872-694c-498c-96d9-9e460b7c65f2.png)

### Em suma

![image](https://user-images.githubusercontent.com/12052283/148757455-0253238c-6cb9-4a14-9593-681c10605cb2.png)

![image](https://user-images.githubusercontent.com/12052283/148757488-e7116c1f-8713-4e4d-8d3f-e700d7ea7129.png)

### Passagem de dados: ViewData

![image](https://user-images.githubusercontent.com/12052283/148757628-47e8bcdb-047a-4b2c-ae43-69ca39f86855.png)

### Passagem de dados: ViewBag

![image](https://user-images.githubusercontent.com/12052283/148757710-8f410883-60e3-4838-8390-1c82621cc467.png)

## Views

- **A view não deve executar qualquer lógica de negócio, ou interagir com a base de dados diretamente**

- **Deve trabalhar somente com os dados que lhe são fornecidos pelo controlador**

![image](https://user-images.githubusercontent.com/12052283/148758024-f8b298a5-cd9d-45bf-a2fb-e9775ea8ce6a.png)

## Razor View Engine

![image](https://user-images.githubusercontent.com/12052283/148761297-b10179a4-2df1-4ca5-98b7-ec47b372a103.png)

![image](https://user-images.githubusercontent.com/12052283/148761434-d3db617d-6531-45fc-bcb7-2e785f4460f3.png)

![image](https://user-images.githubusercontent.com/12052283/148761560-ed091f25-4a57-48f8-84c3-26016346e278.png)

### Algumas regras

![image](https://user-images.githubusercontent.com/12052283/148761618-eefb91d4-7cc8-4c94-879d-3c3bf90d7211.png)

## Layout com Razor

![image](https://user-images.githubusercontent.com/12052283/148761795-e715c4b4-8c45-4ddd-859b-7ed115c7e4c1.png)

- **RenderBody**
  - Permite especificar onde será apresentado o conteúdo individual das views
  - É obrigatorio a sua chamada numa vista layout

![image](https://user-images.githubusercontent.com/12052283/148761920-7c3d8e9c-c7ed-49ec-b88d-fb32d3c9cca8.png)

- **RenderSection**
  - Chamada opcional numa *Layout View*
  - Fornece uma *content view* como a view Index, permitindo aplicar conteúdo em outras secções da página
  - A secção necessita de ter um nome e estar definida no ficheiro content view
  
![image](https://user-images.githubusercontent.com/12052283/148762194-8a7ace86-db67-4814-805b-384b3797f5e7.png)

![image](https://user-images.githubusercontent.com/12052283/148762391-c48c142b-3667-4495-aa6c-30306b74fa93.png)

- **Partial Views**
  - Permite especificar código HTML e C# num ficheiro para que depois possa ser reutilizado em várias vistas
  - Poder ser usado simplesmente para simplificar uma vista
  - Por convenção deve-se especificar no prefixo do nome, o caracter **_**
  - Caso seja utilizada por várias vistas, deverá ser colocada na pasta *shared*, caso contrário coloca-se na pasta onde irá ser utilizada

![image](https://user-images.githubusercontent.com/12052283/148762645-6d50513a-202b-4da4-8d60-4f757dfd919d.png)


## Tag Helpers

![image](https://user-images.githubusercontent.com/12052283/148763905-5fd05f31-b93f-4604-8235-eae21a86e4f9.png)

- **Tag Helpers**
  - São um novo recurso disponivel no ASP.Net Core no entanto continua a ser possível a utilização de HTML.Helpers
  - A sintaxe é semelhante à sintaxe do HTML mas é processado pelo Razor no servidor
  - Estes são uma alternativa aos **Html Helpers**
  
![image](https://user-images.githubusercontent.com/12052283/148764070-6c61da60-1777-4626-bb44-865dab510c2a.png)

![image](https://user-images.githubusercontent.com/12052283/148764356-76d44b43-a72a-4f6c-802a-7a21aa982f13.png)

![image](https://user-images.githubusercontent.com/12052283/148764471-cacdda68-9e9d-45eb-960e-1675454cba58.png)
