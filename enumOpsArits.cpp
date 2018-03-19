#include "enumOpsArits.h"

//typedef enum{SUM, RES, MUL, DIV}enumOpsArits;

// Carga de una FUNC por comparacion de strDyn: recibe el tercer substring y retorna una variable FUNC con el tipo de FUNC para guardarla en el struct (del AS3 al AS6) dentro de la union
// precondicion, debe validarse con StringDyn_equalAnyFUNCarits que sea una de las 4 funcs
void enumOpsAritsFUNC_carga(enumOpsArits &oa, StringDyn strDynFUNC_IN){
    StringDyn strDynSUM, strDynRES, strDynMUL, strDynDIV;
    StringDynPROC_iniStrDynVarsOpsArits(strDynSUM, strDynRES, strDynMUL, strDynDIV);
    if (StringDyn_equal(strDynFUNC_IN, strDynSUM))
    {
        oa = SUM;
    }
    else if (StringDyn_equal(strDynFUNC_IN, strDynRES))
    {
        oa = RES;
    }
    else if (StringDyn_equal(strDynFUNC_IN, strDynMUL))
    {
        oa = MUL;
    }
    else
    {
        oa = DIV;
    }
    StringDyn_destruir(strDynSUM);
    StringDyn_destruir(strDynRES);
    StringDyn_destruir(strDynMUL);
    StringDyn_destruir(strDynDIV);
}
