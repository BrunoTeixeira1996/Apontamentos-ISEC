# Multihomming

- É a prática de ligarmos uma rede a mais do que um provedor de serviço (ISP)

- É sempre interessante estar em multihomming porque sempre a nossa disponibilidade

- Multiattachement é estar ligado ao mesmo operador mas por vários canais(wifi, cabo, etc)

- DFZ (nenhum router tem a entradada `0.0.0.0`)

- PI (Endereço que não é de nenhum ISP)
    - Podemos pedir isto mas é muito complicado

# Provider Independent Address (PI)

- Isto é quando nós requisitamos endereços a um Registry Regional e depois o mais normal é, a empresa que faz isto instala o BGP e anuncia as suas rotas através dos vários ISPs e assim consegue atrair trafego de um ISP ou de outro ISP.

- **Uma desvantagem de usarmos PI é que as tabelas de encaminhamento ficam muito maiores e isso tem graves consequências para os routers que estão na default free zone (DFZ, routers que não tem a rede 0.0.0.0)**

- O BGP só consegue anunciar endereços que sejam /24 ou mais curtos
  - Um dos parametros do BGP é a periocidade que ele dispoleta o recalculo da FIB(versao compilada da tabela de encaminhamento)

# Provider Assigned Address (PA) (endereços atribuidos por ISPs)

- **Cada ISP da-me uma fatia(isto é termos por exemplo um servidor local e queremos que pessoas de fora acedam a esse servidor)**

- Nós como Assigned Provided Addresses(`ISPs`), podemos chegar a uma conclusão
  - Ok temos muitos clientes em comum que usam multihoming, entao vamos ter um espaço de endereçamento comum e quando eu estiver em blackout passo para outro ISP mas o mais normal é isto nao acontecer porque os ISPs andam sempre em competição

- A vantagem é que se os endereços foram atribuidos como deve de ser, os mesmos podem ser agregados

## Questão sobre TCP com ISP Alfa e ISP Beta em que existe a queda de um cliente do ISP Alfa

- Se tiver uma sessão TCP estabelecida pelo **ISP alfa**, que me dá um certo espaço de endereçamento, e esse **ISP alfa** for à vida e os meus clientes voltarem a tentar aceder ao serviço que agora vai estar disponível no **ISP beta**, a sessão TCP continua ativa ou cai?

- A sessão vai cair, uma vez que o ISP Beta não tem rotas para o espaço de endereçamento de ISP Alfa.
- Caso tivessemos a usar o SCTP já dava uma vez que este protocolo permite ter várias streams ou seja, quer dizer que na rede podem ser estabelicidas varias sessões com o destino e caso um dos caminhos esteja em baixo, conseguimos na mesma utilizar outro caminho alternativo.


## NAT Based

- O NAT Based é um remendo para eu conseguir ter a minha rede interna ligada a 2 ISPs
- Ou seja, não me atrevo a atribuir nenhum espaço de endereçamento público, é tudo privado(internamente). Sucede que no Router de acesso eu tenho um serviço de NAT/PAT que pode pegar em trafego interno e manda para o exterior com o endereço publico que o ISP me dá ou entao pode estar a fazer port forwarding de pedidos que venham de fora.(pag 56)

### Questão relativa ao NAT Based

- Então quer dizer que mesmo assim, com o NAT Based implementado, eu poderei dar um serviço interno (alguem de fora da rede vai consumir um serviço meu) e dar mais disponibilidade aos meus clientes uma vez que estou a fazer multihoming? 

- Ou seja, aqui ha dois desafios
  - **Um deles é eu de dentro ter acesso a serviços externos e isso consigo uma vez que estou a sair por 2 ISPs havendo assim redundância caso um deles vá à vida**
  - **O outro é se um cliente quiser vir de fora para a nossa rede rede de dentro(somos então um PA) e se ja tiver uma conexão mas essa conexão falhar, o cliente de fora nao vai conseguir conectar**
	- Para resolver isto, temos de criar no DNS uma politica que por exemplo envia os IPs por round-robin. No entanto o DNS pode até enviar vários IPs para o cliente(**esta até é a melhor forma**) e o cliente escolhe o que quiser. 
	- Normalmente o cliente escolhe o primeiro, no entanto isto depende bastante da aplicação(pag 56).
		- `O browser é um bom exemplo disto, o browser recebe varios IPs no entanto escolhem qual é o melhor fazendo várias comunicações, isto com algoritmos.`
	- No entanto convem na mesma haver cookies para que o cliente nao tenha noção que foi estabelecida outra conexão TCP, ou seja, juntamos as cookies do HTTP com o DNS

- **Uma enorme vantagem com o HTTP é por exemplo se estiver numa rede multihoming e esse HTTP contiver cookies eu posso conseguir sobreviver à perda de um dos router ISPs por causa desses cookies, no entanto o cliente tem de saber que existemvários caminhos para aceder a esse serviço HTTP e isto ele sabe com o DNS**(pag 56)


### Será então o DNS uma boa solução? 

![image](https://user-images.githubusercontent.com/12052283/145249344-26780f4c-ce2c-493d-a339-8b44700f9994.png)



## Soluções ID/Loc Split

- Problema da segurança
- Problema do multihomming
- Problema da mobilidade
  - Estou a receber uma chamada VOIP, perco o WIFI, ligo por 4G e lá se foi a chamada
- Problema ID/Loc Split
  - Como causa das limitações arquiteturais correntes tem sido apontada o facto dos endereços IP serem usados simultaneamente no papel de **Identificadores** e **Localizadores**

- Para resolver estes problemas todos, existem varias soluções, como por exemplo o HIP, no entanto HIP implica alterar os terminais e isto nunca é bom porque nós nao queremos alterar nunca os terminais, queremos apenas alterar a rede

## SCTP

- Este é então o protocolo mais importante dos outros todos dos problemas aqui de cima
- Trata-se de uma solução da camada de transporte que não implica alterações de relevo à infraestrutura
