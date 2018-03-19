#include <time.h>
#include "archivos.h"



boolean archivoFUNC_existeArchivo(StringDyn strNombreArchivo_con_extension)
{

    boolean isExiste = FALSE;
    FILE* aux;
    aux = fopen(strNombreArchivo_con_extension,"r");
    if (aux != NULL)
    {
        isExiste = TRUE;
    }
    else
    {

        fclose(aux);
    }

    return isExiste;

}

void archivoPROC_crearArchivo(FILE * &archivo, StringDyn nombreArchivo)
{
   archivo = fopen (nombreArchivo, "wb");

}

void archivoPROC_borrarArchivo(StringDyn nombreArchivo){

    remove(nombreArchivo);

}

void archivoPROC_abrirArchivo(FILE * &archivo, StringDyn nombreArchivo, StringDyn como)
{

    archivo = fopen(nombreArchivo,como);
}

void archivoPROC_cerrarArchivo(FILE * &archivo)
{
    if (archivo != NULL)
    {
        fclose(archivo);

    }
}

boolean archivoFUNC_isArchivoVacio(StringDyn nombreArchivo_con_extension)
{
    boolean isVacio = FALSE;
    FILE* aux;
    aux = fopen(nombreArchivo_con_extension,"rb");
    fseek (aux, 0, SEEK_END);

    if (ftell(aux) == 0)
    {
        isVacio = TRUE;
    }
    fseek (aux, 0, SEEK_SET);
    fclose(aux);
    return isVacio;
}

StringDyn archivoFUNC_cargarLaSiguienteLinea(FILE * archivo)
{

    StringDyn linea;
    StringDyn_crearDadoLargo(linea, MAX);

    int i = 0;
    fscanf(archivo, "%c", &linea[i]);
    if(!feof(archivo) && linea[i] != '\n')
    {
        do
        {
            i++;
            fscanf(archivo, "%c", &linea[i]);

        }
        while(!feof(archivo) && linea[i] != '\n');

    }
    i++;
    linea[i] = '\0';
    StringDynPROC_limpiarFinalLinea(linea);
    StringDynPROC_limpiarTabsLinea(linea);
    StringDynPROC_siSoloEspaciosCaracterNulo(linea);
    return linea;



}

// ===============================================================
// ===============================================================

void archivoPROC_bajarABB_de_Variables_al_Archivo(arbolVariables abb, FILE * archivo)
{
    if (abb != NULL)
    {
        archivoPROC_bajarVariable(abb->info, archivo);
        archivoPROC_bajarABB_de_Variables_al_Archivo(abb->Hizq,archivo);
        archivoPROC_bajarABB_de_Variables_al_Archivo(abb->Hder,archivo);
    }
}

void archivoPROC_levantoABB_de_Variables_a_Memoria(arbolVariables &abb,FILE * archivo)
{
    variable v;
    archivoPROC_levantarVariable(v, archivo);
    while(!feof(archivo))
    {
        arbolVariablesPROC_agregarVariableAlArbol(abb,v);
        archivoPROC_levantarVariable(v, archivo);
    }

}

void archivoPROC_bajarVariable(variable v, FILE * archivo)
{
    // Bajo el nombre
    StringDyn nombre;
    StringDyn_crear(nombre);
    variablePROC_darNombre(v, nombre);
    archivoPROC_bajarString(nombre, archivo);

    // Bajo el valor
    int valor = variableFUNC_darValor(v);
    fwrite(&valor,sizeof(int),1,archivo);

}

void archivoPROC_levantarVariable(variable &v, FILE * archivo)
{
    // Levantar el nombre
    StringDyn nombre;
    StringDyn_crear(nombre);
    archivoPROC_levantarString(nombre, archivo);

    // Levantar valor
    int valor = 0;
    fread(&valor, sizeof(int), 1, archivo);
    variableFUNC_PARAM_cargaVariable(v, nombre, valor);
}

void archivoPROC_listaInstrucciones_BajarLista_al_Archivo(listaInstrucciones li, FILE * archivo)
{

    while(li != NULL)
    {
        archivoPROC_listaInstrucciones_bajarInstruccion(li->info, archivo);
        li = li->sig;
    }
}

void archivoPROC_listaInstrucciones_LevantarLista_a_Memoria(listaInstrucciones &li, FILE * archivo)
{

    instruccion inst;
    archivoPROC_listaInstrucciones_levantarInstruccion(inst, archivo);

    while(!feof(archivo))
    {
        listaInstruccionesPROC_instertBack(li, inst);
        archivoPROC_listaInstrucciones_levantarInstruccion(inst, archivo);

    }

}

