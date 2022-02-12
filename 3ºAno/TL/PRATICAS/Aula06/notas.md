# Aula P 16/11/2021 (Rascunho)
 
## Como é que funciona o STP?

- Em traços gerais, aquilo que o STP faz é eliminar logicamente caminhos de comunicação. Para tal o protocolo cria uma árvore de switches presentes na rede e elege o switch de referência, a partir do qual será criada a árvore.

No âmbito do protocolo STP, esse switch é denominado de **root bridge**. A eleição da **root bridge** é feita com base numa prioridade e também com base no Mac-Address. **Numa rede apenas pode existir uma root bridge**.

Tendo em consideração o exemplo, o SwitchA é eleito root bridge porque é o que tem **menor prioridade (por omissão, a prioridade é 32768)  e também o menor endereço físico (MAC address)**.

![image](https://user-images.githubusercontent.com/12052283/143689748-c498586d-5552-471c-85da-0ceb589e47cf.png)

Em seguida, cada switch, que não é root bridge, define qual é a sua **root port**. Esta interface é escolhida tendo em conta o **menor custo (tendo como base a largura de banda)** para a root bridge. Esta interface é colocada em modo de encaminhamento.

![image](https://user-images.githubusercontent.com/12052283/143689827-0e77b785-b879-4908-b358-3310ab8bee0c.png)

Por cada segmento, é definido uma **designated bridge**. Este será o switch com menor custo até à root bridge (no exemplo a seguir é o SwitchD). A interface de ligação com a root bridge é colocada no modo "encaminhamento". A porta do SwitchE é colocada em modo de bloqueio, fazendo assim o bloqueio das frames e evitando os loops na rede.

## Exemplo da Aula

- **Atenção que alteramos a rede do PC2 para .20 e a rede do PC3 para .10**


### Algoritmo STP

- Primeiro temos de eleger a **root bridge** (`switch principal`)
  - É eleito o que tiver o identificador mais baixo
  - No caso do exercicio da aula o RB é o SW5 porque nós queremos que seja

- Determinar a distância de cada bridge até à root bridge
  - A distância é a soma das distâncias entre cada bridge

![image](https://user-images.githubusercontent.com/12052283/144052804-d36c7d0c-317b-40c0-b8b3-377428e32d2d.png)


- Depois de calcular as distâncias temos de ver qual é a RP(`root port`), porta esta que é a porta que está ligada ao caminho escolhido no ponto `2.1`, ou seja, no caminho mais curto
  - Quando existe empates para escolher qual é a *root port* o caminho escolhido usa o vizinho com o *bridge ID* mais baixo
  - Em alguns casos continua a haver um empate por exemplo se o caminho escolhido tiver um caminho primário e um secundário, então nestes casos o desempate é feito pela porta mais baixa
	- Por exemplo se houvesse a e0/2 e a e0/3, ele iria escolher a porta mais baixa, ou seja a e0/2

![image](https://user-images.githubusercontent.com/12052283/144052893-ba167337-122b-4816-8719-a44320f1154e.png)

- Depois temos de calcular o melhor caminho a partir de cada segmento
  - A melhor vai ser designada por DP(`designated port`)
  - O truque é posicionarmo-nos a meio do link e ver qual é a melhor porta (`a que gasta menos`)
  - Quando vemos uma RP de um lado, a DP é a porta contrária

![image](https://user-images.githubusercontent.com/12052283/144053000-cef5ad1d-c27e-4f47-944d-fa832c64d736.png)

- Por fim bloqueamos todas as outras portas
  - Estas chamam-se BP (`blocked port`)
  - Basicamente são as portas que sobram que nao foram pintadas

![image](https://user-images.githubusercontent.com/12052283/144053167-46de3397-8f59-404c-a018-0ab81ff3ef8f.png)


- A spanning tree é então a junção dos pontos todos sem ser os das BP

![image](https://user-images.githubusercontent.com/12052283/144053218-b22be646-e0c3-4994-a766-39d72a4e5e37.png)

## Configuração do GNS3

### No SW5

- Configurar os trunks
- Colocar o vtp em modo transparente
- Criar a vlan 20 e dizer que ela é primaria e associar à 21
- Ir à vlan 21 e dizer que ela é comunitaria
- Ir à porta e0/0 e associar a vlan 21
- Criar o resto das vlans
- Colocar este SW como Root Bridge
- Criar o port channel na e2/1 e e2/0
- Forçar a bandwidth do port channel a 12 Mbps (como pede no enunciado)
- Baixar a prioridade da porta e1/3 para o trafego vir do SW1 pela porta e1/3 em vez de ir pela e1/1
  - Por omissão vem pela e1/1 porque e1/1 é mais pequeno que e1/3 (o tal segundo fator de desempate)

```console
int range e2/0-1,e1/1,e1/3
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

vtp mode transparent

vlan 20
private-vlan primary
private-vlan association 21

vlan 21
private-vlan community

int e0/0
sw mode private-vlan host
sw private-vlan host-association 20 21

vlan 99
vlan 30
vlan 10

conf t
spanning-tree-vlan 1,10,20,21,30,99 priority 4096

int range e2/0-1
channel-group 1 mode active

int po1
bandwidth 12000

conf t
int e1/3
spanning-tree port-priority 64
```

### No SW6

- Configurar a vlan 30
- Configurar os trunks
- Criar o STP
- Forçar e1/0 a ser a Root Port (como pede no enunciado) mudando o custo da porta
  - Reduzimos para 97 porque originalmente ela valia 100 entao temos de reduzir 3 para ir pela porta e1/0
  
```console
int e0/0
sw mode acc
sw acc vlan 30

int range e1/0-1,e0/3
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

spanning-tree vlan 1,10,20,21,30,99 priority 53248

int e1/0
spanning-tree cost 97
```

### No SW1

- Desligar o vtp
- Configurar a vlan privada 21 em modo community
- Configurar a e0/0 para usar a vlan privada
- Criar a vlan 99 (vlan nativa)
- Colocar o resto das portas em trunk
- Criar o resto das vlans
- Criar o STP
- Criar pool DHCP para vlan 10,20 e 30
- O SW1 é o DG da VLAN 20
- Configurar o RIP


```console
conf t
vtp mode transparent

vlan 20
private-vlan primary
private-vlan association 21
private-vlan community

int e0/0
sw mode private-vlan host
switchport private-vlan host-association 20 21

conf t
vlan 99

int range e1/0-3, e0/3
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

vlan 10
vlan 20
vlan 30

conf t
spanning-tree vlan 1,10,20,21,30,99 priority 12288

ip dhcp pool pool10
network 192.168.10.0 255.255.255.0
default-router 192.168.10.254
dns-server 192.168.100.1
ip dhcp pool pool20
network 192.168.20.0 255.255.255.0
default-router 192.168.20.254
dns-server 192.168.100.1
ip dhcp pool pool30
network 192.168.30.0 255.255.255.0
default-router 192.168.30.254
dns-server 192.168.100.1

ip routing
interface vlan 20
ip add 192.168.20.254 255.255.255.0
private-vlan mapping 21

router rip
network 0.0.0.0
```
### No SW3

- Configurar os trunks
- Ativar o VTP
- Criar o resto das vlans
- Criar o STP
- Alterar a bandwith entre o SW3 e o SW4 (como pede no enunciado)
- Criar o port channel na e2/1 e na e2/0
- Forçar a bandwidth do port channel a 12 Mbps (como pede no enunciado)

```console
conf t
int range e1/1-3,e2/0-1,e0/3
sw trunk encapsulation dot1q
sw trunk nativa vlan 99
sw mode trunk

vtp mode server
vtp domain TL

vlan 10
vlan 20
vlan 99

spanning-tree vlan 1,10,20,21,30,99 priority 20480

int e1/1
bandwidth 100000

int range e2/0-1
channel-group 5 mode active

int po5
bandwidth 12000
```
### No SW2

- Configurar os trunks
- Configurar a vlan 10
- Criar o STP

```console
conf t
int range e1/0-3
sw trunk encapsulation dot1q
sw trunk nativa vlan 99
sw mode trunk

int e0/0
sw mode access
sw access vlan 10

spanning-tree vlan 1,10,20,21,30,99 priority 36864
```

### No SW4

- Configurar os trunks
- Criar o STP
- Alterar a bandwith entre o SW4 e o SW3  (como pede no enunciado)

```console
conf t
int range e1/0-2,e2/0
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

spanning-tree vlan 1,10,20,21,30,99 priority 45056

int e1/1
bandwidth 100000
```

### No SW7

- Configurar o trunk
- Criar o STP
- Configurar a rede .100 de modo a desligar o L2 do switch para passarmos de nível 2 para nível 3
- Configurar o RIP

```console
int e0/3
sw trunk encapsulation dot1q
sw trunk native vlan 99
sw mode trunk

spanning-tree vlan 1,10,20,21,30,99 priority 28672

int e1/1
no switchport
ip add 192.168.100.7 255.255.255.0
no shut

router rip
network 0.0.0.0
```

### No R1

- O R1 é o DG da vlan 10 e da vlan 30 (`porque só temos 1 cabo, logo temos de criar sub interfaces virtuais`)
- Dar ip à e1/1 que está ligada ao SW7
- Configurar o RIP

```console

conf t
int e1/0
no shut
int e1/0.10
encapsulation dot1q 10
ip add 192.168.10.254 255.255.255.0
int e1/0.30
encapsulation dot1q 30
ip add 192.168.30.254 255.255.255.0

int e1/1
ip add 192.168.100.1 255.255.255.0
no shut

router rip
network 0.0.0.0
```

### No R2

- Pedir ip por dhcp
- Configurar o NAT
- Configurar link com R1
- Configurar o RIP

```console

conf t
int e0/0
ip add dhcp
no shut

int e0/0
ip nat outside
exit
access-list 10 permit any
ip nat inside source list 10 interface e0/0 overload

int se2/0
ip add 172.16.10.2 255.255.255.0
ip nat inside
no shut

router rip
network 172.16.0.0
default-information originate
```

## Notas

- Uma coisa é termos um port channel em que duas ligações representam apenas 1 , outra coisa é termos um caminho primário e outro secundário

![image](https://user-images.githubusercontent.com/12052283/142015968-3cb02277-a1dc-4ecb-b143-6e6818c97889.png)

- Devemos eleger uma RB que esteja no meio da empresa

- `sh spanning-tree vlan <nr da vlan>` -> mostra o STP da respetiva vlan

- A prioridade no spanning tree nao pode ser definida com um número qualquer, tem de se usar ou o `0` ou o `4096` ou o `8192` e assim sucessivamente até `61440`
  - No caso do exercicio usamos as prioridades consoante o ponto 3 da parte vermelha da topologia do GNS3

## Referências

- https://pplware.sapo.pt/tutoriais/redes-sabe-o-que-faz-e-como-funciona-o-spanning-tree-protocol/

- https://www.youtube.com/watch?v=japdEY1UKe4
