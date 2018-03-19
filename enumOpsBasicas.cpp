#include "enumOpsBasicas.h"

// Carga de una enumOpsBasicas por numero del 0 al 7: recibe un numero codigo 0-7 y retorna una variable enumOpsBasicas con el tipo de operacion para guardar lo correspondiente segunda, incluyendo a la union, si es del AS1 al AS6
void enumOpsBasicasFUNC_carga(enumOpsBasicas &ob, int codigoCeroSieteIN){
    switch (codigoCeroSieteIN)
    {
    case 0: ob = LEER;
        break;
    case 1: ob = MOSTRAR;
        break;
    case 2: ob = enum_AS1;
        break;
    case 3: ob = enum_AS2;
        break;
    case 4: ob = enum_AS3;
        break;
    case 5: ob = enum_AS4;
        break;
    case 6: ob = enum_AS5;
        break;
    case 7: ob = enum_AS6;
        break;
    }
}
