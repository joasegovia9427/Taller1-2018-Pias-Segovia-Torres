#ifndef INSTRUCCION_H_INCLUDED
#define INSTRUCCION_H_INCLUDED

#include "AS3.h"
#include "AS4.h"
#include "AS5.h"
#include "AS6.h"

typedef struct
{
    StringDyn nombreVar;
    enumOpsBasicas tipoInstruccion; //typedef enum {LEER, MOSTRAR, enum_AS1, enum_AS2, enum_AS3, enum_AS4, enum_AS5, enum_AS6} enumOpsBasicas;
    union
    {
        int numeroEntero;
        StringDyn nomVar1;
        AS3 AS3_funcIntInt;
        AS4 AS4_funcIntVar;
        AS5 AS5_FuncVarInt;
        AS6 AS6_FuncVarVar;
    } discInstruccion;
} instruccion;

//1
void instruccionFUNC_cargar(instruccion &i, StringDyn nombreVar, enumOpsBasicas tipoInstruccion, int numeroEntero, StringDyn nomVar1, AS3 AS3_funcIntInt, AS4 AS4_funcIntVar, AS5 AS5_FuncVarInt, AS6 AS6_FuncVarVar);//1

//selectoras

void instruccionPROC_darNombreVar0(instruccion instIN, StringDyn &nombreVar1LadoIzq);//2

enumOpsBasicas instruccionFUNC_darTipoInstruccion(instruccion instIN);//3

int instruccionFUNC_darNumeroEntero(instruccion instIN);//4

void instruccionPROC_darNombreVar1(instruccion instIN, StringDyn &nombreVar1LadoDer);//5

AS3 instruccionFUNC_darAS3_funcIntInt(instruccion instIN);//6

AS4 instruccionFUNC_darAS4_funcIntVar(instruccion instIN);//7

AS5 instruccionFUNC_darAS5_FuncVarInt(instruccion instIN);//8

AS6 instruccionFUNC_darAS6_FuncVarVar(instruccion instIN);//9

StringDyn instruccionFUNC_darNombreVar0(instruccion instIN);//10

StringDyn instruccionFUNC_darNombreVar1(instruccion instIN);//11
#endif // INSTRUCCION_H_INCLUDED
