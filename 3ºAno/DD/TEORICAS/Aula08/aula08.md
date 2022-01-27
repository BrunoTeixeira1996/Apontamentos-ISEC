# Aula 17/12/2021

- No protocolo IP existe um campo chamado **Type Of Service** para o DiffServ

- Para o IPv6 existe o **Traffic Class**
  - No IPv6 existe o *Flow Label* que permite apanhar um pacote e ver a que fluxo pertence

## Acondicionamento do DiffServ

### Per-Hop Behavior

- **Default**
  - É o único comportamento cuja implementação é obrigatória
  - Absorve todo o tráfego que não se enquandra noutra classe
  - Serviço *Best Effort*

- **Expedited Forwarding (EF)**
  - Serve tráfego com requisitos de tempo real: voz e video
  - Latência, perdas e jitter reduzidos

- **Assured Forwarding (AF)**
  - A entrega é assegurada se não forem excedidos débitos subscritos
  - Aqui podem haver 4 classes com tratamentos diferentes

![image](https://user-images.githubusercontent.com/12052283/148056227-4d627bb8-f3ee-4983-8307-8128d8e29233.png)

- **Class Selector**
  - Solução que o IETF propoe para menter compatibilidade com o tratamento do campo de 3 bits que antes se denominava *Precedende*

![image](https://user-images.githubusercontent.com/12052283/148056332-4451c4b4-014e-44fc-a00a-9c41d812d058.png)

- Mapeamento da marcação L2(VLAN PCP) <-> L3(DSCP)
  - POdemos reescrever a tabela de marcação, tanto de L2 para L3 como ao contrário

![image](https://user-images.githubusercontent.com/12052283/148056448-29a0eccc-1cdb-4945-b931-a3abd8f3f58a.png)

## Delay

- Tempo perdido do envio até à trnasmissão
- O delay é das coisas mais complicadas de combater

## Jitter

- Diferença de atraso que um pacote tem em relação ao seguinte

## Configurar o DiffServ

- O melhor para configurar o DiffServ é começarmos com poucas classes e irmos testando a rede
- Depois, consoante os requisitos da rede, vamos aumentando a complexidade aumentando assim o nº de classes

![image](https://user-images.githubusercontent.com/12052283/148056766-2a626c9f-2a16-4e26-a702-b99a9c94c52f.png)

## Desvantangens do DiffServ

- Não permite às aplicações saberem se estão a receber da rede a QoS desejável
- Modelo que funciona bem com transferências curtas (web browsing) mas que oferece um desempenho pobre em aplicações de tempo real
- Pensado para redes relativamente estáticas
- Dificil de redistribuir recursos pelas classes geridas
- **Garantias de QoQ associadas a uma classe não se traduzem necessáriamente em garantias dadas a um fluxo (os fluxos de uma mesma classe poderão interferir entre si)**
