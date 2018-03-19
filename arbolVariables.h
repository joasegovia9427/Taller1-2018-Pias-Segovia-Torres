#ifndef ARBOLVARIABLES_H_INCLUDED
#define ARBOLVARIABLES_H_INCLUDED

#include "variable.h"

typedef struct nodoVariableAlias
{
    variable info;
    nodoVariableAlias *Hizq;
    nodoVariableAlias *Hder;
} nodoVariable;

typedef nodoVariable *arbolVariables;


//crea el abb en null, como modifica el mismo abb hay que pasarlo por referencia
void arbolVariablesPROC_crearABB(arbolVariables &abb);//1

void arbolVariablesPROC_destruirABB(arbolVariables &abb);//2

boolean arbolVariablesFUNC_isArbolVacio(arbolVariables av);//3

void arbolVariablesPROC_agregarVariableAlArbol(arbolVariables &av, variable v);//4

void arbolVariablesPROC_modificarVariableEnABB(arbolVariables &abb, StringDyn nombreVar, int nuevoValor);//5

boolean arbolVariablesFUNC_verificarExistenciaString(arbolVariables av, StringDyn str);//6

variable arbolVariablesFUNC_darRaiz(arbolVariables abb);//7

arbolVariables arbolVariablesFUNC_darHizq(arbolVariables abb);//8

arbolVariables arbolVariablesFUNC_darHder(arbolVariables abb);//9

void arbolVariablesPROC_PrintNombreValor(arbolVariables abb, StringDyn nombreVar);//10

int arbolVariablesFUNC_valorDeVariable(arbolVariables abb, StringDyn nombreVar);//11

void arbolVariablesPROC_obtenerListaDeNombres(arbolVariables abb, listaStrings &variablesUSADAS);//12
#endif // ARBOLVARIABLES_H_INCLUDED
