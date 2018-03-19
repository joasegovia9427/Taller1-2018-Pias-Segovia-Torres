#ifndef ENUMOPSBASICAS_H_INCLUDED
#define ENUMOPSBASICAS_H_INCLUDED


#include "listaStrings.h"

typedef enum {LEER, MOSTRAR, enum_AS1, enum_AS2, enum_AS3, enum_AS4, enum_AS5, enum_AS6} enumOpsBasicas;
//asignacion se divide en 6
//--> 8 ops basica

// Carga de una enumOpsBasicas por numero del 0 al 7: recibe un numero codigo 0-7 y retorna una variable enumOpsBasicas con el tipo de operacion para guardar lo correspondiente segunda, incluyendo a la union, si es del AS1 al AS6
void enumOpsBasicasFUNC_carga(enumOpsBasicas &ob, int codigoCeroSieteIN);//1

#endif // ENUMOPSBASICAS_H_INCLUDED
