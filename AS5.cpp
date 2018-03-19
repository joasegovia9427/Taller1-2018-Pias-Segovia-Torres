#include "AS5.h"

void AS5_FUNC_carga(AS5 &as, enumOpsArits func, StringDyn nomVariable, int valor1){    as.func     = func;
    as.nomVariable = nomVariable;
    as.valor1   = valor1;
}
enumOpsArits AS5_FUNC_darTipoFUNC(AS5 as5){    return as5.func;}

void AS5_PROC_darNombreVariable(AS5 as5, StringDyn &nombreVar){    nombreVar = as5.nomVariable;}

int AS5_FUNC_darValor1(AS5 as5){    return as5.valor1;}

StringDyn AS5_FUNC_darNombreVariable(AS5 as5IN){
    return as5IN.nomVariable;
}
