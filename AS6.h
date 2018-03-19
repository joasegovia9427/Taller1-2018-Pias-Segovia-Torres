#ifndef AS6_H_INCLUDED
#define AS6_H_INCLUDED

#include "arbolVariables.h"

typedef struct
{
    enumOpsArits func;
    StringDyn nomVariable1;
    StringDyn nomVariable2;
} AS6;

void AS6_FUNC_carga(AS6 &as, enumOpsArits func, StringDyn nomVariable1, StringDyn nomVariable2);//1

enumOpsArits AS6_FUNC_darTipoFUNC(AS6 as6);//2

void AS6_PROC_darNombreVariable1(AS6 as6, StringDyn &nombreVar1);//3

void AS6_PROC_darNombreVariable2(AS6 as6, StringDyn &nombreVar2);//4

StringDyn AS6_FUNC_darNombreVariable1(AS6 as6IN);//5

StringDyn AS6_FUNC_darNombreVariable2(AS6 as6IN);//6

#endif // AS6_H_INCLUDED
