# Aula 25/10/2021

## Strings

![image](https://user-images.githubusercontent.com/12052283/138672360-6c6213f4-fbb7-4bdd-9bdd-292040c6d895.png)

### Caracter @

- Podemos usar o `@` para a contrução de strings mais facilmente sem recorrer tanto às sequências de *escape* usando antes *verbatim strings*

![image](https://user-images.githubusercontent.com/12052283/138672731-49e6d0b3-7e7a-4cc8-8b23-e4a9df215e46.png)

- O `@` ajuda tambem na formatação de espaços, mudanças de linhas ...

![image](https://user-images.githubusercontent.com/12052283/138672903-eae53695-ccba-44db-95cf-73316bbf88f4.png)

- O `@` tambem serve para formatar SQL querys por exemplo

```csharp
var alunos = @"SELECT *
FROM Aluno
WHERE curso = 'EI'
```

### Conversão de Strings

- A conversão de strings em arrays de bytes ou array de strings é algo habitualmente feito

- Por exemplo, vamos converter uma string para um array de bytes

![image](https://user-images.githubusercontent.com/12052283/138673851-cd387b77-01ab-4fa6-91d3-dc086baa1889.png)

- Agora convertendo array de bytes em strings

![image](https://user-images.githubusercontent.com/12052283/138674111-a20e8194-dc32-4c7d-ad5c-3a13322a1c4f.png)

- Exemplo concreto

![image](https://user-images.githubusercontent.com/12052283/138674393-3d147463-b452-49e9-9af3-40321df698e0.png)

## Algoritmo de validação do NIF

![image](https://user-images.githubusercontent.com/12052283/138680653-aa0c2f54-142c-4f3c-991a-d9da6764347b.png)

![image](https://user-images.githubusercontent.com/12052283/138680929-6485d5c9-b032-40f0-a3e5-83440a020729.png)

 - Ver a parte da validação do NIF com regex
 
## Operadores

![image](https://user-images.githubusercontent.com/12052283/139420171-df261333-b9d1-4fbf-b318-f53b25fdaa8b.png)

![image](https://user-images.githubusercontent.com/12052283/139420214-481fd3e3-0eae-4fcc-bbc1-f90e2062e840.png)


## Switch

![image](https://user-images.githubusercontent.com/12052283/139420534-042314c3-7a21-4490-84af-1f3f32124bd0.png)

![image](https://user-images.githubusercontent.com/12052283/139420564-813bc272-3a3b-4a36-8f78-7d2bdb2b12ac.png)

![image](https://user-images.githubusercontent.com/12052283/139420584-11c63c6b-d952-4185-bdf3-266bf60b85fe.png)

## Instrução Switch

- Instruções Switch **não é o mesmo** do que Expressões switch

- Caracterizam-se por a variavel aparecer antes da palavra chave switch

- Permite uma maior compactação e é usado o operador *lambda*

![image](https://user-images.githubusercontent.com/12052283/139420776-03426516-9be2-4b34-9e41-265b46a8fe44.png)

![image](https://user-images.githubusercontent.com/12052283/139420800-565d0081-aec2-4bef-ba51-78d8bfbb2cf2.png)

![image](https://user-images.githubusercontent.com/12052283/139420839-6f1f1fec-f7d5-4c33-a645-3f44172884d8.png)

![image](https://user-images.githubusercontent.com/12052283/139420858-e1c13c55-1141-4918-8eee-38bfe081d56f.png)
