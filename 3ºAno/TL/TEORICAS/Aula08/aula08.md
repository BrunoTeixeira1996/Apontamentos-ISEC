# Aula 07/12/2021

## RSTP

- Evolução do STP

- O STP tem quatro estados (`block,listening,forward,learning`) e o RSTP tem 3 estados(`discard, listening, learning`) (pag.80)

- O RSTP é mais rápido que o STP porque nao deita as interfaces todas abaixo. No processo de *Proposal/Aggremment* ele nao vai bloquear todas as portas, apenas bloqueia a porta da frente do link que está a negociar

- Portas do tipo *Edge*
  - São as portas que estão viradas para os PCs
  - Temos de configurar isto como mostra em baixo com `spanning-tree portfast`

![image](https://user-images.githubusercontent.com/12052283/145883173-b405007e-4d38-44d2-b1fb-1872ada3e1d2.png)


- Temos tambem de configurar se os trunks sao point-to-point(full-duplex) ou shared(half-duplex)
  - Como os switches são full-duplex usamos o comando `spanning-tree link-type point-to-point` dentro da interface trunk

- **Usamos este no TP**


### Configurar o RSTP numa rede com 3 switch em ciclo

#### No SW1

```console
spanning-tree mode rapid-pvst
int range e0/1-3 
sw trunk encapsulation dot1q
sw mode trunk
int e0/0
sw mode acc 
spanning-tree portfast
int range e0/1-3
spanning-tree link-type point-to-point
```

#### No SW2

```console
spanning-tree mode rapid-pvst
int range e0/1-3 
sw trunk encapsulation dot1q
sw mode trunk
int e0/0
sw mode acc 
spanning-tree portfast
spanning-tree link-type point-to-point
```

#### No SW3

```console
spanning-tree mode rapid-pvst
int range e0/1-3 
sw trunk encapsulation dot1q
sw mode trunk
int e0/0
sw mode acc
spanning-tree portfast
spanning-tree link-type point-to-point
```

