
**LINHA DE COMANDOS começa com um comando, não com um ficheiro.txt**




## cat
	-> o que vem do stdin é enviado para stdout

## Associar comandos a um ficheiro
	-> comando >> ou << ou 2> ficheiro.txt 
		->  >> acrescenta ao ficheiro
		->  > escreve em cima do ficheiro 
		->  < stdin vai para o ficheiro
		->  2> stderr vai para o ficheiro

## Associar comando com comando - dá a soma dos comandos, encadeia vários comandos
	-> comando | comando

## Ter dois comandos e o resultado dos dois
	-> comando ; comando

## Copia de um ficheiro
	-> cp antigo.txt novo.txt

## para vermos conteudo da pasta
	-> ls

## listagem longa
	-> ls -l

## listagem de todos os ficheiros, até aqueles que começam com um ponto
	-> ls -a (all)

## Para contar 
	-> wc
		-> conta deste modo: -l(lines)  -w(words)  -c(chars)
	
	-> ls | wc -w 
		-> conta quantas palavras aparecem com o comando ls
		-> como sabemos que ls mostra p.exemplo: ola.txt  ole.txt oi.txt
		-> sabemos assim quantas palavras (pois usamos -w) é que aparecem no ls
		-> assim sabemos quantos ficheiros lá temos
			-> se o nome de o ficheiro tiver espaços, conta mais que uma palavra e depois pensamos que temos mais que um ficheiro 

	-> ls -l | wc -w 
		-> aqui nao corremos o risco de contar palavras a mais (de ficheiros cujo nome tinha 2 ou + palavras)

## Para saber o nr de carateres no ficheiro
	-> cat ficheiro.txt | wc -c

## Quando nao queremos que o caracter especial seja usado
	-> \caracterEspecial 
	-> Assim aparece o caracter especial e o seu uso como especial não acontece

## Quando queremos mesmo usar o especial: -e (echo)

## Mascaras
	-> t* - todos os ficheiros que começam em t e têm algo à frente
	-> t? - todos os ficheiros que começam em t e têm um caracter à frente (mais um ? e seria 2 caract. à frente e sempre assim)
	-> t[ae] - todos os ficheiros que começam por t e são seguidos por a ou e logo a seguir ao t
	-> t[a-e] - todos os ficheiros que começam por t e são seguidos pelas letras de a até e
	-> t[a-ek] - todos os ficheiros que começam por t e são seguidos pelas letras de a até e seguidos de k
	-> rm *txt - apaga todos que têm algo e depois acabam em txt

## who
	-> mostra quem está li gado na máquina

## finger
	-> informação parecida ao who mas com mais pormenores

## whoami
	-> diz o nome do user
 
## id
	-> informação sobre o user
	-> id -u : id do user

## pwd 
	-> pasta pessoal onde estou
	-> onde onde sistema vai colocar o user quando ele fizer login

## /etc/passwd - LOGIN: PASSWORD: UID(userid): GIP(groupid): INFO: HOMEDIR: SHELL
	-> aluno:pass : 1001 : 1001 : alunoSO : /home/aluno : /home/bash

## chmod *g* ou *u* ou *o* + ou - ou = *r* ou *w* ou *x*
	-> estamos a dar ou tirar permissões ao grupo (g), user (u) ou outro (u) de ler (r) ou escrever (w) ou executar (x)
	-> p.exemplo: chmod g+w ficheiro.txt - os de grupo ja podem escrever   
	-> + acrescenta, - retira, = diz quais define as que queremos (substitui pelas permissões anteriores)
	-> chmod ugo+algo dá permissões a todos de executar 

## head -n +x - mostra as x linhas de cabeçalho do ficheiro

## cut -c(caracteres) ou -d(delimitador) ou -f(campo) - cortar algo em específico

