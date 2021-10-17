# Aula 15/10/2021

- Esquema da aula feito em GNS3

## Funcionamento dos cabos na sala de rede

- Escolhemos os routers e colocamos papeis em cima dos mesmos

- Ligamos uma *FastEthernet* do **router** ao **switch** (representa a ligação do router ao switch)

- Do **switch** ligamos à régua no **1I** (representa a ligação do switch a um PC)

- No lugar ligamos do **1I** a um **PC** (representa a ligação do switch a um PC)

- Caso **usemos um FTDI**

	- No router ligamos um **cabo normal** à consola até à régua no **2A**

- Caso **não usemos FTDI**

	- No router ligamos um **cabo azul** à consola até à régua no **2A**

- No lugar ligamos do **2A** a um **PC** com o cabo **FTDI** (representa a ligação do PC ao router, PC que vai configurar o router)

**Muito importante saber é que nas ligações entre routers (ligações serie) temos de fazer o clock rate a um dos routers na porta serie, caso contrário nada funciona**

## Referências

-