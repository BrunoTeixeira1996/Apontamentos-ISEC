# Exercicio 1
## Explicação
O compilador vai à classe base e como encontra a void treinar() não sendo marcada virtual, ela é executada quando é chamada a função treinar da classe Defesa porque é a primeira função que aparece.
Caso a função fosse virtual void treinar() na classe Jogador, o compilador iria executar a função void treinar() da classe Defesa.
```
treinar
jogar defesa

treinar
jogar ataque

treinar
jogar ataque
```

### Resposta
```
C
```

# Exercicio 2
## Explicação
Só pode ser a 1 e a 2.
Temos de ter atenção que o raio é um const int, ou seja, é um membro constante e membros constantes têm de ser inicializados obrigatoriamente na lista de inicialização.

### Resposta

```
C
```


# Exercicio 3
## Explicação
A resposta B é falsa porque como a classe Ave deriva da classe Animal, a classe Animal já definiu a função f() logo, a classe Ave não precisa de o fazer porque herda tudo.

A resposta C é falsa porque mesmo sendo definida a funcao h(), fica a faltar a definição da função g() .

### Resposta
```
A
```

# Exercicio 4

## Explicação

O "antes" é mandado para o cout
O throw lança um objeto Erro que recebe uma string (que é a maneira correta de inicializar um objeto do tipo Erro)
O throw fica ativo e vai procurar um catch válido, enquanto não o encontrar não mostra nenhum cout e passa tudo à frente
O catch correto é o catch (Erro & e) porque recebe um tipo "Erro" tipo este que foi lançado no throw
Entao basicamente o catch(Errro & e) recebe o throw e executa a funcao e.what() que acrescenta "Erro " à string já criada no throw Erro(" em funcao...")
Depois, o throw fica desativo e existe o cout do "fim funcao".
Na main como o throw esta desativo, faz o cout do "fim main".

Caso dentro da funcao void funcao() o throw continuasse ativo, ou seja, nao houvesse o catch (Erro & e), ao ir para a funcao main, iria parar no catch e iria mostrar "catch erro main;"

```
antes;
Erro em funcao...
fim funcao
fim main
```

# Exercicio 5

## Explicação
Uma vez que a classe Zoo é responsavel pelas fichas dos animais, então o construtor da classe Gaiola só precisa de limpar o array de strings.

### Resposta
```
B
```


# Exercicio 6

Se tivermos uma referência como membro variavel, temos obrigatoriamente de a passar no construtor a partir da lista de inicialização e inicializala dentro de {}



# Exercicio 7

Se queremos herdar um membro variavel de uma classe Base para usar no construtor de uma classe Derivada, temos de usar o protected
