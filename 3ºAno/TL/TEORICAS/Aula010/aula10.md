# Aula 21/12/2021

## QinQ

- Conhecida por VLAN dot1q tunnel
- Normalmente os *Service Providers* utilizam esta função para estabelecerem conectividade L2 (com VLANs) entre dois clientes
- **QinQ encapsula a VLAN privada da empresa na VLAN Pública, logo existe uma dupla marcação**

![image](https://user-images.githubusercontent.com/12052283/148048727-3864ece9-4b5a-4bc1-a636-41918abf3a3e.png)

![image](https://user-images.githubusercontent.com/12052283/148048803-3919dc97-bf58-49f9-9b85-f083e2e2f313.png)

- **No entanto aqui existem algumas limitações, por exemplo o facto das Provider Bridged Networks necessitarem de aprender os MACs dos seus clientes e suportarem apenas 4096 identificadores**

- Resolvemos este problema de os endereços mac estarem a propagar para dentro do ISP com o MACinMAC

### Evolução

![image](https://user-images.githubusercontent.com/12052283/148049092-d11779e9-69f2-4650-98f9-4ebfecbbede1.png)



## MPLS (Multiprotocol Label Switch)

- Utilizada em redes de alto-desempenho, direcionando o tráfego de um router para o próximo através da aplicação de rótulos (`labels`) aos dados, evitando as tradicionais pesquisas nas tabelas de encaminhamento

- LDP (`Label Distribution Protocol`) é o protocolo que dita quais são as labels
  - O protocolo combina as labels entre 2 routers apenas

- A tecnica dos identificadores usada no OSPF é praticamente igual no MPLS e precisamos de identificadores no MPLS
  - **Então no MPLS ele usa a maior das interfaces loopbacks ou então o maior endereço IP das interfaces fisicas**
  - **Então devemos sempre criar em cada router uma interface de loopback**

### Arquitetura

![image](https://user-images.githubusercontent.com/12052283/148050258-ac5172bf-eb25-47cd-bee8-d9c9e35440cb.png)

### Operação

![image](https://user-images.githubusercontent.com/12052283/148050338-3bc86550-ae52-4091-9799-e807acc822f1.png)

![image](https://user-images.githubusercontent.com/12052283/148050422-708c3421-58bd-42c0-b8e2-8440403cebaf.png)


### Configurar o MPLS

![image](https://user-images.githubusercontent.com/12052283/148050674-4995be90-d188-4255-b315-5355d9cdad55.png)

- A primeira fase para o MPLS é:
  - Configurar loopback em todos os routers que vão usar MPLS
  - Ativar o OSPF (nao esquecer de colocar tambem a loopback)

![image](https://user-images.githubusercontent.com/12052283/148050703-ae2db5b6-f9b2-4eaa-bc6c-b2dcbbff63ad.png)


- Segunda fase é configurar o LDP ao nível do processo OSPF

![image](https://user-images.githubusercontent.com/12052283/148050801-989194f8-9329-4c5b-915e-ba1486d6611f.png)


- Terceira fase é criar os rotulos do LDP

![image](https://user-images.githubusercontent.com/12052283/148050877-a04f4da0-c021-402b-8a4a-3737cf4def33.png)
