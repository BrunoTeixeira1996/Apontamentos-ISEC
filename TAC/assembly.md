# Assembly

## Segmentação

*O endereçamento segmentado usa 2 componentes para especificar uma localização de memória: um valor de segmento e um deslocamento dentro deste segmento.*

__Este par é normalmente representado por segment:offset.__

*O tamanho do offset limita o tamanho máximo de um segmento. No 8086, com offsets de 16 bits, um segmento não pode ser maior do que 64 Kbytes.*

*Um endereço representado na forma segment:offset tem o nome de endereço lógico.*

*O atual endereço linear que aparece no bus de endereços é o endereço físico ou real.*

![Untitled Diagram (14)](https://user-images.githubusercontent.com/12052283/79072724-73753f80-7cda-11ea-8084-d66a14cda4aa.png)

*Pode surgir uma multiplicade de representações para referir dados em memória.
__11F0:0, 1100:F00, 1080:1700__ são diferentes endereços de memória que se referem ao mesmo endereço fisico 11F00*

*A solução para isto é normalizar os endereços. Ou seja, a parte do segmento pode conter qualquer valor de 16 bits e a parte do deslocamento tem de ser um valor na gama __0...0F__*

*Normalizando o endereço fisico __11F00__ do endereço lógico __1000:1F00__, fica _11F0:0__*


*Pode aparecer o seguinte exercicio que pede para calcular o endereço real de um certo endereço endereço virtual.*

![image](https://user-images.githubusercontent.com/12052283/79072847-39f10400-7cdb-11ea-99c6-7548d395e0f9.png)

__Resolução__

*Nota que nós cálculamos o endereço real e normalizamos depois os endereços.*

![Untitled Diagram (15)](https://user-images.githubusercontent.com/12052283/79073424-678b7c80-7cde-11ea-8963-c58f59e771f1.png)


## Instruções

![Untitled Diagram (16)](https://user-images.githubusercontent.com/12052283/79073628-8b02f700-7cdf-11ea-9b45-a65b97f6ee0d.png)

### Modos de endereçamento

*Atenção que nao se pode misturar registos que tem tamanhos diferentes.*

__Nota 1 : BX(dados) -> DS / BP(pilha) -> SS__

__Nota 2 : SI(dados) -> DS / DI(dados)__

__Nota 3: tem parenteses retos ? então é por memoria__

__→ Por Registo__      

    MOV AX,BX -> Copiar conteúdo de BX para AX (16 bits)

__→ Imediato__

    MOV AX,123h -> Copiar 123h para AX

__→ Por memória__

    → Direto
        MOV CL, [123h] -> Copiar o valor de DS:0123h para CL
        Aqui está implicito um registo DS antes do [123h]

        MOV SS:[12F3h],BX -> Copiar o valor de BX para SS:12F3h

    → Indireto(por registo)

        → Baseado(com deslocamento)
            MOV DL,[BX] -> Copiar o valor de DS:BX para DL
            MOV DX,[BP] -> Copiar o valor de SS:BP para DX

        → Indexado(com deslocamento)
            MOV DL,[SI] -> Copiar o valor de DS:DI para DL
        
        → Baseado e Indexado(com deslocamento)
            MOV DL,[BP][SI] -> Copiar o valor de SS(BP+SI) para DL
            MOV DL, 100h[BX][SI] -> Copiar o valor de DS:(100h+BX+SI) para DL

__Exercicio__

*De seguida temos um exercicio para esclarecer melhor esta parte.*

*Primeiro temos os dados que o exercicio dá.*

*O esboço do lado direito serve de ajuda.*

![image](https://user-images.githubusercontent.com/12052283/79146524-734c7100-7dba-11ea-86b9-22f2cca751b7.png)

![image](https://user-images.githubusercontent.com/12052283/79146827-df2ed980-7dba-11ea-9f17-1fb1d34b1941.png)

__Resolução__

__Atenção que só é preciso calcular endereços virutais e reais quando estamos na presença de um registo por memória.__

![Untitled Diagram (20)](https://user-images.githubusercontent.com/12052283/79150435-b01b6680-7dc0-11ea-9a2d-0b18ec5f48b8.png)


![Untitled Diagram (21)](https://user-images.githubusercontent.com/12052283/79152575-5d43ae00-7dc4-11ea-9dfe-0ebcd8851b0c.png)

![Untitled Diagram (22)](https://user-images.githubusercontent.com/12052283/79160366-933b5f00-7dd1-11ea-8a98-c230854e6a35.png)



## DOSBOX

__Criar ficheiro de código .asm e abrir no DOSBOX__

    ml /Zi ex.asm
    ml ex.asm
    Ambas estão certas, no entanto o Zi ajuda para o debug

__Comandos__

    cls → limpa a tela
    cd → mudar de pasta
    dir → mostra o conteúdo da pasta atual
    type → mostra o tipo de ficheiro
    del → apaga ficheiros
    exit → sai do DOSBOX
    
__DOSBOX__

    helppc → ajuda local
    codeview → debugger → cv ex.exe


## Variáveis

__Inteiros__

    → Sem sinal (binário puro)

        → byte (1 byte = 8 bits)
        → word (2 bytes)
        → dword (4 bytes)
        → fword (6 bytes)
        → qword (8 bytes)
        → tbyte (10 bytes)
    
    → Com sinal (complementos de 2)

        → sbyte(1 byte)
        → swod (2 bytes)

__Reais (IEEE754)__

    → Real4 (precisão simples) → 32 bits
    → Real8 (precisão dupla) → 64 bits
    → Real10 (precisão expandida) → 80 bits


__Variaveis com sinal começam sempre por "S"__

*Podemos declarar variáveis com valores decimais, binários ou hexadecimais.*

![Untitled Diagram(17)](https://user-images.githubusercontent.com/12052283/79510131-b31e8d00-8034-11ea-8b71-d8dcdb946879.png)


*No caso de querermos usar um numero real, se nao declararmos o valor com uma virgula flutuante dará um erro de compilação.*

![Untitled Diagram (18)](https://user-images.githubusercontent.com/12052283/79075696-577a9980-7cec-11ea-8cbf-e0fcc9f555d2.png)

__Arrays__

![Untitled Diagram (19)](https://user-images.githubusercontent.com/12052283/79075863-454d2b00-7ced-11ea-8a88-987221b01f26.png)

__IMPORTANTE__

*Se tivermos a variável __num1__ como valor __204A(16)__, sabemos que o __20__ é o bit mais significativo e o __4A__ é o menos significativo, logo vai inverter os bytes quando virmos no __code view__. Neste caso irá aparecer __4A20__.*

__Nota__ : *Com isto conseguimos perceber que as variáveis que tiverem mais do que 1 byte sao invertidas.*
*Será invertida sempre de byte a byte, ou seja, se tivermos __C1180000__ , aparecerá __000018C1__.*


__Exercicio__

![image](https://user-images.githubusercontent.com/12052283/79161828-0e057980-7dd4-11ea-96e0-de417fded23a.png)

__Resolução__

![image](https://user-images.githubusercontent.com/12052283/79162472-3c378900-7dd5-11ea-8bc2-46332d8b6334.png)


__var2w word -28__
*Apesar da variavel ser sem sinal, passamos sempre para C2 uma vez que o numero é negativo, colocamos com 8 bits e depois acrescentamos os outros 8 bits dando FFE4 em hex na memoria(ja invertido).*

__var3dw sdword -28 = -28 (10) = FFE4h(C2) = FF FF FF E4h(C2)__

## Movimentação

__MOV__ → *Copia o valor de SRC(2º operando) para DEST(1º operando)*
    
    NUM WORD 2020
    MOV AX, NUM ; Copia 2020 para AX

__XCHG__ → *Troca o conteúdo dos operandos*

    NUM WORD 2020
    XCHG AX,NUM ; Pega no valor de AX  e copia para NUM e pega no vamor de NUM e copia para AX

__LEA__ → *Copia para o primeiro operando o "deslocamento" do segundo*

    TABELA WORD 10,20,30
    MOV SI, 4 ; byte do array a que pretendemos aceder
    MOV AX,TABELA[SI] ; vai buscar o valor do deslocamento

![Untitled d](https://user-images.githubusercontent.com/12052283/79568156-4398b400-80ad-11ea-83eb-152ebf2ce782.png)


## Aritmética

__SOMAR (+)__

__ADD__ → *Soma os 2 operandos e coloca o resultado no primeiro*

    ADD NUM,3 ; NUM = NUM + 3

__ADC__ → *Soma os 2 operandos e o __CARRY__*

__CARRY__ → *Útil para o overflow*

    ADC CX,5 ; CX = CX+5+CARRY

__INC__ → *Incrementa o operando*

    INC NUM; NUM = NUM + 1




__SUBTRAIR (-)__

__SUB__ → *Subtrai os 2 operandos e coloca o resultado no primeiro*

    SUB NUM,3 ; NUM = NUM - 3

__SBB__ → *Subtrai os 2 operandos e o CARRY*

    SBB CX,5 ; CX = CX - 5 - CARRY

__DEC__ → *Decrementa o operando*

    DEC AL; AL = AL - 1




__MULTIPLICAR (*)__

*MUL (SEM SINAL) / IMUL (COM SINAL)*

__Operando(s) de 8 bits → AX = AL x Operando(8 bits)__

    MOV AL,126
    MOV CL, 3
    MUL CL 
    ; AX = 126 * 3

__Operando(s) de 16 bits → DX:AX = AX * Operando(16 bits)__

    MOV AX, 126
    MOV CX, 3
    MUL CX
    ; DX:AX = 126 * 3

![Untitled Diagram (121)](https://user-images.githubusercontent.com/12052283/79581573-81ec9e00-80c2-11ea-96b8-8b7f5480099f.png)




__DIVIDIR (/)__

*DIV (SEM SINAL) / IDIV (COM SINAL)*

__Operando(s) de 8 bits → AL = AX / Operando__

__AH = Resto; AL = Resultado__

    MOV AX,127
    MOV BL,4
    DIV BL ; divisão de 8 bits
    ; 127 : 4 = 31
    ; AL = 31 Resultado
    ; AH = 3 Resto

__Operando(s) de 16 bits → AX = DX:AX / Operando__

__AX = Resultado; DX = Resto__

![Untitled Diagram 302)](https://user-images.githubusercontent.com/12052283/79583160-a8133d80-80c4-11ea-816e-1382a20a8823.png)



__NEGAR (+/-)__

__NEG → Complemento de 2 de um número__

    MOV AL,28
    NEG AL; -28(C2)
    ; Se o nr for positivo fica negativo
    ; Se o nr for negativo fica positivo


__LÓGICA__

__AND ('E') → Produto Lógico → Só dá 1 se ambos forem 1__

    AND AL,00001111
    ; forçar a zero os 4 bits menos significativos ('0')


__OR ('OU') → Soma Lógica → Dá 1 se pelo menos um dos bits for 1__

    OR AL, 00001111
    ; forçar a '1' os 4 bits mais significativos ('1')

__XOR → Soma Lógica Exclusiva → Dá 1 se apaneas um dos bits por 1__

    XOR AL,00001111
    ; inverte os 4 bits mais significativos ('1')

__NOT → Negação → Inverte os bits do operando__

    NOT AL
    ; inverte todos os bits


## Instruções de controlo


__Salto incondicional__

    JMP


![image](https://user-images.githubusercontent.com/12052283/80862893-5ba53180-8c70-11ea-995c-2bbe1c2f42f3.png)


__Salto condicional__

    CMP (condições - comparar números)
    TEST (condições - testar bits)

    Numeros(sem sinal):
        JA,JB,JE,JNE, ...
    
    Numeros(com sinal):
        JG(reater),JL(ess),JE(qual),JNE, ...

    Flags:
        JC,JZ,JS,JO,JP,JNC, ...
        (C)arry,(Z)ero,(S)ignal,(O)verflow,(P)arity



*JA* → Se 1Arg > 2Arg Salta


*JB* → Se 1Arg < 2Arg Salta


*JE* → Se 1Arg = 2Arg Salta


*JG*  → Se 1Arg > 2Arg Salta

*JL* → Se 1Arg < 2Arg Salta


![image](https://user-images.githubusercontent.com/12052283/80863063-7a57f800-8c71-11ea-8055-44827959a036.png)



![image](https://user-images.githubusercontent.com/12052283/80863239-cb1c2080-8c72-11ea-8ced-8a8a4eb35b22.png)


__Exemplos de Ifs e Elses__

![image](https://user-images.githubusercontent.com/12052283/80863798-7aa6c200-8c76-11ea-9361-4911c3f48fe5.png)



__Exemplo de equivalencias__

*JNA* = *JBE*

    "JNA" → JUMP IF NOT ABOVE → SALTA SE NAO FOR MAIOR
    "JBE" → JUMP IF BELOW OR EQUAL → SALTA SE FOR MENOR OU IGUAL


__Chamada/retorno de funções__

    CALL
    RET


![image](https://user-images.githubusercontent.com/12052283/80863746-4501d900-8c76-11ea-8980-4adf6b935a58.png)



## Ciclos

__Aqui nos ciclos, vamos na mesma usar estruturas de controlo__


![image](https://user-images.githubusercontent.com/12052283/81513370-944fa580-9317-11ea-8efd-c33e6666f68d.png)

![image](https://user-images.githubusercontent.com/12052283/81513408-d0830600-9317-11ea-8531-b841813827e7.png)

__Neste caso do for, conseguimos fazer o mesmo com uma instrução mais pequena, no entanto em ves de incrementarmos o indice, vamos começar com o indice na posição final e decrementamos até ser 0.__

__Usando para isso o LOOP__

![image](https://user-images.githubusercontent.com/12052283/81513440-15a73800-9318-11ea-807c-4d6e21c8494f.png)

*Analisando o __LOOP__ em baixo, conseguimos perceber melhor o que realmente faz.*

![image](https://user-images.githubusercontent.com/12052283/81513453-353e6080-9318-11ea-8938-ef13e2ea34c2.png)

*Ou seja, inicializamos o CX com o valor 100 (por exemplo). Depois começamos o ciclo, fazemos o que nos pedem, decrementamos o CX (fica agora com o valor 99), comparamos o CX com o 0 , e se não for igual, voltamos ao ciclo.*
