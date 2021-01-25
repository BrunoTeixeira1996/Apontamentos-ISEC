# Exercicio 1
## Explicação
Como o vector<Funcionario*>convocados não pertence à classe Reunião, só precisamos de ter um ponteiro apontar para vector de convocados. No entanto como o vector<string *>ordemDeTrabalhos pertence à classe Reunião, para copiarmos corretamente cada ponteiro, temos de fazer um ciclo for.

### Resposta
```
A
```

# Exercicio 2
## Explicação
Como na função temos void f(const Num *p), significa que o ponteiro aponta para uma constante, ou seja, conseguimos ver o seu valor, no entanto não conseguimos alterar o seu valor.
Conseguimos fazer p = new Num() sem problema nenhum.

Na funcao void g(Num * const p) o ponteiro é constante ou seja, se o ponteiro nascer apontar para um certo lugar, não conseguirmos alterar para ele aponta, mas conseguimos alterar o seu valor.

### Resposta
```
D
```

# Exercicio 3
## Explicação
Dá throw Erro("lado negativo")
Depois encontra um catch(Erro &e) e coloca o lado = 0;
Depois faz cout da area, e a area = 0;
Depois vai para a main , o throw já foi resolvido , mostra o cout << "depois" e faz cout << "fim main";

### Resposta
```
area = 0; depois; fim main;
C
```

# Exercicio 4
### Resposta
```
Carne Racao 12  1
C
```

# Exercicio 5
## Explicação
A alinea A não é a mais apropriada porque a classe Galgo devia de derivar de Cao e não de Canideo.

A alinea C não está correta porque no enunciado diz que a velocidade tem um impacto na dose diária, logo a função virtual dose() deve ser adaptada.

### Resposta
```
B
```
