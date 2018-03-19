#include "AS6.h"

void AS6_FUNC_carga(AS6 &as, enumOpsArits func, StringDyn nomVariable1, StringDyn nomVariable2){

    as.func = func;
    as.nomVariable1 = nomVariable1;
    as.nomVariable2 = nomVariable2;}
enumOpsArits AS6_FUNC_darTipoFUNC(AS6 as6){    return as6.func;}

void AS6_PROC_darNombreVariable1(AS6 as6, StringDyn &nombreVar1){     nombreVar1 = as6.nomVariable1;}
void AS6_PROC_darNombreVariable2(AS6 as6, StringDyn &nombreVar2){     nombreVar2 = as6.nomVariable2;
}

StringDyn AS6_FUNC_darNombreVariable1(AS6 as6IN){
    return as6IN.nomVariable1;
}

StringDyn AS6_FUNC_darNombreVariable2(AS6 as6IN){
    return as6IN.nomVariable2;
}
