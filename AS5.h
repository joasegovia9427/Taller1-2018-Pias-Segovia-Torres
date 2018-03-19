#ifndef AS5_H_INCLUDED
#define AS5_H_INCLUDED

#include "arbolVariables.h"

typedef struct
{
    enumOpsArits func;
    StringDyn nomVariable;
    int valor1;
} AS5;

void AS5_FUNC_carga(AS5 &as, enumOpsArits func, StringDyn nomVariable, int valor1);//1

enumOpsArits AS5_FUNC_darTipoFUNC(AS5 as5);//2

void AS5_PROC_darNombreVariable(AS5 as5, StringDyn &nombreVar);//3

int AS5_FUNC_darValor1(AS5 as5);//4

StringDyn AS5_FUNC_darNombreVariable(AS5 as5IN);//5

#endif // AS5_H_INCLUDED
