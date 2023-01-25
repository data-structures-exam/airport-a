#include "utils.h"

int ler_linha(char str[], int num_char) {
	int ch, i = 0;
	while ((ch = getchar()) != '\n')
		if (i < n)
			str[i++] = ch;
	getchar(); // remover o '\n' do buffer
	str[i] = '\0';
	return i; // número de caracteres lido
}
