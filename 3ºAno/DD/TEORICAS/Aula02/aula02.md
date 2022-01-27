# Aula 15/10/2021

## O que é a disponibilidade? 

- A disponibilidade é um valor entre 0 e 1

### Disponibilidade instantânea

- Probabilidade do sistema se encontrar *up* no instante t

### Disponibilidade média

- Probabilidade de encontrar um sistema *up* em qualquer momento em que precisemos dele 

### Continuidade

- Extensão do período durante o qual um serviço não é interrompido por uma avaria

## Formula da disponibilidade

![image](https://user-images.githubusercontent.com/12052283/138565504-6d7c4640-5519-4d66-b620-8658e7416713.png)

### Exemplo
```
|               |        |         |
| Continuidade  |DownTime|  Conti. |
|               |        |         |
+---------------+        +---------+
|               |        |         |        Disponibilidade = 8+1.5
|       8       |   0.5  |   1.5   |                         ------- = 0.95
|               |        |         |                            10

|                                  |
+----------------------------------+
|            10 Horas              |
```

## Medidas da Continuidade e Downtime

### Mean Time To Failure (MTTF)

- Tempo médio para avaria

### Mean Up Time (MUT)

- Extensão média de tempo que separa o instante em que um serviço é restaurado após avaria até à próxima avaria

### Mean Time Between Failures (MTBF)

- Tempo médio entre avarias sucessivas

### Mean Time To Repair (MTTR)

- Tempo médio de reparação das avarias

### Exemplo

![image](https://user-images.githubusercontent.com/12052283/138565851-c5667d00-b63f-4709-9a3b-4218175316d1.png)

### Quantificação de disponibilidade média

![image](https://user-images.githubusercontent.com/12052283/138565893-4b8f328d-7292-4b06-9673-660207c7058e.png)

![image](https://user-images.githubusercontent.com/12052283/138565970-41891073-4c9c-4c3f-b9a5-1b82526a902a.png)

- Quantos mais `9's` mais caro fica uma vez que a disponibilidade aumenta

## Sistemas em Série


```
                   +------------+
A'   A ------------+     SWx    +----------- B
                   +------------+


                   +------------+     +------------+
A''  A ------------+     SWx    +-----+     SWy    +---- B
                   +------------+     +------------+
```

```
+-               --+
| Ex = SWx Avariar |
|                  +----> Isto sao acontecimentos independentes
| Ey = SWy Avariar |
+-               --+

 A' = 1-P(Ex)   Probabilidade de A chegar a B

 A''= [1-P(Ex)] x [1-P(Ey)]   Probabilidade de A chegar a B
```

- Caso `SWx` e `SWy` seja 0.9 de disponibilidade
  - 0.9x0.9 = 0.81 -> A disponibilidade caiu

- Ou seja, quanto mais equipamentos tivermos maior a probabilidade da disponibilidade ser inferior isto em **Sistemas em série**

## Sistemas em Paralelo

```
                   +------------+
A'         A-------+     SWx    +-------B
                   +------------+


                   +------------+
                +--+     SWx    +--+
                |  +------------+  |
A''     A-------+                  +-----B
                |  +------------+  |
                +--+     SWy    +--+
                   +------------+
```

```
+--------------------+
| Ex -> SWx Avariar  |
| Ey -> SWy Avariar  |
+--------------------+

 A' = 1-P(Ex)    Probabilidade de A chegar a B

 A'' = 1-P(Ex)xP(Ey)   Probabilidade de A chegar a B
```

```
Probabilidade de Swx avariar <-----      -->   Probabilidade de Swy avariar
                                   |      |
                                   |      |
                                 ------ ------
             Disponibilidade = 1-(P(Ex)x(P(Ey))
                              ----------------
                                     |
                                     |
                                     ----> A chegar a B
```									 

### Em Resumo ...

  - P(Ax) -> SWx nao avariar
  - P(Ay) -> SWy nao avariar
  - 1-P(Ax) -> SWx avariar
  - 1-P(Ay) -> SWy avariar


- Em sistemas em série a fórmula é
  - `Disponibilidade` = P(Ax) x P(Ay)

- Em sistemas em paralelo a fórmula é
  - `Disponibilidade` = 1-([1-P(Ax)] x [1-P(Ay)])
