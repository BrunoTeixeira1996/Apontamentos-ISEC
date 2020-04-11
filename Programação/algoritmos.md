# Algoritmos & Stuff

## Algortimo de ordenação -> BubbleSort
```c
#include <stdio.h>

void bubbleSort(int array[], int size)
{
  for (int step = 1; step < size ; ++step)
  {
    for (int i = 0; i < size - step - 1; ++i)
    {
      // To sort in descending order, change">" to "<".
      if (array[i] > array[i + 1])
      {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
      }
    }
  }
}
```
```c
for com o começo i = 1 até ao total do array
    for com j = 0, até ao total-i
        se(string1 > string2)
            auxiliar = string1
            string1 = string2
            string2 = auxiliar
```
## Algoritmo eliminação ordenada 
```c
Encontrar a posiçao do elemento a eliminar 
Fazer  for j = pos até j < tamanho-1
    depois pegar no array[j] = array[j+1]
```