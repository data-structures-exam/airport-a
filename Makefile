
all:
	gcc -Wall -g -c bagagem.c  -o bagagem.o
	gcc -Wall -g -c lista_palete.c  -o lista_palete.o
	gcc -Wall -g -c lista_voo.c -o lista_voo.o
	gcc -Wall -g -c data.c  -o data.o
	gcc -Wall -g -c palete.c -o palete.o
	gcc -Wall -g -c voo.c -o voo.o
	gcc -Wall -g -c utils.c -o utils.o
	gcc -Wall -g -c pilha_bagagem.c -o pilha_bagagem.o
	gcc -Wall -g -c pista.c -o pista.o
	gcc -g -Wall menu.c *.o -o menu
run:
	./menu

clean:
	rm *.o
	
