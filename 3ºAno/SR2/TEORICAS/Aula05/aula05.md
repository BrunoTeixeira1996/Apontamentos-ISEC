# Aula 15/12/2021

## Correio Eletrónico

- O objetivo do correio eletrónico é o envio de mensagens entre utilizadores podendo esses estar "off-line"
- O local de armazenamento é conhecido por *mail-box* ou *caixa-do-correio*

### Baseado em sistema de ficheiros

- Um servidor deste tipo está totalmente contigo num único servidor e não utiliza a rede diretamente
- Cada mensagem tem um remetente (**FROM**) e um destinatário (**TO/CC/Bcc**)

- O sistema pode assim ser implementado usando um sistema de ficheiros com permissões de utilizador utilizando apenas o
nome do utilizador para a autenticação (**não é necessário utilizar a noção/definição de domínio**)

### Correio eletrónico em rede

- A comunicação entre sistemas centrais de correio recorre a uma infraestrutura de rede e será realizada segundo um
protocolo de aplicação que **tem de ser reconhecido pelos dois intervenientes**

- O fluxo de uma forma simples é o seguinte:
  - O cliente envia a mensagem para o servidor de mail
  - O servidor encaminha a mensagem para uma fila de envio.
  - A mensagem chega ao sistema de mail destino
  - O servidor encaminha a mensagem para a mail box do utilizador
  - O cliente destinatário descarrega a mensagem no seu cliente

