#include "data.h"

struct tData {
	int dia, mes, ano;
};

Data *criar_data(int dia, int mes, int ano) {
	Data *data = (Data *)malloc(sizeof(Data));
	data->dia = dia;
	data->mes = mes;
	data->ano = ano;
	return data;
}
