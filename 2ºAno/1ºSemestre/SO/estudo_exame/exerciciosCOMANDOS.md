# Ficha n7 Linha de comandos

### Pequenas notas
```
cat novo.txt | wc -c -> o wc vai receber o output do cat e executar
cat novo.txt ; wc -c resultado.txt -> o cat é executado e depois é o wc executado, são ambos independentes usando o ;
```
**Usar o grep com AND**
```
cat texto.txt | grep "Maria\|Pedro"
```
**Comando util para retirar um cabeçalho**
```
tail -n +2
```
**Dispositivos de bloco ou de carater são ficheiros deste genero(começam com 'c' ou 'b')**
```
crw-rw----  1 root disk     21,   0 Feb  3 17:47 sg0
brw-rw----  1 root disk      8,   1 Feb  3 17:47 sda1
```

## 1. Apresente no ecrã o número de utilizadores logados na máquina.
```
who | wc -l
```
## 2. Apresente no ecrã o número de utilizadores logados na máquina, sem repetição de utilizadores.
```
who | tr -s " " | cut -d" " -f1 | sort -u | wc -l
```
## 3. Apresente  o  número  de  vezes  que  o  utilizador  com  username  "manuel"  está  logado  na  máquina  (use outro username se não existir nenhum "manuel").
```
who | grep "^manuel " | wc -l
```
## 4. Apresente no ecrã o número de ficheiros ou directorias que existem na directoria /tmp.
```
ls -l /tmp | grep "[^-d]" | wc -l
```
## 5. Apresente no ecrã o número de ficheiros executáveis que existem na directoria /bin.
```
ls -l /bin | tail -n +2 | cut -c4,7,10 | grep "x" | wc -l
```
## 6. Apresente  no  ecrã  o  número  de  dispositivos  de  bloco  ou  de  caracter  e  apenas  esses  que  existem  na directoria /dev.
```
ls -l /dev | tail -n +2 | cut -c 1 | grep "[d/|c]" | wc -l
```
## 7. Apresente no ecrã o número de dispositivos SATA que existem na sua máquina.
```
lspci | grep "SATA" | wc -l
```
## 8. Apresente no ecrã o número de ficheiros em /etc cujo nome contém "gnome".
```
ls -l /etc | tail -n +2 | tr -s " " | cut -d" " -f9 | grep "gnome" | wc -l
```
## 9. Escreva   no   ficheiro   conta   o   número   ficheiros   regulares   em   /etc"   que   tenham  exactamente   as permissões:  dono  pode  ler  e escrever,mas  não  executar.  O  grupo  pode  ler  apenas, e  os restantes utilizadores não podem fazer nada.
```
ls -l /etc | grep "^-rw-r-----" | wc -l > conta.txt
```
## 10. Crie  um  ficheiro  na  sua  directoria  pessoal  chamado  "ficheiro".  O  ficheiro  deve  ter  na  primeira  linha "exemplo"  e  na  segunda  "etc".  Não  pode  usar  nenhum  editor  de  texto  para  criar  o  ficheiro  nem  para colocar lá o conteúdo.
```
echo -e "exemplo\netc" > ficheiro.txt
```
## 11. Mude  as  permissões  do  ficheiro  "ficheiro.txt"  para  que  o  utilizador  possa  ver  e  escrever  (mas  não executar), grupo possa ler apenas, eos restantes utilizadores não possam fazer nada.
```
chmod u=rw,g=r,o=--- ficheiro.txt
```
## 12. Crie um ficheiro na directoria temporária do sistema com a lista de ficheiros existente na sua directoria pessoal que comecem por ".p" (evidentemente, não pode usar um editor de texto).
```
ls -la | tail -n +2 | tr -s " " | cut -d" " -f9- | grep "^.p" > ficheira.txt
```
## 13. Apresente no ecrã o comprimento dos 7 maiores ficheiros existentes em /bin.
```
ls -l /bin | tail -n +2 | tr -s " " | cut -d" " -f5 | sort -n -r | head -n +7
```
## 14. Apresente no ecrã o nome da directoria pessoal dos utilizadores cujo nome comece por uma vogal.
```
ls /home | grep "^[aeiou]"
```
## 15. Apresente  no  ecrã  o  conteúdo  da  directoria  pessoal  do  primeiro  utilizador  que  tenha  no  nome  "jose" ou  "silva".
```
ls /home | grep "jose\|silva"
```
## 16. Apresente apenas o username e user ID dos utilizadores existentes no sistema.
```
cat /etc/passwd | cut -d":" -f1,3 | tr ":" " "
```
## 17. Repita o exercício anterior mas coloque o resultado por ordem alfabética de username. 
```
cat /etc/passwd | cut -d":" -f1,3 | tr ":" " " | sort
```
## 18 Repita o exercício anterior, mas desta vez o resultado é por ordem numérica decrescente de user ID.
```
cat /etc/passwd | cut -d":" -f1,3 | tr ":" " " | sort -n -k 2 -r
```
## 19 Escreva no ecrã a mensagem "estás a usar XXXX. Muito bem", em que XXX é o nome do sistema, o qual deve  ser  descoberto  automaticamente.
```
echo "Estas a usar $(uname)"
```
## 20 Apresente o número de  ficheiros que existem na directoria do utilizador cujo username  é  XXX (é  para substituir XXX por vários usernames, um de cada vez.
```
ls -l $(cat /etc/passwd | grep "^brun0:" | cut -d":" -f6) | grep "^-" | wc -l
```
## 21 Apresente no ecrã o tamanho do maior ficheiro que existe na directoria pessoal do utilizador que tem o nome lexicograficamente maior.
```
ls -l /home/$(ls -l /home | tail -n +2 | tr -s " " | cut -d" " -f9 | sort -r | head -n1) | grep "^-" | tr -s " " | cut -d" " -f5 | sort -n | tail -n1

```
## 22 Indique  o  número  total  de  ficheiros  executáveis  com  o  bit  SetUID  ligado  que  existe na diretoria /usr/bin/passwd.
```
ls -l /usr/bin/passwd | tr -s " " | cut -d" " -f1 | grep "s" | wc -l

```

