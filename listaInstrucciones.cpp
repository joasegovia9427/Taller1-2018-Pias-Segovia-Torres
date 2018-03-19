#include "listaInstrucciones.h"

void listaInstruccionesPROC_crearLI(listaInstrucciones &li){

     li = NULL;

}

void listaInstruccionesPROC_destruirLI(listaInstrucciones &li){
    if (li != NULL)
    {
        listaInstruccionesPROC_destruirLI (li->sig);
        delete li;
        li = NULL;
    }
}

boolean listaInstruccionesFUNC_isNull(listaInstrucciones li){

    return boolean(li==NULL);

}

int listaInstruccionesFUNC_largo(listaInstrucciones li){
    int i=0;
    while(li != NULL)
    {
        i++;
        li = li->sig;

    }
    return i;
}

void listaInstruccionesPROC_instertFront(listaInstrucciones &li, instruccion i){

    listaInstrucciones aux;
    aux = new nodoInstruccion;
    aux->info = i;
    aux->sig = li;
    li = aux;

}

//utilizada para el armado de la estructura lista de instrucciones
void listaInstruccionesPROC_instertBack(listaInstrucciones &li, instruccion i){

    listaInstrucciones nuevo = new nodoInstruccion;
    nuevo->info = i;
    nuevo->sig = NULL;
    if (li == NULL){
        li = nuevo;
    }
    else
    {
        listaInstrucciones aux = li;
        while (aux->sig != NULL)
            aux = aux->sig;
        aux->sig = nuevo;

    }

}

// el contador se suma afuera y le pasa para que buclee n veces hasta que da el siguiente elemento
// util para ver todas las instrucciones en la estructura lista de instrucciones cuando se carge
// para usar en ejecucion
instruccion listaInstruccionesFUNC_darInstruccion(listaInstrucciones li, int numero){

    int i = 0;
    while ( (li->sig != NULL) && (i != numero) )
    {
        i++;
        li = li->sig;
    }
    return li->info;}

// guarda una instrucicon a la lista con el discriminante-
// tipo del enumeradoopsBasi leer y el nombre de la variable
void listaInstruccionesPROC_agregarInstruccionLEER(StringDyn str, listaInstrucciones &li){

    instruccion i;
    enumOpsBasicas ob;
    ob = LEER; // LEER * enumAS1
    int numero_entero = 0;
    StringDyn nomVar1;
    StringDyn_crear(nomVar1);
    AS3 as3;
    AS4 as4;
    AS5 as5;
    AS6 as6;

    instruccionFUNC_cargar(i, str,ob, numero_entero,nomVar1, as3, as4, as5, as6);
    listaInstruccionesPROC_instertBack(li,i);

}

// guarda una instrucicon a la lista con el discriminante- tipo del
// enumeradoopsBasi mostrar y el nombre de la variable
void listaInstruccionesPROC_agregarInstruccionMOSTRAR(StringDyn str, listaInstrucciones &li){

    instruccion i;
    enumOpsBasicas ob;
    ob = MOSTRAR; // MOSTRAR o EnumAS2
    int numero_entero = 0;
    StringDyn nomVar1;
    StringDyn_crear(nomVar1);
    AS3 as3;
    AS4 as4;
    AS5 as5;
    AS6 as6;

    instruccionFUNC_cargar(i, str,ob, numero_entero,nomVar1, as3, as4, as5, as6);
    listaInstruccionesPROC_instertBack(li,i);
}



