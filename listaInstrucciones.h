#ifndef LISTAINSTRUCCIONES_H_INCLUDED
#define LISTAINSTRUCCIONES_H_INCLUDED

#include "instruccion.h"

typedef struct nodoInstruccionAlias
{
    instruccion info;
    nodoInstruccionAlias * sig;
} nodoInstruccion;

typedef nodoInstruccion * listaInstrucciones;

void listaInstruccionesPROC_crearLI(listaInstrucciones &li);//1

void listaInstruccionesPROC_destruirLI(listaInstrucciones &li);//2

boolean listaInstruccionesFUNC_isNull(listaInstrucciones li);//3

int listaInstruccionesFUNC_largo(listaInstrucciones li);//4

void listaInstruccionesPROC_instertFront(listaInstrucciones &li, instruccion info);//5

//utilizada para el armado de la estructura lista de instrucciones
void listaInstruccionesPROC_instertBack(listaInstrucciones &li, instruccion info);//6

//el contador se suma afuera y le pasa para que buclee n veces hasta que da el siguiente elemento
//util para ver todas las instrucciones en la estructura lista de instrucciones cuando se carge para usar en ejecucion
instruccion listaInstruccionesFUNC_darInstruccion(listaInstrucciones li, int numero);//8

//guarda una instrucicon a la lista con el discriminante- tipo del enumeradoopsBasi leer y el nombre de la variable
void listaInstruccionesPROC_agregarInstruccionLEER(StringDyn str, listaInstrucciones &li);//9

//guarda una instrucicon a la lista con el discriminante- tipo del enumeradoopsBasi mostrar y el nombre de la variable
void listaInstruccionesPROC_agregarInstruccionMOSTRAR(StringDyn str, listaInstrucciones &li);//10

//11
void listaInstruccionesPROC_agregarInstruccionAScompuesta(arbolVariables abb, listaInstrucciones &li, listaStrings ls, int nroLinea, boolean &huboError, int &nroLineaWarning, boolean &compiloConCero);//11
//guarda una instrucicon a la lista analizando cual de las combinaciones de 5 elementos es para guardarla con su respectivo structura datos de la union y discriminante
//de existir el error, tirarlo en el formato :
// printf("\n***Error de compilaci%sn - linea %d: para la instruccion de la asignacion con FUNC con 2 argumentos",nroLinea); //tilde

//   Guardo las intruccion en la lista de instrucciones, le paso la lista de substring y se debera validar correctamente todas las combinaciones, tanto LEER, MOSTRAR y asiganciones, dadas en el diseño.
//Utilizando la estructura y haciendo énfasis en la union para las combinaciones en la asignacion.
//
//tiene q retornar una bool para ver si hubo algun error, asi puedo saber si bajo todo o no

//12
void listaInstruccionesPROC_agregarInstruccionASsimpple(arbolVariables abb, listaInstrucciones &li, listaStrings ls, int nroLinea, boolean &huboError);//12

#endif // LISTAINSTRUCCIONES_H_INCLUDED
