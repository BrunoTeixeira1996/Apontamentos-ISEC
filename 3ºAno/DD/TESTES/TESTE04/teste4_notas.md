# Teste 04

## GLBP

- Solução proprietária da CISCO que essencialmente representa uma versão do HSRP melhorada

- Suporta explicitamente load balancing sem a necessidade de configurar múltiplos grupos e múltiplos DGs em clientes distintios.

- Em vez de um, podem ser usados simultaneamente até quatro routers a desempenhar a tarefa de DG, sendo que todos partilham o mesmo IP Virtual e todos recorrem a um MAC Virtual distinto

### Funcionamento

- Membros de um grupo GLBP elegem um elemento como **Active Virtual Gateway(AVG)**
  - O AVG atribui um Virtual MAC a cada membro do grupo
  - Estes tornam-se **Active Virtual Forwarders(AVFs)**
	- São no máximo 4 e passam a ter a responsabilidade de encaminhar tráfego endereçado para o seu Virtual MAC
  - O AVG responde aos ARP Request dirigidos ao Virtual IP
	- O balanceamento é conseguido através de diferentes respostas
- Os AVFs estão sempre disponíveis como backup do AVG

### Em caso de falha de um AVF

- Um dos **SVF (Secondary Virtual Forwarders daquele MAC virtual)** toma temporariamente a responsabilidade de PVF de MAC Virtual
- Durante o Redirect Time o AVG continua a enviar ARP Replies para o MAC Virtual perdido
- Após o Redirect Time expirar o AVG cessa a utilização daquele MAC Virtual mas o AVF substituto continua a encaminhar tráfego que lhe é remetido com o MAC Virtual perdido
- Só depois do Holdtime expirar é que o MAC Virtual perdido volta a estar disponivel para o AVG atribuir

### A prioridade de cada router determina

- O AVG é o equipamento com maior prioridade no grupo
- Quem substitui o AVG em caso de falha é o AVF com maior prioridade
- Quem suporta temporariamente os MAC Virtuais perdidos
- **Na retoma do papel de AVG o modo preempetivo encontra-se inativo por omissão**
- **Na remota do papel de AVF O modo preemptivo encontra-se ativo mas a retoma é atrasa em 30 segundos**

## Experiências

### Experiencia 1

- Configurando o GLBP apenas na Rede B conseguimos perceber que o R1 é AVG e AVF  e o R2 é apenas AVF
- Ao fazer ping do PC1 para o PC3 o R1 envia o MAC Virtual do R2 para o mesmo encaminhar
- Logo de seguida ao fazerping do PC2 para o PC3 o R1 envia o seu MAC Virtual para o mesmo encaminhar, sendo que o protocolo usado é o **round-robin**

