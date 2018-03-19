#include "AS4.h"

void AS4_FUNC_carga(AS4 &as, enumOpsArits func, int valor1, StringDyn nomVariable){
    as.func     = func;
    as.valor1   = valor1;
    as.nomVariable = nomVariable;
}
enumOpsArits AS4_FUNC_darTipoFUNC(AS4 as4){    return as4.func;
}
int AS4_FUNC_darValor1(AS4 as4){    return as4.valor1;}
void AS4_PROC_darNombreVariable(AS4 as4, StringDyn &nombreVar){    nombreVar = as4.nomVariable;}

StringDyn AS4_FUNC_darNombreVariable(AS4 as4IN){
    return as4IN.nomVariable;
}
