#ifndef LISTASTRINGS_H_INCLUDED
#define LISTASTRINGS_H_INCLUDED

#include "String.h"

typedef struct nodoListaStringAlias
{
    StringDyn info;
    nodoListaStringAlias * sig;
} nodoListaString;

typedef nodoListaString * listaStrings;

void listaStringsPROC_crearLista(listaStrings &ls);//1

void listaStringsPROC_destruirLista(listaStrings &ls);//2

int listaStringsFUNC_largo(listaStrings ls);//3

boolean listaStringsFUNC_isNull(listaStrings ls);//4 //o FUNC_isVacia

void listaStringsPROC_instertFront(listaStrings &ls, StringDyn info);//5

//utilizada para la particion de substrings
void listaStringsPROC_instertBack(listaStrings &ls, StringDyn info);//6

boolean listaStringsFUNC_isNodoPertenece(listaStrings ls, StringDyn info);//7

//----------------------
//precondicion: se sabe que tiene 5 justo
//estos estan para que devuelva el string directo como info

StringDyn listaStringsFUNC_darPRIMERstr(listaStrings ls);//8

StringDyn listaStringsFUNC_darSEGUNDOstr(listaStrings ls);//9

StringDyn listaStringsFUNC_darTERCERstr(listaStrings ls);//10

StringDyn listaStringsFUNC_darCUARTOstr(listaStrings ls);//11

StringDyn listaStringsFUNC_darQUINTOstr(listaStrings ls);//12

//el contador se suma afuera y le pasa para que buclee n veces hasta que da el siguiente elemento
//util para ver todas las variables en la seccion variables
//precondicion: no debe estar vacia
StringDyn listaStringsFUNC_darSIGUIENTEstr(listaStrings ls, int numero);//13

void PROC_partirStrEnSubStrs(StringDyn linea, listaStrings &lsSubsString);//14

//PRECONDICIONES PARA LOS SIGUIENTES 3 es que no este vacia

listaStrings listaStringsFUNC_listaSinPrimerElemento(listaStrings lsCompilacion);//15

void listaStringsPROC_resto(listaStrings &ls);//16

void listaStringsPROC_obtenerUltimo(listaStrings ls, StringDyn &ultimoINFO);//17

int listaStringsFUNC_ocurrenciasDeInfo(listaStrings ls, StringDyn info);//18

void listaStringsPROC_print(listaStrings ls);//19
#endif // LISTASTRINGS_H_INCLUDED
