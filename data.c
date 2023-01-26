#include "data.h"



Data *criar_data(int dia, int mes, int ano) {
	Data *data = (Data *)malloc(sizeof(Data));
	data->dia = dia;
	data->mes = mes;
	data->ano = ano;
	return data;
}
