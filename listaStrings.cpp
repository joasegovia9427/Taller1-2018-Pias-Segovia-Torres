#include "listaStrings.h"


void listaStringsPROC_crearLista(listaStrings &ls){    ls = NULL;
}
void listaStringsPROC_instertFront(listaStrings &ls, StringDyn info){    listaStrings aux;
    aux         = new nodoListaString;
    aux->info   = info;
    aux->sig    = ls;
    ls          = aux;
}

//utilizada para la particion de substrings
void listaStringsPROC_instertBack(listaStrings &ls, StringDyn info){    listaStrings nuevo  = new nodoListaString;
    nuevo->info         = info;
    nuevo->sig          = NULL;
    if (ls == NULL)
    {
        ls = nuevo;
    }
    else
    {
        listaStrings aux = ls;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;
    }
}
////o FUNC_isVacia
boolean listaStringsFUNC_isNull(listaStrings ls){    return boolean(ls==NULL);}

//----------------------
//precondicion: se sabe que tiene 5 justo
//estos estan para que devuelva el string directo como info

StringDyn listaStringsFUNC_darPRIMERstr(listaStrings ls){
    return ls->info;
}

StringDyn listaStringsFUNC_darSEGUNDOstr(listaStrings ls){
    return ls->sig->info;
}

StringDyn listaStringsFUNC_darTERCERstr(listaStrings ls){
    return ls->sig->sig->info;
}

StringDyn listaStringsFUNC_darCUARTOstr(listaStrings ls){
    return ls->sig->sig->sig->info;
}

StringDyn listaStringsFUNC_darQUINTOstr(listaStrings ls){
    return ls->sig->sig->sig->sig->info;
}
boolean listaStringsFUNC_isNodoPertenece(listaStrings ls, StringDyn info){    boolean isPertenece = FALSE;
    while ( (ls != NULL) && (isPertenece == FALSE) )
    {
        if ( StringDyn_equal(info,ls->info) )
        {
            isPertenece = TRUE;
        }
        ls = ls->sig;
    }
    return isPertenece;
}

int listaStringsFUNC_largo(listaStrings ls){    int largo = 0;
    while (ls != NULL)
    {
        largo++;
        ls = ls->sig;
    }
    return largo;}

//PRECONDICIONES PARA LOS SIGUIENTES 3 es que no este vacia

listaStrings listaStringsFUNC_listaSinPrimerElemento(listaStrings lsCompilacion){    listaStrings lsResto;
    listaStrings aux = new nodoListaString;
    aux = lsCompilacion;
    lsCompilacion = lsCompilacion->sig;
    delete(aux);
    lsResto = lsCompilacion;    return lsResto;
}
void listaStringsPROC_resto(listaStrings &ls){//    listaStrings aux = new nodoListaString; //no se si le falta esta linea a la solucion del teorico en P2
//    aux = ls;
//    ls = ls->sig;//ls = ls->sig;
//    delete(aux);


//    listaStrings aux = new nodoListaString; //no se si le falta esta linea a la solucion del teorico en P2
    listaStrings aux = ls;
    ls = aux->sig;
    delete(aux);
}

void listaStringsPROC_obtenerUltimo(listaStrings ls, StringDyn &ultimoINFO){//    StringDyn_copiar(ultimoINFO, ls->info);
//    while (ls != NULL)
//    {
//        StringDyn_copiar(ultimoINFO, ls->info);
//        ls = ls->sig;
//    }
    while (ls->sig != NULL)
        ls = ls->sig;
    StringDyn_copiar(ultimoINFO,ls->info);
}////b) UltimoIter: Dada una lista, devuelve su último elemento.
////Precondicion: no puede estar vacia
//int listaEnterosFUNCrec_obtenerUltimo(listaEnteros l){
//    if (l->sig == NULL)
//       return l->info;
//    else
//        return listaEnterosFUNCrec_obtenerUltimo(l->sig);
//}

int listaStringsFUNC_ocurrenciasDeInfo(listaStrings ls, StringDyn info){    int ocurrenciasDeInfo = 0;
    while (ls != NULL){
        if (StringDyn_equal(info,ls->info)){
            ocurrenciasDeInfo++;
        }
        ls = ls->sig;
    }
    return ocurrenciasDeInfo;
}

void listaStringsPROC_destruirLista(listaStrings &ls){
    if (ls != NULL)
    {
//        listaStringsPROC_destruirLista (ls->sig);
//        delete ls;
//        ls = NULL;


    }
ls = NULL;

//recorro todo y voy delete( ) uno a uno cada nodo?
//y a lo ultimo devuelvo el puntero a null
//    while (listaStringsFUNC_largo(ls) != 0) // en los dos entra solo dos veces no se si efectivamente se esta borrando el tulimo nodo
//    while (!listaStringsFUNC_isNull(ls))
//    {
//        listaStringsPROC_resto(ls);
//        if (!listaStringsFUNC_isNull(ls))
//        {
//            ls = ls->sig;
//        }
//        else{
//            ls = NULL;
//        }
//
//    }
}

//el contador se suma afuera y le pasa para que buclee n veces hasta que da el siguiente elemento
//util para ver todas las variables en la seccion variables
//precondicion: no debe estar vacia
StringDyn listaStringsFUNC_darSIGUIENTEstr(listaStrings ls, int numero){    int bucleInterno = 0;
//    while ( (ls != NULL) && (bucleInterno != numero) )
    while ( (ls->sig != NULL) && (bucleInterno != numero) )
    {
        bucleInterno++;
        ls = ls->sig;
    }
    return ls->info;}

void PROC_partirStrEnSubStrs(StringDyn linea, listaStrings &lsSubsString){
    StringDyn palabra, restoLinea;
    StringDyn_crear(palabra);
    StringDyn_crear(restoLinea);
    do{        StringDynPROC_separarPrimerPalabra(linea, palabra, restoLinea);
        if (palabra[0] != '\0')
        {
            listaStringsPROC_instertBack(lsSubsString,palabra);
        }
//        else
//        {
            StringDyn_copiar(linea,restoLinea);
//        }
    }while (StringDyn_largo(linea) != 0);//linea[0] != '\0'); //
//    StringDyn_destruir(palabra);
    StringDyn_destruir(restoLinea);
}

void listaStringsPROC_print(listaStrings ls){
    while(ls != NULL){
        printf("\n");
        StringDyn_print(ls->info);
        ls = ls->sig;
    }
}
