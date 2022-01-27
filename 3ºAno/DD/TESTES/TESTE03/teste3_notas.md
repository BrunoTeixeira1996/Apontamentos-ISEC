# Teste 03

## HSRP - Dois routers no mesmo grupo com IPs virtuais diferentes + autenticação (Topologia 1)

Ao configurar os dois routers do mesmo grupo HSRP com IPs virtuais diferentes, acontece que o último router a ser configurado, mantem-se em Standby Router, no entanto está sempre a mostrar no seu *output* que existe uma má configuração sendo que esta má configuração não permite a comunicação do IPterm-1 para o IPterm-2.

Na autenticação ocorre o mesmo problema, ou seja, se um router tiver autenticação ligada, o seu SR tambem tem de ter essa autenticação com a chave correta, caso contrário não é feita a comunicação.

![image](https://user-images.githubusercontent.com/12052283/141144614-682d447c-5fe3-47dd-abb0-6732692a64a2.png)

## VRRP

Nos PCs configuramos exatamente igual ao HSRP, ou seja, colocamos o **DG** com o IP virtual definido no grupo

No R1 configuramos a interface e0/0 para usar o mesmo IP de R1 (`vrrp 1 ip 192.168.100.254`) assim como autenticação em MD5 (`vrrp 1 authentication md5 key-string EsteEOMeuSegredo`

![image](https://user-images.githubusercontent.com/12052283/141158379-77547232-8e31-4ab9-a7ea-6600a15f4070.png)

Agora desativamos o VRRP e voltamos a fazer tudo de novo mas com os *object tracking* ativos e com o IP Virtual global, ou seja para a Rede A `192.168.100.100` para a rede B `192.168.200.100` 

Depois do R1 ficar a Master, apenas este emite tráfego de 1 em 1 segundo, ao contrário do HSRP que tanto o AR como o SR transmitiam tráfego de 3 em 3.


- No R1

```console
conf t
track 1 interface e0/1 line-protocol
exit
track 2 interface e0/0 line-protocol
exit
int e0/0
vrrp 1 ip 192.168.100.100
vrrp 1 priority 105
vrrp 1 track 1
int e0/1
vrrp 1 ip 192.168.200.100
vrrp 1 priority 105
vrrp 1 track 2
```


- No R2

```console
conf t
track 1 interface e0/1 line-protocol
exit
track 2 interface e0/0 line-protocol
exit
int e0/0
vrrp 1 ip 192.168.100.100
vrrp 1 priority 100
vrrp 1 track 1
int e0/1
vrrp 1 ip 192.168.200.100
vrrp 1 priority 100
vrrp 1 track 2
```

![image](https://user-images.githubusercontent.com/12052283/141160059-f541eea7-03d3-4fc6-8c57-156b78773a43.png)


![image](https://user-images.githubusercontent.com/12052283/141160720-d61b640a-27b8-42ca-825e-20b6f10508b4.png)

### Injetar uma falha no R1 e0/0

Depois de injetada a falha no R1 e0/0 e como temos o *tracking object* , o mesmo decrementa em 10 a sua prioridade (era 105 passou a 95) e então o que acontece é que o R2 passa a ser Master tanto na Rede A como na Rede B, tolerando assim uma falha no R1.

Depois da falha o R1 passa a ter a interface e0/0 como Init e a interface e0/1 como Backup

![image](https://user-images.githubusercontent.com/12052283/141162431-351f0d83-83b9-4b15-a6f7-3740679f7263.png)

Quando voltamos a ligar a interface e0/0 do R1 o mesmo volta a ser Master porque a preemptividade no VRRP vem ligada por omissão e a sua prioridade torna-se novamente 105.

### Ultima mensagem que o Master envia antes de sair do grupo

Antes do Master sair do grupo, ele envia uma mensagem a dizer que a sua prioridade ficou a 0 e que ja não faz parte do VRRP e na rede do lado a sua prioridade baixa

![image](https://user-images.githubusercontent.com/12052283/141163600-9a70a90c-cb02-4b86-ab83-745bd634b45f.png)

## HSRP

### HSRP e Tracking Objects


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


### HSRP e Autenticação

Configurei o R11 e o R10 com a versao 2 do hsrp e em baixo esta um exemplo

![image](https://user-images.githubusercontent.com/12052283/140102395-f2f58ad7-3f49-49ab-a95c-905402a5f1b2.png)

Depois foi só configurar uma interface para usar a autenticação como mostra em baixo

![image](https://user-images.githubusercontent.com/12052283/140103479-2cc3ec3b-2b02-4578-95a5-32a418ded01e.png)
