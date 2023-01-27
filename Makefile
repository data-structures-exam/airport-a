
all:
	gcc -Wall -c bagagem.c  -o bagagem.o
	gcc -Wall -c lista_palete.c  -o lista_palete.o
	gcc -Wall -c lista_voo.c -o lista_voo.o
	gcc -Wall -c data.c  -o data.o
	gcc -Wall -c palete.c -o palete.o
	gcc -Wall -c voo.c -o voo.o
	gcc -Wall -c utils.c -o utils.o
	gcc -Wall -c pilha_bagagem.c -o pilha_bagagem.o
	gcc -Wall -c pista.c -o pista.o
	gcc -Wall menu.c *.o -o menu
run:
	./menu

clean:
	rm *.o
	
