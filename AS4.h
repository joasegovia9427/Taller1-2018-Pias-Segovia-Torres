#ifndef AS4_H_INCLUDED
#define AS4_H_INCLUDED

#include "arbolVariables.h"

typedef struct
{
    enumOpsArits func;
    int valor1;
    StringDyn nomVariable;
} AS4;

void AS4_FUNC_carga(AS4 &as, enumOpsArits func, int valor1, StringDyn nomVariable);//1

enumOpsArits AS4_FUNC_darTipoFUNC(AS4 as4);//2

int AS4_FUNC_darValor1(AS4 as4);//3

void AS4_PROC_darNombreVariable(AS4 as4, StringDyn &nombreVar);//4

StringDyn AS4_FUNC_darNombreVariable(AS4 as4IN);//5
#endif // AS4_H_INCLUDED
