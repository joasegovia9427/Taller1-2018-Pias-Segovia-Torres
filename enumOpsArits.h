#ifndef ENUMOPSARITS_H_INCLUDED
#define ENUMOPSARITS_H_INCLUDED

#include "listaStrings.h"

typedef enum{SUM, RES, MUL, DIV}enumOpsArits;

// Carga de una FUNC por comparacion de strDyn: recibe el tercer substring y retorna una variable FUNC con el tipo de FUNC para guardarla en el struct (del AS3 al AS6) dentro de la union
// precondicion, debe validarse con StringDyn_equalAnyFUNCarits que sea una de las 4 funcs
void enumOpsAritsFUNC_carga(enumOpsArits &oa, StringDyn strDynFUNC_IN);//1

#endif // ENUMOPSARITS_H_INCLUDED