![image](https://user-images.githubusercontent.com/12052283/146246355-f8e2bafb-674d-4c61-bd6c-d58aefd28a75.png)

![image](https://user-images.githubusercontent.com/12052283/146246548-11543433-fd01-4ff9-adb0-70ecdb1f8a26.png)

### Funcionamento

- A forma tradicional de enviar mail é utilizar um programa cliente (MUA) que comunica com o servidor de mail (MTA).Esta comunicação é direta se este estiver instalado na mesma máquina, ou é através do protocolo SMTP (**porto TCP 25**) se estiverem instalados em máquinas diferentes

- Utilizando a porta 25 e o protocolo SMTP, os MTAs, encaminham o mail até ao destino final
- Se o utilizador não tem acesso direto ao computador onde recebe o email, poderá então faze-lo utilizando o protocolo **POP3** (ou **IMAP**) utilizando um servidor intermediário

![image](https://user-images.githubusercontent.com/12052283/146247540-c8ae469e-e0bf-4835-b1a8-d2ea64305507.png)

![image](https://user-images.githubusercontent.com/12052283/146247636-1323f682-f4f1-41e8-a0ab-76bb98658568.png)

## SMTP (Simple Mail Transter Protocol)

- Pertence à camada de aplicação OSI
- Baseia-se num funcionamento do tipo store-and-forward (**é uma técnica de telecomunicações em que a informação é enviada a uma estação intermediária onde é mantida para ser posteriormente enviada para um dispositivo dedestino ou para outra estação intermediária.**)

- É o protocolo mais usado para **transferir mensagens de correio eletrónico entre sistemas**
- Identifica os users com **user@dominio**
  - **Dominio** é o nome DNS qualificado do servidor de correio onde a mailbox desse utilizador se encontra.
  
- Quando o MTA processa uma mensagem verifica se o “dominio” corresponde ao seu próprio domínio, nessa caso procura a mailbox local correspondente ao “UTILIZADOR” e deposita lá a mensagem
- Se o “dominio” pertence a outro servidor, contacta esse servidor (resolvendo o nome DNS) e envia-lhe a mensagem usando o protocolo SMTP

- **Existe uma entrada especifica no DNS para o servidor SMTP**

### SMTP (Cabeçalho)

- Os cabeçalhos dos e-mails indicam de onde uma mensagem é enviada e registam todo o caminho que ela segue ao passar pelos diferentes servidor de e-mail

- É assim possível conhecer o caminho de uma mensagem cronologicamente, lendo a partir da parte inferior do cabeçalho, e trabalhando de baixo para cima

![image](https://user-images.githubusercontent.com/12052283/146249436-0e75e409-a997-49aa-9413-3df71a47016a.png)

![image](https://user-images.githubusercontent.com/12052283/146249695-a31c217d-bbe1-4cde-a27c-c4149a410282.png)

### SMTP (Ligação)

- Usa uma ligação TCP para transferir a mensagem de correio eletrónico, para esse efeito os MTA aceitam ligações TCP no porto 25

- A ligação tem três fases:
  - Estabelecimento da ligação (handshaking)
  - Transferência de dados
  - Fecho

![image](https://user-images.githubusercontent.com/12052283/146249920-9c62e591-ba7f-4bdb-9ba0-3e5f77f632c2.png)

![image](https://user-images.githubusercontent.com/12052283/146250000-53cab3df-1960-47c7-a20c-f1b4a90b9b79.png)

![image](https://user-images.githubusercontent.com/12052283/146250038-51c9e567-b61a-4a00-ab7f-4f1274a7ae00.png)

### SMTP (Comandos)

- página 31 e 32 (reler)

### SMTP (Respostas)

- As respostas aos comandos SMTP servem para assegurar a sincronização dos pedidos e as ações nos processos de transferência de correio, de forma a garantir que o cliente SMTP conhece o estado do servidor
- Cada comando gera uma resposta e essa **resposta é constituida por 3 números seguindo de um texto**
  - O 1º número indica se a resposta é boa, má ou incompleta
  - O 2º e 3º número fornecem informações complementares
  
### SMTP (Testar)

![image](https://user-images.githubusercontent.com/12052283/146250949-3a34ea62-10b6-470d-bbba-a0905a0ac7a9.png)


### Funcionamento - Correio Eletrónico (MX)

- No caso de pretender enviar uma mensagem de correio eletrónico, o seu servidor não sabe o nome da máquina onde tem de entregar a mensagem. Conhece apenas o endereço de correio eletrónico do destinatário e consequentemente o domínio.
- O funcionamento será então idêntico ao descrito para saber o IP do nome de uma máquina, **mas agora a pergunta não terá como resposta o IP de um nome mas sim do registo MX do domínio destino**

![image](https://user-images.githubusercontent.com/12052283/146248400-9da5100c-b060-4f87-9fd4-a075c0b53586.png)

![image](https://user-images.githubusercontent.com/12052283/146248496-049372f3-ac3e-49be-8d8e-94a6c2cda871.png)

![image](https://user-images.githubusercontent.com/12052283/146248583-3bf0a723-3fe9-4164-9c58-770b0806bee0.png)

![image](https://user-images.githubusercontent.com/12052283/146248684-2d1ce2c0-ef62-41cb-b056-f72a7b8cabc7.png)

- Resumindo

![image](https://user-images.githubusercontent.com/12052283/146248945-588acf54-dd56-4e0f-90a7-4b246e4f65d6.png)

## Routing de E-mail

- Um endereço de e-mail contem um *domain name* na parte direita
- Este *domain name* especifica o servidor que gere a mailbox do destinatário da mensagem.
- Para se chegar ao mesmo, eventualmente, é necessário passar através de outros servidores intermédios. 
- Para indicar estes caminhos alternativos, usam-se os chamados **mail exchange resource records** no DNS.

![image](https://user-images.githubusercontent.com/12052283/146251243-69752310-31ef-4b08-933f-3b72a84c4759.png)

- Este mecanismo permite introduzir redundância no processo de entrega de e-mail ao destinatário final e permite igualmente introduzir no espaço de endereçamento do e-mail nomes que não são diretamente nomes de servidores ou que são gateways de e-mail, etc

## MIME (Multipurpose Internet Mail Extensions)

- Inicialmente as mensagens de mail apenas podiam conter texto
- Para resolver isto,  o IETF desenvolveu um conjunto de extensões(MIME) que permitem uma variedade de formas de codificação (**programas, imagens, audio**)

- Uma mensagem de correio eletrónico é identificada como estando em formato **MIME** através da presença do campo **MIME-Version** no cabeçalho sendo que a versão atualmente em uso é a *1.0”*
-  As mensagens em formato **MIME** possuem outras linhas de cabeçalho fundamentais para identificar quer o tipo de dados transportados no corpo (**Content-Type:**) quer a forma como esses dados estão representados (**Content-Transfer-Encoding:**)
- O campo **Content-Type** é importante porque permite à aplicação de destino interpretar os dados para os apresentar corretamente ao utilizador
- O conteúdo **multipart** é bastante usado porque permite transportar numa única mensagem vários tipos de conteúdos diferentes em partes separadas

![image](https://user-images.githubusercontent.com/12052283/146251690-1b74ec1d-5841-46c8-901e-8776a9a243b6.png)

![image](https://user-images.githubusercontent.com/12052283/146251991-335876cd-20ba-450f-be74-43e36d5e643a.png)

## POP3 (Post Office Protocol v3)

- Os utilizadores ligam-se a um servidor POP para ler o seu correio. Por sua vez, o servidor POP acede ao mail spool escrito pelo SMTP.

- O POP3 utiliza o **porto 110** e funciona sobre o protocolo TCP

- **É usado essencialmente para obter as mensagens de e-mail de um servidor e depois apagá-las**

- É utilizado apenas para a receção e não para o envio (SMTP)


### Inicialização do serviço

- Na fase inicial, o servidor de correio eletrónico inicia o serviço POP3 e começa a ouvir a Porta TCP 110, ou 995 se a ligação utilizar o protocolo SSL
- Sempre que surge um pedido de uso do serviço, o protocolo estabelece uma conexão TCP entre o servidor de correio eletrónico e o cliente
- Após o estabelecimento da conexão, o servidor POP3 envia uma mensagem de saudação ao cliente, a qual confirma a ligação ao servidor

### Comandos do POP3

- Enquanto a comunicação não for fechada ou abortada, o cliente de correio eletrónico está constantemente a trocar comandos e respostas com o servidor de POP3
- Os comandos interpretados pelo POP3 são constituídos por **palavras-chave seguidos ou não de um ou mais argumentos**,
neste caso, **o protocolo não faz distinção entre letras maiúsculas ou minúsculas, sendo que todos eles terminam com um par CRLF, ou seja, com uma mudança de linha**
- As palavras-chave e os vários argumentos são separados por caracteres de espaço, e o conteúdo de cada um dos elementos
é formado por caracteres ASCII, sendo que as palavras-passe podem ser constituídas por 3 a 4 caracteres e os argumentos
podem ter um máximo de 40 caracteres.

### Respostas do POP3

- As respostas no protocolo POP3 são constituídas por um indicador de estado e uma palavra-passe, seguidos ou não de informações adicionais e terminadas por um CRLF(\n)
- Podem ter até 512 caracteres de comprimento, incluindo o CRLF
- Na versão 3 do protocolo POP, existem dois indicadores de estados
  - positivo e negativo, “+OK” e “-ERR”, respetivamente e sempre em maiúsculas
  
### Fases do POP3

- Após o envio da saudação ao cliente, o protocolo entra no estado de **AUTORIZAÇÃO**
- Nesta fase o servidor pede a autenticação ao cliente e se esta operação for bem-sucedida, estão reunidas as condições para avançar para o estado de **TRANSAÇÃO**
- Neste estado, o cliente faz pedidos ao servidor POP3
- Quando o cliente envia o comando QUIT, a sessão entra no estado **ATUALIZAÇÃO**, e entre outras operações, liberta os
recursos alocados no estado anterior e fecha a conexão TCP

![image](https://user-images.githubusercontent.com/12052283/146253976-d5c78995-7202-489c-8543-525c4c5b7c7c.png)

![image](https://user-images.githubusercontent.com/12052283/146254093-337c1d48-aca5-4962-9fd7-fefcde54d082.png)


## IMAP4 (Internet Message Access Protocol v4)

- O protocolo POP3 é bastante limitado, normalmente serve apenas para obter o conteúdo da mailbox do utilizador e a ligação com o servidor é terminada após essa consulta integral

- O protocolo IMAP4  é bastante mais interativo, também usa uma conexão TCP, neste caso para o **porto 143**, mas normalmente a ligação do cliente com o servidor mantém-se ativa constituindo uma sessão interativa

- **Não é obrigatório o download de mensagens para um disco local sendo que a cópia original da mensagem reside sempre no servidor**

- Possibilita a utilização de inúmeros dispositivos diferentes para aceder ao email sem que o conteúdo seja alterado, tanto de emails recebidos como enviados, pois o mesmo está armazenado no servidor, não sendo descarregado

- O protocolo IMAP, permite três possibilidades de acesso ao correio eletrónico:
- **online**
  - Todas as mensagens, o seu conteúdo e as pastas criadas estão armazenadas no servidor de email, permitindo o utilizador aceder e manipular as mesmas através do software cliente-email
  - Desta forma, todas as caracteristicas apresentadas estão disponíveis ao utilizador, tais como a possibilidade de criação, edição e eliminação de mails e/ou pastas
  - É aconselhavel quando os clientes acedem a partir de redes remotas
- **offline**
  - O software cliente-email descarrega todo o pacote de novas mensagens recebidas do servidor para o dispositivo utilizado pelo utilizador
  - Todo o processamento de mensagens, como informações sobre leitura e resposta, passam a ser mantidas apenas no software utilizado
  - Permite a consulta do correio na máquina local em situações de desconexão da rede
- **disconnected**
  - O fostware cliente-email, realiza uma cópia das mensagens contidas no servidor e desconecta-se do mesmo. Assim o utilizador fica com uma cópia no software utilizado como no servidor
  - Após a relização das operações pretendidas dentro do software cliente-email, quando o utilizador conectar-se novamente ao servidor, o software faz uma sincronização entre o trabalho realizado no software e o conteudo armazenado no servidor
  - Para o utilizador não deverá existir grande diferença entre este modo e o modo online


![image](https://user-images.githubusercontent.com/12052283/146254701-c6b4f3f4-eca9-4585-9c57-772bef59ddbf.png)

## POP - IMAP

![image](https://user-images.githubusercontent.com/12052283/146255603-ef2b8e98-5425-475a-87bc-f7556e6a76ff.png)

## Webmail

- Muitas das vantagens equivalentes às do IMAP4 estão atualmente disponíveis usando sistemas conhecidos por WebMail.
- Trata-se de aplicações CGI que são executadas por um servidor HTTP residente na mesma máquina onde o sistema de correio está a funcionar

![image](https://user-images.githubusercontent.com/12052283/146255731-e9b15d4b-25d8-465b-84b9-d4f7328101b7.png)

## Referências

- https://www.youtube.com/watch?v=0F1JP78JAPE
- https://www.makeuseof.com/tag/pop-vs-imap/
