# SO Enunciado Teorica Parte 1

# Pergunta 1
```
Muitas vezes algumas diretorias centrais são mapeadas em partições independentes como é o caso da /tmp e /home .

No caso da /home é para poder levar a partição/disco para outro sistema.

No caso da /tmp serve para ter um sistema de ficheiros afinado para ficheiros temporários
```

# Pergunta 2
## i)
```
O bit setuid indica que ao executar um programa com esse bit ligado, o processo pode fazer o que o utilizador dono desse programa também pode, ou seja, posso ser um utilizador normal e executar um programa com privilegios root caso esse bit esteja ligado.

Caso o bit setuid esteja desligado ao executar um programa, o processo só pode fazer o que o meu utilizador tambem pode.
```

## ii)
```
O bit setuid serve para dar permissoes de um processo a um utilizador sem permissoes para o executar. Ou seja, permitir a utilizadores comuns executar codigo privilegiado sem partilhar a totalidade dos direitos de administração.
```

## iii)
```
Um exemplo habitual é quando mudamos a password usando o comando passwd.

Uma vez que o programa "passwd" é um dos tais que tem o bit setuid ligado e pertence ao root.
```

# Pergunta 3

## i)
```
No processo pai, temos um ciclo que cria filhos (fork) e esses filhos vao ser lançados para um execl, logo o processo pai termina com sucesso no return 0
```
## ii)
```
No final, quando o i é igual a 3, é executado o printf mostrando 3, uma vez que o processo pai não vai para o execl porque lança um filho para tal.
```

# Pergunta 5
```
As funções sistema pertencem ao sistema operativo porque estão numa zona de memória(no núcleo) à qual o processador reconhece e aceita instruções delas para interagir com o periférico.

No caso das funções biblioteca, estas estão na zona de memória do utilizador, logo não têm capacidades para aceder a zonas de memória onde corre o núcleo do sistema.

O que impede a uma função qualquer de replicar as operações feitas pelo sistema é o sistema operativo e o hardware.
```

# Pergunta 6
## i)
```
2^offset
Então fica 2^12 = 4096
```

## ii)
```
4098/4096 = 1 (resto 2), Ou seja, vamos ao indice 1 e somamos 2.
O endereço real é 8194
```


