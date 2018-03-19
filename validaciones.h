#ifndef VALIDACIONES_H_INCLUDED
#define VALIDACIONES_H_INCLUDED

#include "archivos.h"

void validacionesPROC_guardarVariablesEnABB(listaStrings ls,arbolVariables &abb,boolean &huboError);//1

//2
void validacionesPROC_bucleInstruccionesEjecucion(arbolVariables abb, listaInstrucciones li, int &nroLinea, boolean &huboError);//2

void PROC_compilar(StringDyn nombrePrograma);//3

void PROC_ejecutar(StringDyn nombrePrograma);//4

void PROC_LimpiarYPausa();//5

void cierrePrograma(int opcion);//6

void validacionesPROC_variablesSinUso(arbolVariables abb, listaInstrucciones li, listaStrings &listaNombresOrdenEncontradas);//7

boolean validacionesFUNC_isComentario(listaStrings ls);//8
#endif // VALIDACIONES_H_INCLUDED
