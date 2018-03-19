#ifndef ARCHIVOS_H_INCLUDED
#define ARCHIVOS_H_INCLUDED

#include "listaInstrucciones.h"

// ===============================================================
// MANEJO DE ARCHIVOS
// ===============================================================

// Vetrifica la Existencia de un archivo pasado por parametro
boolean archivoFUNC_existeArchivo(StringDyn strNombreArchivo_con_extension);//1

// Crea un Archivo, recibe el nombre del archivo con extension incluida
void archivoPROC_crearArchivo(FILE * &archivo, StringDyn nombreArchivo);//2

// Elimina un Archivo, recibe el nombre del archivo con extension incluida
void archivoPROC_borrarArchivo(StringDyn nombreArchivo);//3

// Abre el archivo y lo deja abierto
void archivoPROC_abrirArchivo(FILE * &archivo, StringDyn nombreArchivo, StringDyn como);//4

// Cierra el archivo
void archivoPROC_cerrarArchivo(FILE * &archivo);//5

// Verifica si un archivo esta vacío
boolean archivoFUNC_isArchivoVacio(StringDyn nombreArchivo_con_extension);//6

// si es EOF devolver linea = NULL
StringDyn archivoFUNC_cargarLaSiguienteLinea(FILE * archivo);//7

// ===============================================================
// MANEJO DE ARCHIVOS - LECTURA Y ESCRITURA DE DATOS
// ===============================================================
// ===============================================================
// PRECONDICION NECESARIA PARA TODOS LOS METODOS
// ABRIR EL ARCHIVO ANTES DE LLAMAR EL METODO Y
// CERRAR EL ARCHIVO DESPUES QUE SE CORRA EL MISMO
// ===============================================================

// Baja el arbol de variables al archivo
void archivoPROC_bajarABB_de_Variables_al_Archivo(arbolVariables abb, FILE * archivo);//8

// Levanta el arbol de variables a memoria
void archivoPROC_levantoABB_de_Variables_a_Memoria(arbolVariables &abb,FILE * archivo);//9

// Baja la estructura de variable al archivo
void archivoPROC_bajarVariable(variable v, FILE * archivo);//10

// Levanta la estructura de variable
void archivoPROC_levantarVariable(variable &v, FILE * archivo);//11

// Baja la lista de instrucciones al archivo
void archivoPROC_listaInstrucciones_BajarLista_al_Archivo(listaInstrucciones li, FILE * archivo);//12

// Levanta la lista de instrucciones a memoria
void archivoPROC_listaInstrucciones_LevantarLista_a_Memoria(listaInstrucciones &li, FILE * archivo);//13

// Bajar la estructura Instrucciones al archivo
void archivoPROC_listaInstrucciones_bajarInstruccion(instruccion i, FILE * archivo);//14

// Levantar la estructura Instrucciones al archivo
void archivoPROC_listaInstrucciones_levantarInstruccion(instruccion &i, FILE * archivo);//15

// Baja la estructura AS3 al archivo
void archivoPROC_listaInstrucciones_bajarAS3(AS3 as3, FILE * archivo);//16

// Levanta la estructura AS3
void archivoPROC_listaInstrucciones_levantarAS3(AS3 &as3, FILE * archivo);//17

// Baja la estructura AS4 al archivo
void archivoPROC_listaInstrucciones_bajarAS4(AS4 as4, FILE * archivo);//18

// Levanta la estructura AS4
void archivoPROC_listaInstrucciones_levantarAS4(AS4 &as4, FILE * archivo);//19

// Baja la estructura AS5 al archivo
void archivoPROC_listaInstrucciones_bajarAS5(AS5 as5, FILE * archivo);//20

// Levanta la estructura AS5
void archivoPROC_listaInstrucciones_levantarAS5(AS5 &as5, FILE * archivo);//21

// Baja la estructura AS6 al archivo
void archivoPROC_listaInstrucciones_bajarAS6(AS6 as6, FILE * archivo);//22

// Levanta la estructura AS6
void archivoPROC_listaInstrucciones_levantarAS6(AS6 &as6, FILE * archivo);//23

// Baja la estructura Operaciones Basicas al archivo
void archivoPROC_bajarEnumOpsBasicas(enumOpsBasicas ob, FILE * archivo);//24

// Levanta la estructura Operaciones Basicas
void archivoPROC_levantarEnumOpsBasicas(enumOpsBasicas &ob, FILE * archivo);//25

void archivoPROC_bajarEnumArits(enumOpsArits oa, FILE * archivo);//26

void archivoPROC_levantarEnumArits(enumOpsArits &oa, FILE * archivo);//27

void archivoPROC_bajarString(StringDyn s, FILE * archivo);//30

void archivoPROC_levantarString(StringDyn &s, FILE * archivo);//31

void archivoPROC_bajarBoolean(boolean b, FILE * archivo);//32

void archivoPROC_levantarBoolean(boolean &b, FILE * archivo);//33

void archivoPROC_guardarLog(StringDyn log);//34

void archivoPROC_agregarSaltoLineaAlFinal(StringDyn nombreConcatenado);//35

#endif // ARCHIVOS_H_INCLUDED
