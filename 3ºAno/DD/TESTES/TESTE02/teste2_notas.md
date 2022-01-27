# O que acontece se tivermos 2 switches no mesmo dominio de difusão com o mesmo IP? 

# Hot Standby Router Protocol (HSRP)

## Definições

Existe um grupo constituido pelo Active Router, Virtual Router e Standby Router

![image](https://user-images.githubusercontent.com/12052283/139044394-3d50e625-3a45-4ebd-b3c0-cbb06f86b0aa.png)

Existem dois ou mais router fisicos.
Um Active Router (AR) que desempenha o papel de Default Gateway para os terminais.
Um Standby Router (SR) que mantem-se pronto a tomar o papel de router ativo

Depois existe o Standby Group que mantêm-se pronto a tomar o papel de standby router e/ou active router.
No lado dos terminais, os mesmos vêm apenas um único router que representa o standby group.
O Virtual Router é então o router que existe na perspetiva dos terminais tendo este um IP virtual e MAC virtual.

![image](https://user-images.githubusercontent.com/12052283/139045250-dcafff8a-7056-4eb2-8d4e-b60a17d9761a.png)

## Funcionamento

Os terminais usam o VR como default gateway.
O AR é responsável por encaminhar este tráfego.

A cada hellotime (3 segundos) o AR e o SR anuciam o seu papel através do multicast.

Todos os routers do grupo estão à escuta dos anúncios sendo que o router com maior Standby Priority (0 ... 255) é o AR e é escolhido por ser o router mais novo ou com maior capacidade, o router com a segunda maior Standby Priority é o SR e o desempate é feito por maior IP.

**Qualquer router do grupo deve processar tráfego IP transportado em quadros destinados ao seu MAC real, no entanto apenas o AR deve encaminhar tráfego IP destinado ao MAC virtual definido para o VR**

### O que é preempeção neste caso

Se o router que era o AR avariar e o router SR entrar em ação, passado algum tempo se em algum momento o antigo AR voltar a funcionar de maneira correta convem voltarmos a usar o antigo AR sendo isto a maneira preemptiva.
Se continuassemos com o antigo AR como SR não estariamos a usar a preempeção.

### Exemplo de funcionamento

![image](https://user-images.githubusercontent.com/12052283/139052000-5c176cd7-bc99-4a1e-b3cd-09974cb3b9de.png)


## Análise do HSRP PDU

![image](https://user-images.githubusercontent.com/12052283/139047557-2a9e7ab3-192b-465c-a669-4ce1186de517.png)

### Opcode

O Hello anuncia que está pronto a ser AR ou SR
O Coup anuncia que quer tornar-se AR (preempção)
O Resign anuncia que quer abandonar o papel de AR

### State

0 Initial: Estado inicial no arranque das interfaces
1 Learn: Aguarda ouvir AR, desconhece IP virtual
2 Listen: Aguarda ouvir AR, conhece IP virtual
4 Speak: Participa nas eleições para AR/SR
8 Standby: É SR
16 Active: É AR

### Virtual IP Address

Quando um IP virtual não se encontra localmente configurado (em routers no estado 0 ou 1) e o mesmo vá fazer parte do standby group este pode aprender o IP virtual através de mensagens Hello emitidas por routers no estado 2 ou superior.

A aprendizagem deve ocorrer apenas em routers que não possuam o ip virtual localmente configurado e em mensagens autenticadas.

Os terminais devem então usar este endereço IP como o seu default gateway

### Virtual MAC Address

O router que desempenhar o papel de AR responde a pedidos ARP sobre o IP virtual com endereços MAC virtuais.

**A primeira ação que um router desencadeia assim que transita para o papel de AR é difundir um ARP Gratuito com MAC Virtual e o IP Virtual, tendo como objetivo atualizar as tabelas de aprendizagem dos switches de modo que os próximos quadros destinados ao default gateway lhe sejam entregues**

# Fazer um esquema com os routers virtuais e com o IP e MAC Virtual


# Comandos

## Primeira experiencia (Configurar Virtual IP no R1) (Topologia 1)

Depois de ter configurado todos os IPs, fui à interface do R1 que está ligada à Rede A e fiz `standby 1 ip 192.168.100.100`

![image](https://user-images.githubusercontent.com/12052283/139056880-6c271f98-db8b-4c9d-abcc-a3ae71b9597a.png)

O R1 faz Speak (6 segundos), depois passa para Standby (2 segundos) porque verifica que não existe nenhum router com prioridade ou ip superior ao dele tornando-se aqui logo um Standby Router. Como neste processo não foi escutado nenhum AR o R1 torna-se AR e envia um ARP gratuito a registar o Virtual IP 192.168.100.100 emitindo depois avisos periódicos.

![image](https://user-images.githubusercontent.com/12052283/139058299-cf6fee58-8df4-4ab6-accd-f8824dd04f2b.png)

Aqui conseguimos ver o Virtual MAC Address no formato 0000.0C07.ACxy onde xy é o número do StandBy Group em hexadecimal

## Segunda experiencia (Configurar agora o mesmo Virtual IP no R2) (Topologia 1)

Nesta segunda experiencia fui à interface do R2 que está ligada à Rede A e fiz `standby 1 ip 192.168.100.100`, no entanto na verdade o Virtual IP evita de ser configurado porque pode ser aprendido.

![image](https://user-images.githubusercontent.com/12052283/139059627-299b80f7-10fa-4427-b0ce-c1f81fc28f23.png)

O R2 aguarda ouvir um AR para conhecer o Virtual IP, depois de ouvir o R1 (que é o atual AR), faz o Speak para verificiar se passa a ser AR ou SR, depois de verificado o R2 fica em SR.

### Porque motivo R2 é o SR e R1 o AR?

Quando o modo não preemptivo vigora a estabilidade da rede assume prioridade, ou seja, uma vez que configuramos primeiro o R1 este irá ser o AR e seguidamente o R2 o SR.
Caso tivessemos configurado primeiro o R2 este seria o AR e o R1 o SR.

![image](https://user-images.githubusercontent.com/12052283/139061412-fe94e59a-948d-481e-b667-6bc9fc3ea5e2.png)

![image](https://user-images.githubusercontent.com/12052283/139062005-9ecbf6a5-209b-471e-80e7-309e3ef7a33f.png)

![image](https://user-images.githubusercontent.com/12052283/139062249-d6b14424-d605-426b-b887-f3a01d062908.png)

## Terceira experiencia (Forçar o R1 a ser o AR na Rede B) (Topologia 2)

Uma vez que o IP de R1(.254) na Rede B é mais elevado comparado com o IP de R2(.253) na Rede B, seria suficiente ligar o modo preemptivo, no entanto nesta versão do IOS, R1 apenas se torna AR quando a sua prioridade é mais elevada que a de R2.

![image](https://user-images.githubusercontent.com/12052283/139089031-53e15238-94e4-4bb4-b925-ad168ffe5d82.png)

Mesmo colocando o modo preemptivo ativo não vai acontecer nada.

![image](https://user-images.githubusercontent.com/12052283/139089690-fae0c859-891f-4af4-b914-a10520c4b7ca.png)

Porque é preciso alterar a prioridade para este router passar a ser AR uma vez que na versão deste IOS é assim que funciona.
No inicio o router que vai passar a AR vai continuar como StandBy porque só passados 60 segundos é que o mesmo faz o takeover para AR passando o outro para SR.

![image](https://user-images.githubusercontent.com/12052283/139090726-3133811f-f0c3-4066-baef-84f8ceb19e14.png)

## Quarta experiencia (Programar os terminais para tirar partido do HSRP e fazer modificações) (Topologia 3)

Alteramos o default gateway dos PCs de modo a cada um ter o seu respitivo default gateway com o Virtual IP da sua rede

![image](https://user-images.githubusercontent.com/12052283/139097462-1aa3f280-00e8-4911-b3a6-8dfa151e3c39.png)

### Ping do Ipterm-5 para o Ipterm-6

O Ipterm-5(192.168.100.1) vai enviar um ARP Request a perguntar quem é o 192.168.100.100(Virtual IP), de seguida o grupo responde com o mac address virtual e logo a seguir é feito o ping do 192.168.100.1 para o 192.168.200.1

![image](https://user-images.githubusercontent.com/12052283/139098218-fe762293-1b2d-47a4-a90b-87d8f3f03417.png)

### Ping continuo Ipterm-6 para Ipterm-5 desligando a interface e0/0 do R5

Depois de ser desligada a interface e0/0 do R5, e com o ping continuo, a recuperação não chega a verificar-se.
O que aconte é, antes do R5e0/0 ficar em baixo o mesmo emite um HSRP Resign(a dizer que se demite) e o R6 toma o papel de AR, depois o R6 envia um ARP gratuito(difundido em broadcast e em multicast STP) para associar o Virtual IP do grupo ao Virtual MAC Address. Como os terminais já conhecem este MAC Address as suas tabelas de arp mantêm-se inalteradas, logo a atualização é feita nas tabelas de aprendizagem dos switches da rede.

![image](https://user-images.githubusercontent.com/12052283/139101844-1ce8d727-d0d0-4cea-843c-940e9ff6ca4b.png)

Então o problema é que o Echo Reply não chega ao Ipterm-6 porque na rede A o R5 continua a ser o AR.

![image](https://user-images.githubusercontent.com/12052283/139102219-13fe210e-d45a-4708-bdf0-0b3fb8df5c3d.png)

Uma maneira para solucionar isto seria desligar completamente o R5(ou então apenas as interfaces) e assim o R6 seria AR em ambas as redes.

Podemos solucionar isto configurando um protocolo de encaminhamento em R5 e R6 ou então uma rota estática caso haja apenas 2 routers. Esta solução está em baixo

#### Tolerar falha de uma interface com o RIP (Topologia 4) 

Estado Atual antes da Experiencia

![image](https://user-images.githubusercontent.com/12052283/139302114-70e2cd58-d168-4f7b-8823-07c396c0721c.png)


Configurou-se o RIP no R7 e no R8.
Fez-se um ping contínuo do Ipterm-8 para o Ipterm-7 e depois desligou-se a interface e0/1 do R7 fazendo uma captura na interface e0/0 do R8.

No inicio o Ipterm-8 não consegue comunicar com o Ipterm-7 porque o Ipterm-7 continua a ter como AR o R1 como mostra na imagem.

![image](https://user-images.githubusercontent.com/12052283/139303665-42ae211d-a569-49f8-926b-e69c9980c7b4.png)

Passado algum tempo os Ipterms já conseguem comunicar porque o R7 começa a redirecionar o tráfego para o R8 (por causa do RIP) sendo que o R7 continua a ser o AR da Rede A então o Ipterm-7 vai sempre enviar o seu Echo Reply para o R7.

Neste caso o switch que está na Rede A recebe duas vezes um Echo Reply

![image](https://user-images.githubusercontent.com/12052283/139304002-6d6b0277-41d3-4f10-bc63-e1beec09bbf8.png)

A conclusão é que o encaminhamento torna-se assimétrico e não faz sentido o R1 estar a ser usado quando R2 acaba por ser chamado a processar ambos os sentidos do tráfego.

Por omissão os routers com HSRP filtram ICMP Redirects usando o comando `standby redirect`.

Depois de ativarmos novamente a interface e0/0 do R7, o mesmo torna-se AR de ambas as redes uma vez que já tinha a prioridade no máximo e o modo preemptivo ligado.

## Como otimizar o encaminhamento na presença de falhas toleradas pelo HSRP sobre uma única interface? 

Os routers envolvidos devem ser ambos configurados para atuar de forma preemptiva
Os routers envolvidos devem estar configurados para vigiar interfaces relevantes
Os routers envolvidos devem possuir preferências próximas dentrodo grupo. Quando o protocolo associado à interface vigiada ficar *down* a prioridade do router é diminuida automaticamente


### Configuração dos routers pra ja sem tracking (Topologia 5)

No R9 foi feito o seguinte:

```code
int e0/1
standby 1 ip 192.168.100.100
standby 1 preempt delay minimum 60
standby 1 priority 105

int e0/0
standby 1 ip 192.168.200.100
standby 1 preempt delay minimum 60
standby 1 priority 105
```

No R10 foi feito o seguinte:

```code
int e0/0
standby 1 ip 192.168.100.100
standby 1 preempt delay minimum 60
standby 1 priority 100

int e0/1
standby 1 ip 192.168.200.100
standby 1 preempt delay minimum 60
standby 1 priority 100
```

### Configuração dos routers com tracking (Topologia 5)

No R9 foi feito o seguinte:

```console
conf t
track 1 interface e0/0 line-protocol
exit
track 2 interface e0/1 line-protocol
exit

int e0/1
standby 1 track 1

int e0/0
standby 1 track 2
```

![image](https://user-images.githubusercontent.com/12052283/140097010-4cd4fb87-b541-4e23-a10a-9fe710ef663c.png)


No R10 foi feito o seguinte:

```console
conf t
track 1 interface e0/1 line-protocol
exit
track 2 interface e0/0 line-protocol
exit

int e0/0
standby 1 track 1

int e0/1
standby 1 track 2
```

![image](https://user-images.githubusercontent.com/12052283/140097338-456f59d8-f8d3-473d-a0ac-a13c246b2987.png)

#### Resultado de ter desligado a interface e0/0 do R9

Depois de ter desligado a interface e0/0 do R9, o R10 torna-se imediatamente AR em ambas as redes, no entanto no R9 a interface que foi desligada fica a Init e a interface que continua operacional, 1 minuto depois, fica em Standby

![image](https://user-images.githubusercontent.com/12052283/140098190-7640d63c-d24c-4cbc-a3c9-5f4d70a22031.png)


## HSRP Versão 2

Para mudar da versão 1 para a verão 2 usamos `standby version 2` em ambas as interfaces do router

Novo grupo multicast IPv4
Mesmo porto UDP
Nova estrutura TLV
Identificador único do router emissor do Hello
Precisão temporal ao milisegundo

### HSRPv2 com autenticação (Topologia 6)

Configurei o R11 e o R10 com a versao 2 do hsrp e em baixo esta um exemplo

![image](https://user-images.githubusercontent.com/12052283/140102395-f2f58ad7-3f49-49ab-a95c-905402a5f1b2.png)

Depois foi só configurar uma interface para usar a autenticação como mostra em baixo

![image](https://user-images.githubusercontent.com/12052283/140103479-2cc3ec3b-2b02-4578-95a5-32a418ded01e.png)
