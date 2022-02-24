# Aula 04/01/2022

## Autenticação

- Convem criarmos uma classe nova que vai ser a classe dos utilizadores e depois herdar a IdentityUser nessa classe e acrescentarmos o que quisermos à classe dos utilizadores.
  - Temos de mudar algumas coisas e depois criar uma nova migração e atualizar a BD
  - Temos de alterar no Startup tudo o que tiver Identity para o nome da nova classe, na view _loginpartial tambem e no applicationdbcontext

- Se quisermos alterar as páginas que o Identity fornece(Manage your account,login,register, etc) temos de gerar nós as páginas do Identity
  - Ver o video da aula 9h58PM no pc do stor

- Conseguimos adicionar o *PersonalData* com o data anotations no nosso modelo, para assim dizer que esses dados sao dados do utilizador e estao de acordo com o GPDR e isto é obrigatório

## Autorização

### Diretamente no Controller

- Posso bloquear uma View por exemplo usando o *[Authorize]* antes do *public class CategoriasController:Controller*
  - Isto faz com que todo o acesso a este controller só possa ser acedido a quem tiver feito login

### Para cada método dentro do Controller

- Posso bloquear apenas um método dentro do controler, é só meter o *[Authorize]* antes da definição do método

### Autorização no Controller e nos métodos outras

- Posso usar autorizações globalmente no controller e utilizar por exemplo o *[AllowAnonymous]* num método

### Podemos definir perfis para utilizadores

- Podemos dizer que em todo o meu controller só os utilizadores que tenham o perfil Admin é que podem aceder ao Controller

![image](https://user-images.githubusercontent.com/12052283/148134035-0c5b346a-7aa2-4793-8bfb-c135c304cac5.png)

- As roles estao guardadas na tabela **AspNetRoles**

- Para criarmos roles
  - ver as 10h45
- Ouvir e aponta ro que ele diz as 11h05pm

### Podemos definir politicas

- Mas isto é meio meh
