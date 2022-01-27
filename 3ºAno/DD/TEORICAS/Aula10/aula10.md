# Aula 14/01/2022 

## Agregação de ligações

- Mecanismo capaz de aproveitar múltiplos links diretos entre um par de equipamentos para aumentar a largura de banda agregada útil entre ambos

- **Para isto funcionar tem de haver 2 pressupostos**
  - Entrega em sequência, ou seja, sai A e B e chega A e B, pela ordem que sairam é pela ordem que têm de chegar
  - Não haver duplicação de quadros
  - Os links têm de ser do mesmo débito
  - Nao pode haver ligações redundantes de débitos iguais, ou seja, se tiver uma ligação redundante a 10Mbs nao posso ter outra a 10Mbs
  
- **Por omissão, o STP coloca todos os links redundantes em Blocking e com isso há o desperdicio de recursos**

![image](https://user-images.githubusercontent.com/12052283/150364685-b4ffa62a-fa60-4622-9035-3ade5e3cbca7.png)

## IEEE 802.3ad Link Aggregation Protocol

- É norma aplicável à tecnologia Ethernet que permite a agregação de links de qualquer débito

- Sendo assim restringe a agregação a 
  - **envolver apenas links com igual débito**
  - **para um mesmo débito ser a unica ligação existente**

- **Depois esta norma foi enviada para o IEEE 802.1AX uma vez que tinha algumas incoerencias com outros protocolos e a partir daqui foi usado o nome IEEE 802.1AX em vez de 802.3ad**

### Agregador

- Alberga **n** portas agregadas como uma **meta-porta**
  - Se existir um único agregador por equipamento e todas as portas se lhe encontrarem associadas materializa-se uma agregação global, por exemplo os NICs.

- Limitações de hardware podem impor restrições sobre o conjunto de portas que se encontram integradas num dado agregador

![image](https://user-images.githubusercontent.com/12052283/150366127-e3aea67e-197d-4f82-86dc-2a7fe6c151da.png)

### Endereçamento

- A agregação comportando-se como uma porta normal para os clientes MAC (por exemplo ARP), terá que possuir endereço MAC unicast único

- O agregador deve então programar os níveis MAC agregados com tal endereço para obter o comportamento desejado


### Key

- É o conjunto de portas que uma certa porta agrega

- **Cada equipamento vai atribuir uma key a portas que são agregáveis**

- **Por exemplo, se quisermos agregar, o algoritmo vai ver se as keys das portas que queremos agregar têm a mesma key, se tiverem é porque podemos agregar essas portas**

### Função de distribuição

- Processoa a classificaão de quadros em diálogos
- Quanto mais profunda a classificação, mais efetivo se torna o balanceamento
  - **A classificação SA/DA é suficiente para ligações switch-switch mas inutil em cenarios de switch-router**

### Protocolo de marcação

- **Durante a vida da agregação, pode ser necessário mover conversações (por exemplo, adição ou remoção de links)**
- **Para assegurar permanentemente a entrega ordenada os extremos da ligação recorrem ao Marker Protocol**

![image](https://user-images.githubusercontent.com/12052283/150368345-224053e0-c0bc-4811-80de-999df8f28085.png)

### Link Aggregation Control Protocol (LACP)

- Apesar de se poder controlar manualmente a inclsuão e exclusão de portas numa agregação, o LACP automatiza este processo

- **O funcionamento dele é parecido à operação do STP**
  - Os dispositivos geram periodicamente informação acerca das capacidades de agregação nos seus links e processam os anuncios escutados

- **As agregações podem apenas ser constituidas por links que terminem no mesmo equipamento**
  

![image](https://user-images.githubusercontent.com/12052283/150369107-687ffb8e-726b-49ae-8897-9a805a0acd32.png)

- **Por limitações de hardware/débito/gestão nem todos os links são agregaveis, no entanto os links agregaveis recebem a mesma key(16 bits)**

![image](https://user-images.githubusercontent.com/12052283/150369619-04041529-b69c-4602-90be-eaa9e6d41666.png)

![image](https://user-images.githubusercontent.com/12052283/150369871-e3454412-3fbf-4c08-bc4e-332db054177f.png)

### IEEE 802.1AX(IEEE 802.3ad) Limitações

- Esta norma fornece uma solução melhor ao STP uma vez que permite acrescentar desempenho ao aumento de disponibilidade, no entanto a mesma encontra-se limitada a ligações entre dois equipamentos e portanto é capaz de suportar apenas falhas de ligações e não suporta falhas no próprio switch. Para isto foi introduzid o SMLT

## Split Multi-Link Trunking (SMTL)

- A ideia era tratar dois switches da rede como um único perante os restantes switches
- Efetuar ligações em dual-homing dos switches perifericos à agregação criada

### InterSwitch Trunk 

- **Deve ele proprio ser uma agregação de ligações para não existir nenhum single-point-of-failure**

- Troca de informação de estado das ligações
- Troca de informalão relativa à aprendizagem de MAC Addr
- Potencial troca de quadros

![image](https://user-images.githubusercontent.com/12052283/150371603-a782eee8-46ec-4a8e-94da-ca7a038b8fef.png)
