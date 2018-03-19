#include "instruccion.h"

void instruccionFUNC_cargar(instruccion &i, StringDyn nombreVar, enumOpsBasicas tipoInstruccion, int numeroEntero, StringDyn nomVar1, AS3 AS3_funcIntInt, AS4 AS4_funcIntVar, AS5 AS5_FuncVarInt, AS6 AS6_FuncVarVar){

//        StringDyn_crear(i.nombreVar);
        i.nombreVar = nombreVar; //probar si anda asi o con el strCopiar
        i.tipoInstruccion = tipoInstruccion;

        switch (tipoInstruccion)
        {
        case enum_AS1: i.discInstruccion.numeroEntero = numeroEntero;
            break;
        case enum_AS2:i.discInstruccion.nomVar1 = nomVar1;
            break;
        case enum_AS3:i.discInstruccion.AS3_funcIntInt = AS3_funcIntInt;
            break;
        case enum_AS4:i.discInstruccion.AS4_funcIntVar = AS4_funcIntVar;
            break;
        case enum_AS5:i.discInstruccion.AS5_FuncVarInt = AS5_FuncVarInt;
            break;
        case enum_AS6:i.discInstruccion.AS6_FuncVarVar = AS6_FuncVarVar;
            break;
        }
}

//selectoras

void instruccionPROC_darNombreVar0(instruccion instIN, StringDyn &nombreVar1LadoIzq){

    nombreVar1LadoIzq = instIN.nombreVar;
}

enumOpsBasicas instruccionFUNC_darTipoInstruccion(instruccion instIN){

    return instIN.tipoInstruccion;
}

int instruccionFUNC_darNumeroEntero(instruccion instIN){

    return instIN.discInstruccion.numeroEntero;
}

void instruccionPROC_darNombreVar1(instruccion instIN, StringDyn &nombreVar1LadoDer){

    nombreVar1LadoDer = instIN.discInstruccion.nomVar1;
}

AS3 instruccionFUNC_darAS3_funcIntInt(instruccion instIN){

    return instIN.discInstruccion.AS3_funcIntInt;
}

AS4 instruccionFUNC_darAS4_funcIntVar(instruccion instIN){

    return instIN.discInstruccion.AS4_funcIntVar;

}

AS5 instruccionFUNC_darAS5_FuncVarInt(instruccion instIN){

    return instIN.discInstruccion.AS5_FuncVarInt;
}

AS6 instruccionFUNC_darAS6_FuncVarVar(instruccion instIN){

    return instIN.discInstruccion.AS6_FuncVarVar;
}

StringDyn instruccionFUNC_darNombreVar0(instruccion instIN){//10
    return instIN.nombreVar;
}

StringDyn instruccionFUNC_darNombreVar1(instruccion instIN){//11
    return instIN.discInstruccion.nomVar1;
}
