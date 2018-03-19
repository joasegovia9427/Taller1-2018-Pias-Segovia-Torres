#include "arbolVariables.h"

void arbolVariablesPROC_crearABB(arbolVariables &abb)
{
    abb = NULL;
}

void arbolVariablesPROC_destruirABB(arbolVariables &abb)
{
    if (abb != NULL)
    {
        arbolVariablesPROC_destruirABB(abb -> Hizq);
        arbolVariablesPROC_destruirABB(abb -> Hder);
        delete abb;
        abb = NULL;
    }
}

boolean arbolVariablesFUNC_isArbolVacio(arbolVariables av)
{
    boolean IsVacio = TRUE;

    if(av == NULL)
    {
        IsVacio = TRUE;
    }
    else
    {
        IsVacio = FALSE;
    }
    return IsVacio;
}

void arbolVariablesPROC_agregarVariableAlArbol(arbolVariables &av, variable v)
{

    if (av == NULL)
    {
        av = new nodoVariable;
        av->info = v;
        av->Hizq = NULL;
        av->Hder = NULL;
    }
    else
    {
        if (variableFUNC_MenorQue(v,av->info) == TRUE)
        {
            arbolVariablesPROC_agregarVariableAlArbol(av->Hizq,v);
        }
        else
        {
            arbolVariablesPROC_agregarVariableAlArbol(av->Hder,v);
        }
    }
}

//Verificar si existe en el arbol la variable
boolean arbolVariablesFUNC_verificarExistenciaString(arbolVariables av, StringDyn str)
{
    if(av == NULL)
        return FALSE;
    else if (StringDyn_equal(str,variablePROC_darNombre_PARAMETRO(av->info)))
        return TRUE;
    else if(StringDyn_menor(str,variablePROC_darNombre_PARAMETRO(av->info)))
        return arbolVariablesFUNC_verificarExistenciaString(av->Hizq, str);
    else
        return arbolVariablesFUNC_verificarExistenciaString(av->Hder, str);
}

//Dar la raiz del ABB
variable arbolVariablesFUNC_darRaiz(arbolVariables abb)
{
    return abb->info;
}

arbolVariables arbolVariablesFUNC_darHizq(arbolVariables abb)
{
    return abb->Hizq;
}

arbolVariables arbolVariablesFUNC_darHder(arbolVariables abb)
{
    return abb->Hder;
}

void arbolVariablesPROC_modificarVariableEnABB(arbolVariables &abb, StringDyn nombreVar, int nuevoValor){
    if ( StringDyn_equal(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)) )
    {
        variablePROC_modificarValor(abb->info, nuevoValor);
    }
    else if(StringDyn_menor(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)))
        return arbolVariablesPROC_modificarVariableEnABB(abb->Hizq, nombreVar, nuevoValor);
    else
        return arbolVariablesPROC_modificarVariableEnABB(abb->Hder, nombreVar, nuevoValor);
}

void arbolVariablesPROC_PrintNombreValor(arbolVariables abb, StringDyn nombreVar){//10
    if ( StringDyn_equal(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)) )
    {
        printf("\n");
        StringDyn_print(variablePROC_darNombre_PARAMETRO(abb->info));
        printf(" vale: %d",variableFUNC_darValor(abb->info));
    }
    else if(StringDyn_menor(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)))
        return arbolVariablesPROC_PrintNombreValor(abb->Hizq, nombreVar);
    else
        return arbolVariablesPROC_PrintNombreValor(abb->Hder, nombreVar);
}

int arbolVariablesFUNC_valorDeVariable(arbolVariables abb, StringDyn nombreVar){
    if ( StringDyn_equal(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)) )
    {
        return variableFUNC_darValor(abb->info);
    }
    else if(StringDyn_menor(nombreVar,variablePROC_darNombre_PARAMETRO(abb->info)))
        return arbolVariablesFUNC_valorDeVariable(abb->Hizq, nombreVar);
    else
        return arbolVariablesFUNC_valorDeVariable(abb->Hder, nombreVar);
}

void arbolVariablesPROC_obtenerListaDeNombres(arbolVariables abb, listaStrings &variablesUSADAS){
    if (abb != NULL)
    {
        arbolVariablesPROC_obtenerListaDeNombres(abb->Hizq, variablesUSADAS);
        arbolVariablesPROC_obtenerListaDeNombres(abb->Hder, variablesUSADAS);
        listaStringsPROC_instertFront(variablesUSADAS, variablePROC_darNombre_PARAMETRO(abb->info));
    }
}
