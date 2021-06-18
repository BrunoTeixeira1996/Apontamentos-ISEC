# Rede A `192.168.10.0/24`
## R1 -> `f0/0`->`192.168.10.254`
## Servidor de DNS -> `192.168.10.1`
## PC1 -> `192.168.10.50`
## PC2 -> `192.168.10.51`


# Rede B `192.168.20.0/24`
## R2 -> `f0/0`->`192.168.20.254`
## Servidor B -> `192.168.20.1`


# Sub-rede entre os dois routers `192.168.30.0/24`

## A sub-rede deve apenas ter dois hosts

`Nr de hosts -> 2^n - 2 >= 2, n = 2 -> 2 bits para o Host ID, NetID = 32 - 2 = 30`

`Mascara de rede -> era /24, passou a /30, logo 6 bits para SubnetID`

## R1 -> `s0/0` -> `192.168.30.1/30`
## R2 -> `s0/0` -> `192.168.30.2/30`

# Perguntas

## Qual o endereço IP do PC1? e a máscara de rede?
`192.168.10.50/24, 255.255.255.0`

## Qual o default gateway que deve colocar em todas as máquinas da rede A?
`192.168.10.254/24`

## Qual o endereço que deve colocar na interface do router que liga à rede A?
`192.168.10.254/24`

## Qual é a identificação da rede B?
`192.168.20.0/24`

## Qual o endereço IPdo servidor da rede B?
`192.168.20.1/24`

## Qual o endereço de broadcast da rede A? E o da rede B?
`192.168.10.255/24`

`192.168.20.255/24`

## Qual a rede que deve usar para as interfaces serial dos routers?
`192.168.30.0/30`

## Qual a máscara de rede dessa rede?
`/30 ou 255.255.255.252`

## Que endereços deve colocar nos interfaces serial dos router? 
`R1 -> s0/0 -> 192.168.30.1/30`
`R2 -> s0/0 -> 192.168.30.2/30`


## Se desejar usar a próxima rede, qual a sua identificação? E qual o primeiro endereço disponível? E qual o endereço de broadcast?
`
192.168.30.4 -> Identificacao da rede
192.168.30.5 -> 1º Endereço util
192.168.30.7 -> Endereço Broadcast
`