## tail -n +x - mostra as x linhas do fim do ficheiro
	-> cat texto.txt | tail -n 1 : vai buscar a ultima linha do ficheiro
	
	-> cat texto.txt | tail -n 1 | cut -c15-20 : na ultima linha, vai buscar apenas do caracter 15 ao 20
		-> isto pode dar problemas se não acertarmos no numero de caracteres, então:

		-> cat texto.txt | tail -n 1 | cut -d"," -f3  : corta a partir de uma virgula, no 3º campo ou -f1,3 seria o 1º e 3º campo
			-> ou cut -d"," -f3,9- mostra o mesmo mas da linha 9 até ao fim

			-> tr "," "\t" para p.exemplo transformar a virgula em tab, trocar um caracter por outro


	-> cat texto.txt | tail -n +3 : da limha 3 até ao fim

## sort: para ordernar uma pesquisa
	-> sort -n(numeros) ou -r(ordernar revetido) ou -t(delimitador) ou -k(campo) ou -u(unique)

## unique: para não mostrar repetições

## grep: pesquisa especificamente algo numa pesquisa
 	-> cat texto.txt | grep "8" - aparece todas as linhas que têm um 8
 	-> cat texto.txt | grep ",8" - que têm uma virugula seguida de um 8
 	-> cat texto.txt | grep ",8$" - que têm uma virgula seguida de um 8 e mais nada
 	-> cat texto.txt | grep "[Jj]oao" - que começam por j ou J
 	-> cat texto.txt | grep "^[Jj]oao " - que começam por j ou J e que começam pelo nome Joao ou joao (^ indica inicio da linha)
 
 	-> cat texto.txt | grep "^j.\{30, 50\}bash$" ou "^j[0-9]\{30, 50\}bash$"
 		-> ^ - linha que começa por j, . - depois tem um caracter qq, {30,50} que se repete 30 a 50 vezes e $- acaba em bash
 			-> \{30,\} 30 ou mais vezes 
 			-> \{30\} exatamente 30 

 		-> sem o ponto e com os [] já nao seria um caracter qq, mas sim numeros de 0 a 9
 			-> [^0-9] todos os caracteres  não sejam de 0 a 9 - aqui ^ é usado como negação

- ^ inicio, $ fim 

## tr -s "caracter": pesquisa esquecendo o caracter que aparecer repetindo

## ex do 1 ao 5, 6, 9, 10, 12, 13, 15, 1
	-> quando no ex fala em ficheiros normalmente envolve um ls
	-> quando é numero acaba em wc


## ficheiros 	
	-> -d(diretoria), - (regular), p(fifo), l(atalhos)

## para ver todos os users
	-> tail -n +3 /etc/passwd

## para ver todos os grupos
	-> tail -n +3 /etc/group

## sudo groupadd nome: para adicionar um grup

## sudo useradd -m(makedir, criar a pasta do user) -s /bin/bash(criar a shell) -g tac (grupos primarios) -G so, prog (grupos adicionais) -c(comentario) "joao silva" jsilva

## sudo passwd nomeUser: muda a passe de uma user

## sudo login nomeUser: para entrarmos na conta do user em questão

## sudo passwd -l nomeUser: bloqueia um user

## sudo passwd -u nomeUser: desbloqueia um user   

## aspas protegem caracteres
	-> echo "rafael ribeiro"  -> rafael ribeiro é apenas 1 argumento
		-> aspas protegem os argumentos: 
	-> echo rafael ribeiro	  -> rafael é 1 argumento e ribeiro é outro argumento   

    -> os caracteres especiais ($ e `) são protegidos também "sou o $nomeUser" - aparece o valor da variavel nomeUser.
   	
    -> porem, a \ tira sempre a especialidade 

   	-> se fosse com plicas, aparecia literalmente $nomeUser  
   		->garantimos que o que estamos a mandar é texto e não é interpretado como especial

    -> se $NOME = rafael e id -u = 1000
    	-> ID = 'id -u $NOME' : ID fica com: id -u $NOME 
    	-> ID = "id -u $NOME" : ID fica com: id -u rafael
    	-> ID = `id -u` : ID fica com: 1000 
    				ou
    	-> ID = $(id -u) : ID vai ficar com o valor 1000 

    		->portanto, echo "tenho o valor de $(id -u)" : tenho o valor de 1000
 

