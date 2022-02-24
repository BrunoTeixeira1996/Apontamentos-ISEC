# Aula 13/12/2021

- Continuação da ficha 6 a partir da alinea c)

## Ficha 6

### Alinea D)

- Para criar a Dropdownlist fez-se um `Html.DropDownList` na view `index.cshtml` dos Produtos
- `asp-controller` é o nome do controller
- `asp-action` é o nome do método a executar
- O Primeiro parâmetro do `Html.DropDownList` é o Id , depois damos cast para um IEnumerable do ViewData["IdCategoria"] 

![image](https://user-images.githubusercontent.com/12052283/145847526-c7b4f8a5-6d8f-40d9-a297-60c27c01f911.png)

- É mais facil em ver de usar o Html helper tag, usar os helpers com o ViewBag

![image](https://user-images.githubusercontent.com/12052283/145857078-0cf39e6b-81e8-4505-862e-20bab1fbf415.png)


- No controller, passamos o parâmetro `id`
- Criamos o ViewData["IdCategoria"] com uma selectList contendo o Id e o Nome da categoria a partir da BD
- Fazemos um IF a ver se foi selecionada alguma categoria na drop down list, se sim, fazemos um `Where` procurando aquele ID escolhido

![image](https://user-images.githubusercontent.com/12052283/145847965-a5c00626-ae14-4720-a274-2352987638bd.png)

### Alinea E)

- Foi criada uma classe chamada `CategoriaComContagem`

![image](https://user-images.githubusercontent.com/12052283/145854737-249c5606-ce8a-48fb-9843-cc5875a54018.png)

- Depois no controller dos Produtos, foi criado um *extension method* para agrupar e contar os produtos por categoria

- Basicamente agrupamos por IdCategoria, selecionamos esse grupo, criamos um novo objeto `CategoriaComContagem` e definimos os campos.

![image](https://user-images.githubusercontent.com/12052283/145855203-fc234809-09af-45e5-a0d7-024e7c105bd4.png)


### Alinea F)

- Na view `Index.cshtml` dos produtos, criamos um select com as opções de Ascendente e Descendente

![image](https://user-images.githubusercontent.com/12052283/146649415-75c026db-aa38-49a4-a427-4721c3b3edcc.png)

- Depois foi criada a class `Ordenacao.cs` para ajudar no output do texto

![image](https://user-images.githubusercontent.com/12052283/146650087-5514ee15-61af-4d9e-a430-d621d9608a89.png)


- No `ProdutoesController.cs` foi adicionado o argumento `string ordenacao` e depois foi adicionado o código para a ordenação

![image](https://user-images.githubusercontent.com/12052283/146650133-0acfa4ce-b888-4dc7-bc3b-a6cc34fb954f.png)


## Referências

- https://docs.microsoft.com/en-us/aspnet/core/mvc/views/tag-helpers/built-in/?view=aspnetcore-3.1
