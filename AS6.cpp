#include "AS6.h"

void AS6_FUNC_carga(AS6 &as, enumOpsArits func, StringDyn nomVariable1, StringDyn nomVariable2){

    as.func = func;
    as.nomVariable1 = nomVariable1;
    as.nomVariable2 = nomVariable2;
enumOpsArits AS6_FUNC_darTipoFUNC(AS6 as6){

void AS6_PROC_darNombreVariable1(AS6 as6, StringDyn &nombreVar1){
void AS6_PROC_darNombreVariable2(AS6 as6, StringDyn &nombreVar2){
}

StringDyn AS6_FUNC_darNombreVariable1(AS6 as6IN){
    return as6IN.nomVariable1;
}

StringDyn AS6_FUNC_darNombreVariable2(AS6 as6IN){
    return as6IN.nomVariable2;
}