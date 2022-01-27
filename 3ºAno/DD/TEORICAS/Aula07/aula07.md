# Aula 10/12/2021

## Qualidade de Serviço (QoS)

- Existem 3 serviços que queremos disponibilizar na rede
  - voz
  - video
  - dados

- O caminho da indústria foi usar todos estes serviços no mesmo canal, no entanto para isso foi preciso distinguir o tipo de dados que circula na rede para depois saber o que fazer com os mesmos

**Então o problema é, como é que consigo usar estes 3 serviços diferentes na mesma rede????**

### Best Effort

![image](https://user-images.githubusercontent.com/12052283/146089403-2ce4ad26-7f51-4c3c-974f-b5dfb62bc916.png)

- **A internet sempre trabalhou com o *best effort* no entanto esta maneira não permite a integração dos serviços todos**
- No *best effort*, a rede IP tenta encaminhar o tráfego o mais rápido possível sem assegurar qualquer garantia quantitativa ao mesmo
- **Por exemplo**
  - Tenho um pacote de voz e depois tenho um pacote com um ficheiro .iso. Os pacotes de voz são então afetados caso o .iso seja demasiado grande

- Uma solução tentada foi a chamada *over-provisioning* em que basicamente tenta-se manter a oferta de largura de banda acima da procura

- Então o IETF criou o **IntServ** e o **DiffServ**
  - **IntServ** -> Um fluxo é admitido na rede se esta o puder suportar
  - **DiffServ** -> Um fluxo é marcado para tratamento diferenciado


![image](https://user-images.githubusercontent.com/12052283/146088409-a439fd85-d3de-4a74-b5c6-21f259e3fede.png)


## IntServ

- O **IntServ** não consegue ser implementado como foi pensado, ou seja, só é bom no papel uma vez que é restrito


![image](https://user-images.githubusercontent.com/12052283/146089634-ec11feae-e2f1-4f2c-b133-1528152d24b5.png)

### Problemas

![image](https://user-images.githubusercontent.com/12052283/146089797-6197487e-cdc2-4ed3-addd-0a848fef6421.png)


## DiffServ

- O **DiffServ** na teórica e na prática funciona uma vez que é menos restrito. Em que basicamente em vez de se focar nos fluxos, a atenção é posta nas classes de tráfego suportadas

![image](https://user-images.githubusercontent.com/12052283/146090090-379f2ddb-6100-4d8e-aec3-9281768813ea.png)

### Funcionamento

- Basicamente classifica o pacote
  - "Este pacote é uma chamada de voz" (**Class of Service**)
  
- Dentro da rede não existe nenhum equipamento a dizer que já está sobrecarregado e não consegue lidar com um certo pacote, mas sim equipamentos configurados para sabere o que conseguem fazer, ou seja, se conseguem lidar com voz, dados ou vieo.

- Então, **o segredo não é não deixar entrar na rede, mas sim marcar trafego com aquilo que a rede tolera**
- Para isto temos de configurar a rede, testamos, se não houver problema está tudo bem. 
  - Se algum cliente se queixar, vemos onde está o problema, se precisarmos de mais acesso para voz, configuramos então o equipamento responsável pela voz.

- **Per Hop Behaviour** é entao dentro da rede, a complexidade passa a ser indexada ao número de classes e não ao númro de fluxos que atravessam a mesma

- **Existem então filas na entrada, em que cada fila representa um dos 3 serviços**
- **Depois existe um router que classifica o serviço do pacote que quer entrar e depois o equipamento responsável por certo serviço, recebe e trabalha-o**
- **Vai haver tambem uma fila de "urgências" que serve o tráfego mais prioritario**

![image](https://user-images.githubusercontent.com/12052283/146094753-ab2c2559-1edf-4f6a-b437-6c53005892cf.png)

- Entra um pacote, é classificado ou pode ser medido
- Se for classificado vai para o *marker*
- Se for medido é visto se é *trusted*, se sim é markado, se for *untrusted*  vai para o *marker*
- No *marker* pode ser *shaper* ou *dropped*, se for *shaper* é porque foi aceite, se for *dropped* é porque não foi aceite

- **Normalmente os switches da camada de acesos é que têm o trabalho da marcação do trafego, todos os outros equipamentos da rede confiam neste tráfego uma vez que é marcada por um switch importante**
- Esta marcação é feita no quadro/pacote
- Funciona em L2 e L3

![image](https://user-images.githubusercontent.com/12052283/146091380-6da8e761-d972-4114-a409-7ffbd822dea8.png)

![image](https://user-images.githubusercontent.com/12052283/146092281-df6bf49d-d369-422f-b930-67c02279994c.png)

![image](https://user-images.githubusercontent.com/12052283/146092329-4b412985-be98-4d59-b2aa-dfed51f2a2f8.png)


#### Classes de Serviço

![image](https://user-images.githubusercontent.com/12052283/146091807-25704855-0411-4213-a8d3-ebfe23388b07.png)



### Arquitetura

![image](https://user-images.githubusercontent.com/12052283/146090390-e4fe7289-cf12-4565-9ee1-77f89eb090da.png)

