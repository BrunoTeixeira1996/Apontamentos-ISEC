# Aula T 29/10/2021

- Na ultima aula vimos o HSRP, no entanto o mesmo continuava a ter algumas falhas, principalmente na parte da redundância, uma vez que tinhamos de fazer vários "truques" para a rede continuar operacional e não haver um SPOF

- Vimos tambem que o HSRP pode ter mais desempenho se tivermos por exemplo 2 grupos, no entanto isto é uma configuração dificil de ser feita e não vale a pena irmos por este caminho

- Então porque não ter 2 routers ativos em vez de 1 só?

![image](https://user-images.githubusercontent.com/12052283/140057111-9e78471e-52ff-4d9e-ab44-2207f48263e2.png)

- A solução nova é então um serviço responsável pelos ARP Replys e outro ser responsável pelos IPs, no entanto temos na mesma de ter cuidado com o SPOF

- Ou seja, quem estiver (router) responsável por encaminhar IPs tem de ser vigiado porque pode ir à vida e deixar de dar

- Aqui entra então o GLBP (**Só podem haver 4 routers no máximo**)

## GLBP (Gateway Load Balancing Protocol)

- Versão melhorada do HSRP que suporta explicitamente *load balancing* sem a necessidade de configurar múltiplos grupos e múltiplos DGs em clientes distintos

- Em vez de um, podem ser usados simultaneamente até 4 routers a desempenhar a tarefa de DG

- Todos partilham o mesmo endereço IP Virtual

- Todos recorrem a um endereço MAC Virtual distinto

- Sendo que este protocolo suporta o *failover* dos membros como o HSRP já fazia

- **Tal como o HSRP, corre sobre UDP no mesmo grupo multicast mas num porto distinto**

### Funcionamento do GLBP

- Os membros do grupo GLBP elegem um elemento como AVG (*Active Virtual Gateway*)
  - O AVG atribui um MAC Virtual a cada membro do grupo
  - Estes tornam-se AVF (*Active Virtual Forwarders*)
	- São no máximo 4 e passam a ter responsabilidade de encaminhar tráfego enderelado para o seu Virtual MAC
  - O AVG responde aos **ARP Requests** dirigidos ao IP Virtual
  - Os AVFs estão sempre disponíveis como backup do AVG

### Em caso de falha de um AVF

- Um dos SVF (*Secondary Virtual Forwarders* -> router que aprende o MAC Virtual através da escuta passiva das mensagens de Hello do AVG) toma temporariamente a responsabilidade de PVF
- Durante *Redirect Time* o AVG continua a enviar ARP Replies para o MAC Virtual perdido
  - Após esse tempo expirar o AVG cessa a utilização do MAC Virtual mas o AVF substituto continua a encaminhar trafego que lhe é remetido com o "MAC Virtual perdido"
  - Quando o *Holdtime* expirar o "MAC perdido" volta a estar disponivel para o AVG atribuir
  - Sendo que estes *timers* são comunicados nas mensagens de *Hello* do AVG
- Aqui há preemptividade por omissão mas a retoma é atrasada em 30 segundos

### Em caso de falha de um AVG

- Se um AVG for à vida um AVF(o que tiver a maior prioridade) torna-se o novo AVG, no entanto se o antigo AVG voltar a estar operaconal ele fica na mesma AVF ou seja, não ha preemptividade por omissão
