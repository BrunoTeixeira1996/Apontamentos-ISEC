# Aula 09/12/2021

## Exercicio 1

- Crie um novo site com as seguintes caraterísticas
  - O site tem o nome de Portal
  - Deve criar uma pasta nova com o nome de Portal dentro da inetpub(`pasta por omissão onde vão ser guardados todos os ficheiros do site`) para alojar os ficheiros do site
  - Autenticação anonima (todas as pessoas têm acesso)
  - O site responde na porta 80 pelo nome de www.sr2.pt

- Configure o logging para ter um report diário com a informação básica  de acesso.


### How To

#### Instalar o IIS

![image](https://user-images.githubusercontent.com/12052283/145445287-e1dead1d-a341-4215-b9a7-432aa01fdad0.png)

![image](https://user-images.githubusercontent.com/12052283/145445316-33f49791-20c8-4354-b66d-833be318e4bb.png)

![image](https://user-images.githubusercontent.com/12052283/145446621-a8406378-cad8-4af9-ba8f-ec79cfa40212.png)

#### Criar um novo site

![image](https://user-images.githubusercontent.com/12052283/145446865-5356e041-d34c-4973-9b74-c8746a40603d.png)

![image](https://user-images.githubusercontent.com/12052283/145453582-1f42505c-6e22-4ad7-8ff6-04b047107f57.png)


- Depois é preciso criar uma entrada no DNS para o www (**Atenção que o DNS no cliente tem de estar apontar para o servidor**)

![image](https://user-images.githubusercontent.com/12052283/145448437-df2b3ae7-2cff-42a6-9bff-6257ab8636ed.png)


#### Configurar o logging para ter um report diário

- Por omissão isto já acontece e vemos aqui isso

![image](https://user-images.githubusercontent.com/12052283/145449137-3d80e227-b43c-4d4c-8a39-72efd69f712e.png)


## Exercicio 2

- Crie um novo web site chamado intranet
- Deve criar uma pasta nova com o nome de Intranet para alojar os ficheiros do site
- O site responde na porta 80 pelo nome de intranet.sr2.pt
- A página de entrada deve ter o nome de intranet.htm
- Ative a autenticação integrada no Windows 


### How To

#### Instalar o Windows Authentication no Security

- Como aqui é pedida a autenticação integrada no Windows tivemos de fazer os seguinte

![image](https://user-images.githubusercontent.com/12052283/145450723-456e74b9-1f32-41d6-8e6f-ab39190f048d.png)

#### Criar pasta com o nome intranet para alojar os ficheiros do site

![image](https://user-images.githubusercontent.com/12052283/145449579-abd6baf8-f92c-432a-80d6-72012bf39680.png)

#### Criar site chamado intranet

![image](https://user-images.githubusercontent.com/12052283/145453219-15e88f3e-43e0-4058-b7ff-7dd0cfedf77b.png)


- Testando no cliente

![image](https://user-images.githubusercontent.com/12052283/145451127-2228790e-c00e-4dd6-8713-ccf4aa9be0f4.png)


- Ir ao DNS e colocar um registo A com `intranet`

![image](https://user-images.githubusercontent.com/12052283/145451765-2fff8442-9a78-48a0-85b1-a0eeae30ced3.png)


#### Ativar a autenticação por windows e depois de ter criado um index.html na pasta "intranet"

![image](https://user-images.githubusercontent.com/12052283/145451712-1964b681-bdc4-4859-b062-cc6bfa009fd4.png)

- Testando no cliente

![image](https://user-images.githubusercontent.com/12052283/145455395-499b901a-cdfb-4234-9dc9-95850ce5d767.png)


## Exercicio 3

- Faça a instalação do serviço FTP
- Crie um site FTP publico (ftpsrvpub.sr19.pt). Disponibilize um ficheiro. Teste no servidor e no cliente. Os utilizadores apenas podem copiar ficheiros do servidor
- Deve ainda
  - O site deve ser mostrado como é visto no mundo unix
  - As opções: Virtual Directories, Available bytes e Four-digit year devem estar activas
  - Edite o Banner, mensagem de boas vindas e de saída.
  - Não deve aceitar mais do que 20 ligações

### How To

#### Instalar o FTP

![image](https://user-images.githubusercontent.com/12052283/145456123-0ab7afaa-7124-4c28-9c1a-f39ab21397c5.png)

#### Criar o site FTP

![image](https://user-images.githubusercontent.com/12052283/145456686-e81a230f-07a8-44fc-b28c-f948a33d8e9b.png)

![image](https://user-images.githubusercontent.com/12052283/145456928-9f9bee47-e499-44bb-90e1-163519e3557b.png)

![image](https://user-images.githubusercontent.com/12052283/145457708-579ef45b-c48e-4e4a-9ba4-24e9cc2ac715.png)

![image](https://user-images.githubusercontent.com/12052283/145457983-b2cb0b74-91a5-4ff5-82ba-e6ab52bf65e2.png)

- Temos tambem de criar um registo do tipo A (ou CNAME) para o ftp

![image](https://user-images.githubusercontent.com/12052283/145458070-e48854a4-8503-4a86-8235-7ad4f25580bf.png)

#### Configurar o site FTP

![image](https://user-images.githubusercontent.com/12052283/145458381-52a8ee33-f9e4-4efc-9444-2042985e50be.png)

#### Configurar acesso a utilizadores anonimos

![image](https://user-images.githubusercontent.com/12052283/145459375-14d1a651-8c28-4d87-b80e-7dd9ef2aa899.png)

![image](https://user-images.githubusercontent.com/12052283/145459433-f4e65fec-8f19-4acc-9dd5-f6f5da50eb85.png)

- Testando no cliente o acesso ao ftp

![image](https://user-images.githubusercontent.com/12052283/145459489-2f65109d-8794-4ff0-b6d5-7443b7f88845.png)

#### Editar o banner, mensagem de boas vindas e de saida

![image](https://user-images.githubusercontent.com/12052283/145459667-f1097ab9-028c-404e-8004-1c8e0893db55.png)

#### Permitir apenas 20 sessões

![image](https://user-images.githubusercontent.com/12052283/145460803-cc2e2554-bee5-492e-ba42-b544c7bddde0.png)

![image](https://user-images.githubusercontent.com/12052283/145460856-5fca834c-c83f-4902-9931-2720a1330045.png)


## Exercicio 4

### How To

- Como vamos usar https aqui temos entao de criar um certificado para isso fazemos isto

![image](https://user-images.githubusercontent.com/12052283/145461875-e03f4538-b626-4aa6-a75c-214ade2addd8.png)

![image](https://user-images.githubusercontent.com/12052283/145461980-2edd16df-8001-4010-9626-c55ab74cc0dd.png)

![image](https://user-images.githubusercontent.com/12052283/145462119-3b495820-08b7-44e8-acb1-3279f36d41dc.png)

![image](https://user-images.githubusercontent.com/12052283/145462272-35bae3e6-d9da-4a81-a19a-80115ffa4ff8.png)

- Depois disto temos de fazer a requisição do certificado

![image](https://user-images.githubusercontent.com/12052283/145462454-c91dcbc9-ce36-4b6e-a875-a242acdf9fe2.png)

![image](https://user-images.githubusercontent.com/12052283/145463214-9388c030-d7c4-4f12-b896-6986ee4bd735.png)

![image](https://user-images.githubusercontent.com/12052283/145463274-6b713420-d204-4071-9d2a-6ab101ce9e1c.png)

- Criada a pasta `vendedores` no `inetpub`
- Adicionado um registo `A` com o nome `extranet.sr19.pt` e com o ip `192.168.20.1`

![image](https://user-images.githubusercontent.com/12052283/145461714-50159507-fc72-4064-8dde-355522477caf.png)

- Criado o site com ssl e com o certificado válido

![image](https://user-images.githubusercontent.com/12052283/145463422-2e9678a7-22e0-46c8-9ebe-beec10ebf844.png)

![image](https://user-images.githubusercontent.com/12052283/145463579-e9be6aa0-10df-4791-8048-409f39aed4b2.png)

- Testando no Cliente

![image](https://user-images.githubusercontent.com/12052283/145463964-e44a2883-0350-4ddb-96db-ba4ed7d60880.png)

- **Para fazer com que só aceitemos ligações ssl dos clientes , é ativar isso no ssl**
