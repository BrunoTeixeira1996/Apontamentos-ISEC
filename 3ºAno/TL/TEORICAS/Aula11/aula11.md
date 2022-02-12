# Aula 04/01/2022

## Exame 13 Fev 2020

R1-R2-R3-R4 -> MPLS

### Pergunta 9

- Primeiro ver se é o penultimo
  - se sim é logo null
  - se nao é ver o router que recebe e ver qual é a label dele

------------------------------------------------------------------------------

R1-R2 -> **label 202**
- É do R1 para o R2 logo é  a label que o 2 usa e estamos situados no R2
R2-R1 -> **label 116**
- É do R2 para o R1 logo é a label que o 1 usa

------------------------------------------------------------------------------

R2-R3 -> **label 302**
- É do R2 para o R3 logo é a label que o 3 usa

R3-R2 -> **label 213**
- É a label que o 2 usa logo é a local

------------------------------------------------------------------------------

R3-R4 -> **null** porque é o penultimo 
R4-R3 -> **312** porque é a marcação que o 3 usa

------------------------------------------------------------------------------

### Pergunta 10

R1-R2
- Vemos o 4.4.4.4 porque é do PC1 para o PC6
  - Exterior é a **206** que é a MPLS
  - Interior é a do tunel que é a **400**

R2-R1
- Interior é a do tunel que é a **100**
- Vemos o 1.1.1.1 porque é do PC6 para o PC1
  - Exterior é **null** porque é a penultima

------------------------------------------------------------------------------

R2-R3
- Interior é a do tunel logo é **400**
- Exterior é vermos o 4.4.4.4 e vermos a marcação que o R3 usa logo é **305**

R3-R2
- Interior é a do tunel logo é **100**
- Exterior é vermos o 1.1.1.1 e vermos a marcacao que o R2 usa logo é **208**

------------------------------------------------------------------------------

R3-R4
- Interior é a do tunel logo é **400**
- Exterior é vermos o 4.4.4.4 mas como é o penultimo salto fica a **null**

R4-R3
- Interior é a do tunel logo é **100**
- Exterior é vermos o 1.1.1.1 e vermos a marcacao que o R3 usa logo é **307**

------------------------------------------------------------------------------
