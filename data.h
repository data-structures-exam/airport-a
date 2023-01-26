#ifndef DATA_H
#define DATA_H

#include "stdio.h"
#include "stdlib.h"

struct tData {
	int dia, mes, ano;
};
typedef struct tData Data;

Data *criar_data(int dia, int mes, int ano);

#endif
