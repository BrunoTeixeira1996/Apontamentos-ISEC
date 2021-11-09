# Aula T 27/10/2021


## UOs

![image](https://user-images.githubusercontent.com/12052283/139958279-9f468296-eebe-43f3-8687-f347c6002590.png)

- Podemos agrupar por exemplo utilizadores e assim podemos dar permissões aos grupos

- **Não podemos ter nomes repetidos nas UOs nem nos Grupos**


## Domínio ou UO?

- Escolhemos dominio quando precisamos de:
  - Migração
  - Segurança
  - Replicação
  
- Não devemos basear em divisões, departamentos ou grupos, isso nao é um dominio

- Escolhemos UO quando precisamos de:
  - Controlar a administração
  
- Não devemos criar um UO caso seja necessário refletir grupos politicos ou organizações
  - Por exemplo quando temos um projeto na empresa com pessoal dos RH e da Financeira, não faz sentido criarmos uma UO mas sim um grupo
  
## Politicas de Grupo (GPO's)

- São um método eficaz que o administrator do domínio tem ao seu alcance para disciplinar os utilizadores e para criar regras bem definidas para a correta utilização da rede e dos recursos disponibilizados

- Estas são então um conjunto de configurações/definições que podem ser aplicadas a computadores, sites, domínios e unidades de organização

### Algumas regras das GPOs

- Convem não mexermos no ficheiro `Default Domain Policy` uma vez que é este ficheiro que vai servir de backup caso alguma coisa corra mal e queiramos começar do zero

- Devemos tambem retirar o Administrador dos `Domain Users` uma vez que por vezes vamos querer aplicar politicas a este grupo e isso irá afetar tambem o Administrador

- **Devemos criar GPOs para os PCs quando queremos que ao nivel do PC (hardware) deixe de ser possivel fazer determinada coisa**

- **Se quisermos que um certo utilizador não tenha acesso a alguma coisa, independentemente do PC que este usar, temos de aplicar GPOs ao utilizador**

- Às vezes ha politicas que se atropelam entre si (por exemplo GPOs que dão enable e disable), então a última a ser aplicada é a que prevalece

- Depois de editarmos uma GPO temos de a ligar a uma UO

- Ao atualizar uma GPO esta pode não ter logo efeito no utilizador
  - Se for uma politica de utilizador temos de fazer *logof* e *login*
  - Se for uma politica de pc temos de reiniciar o PC
  - No entanto podemos usar o *gpupdate /force* para atualizar as GPOs

### Politicas de grupo Locais

- `c:\Windows\system32\group policy`
- Afetam apenas o computador local

### Politicas de grupo Não Locais

- `c:\Windows\sysvol\nome do domínio\policies`
- Criadas na Active Directory e atribuidas a sites, dominios e unidades de organização

![image](https://user-images.githubusercontent.com/12052283/139958956-936b09dd-c6c8-4836-aace-6e4ff50e16f8.png)

![image](https://user-images.githubusercontent.com/12052283/139959189-ffcb339e-11e7-4ae6-915c-2451eb7c21dd.png)

### Exemplo de politica de grupo

![image](https://user-images.githubusercontent.com/12052283/139959231-bc46aa7a-9fcb-4dcb-a5e6-239b1cef228b.png)

### Onde ficam guardadas as politicas?

![image](https://user-images.githubusercontent.com/12052283/139959387-26250797-e2f2-48c8-aa43-7a2e37b514cd.png)

### Computer Configuration e User Configuration

![image](https://user-images.githubusercontent.com/12052283/139959980-17b39f14-dcce-4230-9830-dd394ba221bf.png)

### Linkar GPO a UO

![image](https://user-images.githubusercontent.com/12052283/139960145-baeb2fd6-cf97-4581-8c12-a8b7bdded7a0.png)

### Planear as politicas de grupo

![image](https://user-images.githubusercontent.com/12052283/139960214-9cc6c3c7-37b3-47c3-9b18-7f55e7f8f23c.png)

![image](https://user-images.githubusercontent.com/12052283/139960247-1d3d1aa0-8a45-49ac-9102-e3ac6bc03952.png)

### Restauro das politicas de grupo

- Podemos usar o `dcgpofix.exe` para restaurar completamente o dominio padrão GPO
- Este restaura apenas as definições de politica que estão contidas nas GPOs padrão no momento em que são gerados
- Destina-se apenas para recuperação de desastres da GPOs padrão

### Prever o resultado das politicas de grupo

- Podemos executar o *gpresult.exe* no computador local para obter as definições de politica em vigor no computador em que é executado

### Scripts

![image](https://user-images.githubusercontent.com/12052283/139960566-766a8534-9bdb-4757-b745-6a685c7219d2.png)

### GPO Troubleshooting

![image](https://user-images.githubusercontent.com/12052283/139960768-9f81813e-23e7-41dd-b442-6878c6390f13.png)
