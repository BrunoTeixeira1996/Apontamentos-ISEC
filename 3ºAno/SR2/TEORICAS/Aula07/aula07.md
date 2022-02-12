# Aula 12/01/2022

## SPAM

- **São mensagens que são enviadas de forma massiva e não solicitada**
- Podem ser de vários tipos, desde fraudes, vendas de produtos, disseminação de virus ou cavalos de troia

### Tipos

- **Boatos (hoax)**
  - Está associdado a fake news, com o intuito de iludir aqueles que a leem e instigar a sua divulgação o mais rapidamente para o maior nr de pessoas
  
- **Correntes (chain letters)**
  - Mensagens desta categoria prometem sorte, riqueza ou algum outro tipo de beneficio àqueles que a reenviarem para um número minimo de pessoas num tempo pre-determinado
  
- **Golpes (scam)**
  - Tratam de oportunidades enganosas e ofertas de produtos que prometem falsos resultados
  
- **Phishing**
  - São mensagens que assumem o disfarce de spam comercial ou cujos titulos simulam mensagens comuns, como comunicados transmitidos dentro de uma organização ou mensgens pessoais oriundas de pessoas conhecidas

- **Programas maliciosos**
  - Apresenta-se sob disfarce e induz o destinatário a executar um programa malicioso

- **Ofensivos**
  - Divulgam conteudo agressivo e violento, como por exemplo acusações infundadas contra individuos especificos

## Sistema Anti-Spam

- **Funcionamento integrado**
  - Funcionamento integrado no servidor de email formando um subsistema proprio

- **Funcionamento externo**
  - Existem empresas que fornecem serviços externos, no entanto implica o redirecionamento de todos os emails da organização para o servidor dessa empresa**

- **Para detetar mensagens spam são utilizadas várias técnicas, as mais simples são bloquear automaticamente pelo remetento, as mais complexas baseiam-se em padrões para efetuar uma análise do conteudo das mensagens tendo um custo de processamento maior**

## Anti-Spam

![image](https://user-images.githubusercontent.com/12052283/149357469-2b2decff-db12-49e2-995f-b910e39ea90b.png)

![image](https://user-images.githubusercontent.com/12052283/149357618-b02eaa1a-2f53-4db8-a9f1-8cd076a4c4a0.png)


## Virus

- **É um pequeno programa desenvolvido para alterar a forma como um computador trabalha sem permissão ou conhecimento do utilizador**

- **Funcionamento básico do virus**
  - Quando um arquito é infetado e executado
  - O virus é carregado na memória e altera as rotinas do sistema necessárias para viabilizar as suas ações

![image](https://user-images.githubusercontent.com/12052283/149359670-22ec16b9-cf94-4c98-a8fa-171e63dbf756.png)

### Técnicas utilizadas pelos virus

- **Tunneling**
   - É uma técnica usada para que os virus possam ultrapassar programas residentes e tomar o controlo de algumas interrupções diretamente
   - Deste modo podem por exemplo monitorizar qualquer acesso ao disco enganando o antivirus
   
- **Stealthing**
  - É uma tecnicas usada para dificultar a sua deteção pelos antivirus
  - Por exemplo, muitos virus nao alteram a data e hora do arquivo que contaminaram ou o tamanho deste
   
- **Encriptação**
  - É uma das técnicas mais usadas em que envolve um *loop* no qual o virus é encriptado ou desencriptado sempre que é executado

- **Polimorfismo**
  - É a capacidade do virus mudar o código fazendo com que cada nova geraçao seja funcionamente igual porém fisicamente diferente

### Tecnicas de deteção

- **Scanning**
  - Localiza strings com caracteristicas de um virus em particular
  - A localização é feita na memória, na boot e no disco
  - **Desvantagens**
	- Identifica apenas virus conhecidos
  - **Vantagens**
	- Deteta rapidamente virus que ainda nao foram executados
	- Baixa taxa de falsos-positivos
	
![image](https://user-images.githubusercontent.com/12052283/149360625-623bd0db-131e-49e6-b9dd-ca73ac1a10c2.png)


- **Integrity checking**
  - Verifica a integridade e grava no disco esta informação sobre os arquivos importantes
  - **Vantagens**
	- Forma mais fiável de provar que um arquivo foi corrompido
	- Permite restaurar o arquivo após uma possivel infeção ou corrupção
  - **Desvantagens**
	- Os programas não oferecem clareza na validação da integridade (**corrompido ou infetado?**)
	- Esta técnica só funciona quando um arquivo já foi infetado
  
- **Heuristic detection**
  - Tecnica utilizada para estudar o comportamento, a estrutura e as caracteristicas de um arquivo
  
![image](https://user-images.githubusercontent.com/12052283/149361055-ac211078-caf4-4207-af17-55452827df03.png)

![image](https://user-images.githubusercontent.com/12052283/149361115-d0187986-83ae-4535-8edb-9d5d06ad1e06.png)

- **Interception**
  - Monitoriza a atividade dos processos que estão a correr no computador, e avisa quando existe alguma sequência suspeita
  - **Vantagens**
	- É um bom método genérico para evitar ação destrutiva por parte de algum virus, trojan ou afins
	- Apesar de não identificar o software malicioso, pode impedir maiores danos, parando a sua ação
  - **Desvantagens**
	- É um recurs fácil de ser desabilitado pelos virus

## Ransomware

- É um tipo de software malicioso que tem por objetivo capturar recursos da vitima e para os libertar exige um pagamento ou resgate
- Este é geralmente pago através de Bitcoins onde as tansações são praticamente anonimas pois são impossiveis de determinar a sua origem e destino

![image](https://user-images.githubusercontent.com/12052283/149362040-63269675-81ef-4105-9f1d-edc40eacc4a0.png)

![image](https://user-images.githubusercontent.com/12052283/149362188-0a163f4e-81c7-441d-ab0f-5f9277a6a087.png)

![image](https://user-images.githubusercontent.com/12052283/149362343-a309577d-4862-4063-b7ee-f52b21009d40.png)

### Como prevenir?

- Investimento das organizações em cibersegurança quer do ponto de vista técnico quer em termos humanos
- Educando o utilizador