void archivoPROC_listaInstrucciones_bajarInstruccion(instruccion i, FILE * archivo)
{

    // Bajo el nombre de la Variable
    StringDyn nombre;
    StringDyn_crear(nombre);
    instruccionPROC_darNombreVar0(i, nombre);
    archivoPROC_bajarString(nombre, archivo);

    // Bajo el tipo de Operacion Basica de la Instruccion
    enumOpsBasicas ob;
    ob = instruccionFUNC_darTipoInstruccion(i);
    archivoPROC_bajarEnumOpsBasicas(ob, archivo);

    // Bajo la asiganacion correspondiente
    // al tipo de Operacion Basica cargado
    // previamente

    switch (ob)
    {

     case LEER:

        instruccionPROC_darNombreVar0(i, nombre);
        archivoPROC_bajarString(nombre, archivo);

      break;

      case MOSTRAR:

        instruccionPROC_darNombreVar0(i, nombre);
        archivoPROC_bajarString(nombre, archivo);

     break;


    case enum_AS1:

        // bajo al archivo el int que se va a asignar como
        // asignado a la variable con el nombre dentro
        // de la estructura
        int valor1;
        valor1 = instruccionFUNC_darNumeroEntero(i);
        fwrite(&valor1,sizeof(int),1,archivo);

        break;

    case enum_AS2:

        // bajo al archivo binario un StringDyn
        // Bajo el nombre de la Variable
        StringDyn nombre;
        StringDyn_crear(nombre);
        instruccionPROC_darNombreVar1(i, nombre);
        archivoPROC_bajarString(nombre, archivo);

        break;
    case enum_AS3:

        // bajo al archivo binario un AS3 cargado
        archivoPROC_listaInstrucciones_bajarAS3(instruccionFUNC_darAS3_funcIntInt(i),archivo);
        break;

    case enum_AS4:

        // bajo al archivo binario un AS4 cargado
        archivoPROC_listaInstrucciones_bajarAS4(instruccionFUNC_darAS4_funcIntVar(i),archivo);
        break;

    case enum_AS5:

        // bajo al archivo binario un AS5 cargado
        archivoPROC_listaInstrucciones_bajarAS5(instruccionFUNC_darAS5_FuncVarInt(i),archivo);
        break;

    case enum_AS6:

        // bajo al archivo binario un AS6 cargado
        archivoPROC_listaInstrucciones_bajarAS6(instruccionFUNC_darAS6_FuncVarVar(i),archivo);
        break;

    }
}

void archivoPROC_listaInstrucciones_levantarInstruccion(instruccion &i, FILE * archivo)
{

    enumOpsBasicas ob;
    int valor1 = 0;
    AS3 as3;
    AS4 as4;
    AS5 as5;
    AS6 as6;
    StringDyn nombre_var0, nombre_var1;
    StringDyn_crear(nombre_var0);
    StringDyn_crear(nombre_var1);

    archivoPROC_levantarString(nombre_var0, archivo);
    archivoPROC_levantarEnumOpsBasicas(ob, archivo);

    switch (ob)
    {

    case LEER:

        archivoPROC_levantarString(nombre_var0, archivo);
        break;

    case MOSTRAR:

        archivoPROC_levantarString(nombre_var0, archivo);
        break;

    case enum_AS1:

        fread(&valor1, sizeof(int), 1, archivo);

        break;

    case enum_AS2:

        archivoPROC_levantarString(nombre_var1, archivo);

        break;
    case enum_AS3:

        archivoPROC_listaInstrucciones_levantarAS3(as3, archivo);

        break;

    case enum_AS4:

        archivoPROC_listaInstrucciones_levantarAS4(as4, archivo);
        break;

    case enum_AS5:

        archivoPROC_listaInstrucciones_levantarAS5(as5, archivo);
        break;

    case enum_AS6:

        archivoPROC_listaInstrucciones_levantarAS6(as6, archivo);
        break;

    }

    instruccionFUNC_cargar(i,nombre_var0, ob,valor1,nombre_var1,as3,as4,as5,as6);

}

void archivoPROC_listaInstrucciones_bajarAS3(AS3 as3, FILE * archivo)
{

    archivoPROC_bajarEnumArits(AS3_FUNC_darTipoFUNC(as3), archivo);

    // Bajo el valor1
    int valor1 = AS3_FUNC_darValor1(as3);
    fwrite(&valor1,sizeof(int),1,archivo);

    // Bajo el valor2
    int valor2 = AS3_FUNC_darValor2(as3);
    fwrite(&valor2,sizeof(int),1,archivo);
}

void archivoPROC_listaInstrucciones_levantarAS3(AS3 &as3, FILE * archivo)
{

    enumOpsArits oa;
    archivoPROC_levantarEnumArits(oa, archivo);

    // Levanto valor1
    int valor1 = 0;
    fread(&valor1, sizeof(int), 1, archivo);

    // Levanto valor2
    int valor2 = 0;
    fread(&valor2, sizeof(int), 1, archivo);

    AS3_FUNC_carga(as3, oa, valor1, valor2);
}