![image](https://user-images.githubusercontent.com/12052283/144277625-80bf511f-92fc-4fd4-b6d9-878509d8d703.png)

### Experiência A 

**Como será que os equipamentos da camada L2 (switches) vêm as suas tabelas de aprendizagem povoadas?**

- Inicialmente o switch nao vai ter a sua tabela de aprendizagem povoada porque a comunicação do GLBP é em anycast e não existe ARPs gratuitos. Apenas quando existe comunicação (PING), ao ser emitido um ARP Request/Reply, o mesmo aprende o MAC fisico dos routers e em que interface cada um está ligado.
  
- https://networkengineering.stackexchange.com/questions/10108/wont-glbp-confuse-a-switchs-mac-address-table

### Experiência B

**Será que o GLBP permite que o IP virtual seja usado por outro equipamento da rede?**

- Foi adicionado o R3(com o mesmo IP virtual) na rede B (rede que já tem o GLBP a funcionar) e quando o mesmo emite os ARP Gratuitos o GLBP indica que existe um endereço duplicado. Depois tentou-se enviar um PING do R3 para o R1 mas nunca funciona dizendo sempre que o existe um endereço duplicado. O R3 apenas consegue comunicar com os PCs da rede B.

- Foi desligado o R1 e o R2 e foi configurado no R3 o ip 192.168.200.100(IP Virtual do GLBP) na e0/0. Depois de ligarmos o R1 e o R2, o mesmo aviso de endereço duplicado aparece, tendo novamente o mesmo problema de nao conseguir comunicar com os restantes routers apenas consegue com os PCs da rede B.

### Experiência C

#### Desligar interface e0/0 do R1

- Inicialmente o R1 é AVG e AVF e o R2 é AVF, no entanto depois de desligarmos a e0/0 do R1, o AVF que estava no R1 passa para o R2 sendo que o R2 vai ter agora 2 forwarders ativos.
- Os timers (Redirect e Time to Live) não entraram em count down 

![image](https://user-images.githubusercontent.com/12052283/144324774-f9a50558-2426-448e-a009-58e08f88f98f.png)

#### Analisar se R3 recebe do AVG o AVF que migrou para o SVG ou se recebe um novo AVF

- Ao configurarmos o GLBP no R3 para se juntar ao grupo, o R3 recebe um novo AVF uma vez que fazendo `sh glbp` vemos que no R2 fica com o Forward 1(`AVF que era do R1`) e Forward 2 ativo e o R3 fica com o Forward 3 ativo


#### Ping de 3 PCs da rede B para a Rede A e anotar os MAC recebidos e perceber se a distribuição de MACs segue round-robin

- Foi feito um ping do PC3,P4 e PC5 para o PC1 e depois foi feito o comando `arp` nos PCs e foi visto que segue o round-robin uma vez que o PC3 foi pelo R1, o PC4 foi pelo R2 e o PC5 pelo R3. Depois foi feito outro ping do PC3 e o mesmo voltou a ir pelo R1 visto que o ultimo a ter encaminhado foi o R3.


#### Quantos MACs virtuais estão na pool usada pelo AVG?

- Na Pool do R1 estão 3 MAC virtuais

- A imagem abaixo mostra os MAC fisicos

![image](https://user-images.githubusercontent.com/12052283/144328429-bbfbed17-e6ca-4afd-8f36-fc9176324b3a.png)

### É justo o que sucede na rede? Consiste isto num bug de implementação?


- O VPCs1 solicita por ARP o MAC do seu DG e o AVG responde-lhe enviando o MAC de AVF#1
  - No entanto o VPCs, por má implementação do ARP, usa o Source Address do ARP Reply em vez do Source Mac Address fazendo assim o ICMP Echo Request ao AVG (R1) 
  
![image](https://user-images.githubusercontent.com/12052283/144329854-64778235-4a15-4a7d-8897-9d99f0ceb18c.png)


- O VPCs2 solicita por ARP o MAC do seu DG e o AVG respondelhe enviando o MAC de AVF#2 visto que estamos a usar round-robin
  - No entanto o VPCs, por má implementação do ARP, usa o Source Address do ARP Reply em vez de usar o Source MAC Address fazendo assim o ICMP Echo Request ao AVG em vez de fazer ao AVF#2
  

![image](https://user-images.githubusercontent.com/12052283/144330055-fd9e5ad5-6268-49e6-a532-6da0641971a2.png)


- A falha aqui reside na forma como os VPCs implementam o processamento do ARP Reply sendo que estes povoam a sua cache ARP com o Source Mac Address em vez de usarem o Target Ip Address

- **Uma maneira de resolver este problema seria o AVG enviar, em ARP Replies, o Source Address do MAC Virtual do AVF atribuido. Ou seja, se o AVF atribuido fosse o AVF#2, o AVG iria enviar o seu MAC Address no campo Source MAC Address.**

### Experiencia 2

- **Foi feito um ping do PC1 para o PC3 e o PC3 ficou com um mac virtual, e depois foi feito outro ping do PC1 para o PC4 e o PC4 ficou com um mac virtual diferente do que o PC3 tem no entanto com o mesmo IP virtual e é assim que é feito o loadbalancing**

![https://user-images.githubusercontent.com/12052283/142192771-e2df6fc6-08c8-4eb5-bc0b-c61399b4d625.png](https://user-images.githubusercontent.com/12052283/142192771-e2df6fc6-08c8-4eb5-bc0b-c61399b4d625.png)

- O GLBP nao permite alterar dinamicamente a priority por *object tracking*
- O *priority* no GLBP apenas server para saber quem faz de *Arp Replier* ou seja quem é o **AVG**
- **Num mecanismo de loadbalancing, o peso serve para saber que router vai ter mais trabalho, ou seja, se tivermos 2 routers com pesos diferentes, o router que tiver maior peso terá mais trabalho**
- Os tracking objects aqui mexem no peso (`weight`) dos routers para dizermos com que peso é que o router deixa de encaminhar por exemplo
    - "Se o peso descer abaixo de 8 já não encaminhas (**deixa de ser AVF**), se subir acima de 10 passas a encaminhar (**passa a ser AVF**)"
	
![https://user-images.githubusercontent.com/12052283/142194584-2b19ecf7-2954-4077-8cc1-ad82abba0623.png](https://user-images.githubusercontent.com/12052283/142194584-2b19ecf7-2954-4077-8cc1-ad82abba0623.png)

![https://user-images.githubusercontent.com/12052283/142194642-31f748d5-1f68-410b-8b99-da7bb49bb741.png](https://user-images.githubusercontent.com/12052283/142194642-31f748d5-1f68-410b-8b99-da7bb49bb741.png)
