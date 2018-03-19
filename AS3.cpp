#include "AS3.h"

void AS3_FUNC_carga(AS3 &as, enumOpsArits func, int valor1, int valor2){
    as.func     = func;
    as.valor1   = valor1;
    as.valor2   = valor2;
}


enumOpsArits AS3_FUNC_darTipoFUNC(AS3 as3){
    return as3.func;
}

int AS3_FUNC_darValor1(AS3 as3){
    return as3.valor1;
}

int AS3_FUNC_darValor2(AS3 as3){    return as3.valor2;
}
