#include "validaciones.h"

void validacionesPROC_guardarVariablesEnABB(listaStrings ls,arbolVariables &abb,boolean &huboError)
{
    huboError = FALSE;
    int nroVariable = 1;
    while ( (nroVariable < listaStringsFUNC_largo(ls)) && !huboError )
    {
        StringDyn nuevaVariable;
        StringDyn_crear(nuevaVariable);



        nuevaVariable = listaStringsFUNC_darSIGUIENTEstr(ls, nroVariable);

        if (StringDyn_contiene_MAYUSCULAS(nuevaVariable))
        {
            printf("\n***Error de compilaci%sn - l%snea 2: la variable ",LETRA_o,LETRA_i);
            StringDyn_print(nuevaVariable);
            printf(" no puede contener may%ssculas",LETRA_u); //tilde
            huboError = TRUE;
        }
        else if (StringDyn_contiene_numeros(nuevaVariable))
        {
            printf("\n***Error de compilaci%sn - l%snea 2: la variable ",LETRA_o,LETRA_i);
            StringDyn_print(nuevaVariable);
            printf(" no puede contener n%smeros",LETRA_u); //tilde
            huboError = TRUE;
        }
        else if (!StringDyn_contiene_minusculasSolo(nuevaVariable))
        {
            printf("\n***Error de compilaci%sn - l%snea 2: la variable ",LETRA_o,LETRA_i);
            StringDyn_print(nuevaVariable);
            printf(" solo puede contener caracteres desde la 'a' hasta la 'z'"); //tilde
            huboError = TRUE;
        }
        else if (arbolVariablesFUNC_verificarExistenciaString(abb, nuevaVariable))
        {
            printf("\n***Error de compilaci%sn - l%snea 2: la variable '",LETRA_o,LETRA_i);
            StringDyn_print(nuevaVariable);
            printf("' ya fue declarada"); //tilde
            huboError = TRUE;
        }
        else
        {
            variable newVar;
            variablePROC_carga(newVar, nuevaVariable);
            arbolVariablesPROC_agregarVariableAlArbol(abb, newVar);
            huboError = FALSE;
        }
        nroVariable++;
        StringDyn_destruir(nuevaVariable);
    }
}

void validacionesPROC_bucleInstruccionesEjecucion(arbolVariables abb, listaInstrucciones li, int &nroLinea, boolean &huboError)
{
    huboError = FALSE;
    int nroInstruccion = 0;

    while (nroInstruccion < listaInstruccionesFUNC_largo(li) && !huboError)
    {
        instruccion aux;
        aux = listaInstruccionesFUNC_darInstruccion(li, nroInstruccion);
        switch (instruccionFUNC_darTipoInstruccion(aux))
        {
        case LEER:
            {////1
                int num1 = 0;
                StringDyn var1;
                StringDyn_crear(var1);
                printf("\nIngrese valor para ");
                StringDyn_print(instruccionFUNC_darNombreVar0(aux));
                printf(": ");
                StringDyn_scan(var1);


                if ( (StringDyn_equalNumeroEntero(var1)== TRUE) && (StringDyn_largo(var1) > 0) )
                {
                    num1 = StringDynFUNC_stringToNumeric(var1);
                    arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), num1);
                }
                else
                {
                    printf("\n***Error de ejecuci%sn - linea %d de la ejecuci%sn: solo se aceptan valores enteros num%sricos para la variable ",LETRA_o, nroLinea, LETRA_o, LETRA_e);
                    StringDyn_print(instruccionFUNC_darNombreVar0(aux));
                    printf("\n");
                    huboError = TRUE;
                }
                StringDyn_destruir(var1);
            }
            break;
        case MOSTRAR:
                ////2
                arbolVariablesPROC_PrintNombreValor(abb, instruccionFUNC_darNombreVar0(aux));
            break;
        case enum_AS1:
                ////3
                arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), instruccionFUNC_darNumeroEntero(aux));
            break;
        case enum_AS2:
            {////4
                int valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb, instruccionFUNC_darNombreVar1(aux)); //uso de variable para mejor lectura
                arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), valorParaAsignar);
            }
            break;
        case enum_AS3:
            {////5
                AS3 as3Aux = instruccionFUNC_darAS3_funcIntInt(aux);//testear, si no anda hacer la carga
                if (AS3_FUNC_darTipoFUNC(as3Aux)==DIV && AS3_FUNC_darValor2(as3Aux)==0)
                {
                    printf("\n***Error de ejecuci%sn - linea %d de la ejecuci%sn: no se puede realizar la divisi%sn entre 0",LETRA_o,nroLinea,LETRA_o,LETRA_o);
                    printf("\n");
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de ejecución no se puede realizar la división entre 0");

                }
                else
                {
                    int valorParaAsignar;
                    switch (AS3_FUNC_darTipoFUNC(as3Aux))
                    {
                    case SUM:
                        valorParaAsignar = AS3_FUNC_darValor1(as3Aux) + AS3_FUNC_darValor2(as3Aux);
                        break;
                    case RES:
                        valorParaAsignar = AS3_FUNC_darValor1(as3Aux) - AS3_FUNC_darValor2(as3Aux);
                        break;
                    case MUL:
                        valorParaAsignar = AS3_FUNC_darValor1(as3Aux) * AS3_FUNC_darValor2(as3Aux);
                        break;
                    case DIV:
                        valorParaAsignar = AS3_FUNC_darValor1(as3Aux) / AS3_FUNC_darValor2(as3Aux);
                        break;
                    }
                    arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), valorParaAsignar);
                }
            }
            break;
        case enum_AS4:
            {////6
                AS4 as4Aux = instruccionFUNC_darAS4_funcIntVar(aux);//testear, si no anda hacer la carga
                if (AS4_FUNC_darTipoFUNC(as4Aux)==DIV && arbolVariablesFUNC_valorDeVariable(abb,AS4_FUNC_darNombreVariable(as4Aux))==0)
                {
                    printf("\n***Error de ejecuci%sn - linea %d de la ejecuci%sn: no se puede realizar la divisi%sn entre 0",LETRA_o,nroLinea,LETRA_o,LETRA_o);
                    printf("\n");
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de ejecución no se puede realizar la división entre 0");
                }
                else
                {
                    int valorParaAsignar;
                    switch (AS4_FUNC_darTipoFUNC(as4Aux))
                    {
                    case SUM:
                        valorParaAsignar = AS4_FUNC_darValor1(as4Aux) + arbolVariablesFUNC_valorDeVariable(abb,AS4_FUNC_darNombreVariable(as4Aux));
                        break;
                    case RES:
                        valorParaAsignar = AS4_FUNC_darValor1(as4Aux) - arbolVariablesFUNC_valorDeVariable(abb,AS4_FUNC_darNombreVariable(as4Aux));
                        break;
                    case MUL:
                        valorParaAsignar = AS4_FUNC_darValor1(as4Aux) * arbolVariablesFUNC_valorDeVariable(abb,AS4_FUNC_darNombreVariable(as4Aux));
                        break;
                    case DIV:
                        valorParaAsignar = AS4_FUNC_darValor1(as4Aux) / arbolVariablesFUNC_valorDeVariable(abb,AS4_FUNC_darNombreVariable(as4Aux));
                        break;
                    }
                    arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), valorParaAsignar);
                }
            }
            break;
        case enum_AS5:
            {////7
                AS5 as5Aux = instruccionFUNC_darAS5_FuncVarInt(aux);//testear, si no anda hacer la carga
                if (AS5_FUNC_darTipoFUNC(as5Aux)==DIV && AS5_FUNC_darValor1(as5Aux)==0)
                {
                    printf("\n***Error de ejecuci%sn - linea %d de la ejecuci%sn: no se puede realizar la divisi%sn entre 0",LETRA_o,nroLinea,LETRA_o,LETRA_o);
                    printf("\n");
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de ejecución no se puede realizar la división entre 0");
                }
                else
                {
                    int valorParaAsignar;
                    switch (AS5_FUNC_darTipoFUNC(as5Aux))
                    {
                    case SUM:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS5_FUNC_darNombreVariable(as5Aux)) + AS5_FUNC_darValor1(as5Aux);
                        break;
                    case RES:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS5_FUNC_darNombreVariable(as5Aux)) - AS5_FUNC_darValor1(as5Aux);
                        break;
                    case MUL:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS5_FUNC_darNombreVariable(as5Aux)) * AS5_FUNC_darValor1(as5Aux);
                        break;
                    case DIV:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS5_FUNC_darNombreVariable(as5Aux)) / AS5_FUNC_darValor1(as5Aux);
                        break;
                    }
                    arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), valorParaAsignar);
                }
            }
            break;
        case enum_AS6:
            {////8
                AS6 as6Aux = instruccionFUNC_darAS6_FuncVarVar(aux);//testear, si no anda hacer la carga
                if (AS6_FUNC_darTipoFUNC(as6Aux)==DIV && arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable2(as6Aux))==0)
                {
                    printf("\n***Error de ejecuci%sn - linea %d de la ejecuci%sn: no se puede realizar la divisi%sn entre 0",LETRA_o,nroLinea,LETRA_o,LETRA_o);
                    printf("\n");
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de ejecución no se puede realizar la división entre 0");
                }
                else
                {
                    int valorParaAsignar;
                    switch (AS6_FUNC_darTipoFUNC(as6Aux))
                    {
                    case SUM:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable1(as6Aux)) + arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable2(as6Aux));
                        break;
                    case RES:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable1(as6Aux)) - arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable2(as6Aux));
                        break;
                    case MUL:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable1(as6Aux)) * arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable2(as6Aux));
                        break;
                    case DIV:
                        valorParaAsignar = arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable1(as6Aux)) / arbolVariablesFUNC_valorDeVariable(abb,AS6_FUNC_darNombreVariable2(as6Aux));
                        break;
                    }
                    arbolVariablesPROC_modificarVariableEnABB(abb, instruccionFUNC_darNombreVar0(aux), valorParaAsignar);
                }
            }
            break;
        }
        nroLinea++;
        nroInstruccion++;
    }
}

