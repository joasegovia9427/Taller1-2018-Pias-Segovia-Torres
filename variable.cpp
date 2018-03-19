#include "variable.h"

//Aproximacion a lo que hay que hacer
void variablePROC_carga(variable &v, StringDyn nombreVar)
{
    v.nombre = nombreVar;
    v.valor = 0;
}

void variableFUNC_PARAM_cargaVariable(variable &v, StringDyn nombreVariable, int valor){

    v.nombre = nombreVariable;
    v.valor = valor;
}

boolean variableFUNC_areIguales(variable v1, variable v2)
{
    if(StringDyn_equal(v1.nombre, v2.nombre))
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}


//Selectora que muestra el nombre de la variable
StringDyn variablePROC_darNombre_PARAMETRO(variable v)
{
    StringDyn nombreVar;
    StringDyn_crear(nombreVar);
    nombreVar= v.nombre;
    return nombreVar;
}

//Selectora sin return
void variablePROC_darNombre(variable v, StringDyn &nombreVar)
{
    nombreVar = v.nombre;
}

//Selectora que devuelve el valor numerico de la variable
int variableFUNC_darValor(variable v)
{
    return (v.valor);
}

//VALIDACION EXTRA  //significa que v1 es menor que v2
boolean variableFUNC_MenorQue(variable v1, variable v2)
{
    if(StringDyn_menor(v1.nombre,v2.nombre) == TRUE)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

void variablePROC_modificarValor(variable &v, int newValor){
    v.valor = newValor;
}