// guarda una instrucicon a la lista analizando cual de las combinaciones de 5 elementos es
// para guardarla con su respectivo structura datos de la union y discriminante
// de existir el error, tirarlo en el formato :
// printf("\n***Error de compilaci%sn - linea %d: para la instruccion de la asignacion
// con FUNC con 2 argumentos",nroLinea); //tilde
void listaInstruccionesPROC_agregarInstruccionAScompuesta(arbolVariables abb, listaInstrucciones &li,
                                                          listaStrings ls, int nroLinea, boolean &huboError,
                                                          int &nroLineaWarning, boolean &compiloConCero){

    boolean makeRoom = FALSE;
    huboError = FALSE;
    instruccion i;
    enumOpsBasicas ob;
    enumOpsArits oa;
    int numero_entero = 0;
    int as3_par1 = 0, as3_par2 = 0, as4_par1 = 0, as5_par2 = 0;
    StringDyn nomVar1;
    StringDyn_crear(nomVar1);
    AS3 as3;
    AS4 as4;
    AS5 as5;
    AS6 as6;


    // Define si es alguna de las funciones AS3-6
    if (StringDyn_equalAnyFUNCarits(listaStringsFUNC_darTERCERstr(ls)) == TRUE)
    {
        enumOpsAritsFUNC_carga(oa, listaStringsFUNC_darTERCERstr(ls));

        //si el dar 4 es un int y el dar 5 to es un int
        if (StringDyn_equalNumeroEntero(listaStringsFUNC_darCUARTOstr(ls)) == TRUE &&
            StringDyn_equalNumeroEntero(listaStringsFUNC_darQUINTOstr(ls)) == TRUE)
        {
           ob = enum_AS3;
           as3_par1 = StringDynFUNC_stringToNumeric(listaStringsFUNC_darCUARTOstr(ls));
           as3_par2 = StringDynFUNC_stringToNumeric(listaStringsFUNC_darQUINTOstr(ls));
           AS3_FUNC_carga(as3, oa,as3_par1,as3_par2);

           if ( (oa == DIV) && (as3_par2 == 0)  )
           {
               nroLineaWarning = nroLinea;
               compiloConCero = TRUE;
           }
        }
        else if (StringDyn_equalNumeroEntero(listaStringsFUNC_darCUARTOstr(ls)) == TRUE &&
                 arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darQUINTOstr(ls)) == TRUE)
        {
            ob = enum_AS4;
            as4_par1 = StringDynFUNC_stringToNumeric(listaStringsFUNC_darCUARTOstr(ls));
            AS4_FUNC_carga(as4, oa,as4_par1,listaStringsFUNC_darQUINTOstr(ls));
        }
        //si el 4to es una var o sea una string  y el 5to es un int
        else if (( arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darCUARTOstr(ls)) == TRUE ) &&
                 StringDyn_equalNumeroEntero(listaStringsFUNC_darQUINTOstr(ls)) == TRUE)
        {
            ob = enum_AS5;
            as5_par2 = StringDynFUNC_stringToNumeric(listaStringsFUNC_darQUINTOstr(ls));
            AS5_FUNC_carga(as5, oa,listaStringsFUNC_darCUARTOstr(ls),as5_par2);

            if ( (oa == DIV) && (as5_par2 == 0)  )
           {
               nroLineaWarning = nroLinea;
               compiloConCero = TRUE;
           }
        }
        //si el 4to es una var o sea una string  y el 5to es una var o sea una string
        else if ((arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darCUARTOstr(ls)) == TRUE) &&
                 (arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darQUINTOstr(ls)) == TRUE))
        {
            ob = enum_AS6;
            AS6_FUNC_carga(as6, oa,listaStringsFUNC_darCUARTOstr(ls),listaStringsFUNC_darQUINTOstr(ls));
        }
        else
        {
            huboError = TRUE;
            printf("\n***Error de compilaci%sn - l%snea %d: ",LETRA_o, LETRA_i, nroLinea);
            if ( StringDyn_equalNumeroEntero(listaStringsFUNC_darCUARTOstr(ls)) == FALSE &&
                 arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darCUARTOstr(ls)) == FALSE)
            {
                makeRoom = TRUE;
                printf("el primer argumento, luego de '");
                StringDyn_print(listaStringsFUNC_darTERCERstr(ls));
                printf("', \ndebe ser un n%smero entero o una variable declarada \nen la segunda secci%sn (VARIABLES)",LETRA_u,LETRA_o);
            }
            if ( StringDyn_equalNumeroEntero(listaStringsFUNC_darQUINTOstr(ls)) == FALSE &&
                 arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darQUINTOstr(ls)) == FALSE)
            {
                if (makeRoom)
                {
                    printf(", y tambi%sn ",LETRA_e);
                }
                printf("el segundo argumento, luego de '");
                StringDyn_print(listaStringsFUNC_darTERCERstr(ls));
                printf("', \ndebe ser un n%smero entero o una variable declarada \nen la segunda secci%sn (VARIABLES)",LETRA_u,LETRA_o);
            }
        }
    }
    else
    {
        //error ingreso una func incorrecta  solo se soprotan 4 funcs // este nunca aparece, se controla afuera
        huboError = TRUE;
         printf("\n***Error de compilaci%sn - l%snea %d: Se ingreso una FUNCI%sN no reconocida por el compilador",LETRA_o, LETRA_i, nroLinea, LETRA_O);

    }

    if (!huboError)
    {
        instruccionFUNC_cargar(i, listaStringsFUNC_darPRIMERstr(ls),ob, numero_entero,nomVar1, as3, as4, as5, as6);
        listaInstruccionesPROC_instertBack(li,i);
    }
}

// Guardo las intruccion en la lista de instrucciones, le paso la lista de substring y se debera
// validar correctamente todas las combinaciones, tanto LEER, MOSTRAR y asiganciones, dadas en el diseño.
// Utilizando la estructura y haciendo énfasis en la union para las combinaciones en la asignacion.
// tiene q retornar una bool para ver si hubo algun error, asi puedo saber si bajo todo o no

void listaInstruccionesPROC_agregarInstruccionASsimpple(arbolVariables abb, listaInstrucciones &li, listaStrings ls, int nroLinea, boolean &huboError){

    instruccion i;
    enumOpsBasicas ob;
//    enumOpsArits oa;
    int numero_entero = 0, par1 = 0;
    StringDyn nomVar1;
    StringDyn_crear(nomVar1);
    AS3 as3;
    AS4 as4;
    AS5 as5;
    AS6 as6;

    // Define si es alguna de las funciones AS3-6
    if (StringDyn_equalNumeroEntero(listaStringsFUNC_darTERCERstr(ls)) == TRUE )
    {
        ob = enum_AS1;
        par1 = StringDynFUNC_stringToNumeric(listaStringsFUNC_darTERCERstr(ls));
        numero_entero = par1;
        instruccionFUNC_cargar(i, listaStringsFUNC_darPRIMERstr(ls),ob, numero_entero,nomVar1, as3, as4, as5, as6);
        listaInstruccionesPROC_instertBack(li,i);

    }
    else if (arbolVariablesFUNC_verificarExistenciaString(abb,listaStringsFUNC_darTERCERstr(ls)) == TRUE )
    {

        ob = enum_AS2;
        StringDyn_copiar(nomVar1,listaStringsFUNC_darTERCERstr(ls));
        instruccionFUNC_cargar(i, listaStringsFUNC_darPRIMERstr(ls),ob, numero_entero,nomVar1, as3, as4, as5, as6);
        listaInstruccionesPROC_instertBack(li,i);
    }
    else{
        printf("\n***Error de compilaci%sn - l%snea %d",LETRA_o, LETRA_i, nroLinea);
    }
}

