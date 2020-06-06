# Exercicios

## Ficha nº2 Assembly


__Ex 7__


__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/80863874-10dae800-8c77-11ea-8937-8566c68f118c.png)



__a)__

    first
    second
    greater

__b)__

    Cada variável ocupa apenas 1 byte (DB)

__c)__

    first DB 25h
        00100101b → 37d

    second DB 31h
        00110001b → 49d

    greater DB ? → A variável não tem valor iniciado

__d)__

![image](https://user-images.githubusercontent.com/12052283/80863988-a8d8d180-8c77-11ea-87b3-5c8fd57308e5.png)

__e)__

![image](https://user-images.githubusercontent.com/12052283/80864096-37e5e980-8c78-11ea-8e84-ed29db0a7dd5.png)

__f)__

    O ASSUME diz ao tradutor qual dos blocos corresponde ao código e qual dos blocos corresponde aos dados.

![image](https://user-images.githubusercontent.com/12052283/80864169-e2f6a300-8c78-11ea-8bf5-7adb1eba5b87.png)


__g)__

    Tem a ver com a necessidade que temos de inicializar o segmento de dados.

__h)__

    Não podemos trocar a linha para algo quivalente
    Porque no MOV não podemos usar um registo de segmentos(DS)
    juntamente com um valor imediato(DATA_HERE)


__i)__

    O CMP faz uma subtração. Se o resultado da subtração for
     zero, então ele sabe que são iguais, se for negativo ele
     sabe que o "dest" > "src", se for positivo "dest" < "src"

    CMP AL,AH = AL = AL-AH , sem afetar o valor de AL


__j)__

    Uma instrução equivalente a JNA é por exemplo, JBE.

    JNA - JUMP IF NOT ABOVE - SALTA SE NAO FOR MAIOR
    JBE - JUMP IF BELOW OR EQUAL - SALTA SE FOR MENOR OU IGUAL


__k)__

    O programa compara dois valores e descobre qual deles é o maior, depois de fazer isto, armazena na variavel
     "greater" o maior valor.


__Ex 8__

__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/80864381-243b8280-8c7a-11ea-99b8-c9a30e92f7f8.png)


![image](https://user-images.githubusercontent.com/12052283/80864904-c01abd80-8c7d-11ea-8156-99eef92eb848.png)

__Resposta__

![image](https://user-images.githubusercontent.com/12052283/80865207-b6925500-8c7f-11ea-8d8a-ddd708bafc69.png)


__O que acontece na linha 20?__

    Basicamente sabemos que a soma irá ter ser 12Ch, logo temos de atribuir a flag Carry ao AH para contar o valor
     de 16 bits no AX. Então somamos o AH+CARRY(que neste caso
      é 1) + 0 porque o adc requer sempre um valor a seguir à
       virgula.

__Resultado no DOSBOX usando o CV__

![image](https://user-images.githubusercontent.com/12052283/80865254-02dd9500-8c80-11ea-8f1f-b467de1c2fef.png)


__Ex 9__


__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/81513527-b39b0280-9318-11ea-9ec3-e490021d6490.png)

![image](https://user-images.githubusercontent.com/12052283/81513557-e1804700-9318-11ea-8e69-8f150496abce.png)


__Resposta__

![image](https://user-images.githubusercontent.com/12052283/81513637-476cce80-9319-11ea-9e33-baaa2a49e1f4.png)

__Resultado no DOSBOX__

*Depois de ter feito todas as iterações*

![image](https://user-images.githubusercontent.com/12052283/81513716-ef829780-9319-11ea-8cf6-95bedc7b2d5c.png)


__Ex 10__


__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/81513740-0cb76600-931a-11ea-9d13-cc2c489c17c9.png)

![image](https://user-images.githubusercontent.com/12052283/81513752-20fb6300-931a-11ea-990c-5e63591092da.png)

__Resposta__

![image](https://user-images.githubusercontent.com/12052283/81587126-1d152280-93a6-11ea-829c-3e884db44512.png)



__Resultado no DOSBOX__

*Depois de ter feito todas as iterações, conseguimos ver que o array soma, fica com todas somas feitas entre o array num1 e o array num2*

*O resultado está representado com circulos.*

*Nota que no cv todas as vars com mais do que 1 byte invertem.*

![image](https://user-images.githubusercontent.com/12052283/81586800-a0824400-93a5-11ea-8cce-772855ef96a9.png)



__Ex 11__

__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/83927424-645fba80-a77c-11ea-8d37-b7ccc2c82180.png)

![image](https://user-images.githubusercontent.com/12052283/83927468-86f1d380-a77c-11ea-9bcf-3f4177538761.png)


__Resposta__


![image](https://user-images.githubusercontent.com/12052283/83927490-9a9d3a00-a77c-11ea-86ca-8fe6ff0b6099.png)


__Resultado no DOSBOX__


![image](https://user-images.githubusercontent.com/12052283/83927393-4abe7300-a77c-11ea-9699-438f5b6ad596.png)


__Ex 12__


__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/83928228-7f332e80-a77e-11ea-8d63-391530241403.png)


![image](https://user-images.githubusercontent.com/12052283/83928248-97a34900-a77e-11ea-8210-2710bc36e4a2.png)


__Resposta__


![image](https://user-images.githubusercontent.com/12052283/83928265-a689fb80-a77e-11ea-8cb0-f02bf56b89ab.png)


__Resultado no DOSBOX__

![image](https://user-images.githubusercontent.com/12052283/83928189-60cd3300-a77e-11ea-8b45-b45ead4efb1c.png)


__Ex 14__

__Enunciado__


![image](https://user-images.githubusercontent.com/12052283/83930267-2a93b180-a786-11ea-93b7-b3e30893e497.png)

![image](https://user-images.githubusercontent.com/12052283/83931066-397c6300-a78a-11ea-87f7-901e89c982e3.png)


__Resposta__

![image](https://user-images.githubusercontent.com/12052283/83930456-38960200-a787-11ea-9826-45c38e586cbc.png)


__Ex 15__

__Enunciado__


__Resposta__

![image](https://user-images.githubusercontent.com/12052283/83931012-f5895e00-a789-11ea-8ac8-722d8c90591e.png)