boolean validacionesFUNC_isComentario(listaStrings ls){
    boolean isComentario = FALSE;
    StringDyn primerElemento;
    StringDyn_crear(primerElemento);
    primerElemento = listaStringsFUNC_darPRIMERstr(ls);
    if (StringDyn_largo(primerElemento) >= 2)
    {
        if (primerElemento[0] == '/')
        {
            if (  (primerElemento[1] == '/') ||   (primerElemento[1] == '*')  )
            {
                isComentario = TRUE;
            }
        }
    }
    StringDyn_destruir(primerElemento);
    return isComentario;
}

void validacionesPROC_variablesSinUso(arbolVariables abb, listaInstrucciones li, listaStrings &listaNombresOrdenEncontradas){
    listaStrings variablesUSADAS;
    listaStringsPROC_crearLista(variablesUSADAS);

    listaStringsPROC_destruirLista(listaNombresOrdenEncontradas);
    listaStringsPROC_crearLista(listaNombresOrdenEncontradas);

    arbolVariablesPROC_obtenerListaDeNombres(abb, variablesUSADAS);

    int nroVariable = 0;
    while ( (nroVariable < listaStringsFUNC_largo(variablesUSADAS)))
    {
        StringDyn variablePosicionada;
        StringDyn_crear(variablePosicionada);
        variablePosicionada = listaStringsFUNC_darSIGUIENTEstr(variablesUSADAS, nroVariable);

        boolean estaEstaVar = FALSE;
        //ahora tengo que recorres todas las instrucciones hasta que no haya mas o hasta que haya encotnrado esta variable en la primera
        int nroInstruccion = 0;
        while (nroInstruccion < listaInstruccionesFUNC_largo(li) && !estaEstaVar)
        {
            instruccion aux;
            aux = listaInstruccionesFUNC_darInstruccion(li, nroInstruccion);

            StringDyn var0,var1,var2;
            StringDyn_crear(var0);
            StringDyn_crear(var1);
            StringDyn_crear(var2);
            switch (instruccionFUNC_darTipoInstruccion(aux))
            {
                case LEER:
                    {////1
                        if (    StringDyn_equal(    variablePosicionada,instruccionFUNC_darNombreVar0(aux)     )     )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case MOSTRAR:
                    {////2

                        if (    StringDyn_equal(    variablePosicionada,instruccionFUNC_darNombreVar0(aux)     )     )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS1:
                    {////3

                        if (    StringDyn_equal(    variablePosicionada,instruccionFUNC_darNombreVar0(aux)     )     )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS2:
                    {////4
                        if (  (StringDyn_equal(variablePosicionada,instruccionFUNC_darNombreVar0(aux))) ||
                              (StringDyn_equal(variablePosicionada,instruccionFUNC_darNombreVar1(aux)))  )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS3:
                    {////5
                        if (    StringDyn_equal(    variablePosicionada,instruccionFUNC_darNombreVar0(aux)     )     )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS4:
                    {////6
                        AS4 as4Aux = instruccionFUNC_darAS4_funcIntVar(aux);
                        if ( (StringDyn_equal(variablePosicionada,instruccionFUNC_darNombreVar0(aux))) ||
                             (StringDyn_equal(variablePosicionada,AS4_FUNC_darNombreVariable(as4Aux)))  )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS5:
                    {////7
                        AS5 as5Aux = instruccionFUNC_darAS5_FuncVarInt(aux);
                        if ( (StringDyn_equal(variablePosicionada,instruccionFUNC_darNombreVar0(aux))) ||
                             (StringDyn_equal(variablePosicionada,AS5_FUNC_darNombreVariable(as5Aux)))  )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
                case enum_AS6:
                    {////8
                        AS6 as6Aux = instruccionFUNC_darAS6_FuncVarVar(aux);
                        if ( (StringDyn_equal(variablePosicionada,instruccionFUNC_darNombreVar0(aux))) ||
                             (StringDyn_equal(variablePosicionada,AS6_FUNC_darNombreVariable1(as6Aux))) ||
                             (StringDyn_equal(variablePosicionada,AS6_FUNC_darNombreVariable2(as6Aux)))  )
                        {
                            estaEstaVar = TRUE;
                        }
                    }
                    break;
            }
            StringDyn_destruir(var0);
            StringDyn_destruir(var1);
            StringDyn_destruir(var2);
            nroInstruccion++;
        }
        if (!estaEstaVar)
        {
            listaStringsPROC_instertBack(listaNombresOrdenEncontradas,variablePosicionada);
        }
        StringDyn_destruir(variablePosicionada);
        nroVariable++;
    }
    listaStringsPROC_destruirLista(variablesUSADAS);
}

void PROC_compilar(StringDyn nombrePrograma)
{
//si la linea que se lee en un archivo resulta vacia, el contenido de la variable strDyn linea, tiene que tener el caracter nulo en la pos 0, asi se sabe que el usuario en esa linea no escribio nada

    StringDyn linea;
    StringDyn_crear(linea);
    arbolVariables abb;
    arbolVariablesPROC_crearABB(abb);
    listaInstrucciones li;
    listaInstruccionesPROC_crearLI(li);
    int nroLinea = 0, nroLineaWarning=0, compiloConCeroCont=0, nroLineaAnterior=0;
    boolean huboError = FALSE, compiloConCero = FALSE, isFinalArchivo = FALSE;

    listaStrings lsCompilacion, listaNombresOrdenEncontradas, listaCompiloConCero;
    listaStringsPROC_crearLista(listaNombresOrdenEncontradas);
    listaStringsPROC_crearLista(listaCompiloConCero);

    StringDyn PROGRAMA, VARIABLES, INSTRUCCIONES, LEER, MOSTRAR;
    StringDynPROC_iniStrDynVarsCompilar(PROGRAMA, VARIABLES, INSTRUCCIONES, LEER, MOSTRAR);

    StringDyn nombreProgConcatenado;
    StringDyn_crear(nombreProgConcatenado);

    StringDyn ext_csim, ext_vars, ext_inst;
    StringDynPROC_iniStrDynExtensionesArchivos(ext_csim, ext_vars, ext_inst);

    nombreProgConcatenado = StringDyn_concatenarFUNC(nombrePrograma, ext_csim);

    archivoPROC_agregarSaltoLineaAlFinal(nombreProgConcatenado);

    FILE * archivo = NULL;

    archivoPROC_abrirArchivo(archivo, nombreProgConcatenado, "rb");// "rb"); //lo abro al principio asi leo la primer linea en la siguiente instruccion

//=================================================================
//antes del eof hay que hacer un read de algo y luego un seek set para mandarlo al inicio nuevamente para empezar a leer desde el principio y no perder nada...
//=================================================================


    while( (!feof(archivo)) && (huboError==FALSE) )  //si no anda u otra cosa, hay que agregar la condicion (!feof(archivo) && huboError == FALSE ) antes de leer una nueva linea
    {

        linea = archivoFUNC_cargarLaSiguienteLinea(archivo);

        listaStringsPROC_crearLista(lsCompilacion);
        PROC_partirStrEnSubStrs(linea, lsCompilacion);

        if (listaStringsFUNC_largo(lsCompilacion) <1)//<= 1) //validar si pongo StringDyn_largo(linea) == 1    o   una func que valide si linea esta vacia
        {
            printf("\n***Error de compilaci%sn - l%snea 1: debe existir una instrucci%sn de la primera secci%sn, \nen la primer linea del c%sdigo fuente\nTip: en la primer linea debe existir la \ninstrucci%sn 'PROGRAMA' seguida del nombre del programa\nej: PROGRAMA nombreApp", LETRA_o, LETRA_i, LETRA_o,LETRA_o,  LETRA_o, LETRA_o);
            huboError = TRUE;
            archivoPROC_guardarLog("Error de compilación - línea 1 debe existir una instrucción de la primera sección, en la primer linea del código fuente. Tip en la primer línea debe existir la instrucción 'PROGRAMA' seguida del nombre del programa. ej: PROGRAMA nombreApp");
        }
        else //si tiene algo ya la puedo partir
        {

//                 StringDyn_print(linea);

//            listaStringsPROC_crearLista(lsCompilacion);
//            PROC_partirStrEnSubStrs(linea, lsCompilacion);

            if (StringDyn_contiene_minusculas(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
            {
                printf("\n***Error de compilaci%sn - l%snea 1: la instrucci%sn de la primera secci%sn del c%sdigo fuente solo puede contener letras may%ssculas",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                huboError = TRUE;
                archivoPROC_guardarLog("Error de compilación - línea 1 la instrucción de la primera sección del código fuente solo puede contener letras mayúsculas");
            }
            else if (StringDyn_contiene_numeros(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
            {
                printf("\n***Error de compilaci%sn - l%snea 1: la instrucci%sn de la primera secci%sn del c%sdigo fuente no puede contener n%smeros",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                huboError = TRUE;
                archivoPROC_guardarLog("Error de compilación - línea 1 la instrucción de la primera sección del código fuente no puede contener números");
            }
            else if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),PROGRAMA))
            {
//
                if (listaStringsFUNC_largo(lsCompilacion) == 1)
                {
                    printf("\n***Error de compilaci%sn - l%snea 1: la instrucci%sn de la primera secci%sn del c%sdigo fuente no es valida, \nnecesita un %snico argumento (nombre de programa)",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de compilación - línea 1 la instrucción de la primera sección del código fuente no es valida, necesita un único argumento (nombre de programa)");
                }
                else if (listaStringsFUNC_largo(lsCompilacion) != 2)
                {
                    printf("\n***Error de compilaci%sn - l%snea 1: la instrucci%sn de la primera secci%sn del c%sdigo fuente no es valida, \nse permite solo un %snico argumento (nombre de programa)",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                    huboError = TRUE;
                    archivoPROC_guardarLog("Error de compilación - línea 1 la instrucción de la primera sección del código fuente no es valida, se permite solo un único argumento (nombre de programa)");
                }
                else if (StringDyn_contiene_MAYUSCULAS(listaStringsFUNC_darSEGUNDOstr(lsCompilacion)))
                {
                    printf("\n***Error de compilaci%sn - l%snea 1: el argumento: '",LETRA_o, LETRA_i);
                    StringDyn_print(listaStringsFUNC_darSEGUNDOstr(lsCompilacion));
                    printf("' de la instrucci%sn de la primera secci%sn del c%sdigo fuente solo puede contener letras min%ssculas",LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                    huboError = TRUE;
                }
                else if (StringDyn_contiene_numeros(listaStringsFUNC_darSEGUNDOstr(lsCompilacion)))
                {
                    printf("\n***Error de compilaci%sn - l%snea 1: el argumento '",LETRA_o, LETRA_i);
                    StringDyn_print(listaStringsFUNC_darSEGUNDOstr(lsCompilacion));
                    printf("' de la instrucci%sn de la primera secci%sn del c%sdigo fuente no puede contener n%smeros",LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                    huboError = TRUE;
                }
                else if (       StringDyn_equal(listaStringsFUNC_darSEGUNDOstr(lsCompilacion), nombrePrograma)         )
                {
                    //antes de leer otra lista borro libero la usada para la linea anterior---------------
                    listaStringsPROC_destruirLista(lsCompilacion);

                    //mienstas no sea el final del archivo
                    linea = archivoFUNC_cargarLaSiguienteLinea(archivo);

                    listaStringsPROC_crearLista(lsCompilacion);
                    PROC_partirStrEnSubStrs(linea, lsCompilacion);

                    if (listaStringsFUNC_largo(lsCompilacion) < 1) //validar si pongo StringDyn_largo(linea) == 1    o   una func que valide si linea esta vacia
                    {
                        printf("\n***Error de compilaci%sn - l%snea 2: debe existir una instrucci%sn \nde la segunda secci%sn, en la segunda linea del c%sdigo fuente \nTip: en la segunda lina debe existir la instrucci%sn 'VARIABLES', \nsi lo desea (puede no haber variables decalradas), seguida del nombre de la(s) \nvariables en min%sscula separadas por la barra espaciadora\nej: VARIABLES variablea variableb suma resta resultado total",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                        huboError = TRUE;
                        archivoPROC_guardarLog("Error de compilación - línea 2 debe existir una instrucción de la segunda sección, en la segunda linea del código fuente\nTip: en la segunda lina debe existir la instrucción 'VARIABLES', si lo desea (puede no haber variables decalradas), seguida del nombre de la(s) variables en minuscula separadas por la barra espaciadora. ej: VARIABLES variablea variableb suma resta resultado total");
                    }
                    else //si tiene algo ya la puedo partir
                    {
//                        listaStringsPROC_crearLista(lsCompilacion);
//                        PROC_partirStrEnSubStrs(linea, lsCompilacion);

                        if (StringDyn_contiene_minusculas(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
                        {
                            printf("\n***Error de compilaci%sn - l%snea 2: la instrucci%sn de la segunda secci%sn del c%sdigo fuente solo puede contener letras may%ssculas",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                            huboError = TRUE;
                            archivoPROC_guardarLog("Error de compilación - línea 2 la instrucción de la segunda sección del código fuente solo puede contener letras mayúsculas");
                        }
                        else if (StringDyn_contiene_numeros(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
                        {
                            printf("\n***Error de compilaci%sn - l%snea 2: la instrucci%sn de la segunda secci%sn del c%sdigo fuente no puede contener n%smeros",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                            huboError = TRUE;
                            archivoPROC_guardarLog("Error de compilación - línea 2 la instrucción de la segunda sección del código fuente no puede contener números");
                        }
                        else if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),VARIABLES))
                        {

                            if (listaStringsFUNC_largo(lsCompilacion) > 1) // si se que hay al menos una variable
                            {
                                huboError = FALSE;
//                                validacionesPROC_guardarVariablesEnABB(listaStringsFUNC_listaSinPrimerElemento(lsCompilacion),abb,huboError);
                                validacionesPROC_guardarVariablesEnABB(lsCompilacion,abb,huboError);
                                // a este le paso la lista sin el substr VARIABLES de modo que recorra anidadamente hasta que sea el final de la lista y vaya agregando varaiable a varaible valida en el abb
                                //voy a tener que estar dando la sieguiente var constantemente
                            }

                            if (!huboError) //si no hubo interrupcion por error en todas las variables, o sea si todas las var estaba bien y no hubo error de compilacion
                            {

                                //antes de leer otra lista borro libero la usada para la linea anterior---------------
                                listaStringsPROC_destruirLista(lsCompilacion);

                                linea = archivoFUNC_cargarLaSiguienteLinea(archivo);

                                listaStringsPROC_crearLista(lsCompilacion);
                                PROC_partirStrEnSubStrs(linea, lsCompilacion);

                                if ( listaStringsFUNC_largo(lsCompilacion) != 1)//StringDyn_largo(linea) != 1) //validar si pongo StringDyn_largo(linea) == 1    o   una func que valide si linea esta vacia
                                {
                                    printf("\n***Error de compilaci%sn - l%snea 3: debe existir solamante la palabra 'INSTRUCCIONES' para determinar el comienzo de la tercer secci%sn del c%sdigo fuente.\nTip: en la siguiente linea puede o no haber instrucciones/operaciones (LEER, MOSTRAR, asignaciones)\nej: INSTRUCCIONES\nLEER var\nMOSTRAR var\nvar = SUM var var",LETRA_o, LETRA_i,LETRA_o,LETRA_o); //tilde
                                    huboError = TRUE;
                                    archivoPROC_guardarLog("Error de compilaci%sn - linea 3 debe existir solamante la palabra 'INSTRUCCIONES' para determinar el comienzo de la tercer seccion del codigo fuente, en la siguiente linea puede o no haber instrucciones/operaciones (LEER, MOSTRAR, asignaciones)\nej: INSTRUCCIONES\nLEER var\nMOSTRAR var\nvar = SUM var var"); //tilde

                                }
                                else //si no escribio mas de una cosa en la tercer linea, me fijo que sea = si o si = a INTRUCCIONES
                                {

//                                    listaStringsPROC_crearLista(lsCompilacion);
//                                    PROC_partirStrEnSubStrs(linea, lsCompilacion);

                                    if (StringDyn_contiene_minusculas(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
                                    {
                                        printf("\n***Error de compilaci%sn - l%snea 3: la instrucci%sn de la tercer secci%sn del c%sdigo fuente solo puede contener letras may%ssculas",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                                        huboError = TRUE;
                                        archivoPROC_guardarLog("Error de compilación - línea 3: la instrucción de la tercer sección del código fuente solo puede contener letras mayúsculas"); //tilde

                                    }
                                    else if (StringDyn_contiene_numeros(listaStringsFUNC_darPRIMERstr(lsCompilacion)))
                                    {
                                        printf("\n***Error de compilaci%sn - l%snea 3: la instrucci%sn de la tercer secci%sn del c%sdigo fuente no puede contener n%smeros",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o,LETRA_u); //tilde
                                        huboError = TRUE;
                                        archivoPROC_guardarLog("Error de compilación - línea 3: la instrucción de la tercer sección del código fuente no puede contener números"); //tilde

                                    }
                                    else if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),INSTRUCCIONES))
                                    {

                                        //antes de leer otra lista borro libero la usada para la linea anterior---------------
                                        listaStringsPROC_destruirLista(lsCompilacion);
//por ejemplo no se si iria un if eof aqui antes de linea
                                        linea = archivoFUNC_cargarLaSiguienteLinea(archivo);

                                        //    if (StringDyn_largo(linea) == 0) //validar si pongo StringDyn_largo(linea) == 0    o   una func que valide si linea esta vacia
                                        //    {
                                        //        //o sea que no hay ninguna instruccion para leer
                                        //        isFinalArchivo = TRUE;
                                        //        archivoPROC_bajoABB(abb);//no bajo la lista porque estaba correcto, termino con INSTRUCCIONES pero sin delcarar una particularmente
                                        //    }
                                        //    else //si tiene algo ya la puedo partir
                                        //    {
                                        isFinalArchivo = FALSE;

                                        huboError = FALSE;
                                        nroLinea = 4;  // esta en la linea 4 y la va a analizar, si dejo una linea libre salta a la siguiente y analiza... hasta que llegue al final del archivo o no haya error

                                        while (!feof(archivo) && huboError == FALSE)   //!isFinalArchivo && !huboError)
                                        {
                                            //if linea esta vacia o sin caracteres que no siga leyendo porque segurametne cuando deja mas de dos lineas vacias, cae
                                            if (StringDyn_largo(linea) == 0)
                                            {
                                                listaStringsPROC_destruirLista(lsCompilacion);
                                                linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
                                                nroLinea++;
                                            }
                                            else{


                                                listaStringsPROC_crearLista(lsCompilacion);
                                                PROC_partirStrEnSubStrs(linea, lsCompilacion);

                                                if (listaStringsFUNC_largo(lsCompilacion) < 1)
                                                {
                                                    listaStringsPROC_destruirLista(lsCompilacion);
                                                    linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
                                                    nroLinea++;
                                                }
                                                else if(validacionesFUNC_isComentario(lsCompilacion))
                                                {
                                                    listaStringsPROC_destruirLista(lsCompilacion);
                                                    linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
                                                    nroLinea++;
                                                }
                                                else if(listaStringsFUNC_largo(lsCompilacion) == 1){
                                                    printf("\n***Error de compilaci%sn - l%snea %d: todas las instrucciones/operaciones dentro de la secci%sn \nINTRUCCIONES del c%sdigo fuente requieren al menos dos componentes",LETRA_o,LETRA_i,nroLinea,LETRA_o,LETRA_o); //tilde
                                                    huboError = TRUE;
                                                    archivoPROC_guardarLog("Error de compilacióon todas las instrucciones operaciones dentro de la sección INTRUCCIONES del código fuente requieren al menos dos componentes"); //tilde
                                                }
                                                else //////////////////////////validar dentro de cada caso que: LEER y MOSTRAR == dos elementos, asSimple == 3 y asCompuesta == 5 como esta
                                                {
                                                    if ( ( StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),LEER)    ) ||
                                                            ( StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),MOSTRAR) ) ||
                                                            ( arbolVariablesFUNC_verificarExistenciaString(abb,listaStringsFUNC_darPRIMERstr(lsCompilacion))  )  )
                                                    {
                                                        if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),LEER)) //CASO 1
                                                        {
                                                            if (arbolVariablesFUNC_verificarExistenciaString(abb,listaStringsFUNC_darSEGUNDOstr(lsCompilacion)))
                                                            {
                                                                if (listaStringsFUNC_largo(lsCompilacion) == 2)
                                                                {
                                                                    //agrego instruccion en lista
                                                                    listaInstruccionesPROC_agregarInstruccionLEER(listaStringsFUNC_darSEGUNDOstr(lsCompilacion), li); //guarda en la lista el discriminante leer mas el nombre de la variable que se ira a buscar al abb en ejecucion
                                                                }
                                                                else
                                                                {
                                                                    printf("\n***Error de compilaci%sn - l%snea %d: para la instrucci%sn LEER debe \nutilizar solamente una variable declarada en la segunda secci%sn, la secci%sn de variables",LETRA_o, LETRA_i,nroLinea,LETRA_o,LETRA_o,LETRA_o); //tilde
                                                                    huboError = TRUE;
                                                                    archivoPROC_guardarLog("Error de compilación: para la instrucción LEER debe utilizar solamente una variable declarada en la segunda sección, la sección de variables"); //tilde

                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n***Error de compilaci%sn - l%snea %d: para la instrucci%sn LEER debe \nutilizar una variable declarada en la segunda secci%sn, la secci%sn de variables",LETRA_o, LETRA_i,nroLinea,LETRA_o,LETRA_o,LETRA_o); //tilde
                                                                huboError = TRUE;
                                                                archivoPROC_guardarLog("Error de compilación: para la instrucción LEER debe utilizar una variable declarada en la segunda sección, la secció de variables"); //tilde

                                                            }
                                                        }
                                                        else if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(lsCompilacion),MOSTRAR)) //CASO 2
                                                        {
                                                            if (arbolVariablesFUNC_verificarExistenciaString(abb,listaStringsFUNC_darSEGUNDOstr(lsCompilacion)))
                                                            {
                                                                if (listaStringsFUNC_largo(lsCompilacion) == 2)
                                                                {
                                                                    //agrego instruccion en lista
                                                                    listaInstruccionesPROC_agregarInstruccionMOSTRAR(listaStringsFUNC_darSEGUNDOstr(lsCompilacion), li); //guarda en la lista el discriminante leer mas el nombre de la variable que se ira a buscar al abb en ejecucion

                                                                }
                                                                else
                                                                {
                                                                    printf("\n***Error de compilaci%sn - l%snea %d: para la instrucci%sn MOSTRAR debe \nutilizar solamente una variable declarada en la segunda secci%sn, la secci%sn de variables",LETRA_o, LETRA_i,nroLinea,LETRA_o,LETRA_o,LETRA_o); //tilde
                                                                    huboError = TRUE;
                                                                    archivoPROC_guardarLog("Error de compilación: para la instrucción MOSTRAR debe utilizar solamente una variable declarada en la segunda sección, la sección de variables"); //tilde

                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n***Error de compilaci%sn - l%snea %d: para la instrucci%sn MOSTRAR debe \nutilizar una variable declarada en la segunda secci%sn, la secci%sn de variables",LETRA_o, LETRA_i,nroLinea,LETRA_o,LETRA_o,LETRA_o); //tilde
                                                                huboError = TRUE;
                                                                archivoPROC_guardarLog("Error de compilación: para la instrucción MOSTRAR debe utilizar una variable declarada en la segunda sección, la sección de variables"); //tilde

                                                            }
                                                        }
                                                        else //CASO 3-8, es una var
                                                        {
                                                            if ( StringDyn_equalSignoIgual(listaStringsFUNC_darSEGUNDOstr(lsCompilacion))  )
                                                            {
                                                                if ( listaStringsFUNC_largo(lsCompilacion) > 2 )
                                                                {

                                                                    if ( ( StringDyn_equalNumeroEntero(listaStringsFUNC_darTERCERstr(lsCompilacion))                         ) ||
                                                                         ( arbolVariablesFUNC_verificarExistenciaString(abb, listaStringsFUNC_darTERCERstr(lsCompilacion))   ) ||
                                                                         ( StringDyn_equalAnyFUNCarits(listaStringsFUNC_darTERCERstr(lsCompilacion))                         ) )//||
                                                                         //( StringDyn_equalNumeroEntero(listaStringsFUNC_darTERCERstr(lsCompilacion))                         )  )
                                                                         //validar el ultimo, creo que se tiene que validar que sea solo numero utilizando boolean StringDyn_equalNumeroEntero(StringDyn s1); //lo modifique al final
                                                                    {
                                                                        if (StringDyn_equalAnyFUNCarits(listaStringsFUNC_darTERCERstr(lsCompilacion)))
                                                                        {
                                                                            if (listaStringsFUNC_largo(lsCompilacion) == 5)
                                                                            {
                                                                                //Guardo las intruccion en la lista de instrucciones, le paso la lista de substring y se debera validar
                                                                                  //correctamente todas las combinaciones, tanto LEER, MOSTRAR y asiganciones, dadas en el diseño.
                                                                                //Utilizando la estructura y haciendo énfasis en la union para las combinaciones en la asignacion.
                                                                                //
                                                                                //tiene q retornar una bool para ver si hubo algun error, asi puedo saber si bucleo / bajo todo o no
                                                                                huboError = FALSE;
                                                                                //huboError = listaInstruccionesPROC_agregarInstruccionAScompuesta(lsCompilacion, nroLinea);
                                                                                listaInstruccionesPROC_agregarInstruccionAScompuesta(abb, li, lsCompilacion, nroLinea, huboError, nroLineaWarning, compiloConCero);
                                                                                if (compiloConCero && nroLineaWarning!=nroLineaAnterior)
                                                                                {
//                                                                                    compiloConCeroCont++;
//                                                                                }
//                                                                                if (compiloConCero && compiloConCeroCont>=2)
//                                                                                {
                                                                                    printf("\n***Alerta - l%snea %d: se esta asignando un int = 0, para realizar la operacion 'DIV'",LETRA_i,nroLineaWarning);
                                                                                    nroLineaAnterior = nroLineaWarning;
                                                                                }

                                                                            }
                                                                            else if(listaStringsFUNC_largo(lsCompilacion) < 5)
                                                                            {
                                                                                printf("\n***Error de compilaci%sn - l%snea %d: las instrucciones de las asignaciones \ncon FUNC tienen que tener 2 argumentos",LETRA_o, LETRA_i, nroLinea); //tilde
                                                                                printf("\nTip: las instrucciones-asignaciones con funciones aritm%sticas (SUM, RES, MUL, DIV) \ndeben estar conformados por 5 elementos en total,\nvariable declarada a asignar, seguida de un signo de igual ('='), a continuaci%sn una de las 4 FUNC y por %sltimo dos argumentos, pueden ser enteros o variables declaradas",LETRA_e,LETRA_o,LETRA_u); //tilde
                                                                                printf("\nEj: vara = SUM varb varc");
                                                                                huboError = TRUE;
                                                                                archivoPROC_guardarLog("***Error de compilación: las instrucciones de las asignaciones con FUNC tienen que tener 2 argumentos"); //tilde

                                                                            }
                                                                            else
                                                                            {
                                                                                printf("\n***Error de compilaci%sn - l%snea %d: las instrucciones de las asignaciones \ncon FUNC solo admiten como maximo 2 argumentos",LETRA_o, LETRA_i, nroLinea); //tilde
                                                                                printf("\nTip: las instrucciones-asignaciones con funciones aritm%sticas \n(SUM, RES, MUL, DIV) deben estar conformados por 5 elementos en total,\nvariable declarada a asignar, seguida de un signo de igual ('='), a continuaci%sn una de las 4 FUNC y por %sltimo dos argumentos, pueden ser enteros o variables declaradas",LETRA_e,LETRA_o,LETRA_u); //tilde
                                                                                printf("\nEj: vara = SUM varb varc");
                                                                                huboError = TRUE;
                                                                                archivoPROC_guardarLog("***Error de compilación: las instrucciones de las asignaciones con FUNC solo se admiten como maximo 2 argumentos"); //tilde

                                                                            }
                                                                        }
                                                                        else //caso 3 o 4
                                                                        {
                                                                            if (listaStringsFUNC_largo(lsCompilacion) == 3)
                                                                            {
                                                                                //validar en testeo si se controla bien en las asignaiones que toda variable exista en el abb, mas que nada en las combinaciones con 5 elementos

                                                                                //Guardo las intruccion en la lista de instrucciones
                                                                                //si es compuesto se valida dentro que todos los componentes desde el tercer substring sean validos, pero aqui
                                                                                // al ser simple, la primer y tercer substring que son variables, ya se validaron
                                                                                //lo que si hay que ver si el tercero, si no es var es un int, porque entro por el || y entro aca porque no es una FUNC, aca adentro hay que ver si es una var o un int y guardar
                                                                               // listaInstruccionesPROC_agregarInstruccionASsimpple(listaStringsFUNC_darPRIMERstr(lsCompilacion),listaStringsFUNC_darTERCERstr(lsCompilacion));

                                                                                huboError = FALSE;
                                                                               // listaInstruccionesPROC_agregarInstruccionASsimpple(listaStringsFUNC_darPRIMERstr(lsCompilacion),nroLinea,huboError);
                                                                                listaInstruccionesPROC_agregarInstruccionASsimpple(abb, li, lsCompilacion, nroLinea, huboError);
                                                                            }
                                                                            else
                                                                            {
                                                                                printf("\n***Error de compilaci%sn - l%snea %d: las instrucciones de las asignaciones sin \nFUNC solo admiten como maximo 1 argumentos (entero o variable declarada)",LETRA_o, LETRA_i, nroLinea); //tilde
                                                                                huboError = TRUE;
                                                                                archivoPROC_guardarLog("Error de compilación: las instrucciones de las asignaciones sin FUNC solo admiten como maximo 1 argumentos (entero o variable declarada)"); //tilde

                                                                            }

                                                                        }
                                                                    }
                                                                    else
                                                                    {
                                                                        printf("\n***Error de compilaci%sn - l%snea %d: luego del signo de = solo puede haber un entero, \nuna variable declarada o una de las cuatro FUNC validas (SUM, RES, MUL, DIV)",LETRA_o, LETRA_i, nroLinea); //tilde
                                                                        huboError = TRUE;
                                                                        archivoPROC_guardarLog("Error de compilación: luego del signo de = solo puede haber un entero, una variable declarada o una de las cuatro FUNC validas (SUM, RES, MUL, DIV)"); //tilde

                                                                    }
                                                                }
                                                                else
                                                                {
                                                                    printf("\n***Error de compilaci%sn - l%snea %d: luego del signo de = debe existir otro elemento, \npuede ser entero, una variable declarada o una de las cuatro FUNC validas (SUM, RES, MUL, DIV)",LETRA_o, LETRA_i, nroLinea); //tilde
                                                                    huboError = TRUE;
                                                                    archivoPROC_guardarLog("Error de compilación: luego del signo de = debe existir otro elemento, puede ser entero, una variable declarada o una de las cuatro FUNC validas (SUM, RES, MUL, DIV)"); //tilde
                                                                }
                                                            }
                                                            else
                                                            {
                                                                printf("\n***Error de compilaci%sn - l%snea %d: para la instrucci%sn asignaci%sn a una variable, \nse debe utilizar el signo '=' (de igual) posteriormente al nombre de la variable a asignar",LETRA_o, LETRA_i, nroLinea, LETRA_o, LETRA_o); //tilde
                                                                huboError = TRUE;
                                                                archivoPROC_guardarLog("Error de compilación: para la instrucción asignación a una variable, se debe utilizar el signo '=' (de igual) posteriormente al nombre de la variable a asignar"); //tilde

                                                            }
                                                        }
                                                    }
                                                    else
                                                    {
                                                        printf("\n***Error de compilaci%sn - l%snea %d: las instrucciones/operaciones posibles son LEER, MOSTRAR,\n o asiganci%sn a una variable declarada en la segunda secci%sn, la secci%sn de variables",LETRA_o, LETRA_i, nroLinea,LETRA_o,LETRA_o,LETRA_o); //tilde
                                                        huboError = TRUE;
                                                        archivoPROC_guardarLog("Error de compilación: las instrucciones/operaciones posibles son LEER, MOSTRAR, o asiganción a una variable declarada en la segunda sección, la sección de variables"); //tilde
                                                    }
                                                    //antes de leer otra lista borro libero la usada para la linea anterior---------------
                                                    listaStringsPROC_destruirLista(lsCompilacion);
                                                    linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
                                                    nroLinea++;
                                    //creo que el carga nueva linea hay que ponerlo aca para que si es un comentario no corte dos sino una
                                                }
//                                                //antes de leer otra lista borro libero la usada para la linea anterior---------------
//                                                listaStringsPROC_destruirLista(lsCompilacion);
//                                                linea = archivoFUNC_cargarLaSiguienteLinea(archivo);
                                            //nroLinea++; //porque no habia un linea++   // estaba abajo

                                                if (StringDyn_largo(linea) == 0) //validar si pongo StringDyn_largo(linea) == 0    o   una func que valide si linea esta vacia
                                                {
                                                    isFinalArchivo = TRUE;
                                                }
//                                                nroLinea++;

                                            }

                                        }

                                        //   }
                                    }
                                    else
                                    {
                                        printf("\n***Error de compilaci%sn - l%snea 3: la instrucci%sn(nombre) de la tercer secci%sn del c%sdigo fuente \ndeber ser la palabra 'INSTRUCCIONES'",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o); //tilde
                                        huboError = TRUE;
                                        archivoPROC_guardarLog("Error de compilación - línea 3: la instrucción(nombre) de la tercer sección del código fuente deber ser la palabra 'INSTRUCCIONES'"); //tilde

                                    }


                                }
                            }
                        }
                        else
                        {
                            printf("\n***Error de compilaci%sn - l%snea 2: la instrucci%sn de la segunda secci%sn del c%sdigo fuente tiene \nque comenzar con la palabra 'VARIABLES'",LETRA_o, LETRA_i,LETRA_o,LETRA_o,LETRA_o); //tilde
                            huboError = TRUE;
                            archivoPROC_guardarLog("Error de compilación - línea 2: la instrucción de la segunda sección del código fuente tiene que comenzar con la palabra 'VARIABLES'"); //tilde

                        }
                    }
                }
                else
                {
                    printf("\n***Error de compilaci%sn - l%snea 1: el argumento '",LETRA_o, LETRA_i);
                    StringDyn_print(listaStringsFUNC_darSEGUNDOstr(lsCompilacion));
                    printf("' de la instrucci%sn de la primera secci%sn del c%sdigo fuente tiene que coincidir \ncon el nombre del archivo '",LETRA_o,LETRA_o,LETRA_o);
                    StringDyn_print(nombrePrograma);
                    printf(".csim' y el nombre de programa como argumento que eligio a compilar");
                    huboError = TRUE;
                }
            }
            else
            {
                printf("\n***Error de compilaci%sn - l%snea 1: la instruccion de la primera seccion del codigo \nfuente tiene que comenzar con la palabra 'PROGRAMA'",LETRA_o, LETRA_i); //tilde
                huboError = TRUE;
                archivoPROC_guardarLog("Error de compilación - línea 1: la instruccion de la primera seccion del codigo fuente tiene que comenzar con la palabra 'PROGRAMA'"); //tilde

            }

        }
    }

       if (!huboError) //en este caso recorrio alguna instruccion/opreacion declarada y al no haber error bajo las dos estructuras a los archivos
        {
            FILE * archivoABB   = NULL;
            FILE * archivoLI    = NULL;
            archivoPROC_crearArchivo(archivoABB, StringDyn_concatenarFUNC(nombrePrograma, ext_vars)  );
            archivoPROC_crearArchivo(archivoLI,  StringDyn_concatenarFUNC(nombrePrograma, ext_inst)  );

            archivoPROC_cerrarArchivo(archivoABB);
            archivoPROC_cerrarArchivo(archivoLI);

            archivoPROC_abrirArchivo(archivoABB,StringDyn_concatenarFUNC(nombrePrograma, ext_vars) , "ab");
            archivoPROC_abrirArchivo(archivoLI, StringDyn_concatenarFUNC(nombrePrograma, ext_inst) ,"ab");

            archivoPROC_bajarABB_de_Variables_al_Archivo(abb, archivoABB);
            archivoPROC_listaInstrucciones_BajarLista_al_Archivo(li, archivoLI);

            archivoPROC_cerrarArchivo(archivoABB);
            archivoPROC_cerrarArchivo(archivoLI);

            validacionesPROC_variablesSinUso(abb, li, listaNombresOrdenEncontradas);
            if (listaStringsFUNC_largo(listaNombresOrdenEncontradas) == 0)
            {

            }
            else if (listaStringsFUNC_largo(listaNombresOrdenEncontradas) == 1)
            {
                printf("\n***Alerta: la siguiente variable, fue declarada pero no se utiliza en ninguna instrucci%sn: ",LETRA_o);
                listaStringsPROC_print(listaNombresOrdenEncontradas);
            }
            else
            {
                printf("\n***Alerta: las siguientes variables, fueron declaradas pero no se utilizan en ninguna instrucci%sn: ",LETRA_o);
                listaStringsPROC_print(listaNombresOrdenEncontradas);
            }
            printf("\n--------------Compilaci%sn exitosa, los archivos fueron creados correctamente--------------",LETRA_o);
            archivoPROC_guardarLog("Compilación exitosa, los archivos fueron creados correctamente");
    }

    archivoPROC_cerrarArchivo(archivo);
    arbolVariablesPROC_destruirABB(abb);
    listaInstruccionesPROC_destruirLI(li);
    listaStringsPROC_destruirLista(listaNombresOrdenEncontradas);
    listaStringsPROC_destruirLista(lsCompilacion); // si genera error es porque ya se hace dentro del codigo
    listaStringsPROC_destruirLista(listaCompiloConCero);
    StringDyn_destruir(linea);
    StringDyn_destruir(PROGRAMA);
    StringDyn_destruir(VARIABLES);
    StringDyn_destruir(INSTRUCCIONES);
    StringDyn_destruir(LEER);
    StringDyn_destruir(MOSTRAR);
    printf("\n");
    printf("\n");
    printf("\n__________________________________Fin de compilaci%sn______________________________________",LETRA_o);
    archivoPROC_guardarLog("Fin de compilación");
}

void PROC_ejecutar(StringDyn nombrePrograma)
{
//si la linea que se lee en un archivo resulta vacia, el contenido de la variable strDyn linea, tiene que tener el caracter nulo en la pos 0, asi se sabe que el usuario en esa linea no escribio nada
//validar si pongo StringDyn_largo(linea) = 1    o   una func que valide si linea esta vacia

    StringDyn linea;
    StringDyn_crear(linea);
    arbolVariables abb;
    arbolVariablesPROC_crearABB(abb);
    listaInstrucciones li;
    listaInstruccionesPROC_crearLI(li);
    int nroLinea = 0;
    boolean huboError = FALSE;
    listaStrings lsEjecucion;
    listaStringsPROC_crearLista(lsEjecucion);

    StringDyn ext_csim, ext_vars, ext_inst;
    StringDynPROC_iniStrDynExtensionesArchivos(ext_csim, ext_vars, ext_inst);
    StringDyn npArbol, npLista;
    StringDyn_crear(npArbol);
    StringDyn_crear(npLista);
    StringDyn_copiar(npArbol, nombrePrograma);
    StringDyn_copiar(npLista, nombrePrograma);
    StringDyn_concatenar(npArbol, ext_vars);
    StringDyn_concatenar(npLista, ext_inst);

//aqui no se usan las vars LEER MOSTRAR porque el switch lo hace con el enumerado-discriminante que el nodo de la lista lo tiene guardado
    FILE * archivoArbol = NULL;
    FILE * archivoVariables = NULL;

    archivoPROC_abrirArchivo(archivoArbol, npArbol, "rb");//"ab"); //validar si abro y cierros aca o dentro los archivos de compilacion
    archivoPROC_abrirArchivo(archivoVariables, npLista, "rb");//"ab");

    archivoPROC_levantoABB_de_Variables_a_Memoria(abb, archivoArbol);
    archivoPROC_listaInstrucciones_LevantarLista_a_Memoria(li, archivoVariables);

    archivoPROC_cerrarArchivo(archivoArbol);
    archivoPROC_cerrarArchivo(archivoVariables);

    if (!listaInstruccionesFUNC_isNull(li))  //significa que hay instruccion alguna entonces recorro y voy ejecutando
    {
        nroLinea = 0;
        huboError = FALSE;
        validacionesPROC_bucleInstruccionesEjecucion(abb, li, nroLinea, huboError);
    }
    printf("\n\n");
    arbolVariablesPROC_destruirABB(abb);
    listaInstruccionesPROC_destruirLI(li);
    listaStringsPROC_destruirLista(lsEjecucion);
    StringDyn_destruir(linea);
    StringDyn_destruir(npArbol);
    StringDyn_destruir(npLista);

    printf("\n__________________________________Fin de ejecucion______________________________________");
    archivoPROC_guardarLog("Fin de ejecucion");
}

void PROC_LimpiarYPausa()
{
    char limpiar;
    fflush(stdin);
    scanf("%c",&limpiar);
    system(LIMPIAR);
}

void cierrePrograma(int opcion)
{
    int i=0,j=0;

    system(LIMPIAR);
    printf("\n\n*******<<<  FIN DEL PROGRAMA CalcuSimple_PSTCompiler  >>>*******\n");
    printf("\n*************(Compilador del lenguaje CalcuSimple)**************\n");
    printf("\n*******<<<********************************************>>>*******\n");

    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
        {
            printf("%c",j);
        }
    }
    printf("\n%c",201);
    for (i=0; i<78 ; i++ )
    {

        printf("%c",205);
    }

    archivoPROC_guardarLog("Salió de CalcuSimple");

    printf("\n%c*****************<<<______About this software______>>>***********************%c",186,186);
    printf("\n%cUDE - Lic. en Info., Curso 2017/18, Nocturno Taller 1, Tutor: Gomez, Federico%c",186,186);
    printf("\n%c# proudlyDevelopedBy FG2 Group:                                              %c",186,186);
    printf("\n%c# Segovia, Joaquin - 4.739.544-4                                             %c",186,186);
    printf("\n%c# Pias, Richard    - 1.924.591-2                                             %c",186,186);
    printf("\n%c# Torres, Mathias  - 4.223.291-4                                             %c",186,186);
    printf("\n%c*****************************************************************************%c",186,186);
    printf("\n%c",200);
    for (i=0; i<78 ; i++ )
    {
        printf("%c",205);
    }
    for (j=176; j<179; j++)
    {
        printf("\n");
        for (i=0; i<80 ; i++ )
        {
            printf("%c",j);
        }
    }
    PROC_LimpiarYPausa();
}

