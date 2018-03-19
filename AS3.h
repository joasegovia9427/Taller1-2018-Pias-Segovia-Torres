#ifndef AS3_H_INCLUDED
#define AS3_H_INCLUDED

#include "arbolVariables.h"

typedef struct
{
    enumOpsArits func;
    int valor1;
    int valor2;
} AS3;

void AS3_FUNC_carga(AS3 &asignacion, enumOpsArits func, int valor1, int valor2);//1

enumOpsArits AS3_FUNC_darTipoFUNC(AS3 as3);//2

int AS3_FUNC_darValor1(AS3 as3);//3

int AS3_FUNC_darValor2(AS3 as3);//4

#endif // AS3_H_INCLUDED
