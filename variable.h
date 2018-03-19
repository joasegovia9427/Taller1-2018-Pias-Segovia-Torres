#ifndef VARIABLE_H_INCLUDED
#define VARIABLE_H_INCLUDED

#include "enumOpsBasicas.h"
#include "enumOpsArits.h"

typedef struct
{
    StringDyn nombre;
    int valor;
} variable;


//carga el nombre de una variable pasada por parametro y devuelve una variable con el nombre y valor = 0
void variablePROC_carga(variable &v, StringDyn nombreVar);//1

//recibe dos variables y determina si se llaman igual
boolean variableFUNC_areIguales(variable v1, variable v2);//2

//selectoras
void variablePROC_darNombre(variable v, StringDyn &nombreVar);//3

int variableFUNC_darValor(variable v);//4

// carga una variable a partir de los parametros de entrada
void variableFUNC_PARAM_cargaVariable(variable &v, StringDyn nombreVariable, int valor);//5

StringDyn variablePROC_darNombre_PARAMETRO(variable v);//6

 //significa que v1 es menor que v2
boolean variableFUNC_MenorQue(variable v1, variable v2);//7

void variablePROC_modificarValor(variable &v, int newValor);//8

//borrar el resto menos linea final

#endif // VARIABLE_H_INCLUDED