void archivoPROC_listaInstrucciones_bajarAS4(AS4 as4, FILE * archivo)
{

    archivoPROC_bajarEnumArits(AS4_FUNC_darTipoFUNC(as4), archivo);
    // Bajo el valor1
    int valor1 = AS4_FUNC_darValor1(as4);
    fwrite(&valor1,sizeof(int),1,archivo);

    // Bajo el nombre de la Variable
    StringDyn nombre;
    StringDyn_crear(nombre);
    AS4_PROC_darNombreVariable(as4, nombre);
    archivoPROC_bajarString(nombre, archivo);

}

void archivoPROC_listaInstrucciones_levantarAS4(AS4 &as4, FILE * archivo)
{
    enumOpsArits oa;

    archivoPROC_levantarEnumArits(oa, archivo);

    // Levanto valor1
    int valor1 = 0;
    fread(&valor1, sizeof(int), 1, archivo);

    // Levantar el nombre de la variable
    StringDyn nombre;
    StringDyn_crear(nombre);
    archivoPROC_levantarString(nombre, archivo);

    AS4_FUNC_carga(as4, oa,valor1,nombre);
}

void archivoPROC_listaInstrucciones_bajarAS5(AS5 as5, FILE * archivo)
{
    archivoPROC_bajarEnumArits(AS5_FUNC_darTipoFUNC(as5), archivo);

    // Bajo el nombre de la Variable
    StringDyn nombre;
    StringDyn_crear(nombre);
    AS5_PROC_darNombreVariable(as5, nombre);
    archivoPROC_bajarString(nombre, archivo);

    // Bajo el valor1
    int valor1 = AS5_FUNC_darValor1(as5);
    fwrite(&valor1,sizeof(int),1,archivo);


}

void archivoPROC_listaInstrucciones_levantarAS5(AS5 &as5, FILE * archivo)
{

    enumOpsArits oa;
    archivoPROC_levantarEnumArits(oa, archivo);

    // Levantar el nombre de la variable
    StringDyn nombre;
    StringDyn_crear(nombre);
    archivoPROC_levantarString(nombre, archivo);

    // Levanto valor1
    int valor1 = 0;
    fread(&valor1, sizeof(int), 1, archivo);

    AS5_FUNC_carga(as5, oa,nombre,valor1);

}

void archivoPROC_listaInstrucciones_bajarAS6(AS6 as6, FILE * archivo)
{

    archivoPROC_bajarEnumArits(AS6_FUNC_darTipoFUNC(as6), archivo);

    // Bajo el nombre de la Variable 1
    StringDyn nombre1;
    StringDyn_crear(nombre1);
    AS6_PROC_darNombreVariable1(as6, nombre1);
    archivoPROC_bajarString(nombre1, archivo);

    // Bajo el nombre de la Variable 2
    StringDyn nombre2;
    StringDyn_crear(nombre2);
    AS6_PROC_darNombreVariable2(as6, nombre2);
    archivoPROC_bajarString(nombre2, archivo);
}

void archivoPROC_listaInstrucciones_levantarAS6(AS6 &as6, FILE * archivo)
{
    enumOpsArits oa;
    archivoPROC_levantarEnumArits(oa, archivo);

    // Levantar el nombre de la variable 1
    StringDyn nombre1;
    StringDyn_crear(nombre1);
    archivoPROC_levantarString(nombre1, archivo);

    // Levantar el nombre de la variable 2
    StringDyn nombre2;
    StringDyn_crear(nombre2);
    archivoPROC_levantarString(nombre2, archivo);

    AS6_FUNC_carga(as6, oa,nombre1,nombre2);
}

void archivoPROC_bajarEnumOpsBasicas(enumOpsBasicas ob, FILE * archivo)
{
    int id_ob;

    switch (ob)
    {

    case LEER:
        id_ob = 0;
        break;

    case MOSTRAR:
        id_ob = 1;
        break;

    case enum_AS1:
        id_ob = 2;
        break;
    case enum_AS2:
        id_ob = 3;
        break;
    case enum_AS3:
        id_ob = 4;
        break;
    case enum_AS4:
        id_ob = 5;
        break;
    case enum_AS5:
        id_ob = 6;
        break;
    case enum_AS6:
        id_ob = 7;
        break;
    }
    fwrite(&id_ob, sizeof(int),1,archivo);
}

void archivoPROC_levantarEnumOpsBasicas(enumOpsBasicas &ob, FILE * archivo)
{
    int id_ob;
    fread(&id_ob, sizeof(int),1,archivo);
    switch (id_ob)
    {
        case 0:
        ob = LEER;
        break;
        case 1:
        ob = MOSTRAR;
        break;

    case 2:
        ob = enum_AS1;
        break;
    case 3:
        ob = enum_AS2;
        break;
    case 4:
        ob = enum_AS3;
        break;
    case 5:
        ob = enum_AS4;
        break;
    case 6:
        ob = enum_AS5;
        break;
    case 7:
        ob = enum_AS6;
        break;
    }
}

