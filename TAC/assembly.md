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
colocar aqui o exercicio 3


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

![Untitled Diagram (17)](https://user-images.githubusercontent.com/12052283/79075295-d8846180-7ce9-11ea-8366-cf64a8c856cf.png)

*No caso de querermos usar um numero real, se nao declararmos o valor com uma virgula flutuante dará um erro de compilação.*

![Untitled Diagram (18)](https://user-images.githubusercontent.com/12052283/79075696-577a9980-7cec-11ea-8cbf-e0fcc9f555d2.png)

__Arrays__

![Untitled Diagram (19)](https://user-images.githubusercontent.com/12052283/79075863-454d2b00-7ced-11ea-8a88-987221b01f26.png)

__IMPORTANTE__

*Se tivermos a variável __num1__ como valor __204A(16)__, sabemos que o __20__ é o bit mais significativo e o __4A__ é o menos significativo, logo vai inverter os bytes quando virmos no __code view__. Neste caso irá aparecer __4A20__.*

__Nota__ : *Com isto conseguimos perceber que as variáveis que tiverem mais do que 1 byte sao invertidas.*
*Será invertida sempre de byte a byte, ou seja, se tivermos __C1180000__ , aparecerá __000018C1__.*