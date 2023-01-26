
all:
	gcc -c bagagem.c  -o bagagem.o
	gcc -c lista_palete.c  -o lista_palete.o
	gcc -c lista_voo.c -o lista_voo.o
	gcc -c data.c  -o data.o
	gcc -c menu.c -o menu.o
	gcc -c palete.c -o palete.o
	gcc -c voo.c -o voo.o
	gcc -c utils.c -o utils.o
	gcc -c pilha_bagagem.c -o pilha_bagagem.o
	gcc -c pista.c -o pista.o
run:
	./main

clean:
	rm *.o
	