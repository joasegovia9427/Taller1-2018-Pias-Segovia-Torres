#ifndef STRING_H_INCLUDED
#define STRING_H_INCLUDED

#include "boolean.h"

const int MAX = 80;
typedef char * StringDyn;

void StringDyn_crear(StringDyn &s);//1
/* crea un string vacío */

void StringDyn_crearDadoLargo(StringDyn &s, int largo);//2

void StringDyn_destruir(StringDyn &s);//3
/* libera la memoria usada por el string */

int StringDyn_largo(StringDyn s);//4
/* devuelve el largo del string s */

void StringDyn_copiar(StringDyn &s1, StringDyn s2);//5
/* copia el contenido del string s2 en s1 */

void StringDyn_scan(StringDyn &s);//6
/* lee el string s desde teclado */

void StringDyn_concatenar(StringDyn &s1, StringDyn s2);//7
/* concatena el contenido de s2 al final de s1 */

void StringDyn_swap(StringDyn &s1, StringDyn &s2);//8
/* intercambia los contenidos de s1 y s2 */

void StringDyn_print(StringDyn s);//9
/* imprime el string s por pantalla */

boolean StringDyn_menor(StringDyn s1, StringDyn s2);//10
//es en abc, testear porque se usara para las id del ABB
/* determina si s1 es alfabéticamente menor que s2 */

boolean StringDyn_equal(StringDyn s1, StringDyn s2);//11
/* determina si los strings s1 y s2 son iguales */

boolean StringDyn_contiene_MAYUSCULAS(StringDyn s1);//12
/* determina si un strings s1 contiene letras MAYUSCULAS */

boolean StringDyn_contiene_minusculas(StringDyn s1);//13
/* determina si un strings s1 contiene letras minusculas */

boolean StringDyn_contiene_numeros(StringDyn s1);//14
/* determina si un strings s1 contiene numeros */

int StringDyn_cantidad_de_SubString(StringDyn s1);//15
/* devuelve la cantidad de subString de una cadena */

//valida que el s1 sea el signo =
boolean StringDyn_equalSignoIgual(StringDyn s1);//16

//valida que el s1 sea igual a una de las funcs, SUM DIV RES MUL
boolean StringDyn_equalAnyFUNCarits(StringDyn s1);//17

//valida que el s1 sea igual a un numero entero
boolean StringDyn_equalNumeroEntero(StringDyn s1);//18

//19
void StringDynPROC_iniStrDynVarsCompilar(StringDyn &PROGRAMA, StringDyn &VARIABLES, StringDyn &INSTRUCCIONES, StringDyn &LEER, StringDyn &MOSTRAR);//19

//20
void StringDynPROC_iniStrDynVarsMain(StringDyn &salir, StringDyn &compilar, StringDyn &ejecutar);//20

//21
void StringDynPROC_iniStrDynVarsOpsArits(StringDyn &SUM, StringDyn &RES, StringDyn &MUL, StringDyn &DIV);//21

//Devuelve Cargado en un StringDyn las exttensiones de los archivos .csim .vars .inst
//22
void StringDynPROC_iniStrDynExtensionesArchivos(StringDyn &ext_csim, StringDyn &ext_vars, StringDyn &ext_inst);//22

void StringDynPROC_separarPrimerPalabra(StringDyn linea, StringDyn &palabra, StringDyn &restoLinea);//23

//Funcion que compara un string con Ascii para determinar si el string = SUM
boolean StringDyn_equalSUM(StringDyn s1);//24

//Funcion que compara un string con Ascii para determinar si el string = RES
boolean StringDyn_equalRES(StringDyn s1);//25

//Funcion que compara un string con Ascii para determinar si el string = MUL
boolean StringDyn_equalMUL(StringDyn s1);//26

//Funcion que compara un string con Ascii para determinar si el string = DIV
boolean StringDyn_equalDIV(StringDyn s1);//27

void StringDyn_copiarDadoLargo(StringDyn &s1,StringDyn s2, int largo, int inicio);//28

StringDyn StringDyn_concatenarFUNC(StringDyn s1, StringDyn s2);//29
/* concatena el contenido de las entradas y lo retorna */

int StringDynFUNC_stringToNumeric(StringDyn s1);//30

void StringDynPROC_limpiarFinalLinea(StringDyn &s1);//31

void StringDynPROC_limpiarTabsLinea(StringDyn &s1);//32

void StringDynPROC_siSoloEspaciosCaracterNulo(StringDyn &s1);//33

void StringDynPROC_quitarSimboloSignoNeg(StringDyn &s1);//34

boolean StringDyn_contiene_minusculasSolo(StringDyn s1);//35

#endif // STRING_H_INCLUDED
