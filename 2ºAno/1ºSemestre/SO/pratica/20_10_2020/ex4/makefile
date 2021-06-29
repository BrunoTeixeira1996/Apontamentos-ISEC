FLAGS=-D DEBUG

ex3: programa.o imprime.o
	gcc programa.o imprime.o -o ex3

programa.o: programa.c imprime.h
	gcc programa.c -c ${FLAGS}


imprime.o: imprime.c
	gcc imprime.c -c ${FLAGS}

limpa:
	rm *.o

instala:
	echo 'Vou instalar... (copiar)'
