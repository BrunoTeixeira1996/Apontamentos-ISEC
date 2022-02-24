# Aula T 08/11/2021

## Collections

![image](https://user-images.githubusercontent.com/12052283/140723419-c55c53e3-58d8-48cc-b062-5292c7215598.png)

![image](https://user-images.githubusercontent.com/12052283/140723797-7d58cd5c-842b-4f2c-b18a-4ef7dde0fcb0.png)

### Inicialização

![image](https://user-images.githubusercontent.com/12052283/140724600-e335b113-c5f0-417a-b237-5d4b4866dcdb.png)


![image](https://user-images.githubusercontent.com/12052283/140725777-d18a3223-61c7-4a2b-91e5-1029b3310c54.png)

## Delegates

- Tipos que permitem fazer referencia a métodos

- Usado para passar métodos como argumentos a outros metodos

- Um delegate é um tipo referencia

- Pode ser usado para encapsular uma método com nome ou anónimo

![image](https://user-images.githubusercontent.com/12052283/140727348-d8760b5c-46b6-4f34-b913-87687b3f2faf.png)

![image](https://user-images.githubusercontent.com/12052283/140727463-82736076-2e8c-4ac7-8408-3740dbe8147e.png)

- O *delegate* é semelhante a um ponteiro de função, a vantagem é que é um ponteiro seguro

### Delegate como parâmetro

![image](https://user-images.githubusercontent.com/12052283/141464255-e6606b74-76d0-48d9-bd44-cf5a034f93d7.png)

![image](https://user-images.githubusercontent.com/12052283/141464414-33393057-985a-413f-9512-c5fc159d9a94.png)


### Instanciar um delegate como um método anónimo

![image](https://user-images.githubusercontent.com/12052283/141464666-3078a47b-e370-4daf-9fb7-17bb6b6558d0.png)


### Métodos anónimos

- A ideia é permitir escrever métodos inline no codigo sem declarar um metodo formal com nome

![image](https://user-images.githubusercontent.com/12052283/141464867-2ef49f25-0d40-4d02-81b5-07abf13403f5.png)


### Func -> retorna sempre alguma coisa

- É um tipo genérico delegate

- Tem zero ou mais parâmetros de entrada e um parâmetro de saida

- O ultimo parâmetro é considerado o parâmetro de saída

- Deve incluir um parâmetro *out* para o resultado

![image](https://user-images.githubusercontent.com/12052283/141465298-76bce113-43ee-4c07-927e-6ee7e0a6e050.png)

![image](https://user-images.githubusercontent.com/12052283/141465468-d1b4661a-26fe-4ab0-9fdc-360b83463834.png)

### Action -> não retorna nada

- É parecido ao *Func* no entanto aqui não retorna nada

- Pode ser usado quando o retorno é *void*

![image](https://user-images.githubusercontent.com/12052283/141465605-f6a796fe-e3a6-4fac-bbaa-d449765fbcae.png)

![image](https://user-images.githubusercontent.com/12052283/141465758-33c78b11-2475-4dc7-90d6-6a0a777ac275.png)

![image](https://user-images.githubusercontent.com/12052283/141465839-2d857798-7ce0-4f3b-a3db-f8c40587e134.png)


### Predicate -> retorna um bool

- Representa um método que contém um conjunto de critérios e verifica se os parâmetros passados cumprem esse critério ou não

- Deve ter um parâmetro de entrada e retorna um bool

![image](https://user-images.githubusercontent.com/12052283/141465983-476e7647-6203-4d74-b26f-be8f520732c3.png)

### Delegate com expressão lambda

![image](https://user-images.githubusercontent.com/12052283/141466357-11027ff9-81ae-482c-85d9-981e15adb13c.png)


## Operador lambda

![image](https://user-images.githubusercontent.com/12052283/141466551-759c7a34-9227-4f16-81f4-a2cbb393dc4b.png)

- As **expressões lambda** são expressões embutidas semelhantes aos métodos anónimos mas ainda mais flexiveis

- Método anónimo
  - sem nome
  - sem modificador de acesso
  - não retorna valor
  - usado como um atalho para a inicialização de um *delegate*

![image](https://user-images.githubusercontent.com/12052283/141467285-0f8c7ed8-67a2-46f6-badf-1659c8d52ee4.png)

### Delegate com Lambda

![image](https://user-images.githubusercontent.com/12052283/141467584-225ddc65-e566-415a-9ad5-99c54ce153e8.png)

### Delegate com Lambda , exemplo com um argumento

![image](https://user-images.githubusercontent.com/12052283/141468110-0db2166d-fabe-4338-9c10-857f26aad203.png)

### Delegate com Lambda, exemplo com vários argumentos

![image](https://user-images.githubusercontent.com/12052283/141468219-4566988e-ae09-407e-bdce-853dbcdfa2dd.png)

### Outras formas de utilização do Lambda

![image](https://user-images.githubusercontent.com/12052283/141468605-66fe4085-c9ed-4c5a-ad85-2fd1653d63eb.png)
