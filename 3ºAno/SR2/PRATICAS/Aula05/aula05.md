# Aula 02/12/2021 (Rascunho)

## Instalar o File Server Resource Manager

![image](https://user-images.githubusercontent.com/12052283/144485426-6a747417-da2c-421f-97d3-138488fcabb6.png)

## Configurar o SMTP (isto faz-se obrigatoriamente antes do resto)

![image](https://user-images.githubusercontent.com/12052283/144486260-6b7dd6a3-f305-4af6-86dd-e0eb0a21fbf7.png)

![image](https://user-images.githubusercontent.com/12052283/144486407-6a13826b-3bfc-48d5-a507-7783d9efe8f4.png)



## Exercicio 1

- Crie uma quota de 100MB para cada uma das pastas dos trabalhadores
- Não deve deixar gravar após atingir os limites definidos (`hard cota`)
- Deve mandar um mail personalizado para o utilizador e para o administrador (admin@sr2.pt) quando atingir os 85% e 95%.
- Deve personalizar o mail, o eventlog e o reportquando atingir 100%.•Pode criar um novo templateou personalizar um dos existentes
- O servidor SMTP para envio de mail é o 192.168.10.6 e o Fromdeverá ser limites@sr2.pt
- Copie para uma das pastas vários ficheiros até atingir os 100MB

### HOW TO

- Criar Template

![image](https://user-images.githubusercontent.com/12052283/144485814-31f20841-920b-4184-b062-c7570f97d0a5.png)

- Enviar email para o admin e para o utilizador ao atingir 85%

![image](https://user-images.githubusercontent.com/12052283/144486126-1f912786-29cb-4f07-9f8e-504390554d2e.png)


- Deve personalizar o mail, o eventlog e o reportquando atingir 100%

![image](https://user-images.githubusercontent.com/12052283/144486694-e8e1679d-7a84-4268-8d71-646416944fa8.png)

![image](https://user-images.githubusercontent.com/12052283/144486748-7c8d1baf-6007-4feb-942b-71f053876419.png)

![image](https://user-images.githubusercontent.com/12052283/144486839-0a60632c-caf3-43d6-9c31-581259cf8478.png)

- Depois de criar o template é preciso atribuir o mesmo À pasta dos trabalhores

![image](https://user-images.githubusercontent.com/12052283/144487145-be7ac01a-3679-4bd4-bc55-7714f6248b24.png)

![image](https://user-images.githubusercontent.com/12052283/144487209-e879e153-ab80-46e0-b094-bbc4c8c917bd.png)


- Resultado Final

![image](https://user-images.githubusercontent.com/12052283/144486839-0a60632c-caf3-43d6-9c31-581259cf8478.png)

- Caso coloquemos um ficheiro acima de 100 MBs

![image](https://user-images.githubusercontent.com/12052283/144487897-e14c0d41-16de-4df0-a3d8-5477ae4a0060.png)

- Aqui esta o log

![image](https://user-images.githubusercontent.com/12052283/144489766-ce0168cf-1f58-49fa-a414-045a918a4558.png)


## Exercicio 2

- Não deixe que o utilizador grave executáveis, ficheiros de música (nomeadamente wav, mp3), ficheiros de vídeo (nomeadamente mp4 e avi) e ficheiros de sistema nas pastas pessoais e de grupo
- Deve enviar um mail para o utilizador indicando que está a tentar gravar um ficheiro malicioso
- Na pasta Projeto X bloquei a gravação também de ficheiros de texto. Veja o que acontece quando tenta criar um ficheiro de texto nessa pasta. Não se esqueça de ativar o reporte de ver o que está lá escrito!!!

### HOW TO

- Como nao vamos permitir alguns tipos de ficheiros, temos de criar assim este template

![image](https://user-images.githubusercontent.com/12052283/144490231-b0dede96-2afc-4361-9ae4-6f4fea85ef16.png)

- Bloquear executaveis,video,musica e ficheiros de sistema

![image](https://user-images.githubusercontent.com/12052283/144490437-d357644e-a455-4c25-8736-654976502831.png)

- Atribuir o template aos utilizadores

![image](https://user-images.githubusercontent.com/12052283/144490650-eb2aa46c-cf8b-442a-867f-c58364d1822a.png)

![image](https://user-images.githubusercontent.com/12052283/144490858-9b5ceeea-b591-4934-ae3b-81c87ba5c299.png)

![image](https://user-images.githubusercontent.com/12052283/144490926-1b2e695a-7176-419d-ab2c-b6bf64aec714.png)

- Bloquear na pasta ProjetoX a gravação de ficheiros .txt ativando o report

![image](https://user-images.githubusercontent.com/12052283/144491395-d7051e96-9842-40f4-9132-ceafecac4e0e.png)

![image](https://user-images.githubusercontent.com/12052283/144491448-a440a034-b1c0-4252-bab2-8cc1242bdcab.png)


## Exercicio 3

- Crie relatórios de utilização do file system das pastas pessoais e outro para as pastas de grupo com a seguinte informação
  - Listagem dos maiores ficheiros
  - Listagem de ficheiros pouco acedidos
  - Utilização da cota
  - Listagem de ficheiros duplicados

### HOW TO

![image](https://user-images.githubusercontent.com/12052283/144492054-1d95aefc-938f-4cf1-89e1-b88ccc93ce70.png)

![image](https://user-images.githubusercontent.com/12052283/144492412-4bf8f4ce-c2d6-499e-862a-4e4ceb9ebaa9.png)

![image](https://user-images.githubusercontent.com/12052283/144492544-f118e5cd-d6f3-4ced-96d8-b666be75480b.png)

![image](https://user-images.githubusercontent.com/12052283/144492566-591bc960-622e-43b9-9de8-be6322baa8ca.png)