void archivoPROC_bajarEnumArits(enumOpsArits oa, FILE * archivo)
{
    int id_oa;
    switch (oa)
    {
    case SUM:
        id_oa = 0;
        break;
    case RES:
        id_oa = 1;
        break;
    case MUL:
        id_oa = 2;
        break;
    case DIV:
        id_oa = 3;
        break;
    }
    fwrite(&id_oa, sizeof(int),1,archivo);
}

void archivoPROC_levantarEnumArits(enumOpsArits &oa, FILE * archivo)
{
    int id_oa;
    fread(&id_oa, sizeof(int),1,archivo);
    switch (id_oa)
    {
    case 0:
        oa = SUM;
        break;
    case 1:
        oa = RES;
        break;
    case 2:
        oa = MUL;
        break;
    case 3:
        oa = DIV;
        break;
    }
}

void archivoPROC_bajarString(StringDyn s, FILE * archivo)
{
    int i=0;
    while(s[i] != '\0')
    {
        fwrite(&s[i], sizeof(char),1,archivo);
        i++;
    }
    fwrite(&s[i], sizeof(char),1,archivo);
}

void archivoPROC_levantarString(StringDyn &s, FILE * archivo)
{
    int i = 0;
    StringDyn aux;
    aux = new char[MAX];
    fread(&aux[i], sizeof(char),1,archivo);
    while(!feof(archivo) && (aux[i] != '\0'))
    {
        i++;
        fread(&aux[i], sizeof(char),1,archivo);
    }
    StringDyn_copiar(s, aux);
    delete [] aux;
}

void archivoPROC_bajarBoolean(boolean b, FILE * archivo)
{
    int id_b = 0;
    switch (b)
    {
    case FALSE:
        id_b = 0;
        break;
    case TRUE:
        id_b = 1;
        break;
    }
    fwrite(&id_b, sizeof(int),1,archivo);
}

void archivoPROC_levantarBoolean(boolean &b, FILE * archivo)
{
    int id_b = 0;
    fread(&id_b, sizeof(int),1,archivo);
    switch (id_b)
    {
    case 0:
        b = FALSE;
        break;
    case 1:
        b = TRUE;
        break;
    }
}

void archivoPROC_guardarLog(StringDyn log){

    StringDyn nom_archivo;
    StringDyn_crear(nom_archivo);
    StringDyn f;
    StringDyn_crear(f);
    nom_archivo = "calcusimple.log";
    time_t tiempo = time(0);
    struct tm *tlocal = localtime(&tiempo);
    char output[128];
    strftime(output,128,"%d/%m/%y %H:%M:%S",tlocal);
    f = output;
    FILE * archivo;
    archivoPROC_abrirArchivo(archivo, nom_archivo,"ab");
    archivoPROC_bajarString(f, archivo);
    archivoPROC_bajarString(" - ", archivo);
    archivoPROC_bajarString(log, archivo);
    fwrite("\r", sizeof(char),1,archivo);
    fwrite("\n", sizeof(char),1,archivo);
    archivoPROC_cerrarArchivo(archivo);

}

void archivoPROC_agregarSaltoLineaAlFinal(StringDyn nombreConcatenado){
    FILE * archivo;
    archivoPROC_abrirArchivo(archivo, nombreConcatenado,"ab");
    fwrite("\r", sizeof(char),1,archivo);
    fwrite("\n", sizeof(char),1,archivo);
    archivoPROC_cerrarArchivo(archivo);

}


//
//void archivoPROC_agregarSaltoLineaAlFinal(StringDyn nombreConcatenado){
//    FILE * archivo;
//    boolean noHaySalto = TRUE;
//    StringDyn linea;
//    StringDyn_crear(linea);
//    int largo = 0;
//
//    archivoPROC_abrirArchivo(archivo, nombreConcatenado,"rb");
//    fscanf(archivo, "%c", &linea[0]);
//    while (!feof(archivo))
//    {
//        linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
//    }
//    largo = StringDyn_largo(linea);
//    if (  largo != 0 )//(linea[largo-2] == '\r')   &&   (linea[largo-1] == '\n')  )
//    {
//        noHaySalto = FALSE;
//    }
//    archivoPROC_cerrarArchivo(archivo);
//    if (noHaySalto)
//    {
//        archivoPROC_abrirArchivo(archivo, nombreConcatenado,"ab");
//        fwrite("\r", sizeof(char),1,archivo);
//        fwrite("\n", sizeof(char),1,archivo);
//        archivoPROC_cerrarArchivo(archivo);
//    }
//    StringDyn_destruir(linea);
//}
