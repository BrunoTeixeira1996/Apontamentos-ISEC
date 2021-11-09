# Aula P 04/11/2021

## Configurar a primeira politica

- Temos de retirar o Administrator dos *Domain Users* então colocamos outro grupo como grupo principal e removemos o *Domain Users* 

### Configure a politica para que quando nos clientes um vendedor se liga não surja o Gestor de Tarefas (“TaskManager”) no Crtl+Alt+Del

![image](https://user-images.githubusercontent.com/12052283/140389745-1c00d160-aed8-47dd-866e-76a11a3d452e.png)

- Forçamos uma politica com *gpupdate /force* num utilizador

## Definir outras politicas

- Para linkar a gpo a todos os utilizadores posso mover da *Group Policy Objects* para as UOs

![image](https://user-images.githubusercontent.com/12052283/140391436-ea247c4d-48f9-49c9-9a8b-6e039c9d11cf.png)

### Esconda as drives a:, b:, c: e d:

![image](https://user-images.githubusercontent.com/12052283/140394001-418e7e65-7840-4b1c-8a92-eef8da9ce79a.png)

### Esconda a possibilidade de os utilizadores fazerem o mapeamento ou desmapear de drives

![image](https://user-images.githubusercontent.com/12052283/140394815-51167a32-3d57-43c1-ac5a-9a120a19eb49.png)


### Impeça que os utilizadores possam correr o cmd

![image](https://user-images.githubusercontent.com/12052283/140395387-ef6aec08-6402-426a-849a-c602fc0fd822.png)


### Altere a politica por forma a que seja essa a imagem de fundo de todos os utilizadores que se liguem ao domínio

- O melhor sitio para colocar imagens é em `C:\Windows\SYSVOL\domain\scripts\` porque todos os utilizadores têm acesso a isto

![image](https://user-images.githubusercontent.com/12052283/140398582-1db73677-ba16-498c-a40e-40bac37c70db.png)

### Remova o acesso a todas as drives moveis nomeadamente o acesso ao USB

- Atenção que isto é no `Computer Configuration`

![image](https://user-images.githubusercontent.com/12052283/140399281-4894c08a-784e-4960-acae-8a45d1af23bb.png)


### Crie uma politica para o grupo financeira, e só para este, impeça para todos os utilizadores desse grupo possam utilizar o botão do lado direito do rato no desktop

![image](https://user-images.githubusercontent.com/12052283/140400602-f9664cab-d59e-4b5d-814d-96218ec1523e.png)
