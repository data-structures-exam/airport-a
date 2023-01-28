#include "utils.h"

int ler_linha(char str[], int num_char) {
	int ch = getchar(), i = 0;
	if (ch != '\n') 
		str[i++] = ch;

	while ((ch = getchar()) != '\n') {
		if (i < num_char - 1)
			str[i++] = ch;
	}
	str[i] = '\0';
	return i; // número de caracteres lido
}
