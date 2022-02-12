# Aula 06/01/2022

## Exercicio 1

### Instalação do SMTP

![image](https://user-images.githubusercontent.com/12052283/148421642-2e7bfae3-7b0d-4f51-a20a-bf2a7e9b8458.png)

![image](https://user-images.githubusercontent.com/12052283/148421794-3c18f341-a3db-49b6-a38e-584676ac2316.png)

![image](https://user-images.githubusercontent.com/12052283/148421992-301510e2-b709-464b-bbea-3009c98abd1f.png)

### Criar o MX

![image](https://user-images.githubusercontent.com/12052283/148423418-6bb88dfc-18e6-4260-9c43-c4f99be44bd3.png)

![image](https://user-images.githubusercontent.com/12052283/148423585-b6c45b22-d0e2-461a-b1fd-213fb0e936b9.png)

### Instalação do Telnet em windows server

![image](https://user-images.githubusercontent.com/12052283/148423778-ec636620-3814-4778-97ca-a624976a57c7.png)


### Instalação do Telnet em windows client


![image](https://user-images.githubusercontent.com/12052283/148423818-db5cb17e-1733-4cf4-9cdc-1f89ef47b8c5.png)

### Comunicação de telnet do cliente para servidor

- No cliente

```console
telnet 192.168.1.20 25
```

## Exercico 2

- Preciso de desabilitar o IIS , o World Wide Web e o SMTP nos serviços ou nao consigo usar o KerioConnect para isso faço o seguinte

![image](https://user-images.githubusercontent.com/12052283/148425401-9a703f82-1c08-4ecb-ac1d-ff18b5f1433d.png)

### Instalação do KerioConnect no Servidor

![image](https://user-images.githubusercontent.com/12052283/148426226-8d7092cf-1cb1-4368-8a31-72b6fd39e81e.png)

![image](https://user-images.githubusercontent.com/12052283/148426292-b9f5dc10-0d0c-4f27-b5a6-18d2ff287003.png)

![image](https://user-images.githubusercontent.com/12052283/148426471-1e01f3ce-6aee-4012-b250-6de37f90c6f8.png)

![image](https://user-images.githubusercontent.com/12052283/148426584-73ca5273-9018-4c10-9de4-546726078024.png)


![image](https://user-images.githubusercontent.com/12052283/148426687-0e06c650-ba06-4fc2-be31-9a1e06565051.png)

### Autenticação no KerioConnect atraves do browser

![image](https://user-images.githubusercontent.com/12052283/148427023-18602a8a-e7ac-4c34-997d-e251686b4fdf.png)

### Testar o SMTP do Kerio

```console
telnet 192.168.20.1 25
```

### Ver os serviços que estao a correr e deixar apenas o SMTP,IMAP,POP3 e HTTP

- **Ativar o Serviço HTTP e HTTPS**


![image](https://user-images.githubusercontent.com/12052283/148427399-943d2ed8-cd3a-4d6f-acca-f73453d846e3.png)


### Crie dois utilizadores locais de mail e os users nao podem alterar a password

![image](https://user-images.githubusercontent.com/12052283/148427543-49d638f3-a7df-4795-a744-1160a6aea891.png)

![image](https://user-images.githubusercontent.com/12052283/148427857-1e7a8a8d-72a8-497d-bd9a-66d44446d7f4.png)

### Entrar com um user no KerioCliente (no servidor) e enviar um mail para mim proprio

![image](https://user-images.githubusercontent.com/12052283/148429555-379ac4bf-0705-4f5a-a99e-eef24bc74ea1.png)

![image](https://user-images.githubusercontent.com/12052283/148429588-a231f6fe-1c45-49c0-a879-ca17842a7648.png)


### Criar um grupo de mail

![image](https://user-images.githubusercontent.com/12052283/148428129-595e5b64-3f27-438f-9e5b-5bac7bac0f52.png)

### Criar um alias

![image](https://user-images.githubusercontent.com/12052283/148430805-e8d6e1b4-747b-464e-a635-222dbceb9cd9.png)

### Ver o tráfego e estatisticas do servidor

![image](https://user-images.githubusercontent.com/12052283/148431038-086e019b-06a5-4384-a8c9-4c4465a695a3.png)

- **A saude do servidor é vista no Integridade do sistema**

### Desabilitar a opção de complexidade da password

![image](https://user-images.githubusercontent.com/12052283/148431585-381af35d-620b-444f-9504-c4112d00cd19.png)


### Obrigar o utilizador a mudar a password a cada 60 dias

![image](https://user-images.githubusercontent.com/12052283/148431732-34ac9f4d-1772-46aa-8ad7-3ad61c1a0c72.png)

### Colocar uma quota de 50GB por caixa postal

![image](https://user-images.githubusercontent.com/12052283/148431876-444e7e69-dc2a-4417-be34-87b337e6f418.png)

### Criar uma limitação de 20MB para mensagens a enviar

![image](https://user-images.githubusercontent.com/12052283/148431943-e8af37a5-2677-41ff-b997-19ddf561b371.png)

![image](https://user-images.githubusercontent.com/12052283/148432152-fb089031-ae26-46f6-80df-0e2ebe497156.png)

### Criar um logotipo para a empresa para que surja nos clientes quando se ligam

![image](https://user-images.githubusercontent.com/12052283/148432450-cfe0f0fe-19b7-4313-bf45-7cc2d4bcf5c4.png)

![image](https://user-images.githubusercontent.com/12052283/148432814-0df83890-6e71-4e29-89db-a0679b074e1d.png)

### Criar uma assinatura para incluir em todas as mensagens de um utilziador

![image](https://user-images.githubusercontent.com/12052283/148433111-e8273df4-15b1-4816-bf93-fbaaa07bb801.png)

![image](https://user-images.githubusercontent.com/12052283/148433148-8c9b6834-5e84-4a30-a067-408a82b27592.png)

### Criar um filtro para que todas as mensagens que venham do endereço lixo@sr19.pt sejam enviadas para a pasta trash

![image](https://user-images.githubusercontent.com/12052283/148433364-2a3c8be1-7cc0-41eb-9fe4-6ed72c83b26f.png)

![image](https://user-images.githubusercontent.com/12052283/148434294-cdd4c8a2-fe54-42dc-8927-e9909ecd055d.png)


### Criar uma mensagem para quando o utilizador esteja fora do escritorio

![image](https://user-images.githubusercontent.com/12052283/148433614-a49b99d1-34b9-4e68-859c-30dc60cea3fd.png)

![image](https://user-images.githubusercontent.com/12052283/148433794-0b438d64-2166-4b21-bf27-5b944671e57a.png)
