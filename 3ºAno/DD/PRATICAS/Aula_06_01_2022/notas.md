# Aula 06/01/2022

## Topologia MultiAttachment

- O comando *redistribute static* redistribui tudo o que são rotas estáticas

### Problema 1

- No inicio temos um serviço stateful por isso é que se pingassemos de dentro da empresa para fora funcionava, mas quando voltava ia para o R2 e o R2 nao tem a entrada NAT para receber o Reply (pag.113)
  - As coisas falham porque o caminho é assimétrico (a saida é um caminho e a entrada é outro caminho)

- Se estamos a usar um serviço com estado e queremos aumentar a redundância do mesmo temos de sincronizar os estados

### Solução do problema 1

![image](https://user-images.githubusercontent.com/12052283/148397486-78a7f950-badf-4845-9f85-6953e9bcfe02.png)

- Na pagina 120 tem uma experiencia com o HSRP mas isso nao funciona porque o RIP nao trabalha com o Virtual IP

### Problema 2

- Se quisermos chegar à Internet pelo R2 mas a interface do RISP esteja em baixo, nós queremos que o R2 saiba que nao pode anunciar a sua rota 0.0.0.0 e isso pode ser feito com o object tracking

### Solução do problema 2

- Criamos uma sonda no R2 para confirmarmos que o caminho para o exterior a partir do R2 é ou não operacional
  - Temos de usar o *source-interface* sendo este a interface que liga diretamente ao ISP
  - Depois criamos um tracking object que é o element que vai viajar a sonda
  - Depois reescrevemos a rota estatica com o tracking object criado

- No R2

```console
conf t
sla 1
icmp-echo 1.1.1.1 source-interface e0/1
frequency 10
timeout 5000
exit
exit
ip sla schedule 1 life forever start-time now
track 3 ip sla 1 reachability
ip route 0.0.0.0 0.0.0.0 194.65.52.9 track 3
```

- *sh ip sla statistics* Mostra as estatisticas da sonda criada

- Mas depois de fazer isto, **temos um problema de dependencia circular** em que a sonda precisa do 0.0.0.0 e o 0.0.0.0 precisa da sonda

- Então eu posso criar no router uma rota especial para o destino **e0/1** e esta entrada vai sempre ser usada antes da entrada dos  0.0.0.0

- No R2(corrigindo a dependencia circular)

```console
conf t
ip route 1.1.1.1 255.255.255.255 194.65.52.9
```

- A partir deste momento fico com o pequeno problema na mesma em que o 1.1.1.1 não está protegido pelo tracking object

- **Foi feita a mesma configuração mas no R3**

## Stateful NAT

- Protocolo usado para sincronizar tabelas de NAT

