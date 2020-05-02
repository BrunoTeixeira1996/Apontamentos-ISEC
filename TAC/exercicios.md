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

    Não podemos trocar a linha para algo quivalente porque no MOV não podemos usar um registo de segmentos(DS) juntamente com um valor imediato(DATA_HERE)


__i)__

    O CMP faz uma subtração. Se o resultado da subtração for zero, então ele sabe que são iguais, se for negativo ele sabe que o "dest" > "src", se for positivo "dest" < "src"

    CMP AL,AH = AL = AL-AH , sem afetar o valor de AL


__j)__

    Uma instrução equivalente a JNA é por exemplo, JBE.

    JNA - JUMP IF NOT ABOVE - SALTA SE NAO FOR MAIOR
    JBE - JUMP IF BELOW OR EQUAL - SALTA SE FOR MENOR OU IGUAL


__k)__

    O programa compara dois valores e descobre qual deles é o maior, depois de fazer isto, armazena na variavel "greater" o maior valor.


__Ex 8__

__Enunciado__

![image](https://user-images.githubusercontent.com/12052283/80864381-243b8280-8c7a-11ea-99b8-c9a30e92f7f8.png)


![image](https://user-images.githubusercontent.com/12052283/80864904-c01abd80-8c7d-11ea-8156-99eef92eb848.png)

__Resposta__

![image](https://user-images.githubusercontent.com/12052283/80865207-b6925500-8c7f-11ea-8d8a-ddd708bafc69.png)


__O que acontece na linha 20?__

    Basicamente sabemos que a soma irá ter ser 12Ch, logo temos de atribuir a flag Carry ao AH para contar o valor de 16 bits no AX. Então somamos o AH+CARRY(que neste caso é 1) + 0 porque o adc requer sempre um valor a seguir à virgula.

__Resultado no DOSBOX usando o CV__

![image](https://user-images.githubusercontent.com/12052283/80865254-02dd9500-8c80-11ea-8f1f-b467de1c2fef.png)

