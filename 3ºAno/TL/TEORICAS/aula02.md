# Aula 19/10/2021

## Conceito de VLANs

- Podemos entender as VLANs como um conjunto de redes independentes a funcionar sobre o mesmo switch e independentes da posição geográficas

- VLAN é então um **domínio de difusão**

## VLAN Nativa

- Por omissão o trafego considrado por um switch na VLAN Nativa  de um trunk, sai para esse trunk como *untaged*

- O trafego *untaged* que entra por um trunk é considedo, pelo switch, na VLAN Nativa desse trunk

## VLANs Privadas

- Um conceito importante e que tambem pode ser útil é o conceito de VLANs Privadas

- Uma VLAN Privada é termos várias VLANs dentro de uma VLAN ou seja, seguementar ainda mais uma rede

- Este conceito é um conceito de **L2** no modelo OSI

## Latência

- A latência mede-se como o tempoq que um bit demora a percorrer desde o terminal origem até ao terminal de destino

- A latência depende sempre da distância e do equipamento em si

## Tipos de switch

### Store and Forward

- Um switch é **store and forward** quando o mesmo lê o quadro todo de uma vez sendo que só no final é que sabe para onde tem de enviar o "pacote"

### Cut Through

- Um switch é **cut through** quando o mesmo lê uma parte do quadro(até ao *destination address*) sabendo já aqui para onde tem de enviar o "pacote"

### Switch assimétrico

- Existe mais banda larga no *uplink*

### Switch simétrico

- A largura de de banda que percorre os links é sempre a mesma

![image](https://user-images.githubusercontent.com/12052283/138261177-527436d3-324f-47b2-a3ed-5b33da4e3aee.png)


### Esquemas de buffering

- Atualmente os switches são do tipo *shared memory*

- Este tipo de switch tem uma memória partilhada por todas as portas sendo que a quantidade de memória por porta atribuida é de maneira dinâmica

## Modo Access

- O trafego do switch para o PC é considerado **trafego não marcado** -> **Modo Access**

- Ou seja, os links que estão ligados do switch aos PCs são configurados com **modo access**

## Modo Trunk

- O trafego do switch para fora é considerado **trafego marcado** -> **Modo Trunk**

- Os links de trunk são usados para transportar tráfego de várias VLANs ao mesmo tempo, sendo que os quadros que trafegam por essa porta são identificados através da **TAG**

![image](https://user-images.githubusercontent.com/12052283/138264557-91fb1d13-061b-4f71-99ab-5294ee06bee1.png)

## VoIP

- Se tivermos VoIP e um PC ligado a um switch (o PC liga a sua tomada ethernet ao telefone e o telefone liga ao switch), o switch vai mandar **trafego não marcado** para o PC e **trafego marcado** para o VoIP

- Sendo assim teriamos de configurar o switch de modo a enviar trafego marcado e trafego não marcado

### No switch

- **Trafego não marcado para o PC**

```console
int f0/20
switchport mode access
switchport access vlan 10
```

- **Trafego marcado para o VoIP**

```console
switchport voice vlan 110
```

- Por fim teriamos de configurar o router de modo a trabalhar com VoIP

# Referências

- https://www.youtube.com/watch?v=3HWCqS-uU84
