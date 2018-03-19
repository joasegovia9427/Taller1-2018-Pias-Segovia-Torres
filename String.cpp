#include "String.h"

//Crea el string dinamico
void StringDyn_crear(StringDyn &s)
{
    s = new char[1];
    s[0] = '\0';
}
//Crea un string dinamico de un largo determinado.
void StringDyn_crearDadoLargo(StringDyn &s, int largo)
{
    s = new char[largo +1];
    s[0] = '\0';
    s[largo] = '\0';
}

//Destruye el string dinamico
void StringDyn_destruir(StringDyn &s)
{
//    delete [] s;
//    s = NULL;

    StringDyn_crear(s);
}

//Funcion que devuelve el largo de un string dinamico
int StringDyn_largo(StringDyn s)
{

    int i = 0;
    while (s[i] != '\0')
    {
        i++;
    }
    return i;
}

void StringDyn_copiar(StringDyn &s1,StringDyn s2)
{
    int i = 0;
    int largo = StringDyn_largo(s2) + 1;
    delete [] s1;
    s1 = new char[largo];
    while (s2[i] != '\0')
    {
        s1[i] = s2[i];
        i++;
    }
    s1[i] = '\0';
}

void StringDyn_copiarDadoLargo(StringDyn &s1,StringDyn s2, int largo, int inicio)
{
    int i = inicio;
    int j = 0;
    s1 = new char[largo+1];
    while((s2[i] != '\0') && (s2[i] != ' '))
    {
        s1[j] = s2[i];
        i++;
        j++;
    }
    s1[j] = '\0';
}

void StringDyn_scan (StringDyn &s)
{
    StringDyn aux = new char[MAX];
    int i=0;
    char c;
    scanf("%c", &c);
    while((c!= '\n') && (i < MAX-1))
    {
        aux[i] = c;
        i++;
        scanf ("%c", &c);
    }
    aux[i] = '\0';
    StringDyn_copiar(s,aux);
    StringDyn_destruir(aux);

}

void StringDyn_concatenar(StringDyn &s1,StringDyn s2)
{
    StringDyn aux;
    StringDyn_crear(aux);
    StringDyn_copiar(aux, s1);
    int largo = StringDyn_largo(s1) + StringDyn_largo(s2) + 1;
    if (largo > MAX)
        largo = MAX;
    delete [] s1;
    s1 = new char[largo];
    int i = 0;
    while (aux[i] != '\0')
    {
        s1[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX-1)
    {
        s1[i] = s2[j];
        i++;
        j++;
    }
    s1[i] = '\0';
    StringDyn_destruir(aux);
}

StringDyn StringDyn_concatenarFUNC(StringDyn s1, StringDyn s2)
{
    StringDyn aux;
    StringDyn_crear(aux);
    StringDyn_copiar(aux, s1);
    int largo = StringDyn_largo(s1) + StringDyn_largo(s2) + 1;
    if (largo > MAX)
        largo = MAX;

    StringDyn sAUX;
    StringDyn_crearDadoLargo(sAUX, largo-1);

    int i = 0;
    while (aux[i] != '\0')
    {
        sAUX[i] = aux[i];
        i++;
    }
    int j = 0;
    while (s2[j] != '\0' && i < MAX-1)
    {
        sAUX[i] = s2[j];
        i++;
        j++;
    }
    sAUX[i] = '\0';
    StringDyn_destruir(aux);
    return sAUX;
}

void StringDyn_swap(StringDyn &s1, StringDyn &s2)
{
    StringDyn aux;
    aux = s1;
    s1 = s2;
    s2 = aux;
    StringDyn_destruir(aux);
}

void StringDyn_print(StringDyn s)
{
    fflush(stdin);
    int i = 0;
    while(s[i]!= '\0')
    {
        fflush(stdout);
        printf("%c", s[i]);
        i++;
    }
}

boolean StringDyn_menor(StringDyn s1, StringDyn s2)
{
    int i = 0;
    boolean encontre = FALSE;
    boolean menor = FALSE;
    while ((!encontre) && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            encontre = TRUE;
        if (s1[i] < s2[i])
            menor = TRUE;
        i++;
    }
    if ((!encontre) && (s2[i]!='\0'))
        menor = TRUE;
    return menor;
}

boolean StringDyn_equal(StringDyn s1,StringDyn s2)
{
    int i = 0;
    boolean iguales = TRUE;
    while (iguales && (s1[i] != '\0') && (s2[i] != '\0'))
    {
        if (s1[i] != s2[i])
            iguales = FALSE;
        i++;
    }
    if ((s1[i] != '\0') || (s2[i] != '\0'))
        iguales = FALSE;
    return iguales;
}

//Funcion que verifica si el string contiene al menos un caracter en minuscula.
boolean StringDyn_contiene_minusculas(StringDyn s1)
{

    int i = 0;
    boolean hayMinusculas = FALSE;
    while (!hayMinusculas  && (s1[i] != '\0'))
    {
        if ((s1[i] >= 97) && (s1[i] <= 122))
            hayMinusculas  = TRUE;
        i++;
    }
    return hayMinusculas;
}

//Funcion que verifica si el string contiene al menos un caracter numerico.
boolean StringDyn_contiene_numeros(StringDyn s1)
{

    int i = 0;
    boolean hayNumeros = FALSE;
    while (!hayNumeros  && (s1[i] != '\0'))
    {
        if ((s1[i] >= 48) && (s1[i] <= 57))
            hayNumeros  = TRUE;
        i++;
    }
    return hayNumeros;
}

//Funcion que verifica si el string contiene al menos un caracter en mayuscula.
boolean StringDyn_contiene_MAYUSCULAS(StringDyn s1)
{

    int i = 0;
    boolean hayMayusculas = FALSE;
    while (!hayMayusculas && (s1[i] != '\0'))
    {
        if ((s1[i] >= 65) && (s1[i] <= 90))
            hayMayusculas = TRUE;
        i++;
    }
    return hayMayusculas;
}

boolean StringDyn_equalSignoIgual(StringDyn s1)
{
    if ( (s1[0] == 61)   &&   (StringDyn_largo(s1) == 1) )
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

//valida que el s1 sea igual a una de las funcs, SUM DIV RES MUL
boolean StringDyn_equalAnyFUNCarits(StringDyn s1)
{
    boolean equalAnyFUNCarits = FALSE;

    if (StringDyn_equalSUM(s1) == TRUE)
    {
        equalAnyFUNCarits = TRUE;
    }
    else if (StringDyn_equalRES(s1) == TRUE)
    {
        equalAnyFUNCarits = TRUE;
    }
    else if (StringDyn_equalMUL(s1) == TRUE)
    {
        equalAnyFUNCarits = TRUE;
    }
    else if (StringDyn_equalDIV(s1) == TRUE)
    {
        equalAnyFUNCarits = TRUE;
    }
    else
    {
        equalAnyFUNCarits = FALSE;
    }
    return equalAnyFUNCarits;
}

//Funcion que compara un string con Ascii para determinar si el string = SUM
boolean StringDyn_equalSUM(StringDyn s1)
{
    boolean equalSUM = FALSE;

    if (s1[0] == 83)
    {
        if (s1[1] == 85)
        {
            if (s1[2] == 77)
            {
                equalSUM = TRUE;
            }
        }
    }
    else
    {
        equalSUM = FALSE;
    }
    return equalSUM;
}

//Funcion que compara un string con Ascii para determinar si el string = RES
boolean StringDyn_equalRES(StringDyn s1)
{
    boolean equalRES = FALSE;

    if (s1[0] == 82)
    {
        if (s1[1] == 69)
        {
            if (s1[2] == 83)
            {
                equalRES = TRUE;
            }
        }
    }
    else
    {
        equalRES = FALSE;
    }
    return equalRES;
}
//Funcion que compara un string con Ascii para determinar si el string = MUL
boolean StringDyn_equalMUL(StringDyn s1)
{
    boolean equalMUL = FALSE;

    if (s1[0] == 77)
    {
        if (s1[1] == 85)
        {
            if (s1[2] == 76)
            {
                equalMUL = TRUE;
            }
        }
    }
    else
    {
        equalMUL = FALSE;
    }
    return equalMUL;
}

//Funcion que compara un string con Ascii para determinar si el string = DIV
boolean StringDyn_equalDIV(StringDyn s1)
{
    boolean equalDIV = FALSE;

    if (s1[0] == 68)
    {
        if (s1[1] == 73)
        {
            if (s1[2] == 86)
            {
                equalDIV = TRUE;
            }
        }
    }
    else
    {
        equalDIV = FALSE;
    }
    return equalDIV;
}

//valida que el s1 sea igual a un numero entero
boolean StringDyn_equalNumeroEntero(StringDyn s1)
{
    StringDyn s;
    StringDyn_crear(s);
    StringDyn_copiar(s,s1);
    boolean isNumero = TRUE;

    if ( (StringDyn_largo(s) == 1) && (s[0]=='-') ) //si al ver si los caracteres son numeros, si es justo el primero y ademas es igual a '-', significa que es un numero negativo, el strToInt tiene que validar seguro que si se da el caso, solo el [0] contendra un -, en ese caso se ara 0 menos el numero antes de retornarlo y se retornara la diferencia
    {
        isNumero = FALSE;
    }
    else if (  (StringDyn_largo(s) >= 2) && (s[0]=='-')  )
    {
        StringDynPROC_quitarSimboloSignoNeg(s);
    }


    int i = 0;
    while((isNumero) && (s[i] != '\0'))
    {
        if( (s[i] != '0') &&
                (s[i] != '1') &&
                (s[i] != '2') &&
                (s[i] != '3') &&
                (s[i] != '4') &&
                (s[i] != '5') &&
                (s[i] != '6') &&
                (s[i] != '7') &&
                (s[i] != '8') &&
                (s[i] != '9')  )
        {
            isNumero = FALSE;
        }
        else
        {
            i++;
        }
    }
    return isNumero;
}

int StringDyn_cantidad_de_SubString(StringDyn s1)
{
    int i = 0;
    int j = 0;
    while(s1[i] != '\0')
    {
        if(s1[i] == ' ')
        {
            j++;
        }
        i++;
    }
    return j;
}

void StringDynPROC_iniStrDynVarsCompilar(StringDyn &PROGRAMA, StringDyn &VARIABLES, StringDyn &INSTRUCCIONES, StringDyn &LEER, StringDyn &MOSTRAR)
{
    StringDyn_crearDadoLargo(PROGRAMA,8);
    StringDyn_crearDadoLargo(VARIABLES,9);
    StringDyn_crearDadoLargo(INSTRUCCIONES,13);
    StringDyn_crearDadoLargo(LEER,4);
    StringDyn_crearDadoLargo(MOSTRAR,7);
    PROGRAMA[0] = 'P';
    PROGRAMA[1] = 'R';
    PROGRAMA[2] = 'O';
    PROGRAMA[3] = 'G';
    PROGRAMA[4] = 'R';
    PROGRAMA[5] = 'A';
    PROGRAMA[6] = 'M';
    PROGRAMA[7] = 'A';
    PROGRAMA[8] = '\0';
    VARIABLES[0] = 'V';
    VARIABLES[1] = 'A';
    VARIABLES[2] = 'R';
    VARIABLES[3] = 'I';
    VARIABLES[4] = 'A';
    VARIABLES[5] = 'B';
    VARIABLES[6] = 'L';
    VARIABLES[7] = 'E';
    VARIABLES[8] = 'S';
    VARIABLES[9] = '\0';
    INSTRUCCIONES[0] = 'I';
    INSTRUCCIONES[1] = 'N';
    INSTRUCCIONES[2] = 'S';
    INSTRUCCIONES[3] = 'T';
    INSTRUCCIONES[4] = 'R';
    INSTRUCCIONES[5] = 'U';
    INSTRUCCIONES[6] = 'C';
    INSTRUCCIONES[7] = 'C';
    INSTRUCCIONES[8] = 'I';
    INSTRUCCIONES[9] = 'O';
    INSTRUCCIONES[10] = 'N';
    INSTRUCCIONES[11] = 'E';
    INSTRUCCIONES[12] = 'S';
    INSTRUCCIONES[13] = '\0';
    LEER[0] = 'L';
    LEER[1] = 'E';
    LEER[2] = 'E';
    LEER[3] = 'R';
    LEER[4] = '\0';
    MOSTRAR[0] = 'M';
    MOSTRAR[1] = 'O';
    MOSTRAR[2] = 'S';
    MOSTRAR[3] = 'T';
    MOSTRAR[4] = 'R';
    MOSTRAR[5] = 'A';
    MOSTRAR[6] = 'R';
    MOSTRAR[7] = '\0';
}

void StringDynPROC_iniStrDynVarsMain(StringDyn &salir, StringDyn &compilar, StringDyn &ejecutar)
{
    StringDyn_crearDadoLargo(salir,5);
    StringDyn_crearDadoLargo(compilar,8);
    StringDyn_crearDadoLargo(ejecutar,8);
    salir[0] = 's';
    salir[1] = 'a';
    salir[2] = 'l';
    salir[3] = 'i';
    salir[4] = 'r';
    salir[5] = '\0';
    compilar[0] = 'c';
    compilar[1] = 'o';
    compilar[2] = 'm';
    compilar[3] = 'p';
    compilar[4] = 'i';
    compilar[5] = 'l';
    compilar[6] = 'a';
    compilar[7] = 'r';
    compilar[8] = '\0';
    ejecutar[0] = 'e';
    ejecutar[1] = 'j';
    ejecutar[2] = 'e';
    ejecutar[3] = 'c';
    ejecutar[4] = 'u';
    ejecutar[5] = 't';
    ejecutar[6] = 'a';
    ejecutar[7] = 'r';
    ejecutar[8] = '\0';
}

void StringDynPROC_iniStrDynVarsOpsArits(StringDyn &SUM, StringDyn &RES, StringDyn &MUL, StringDyn &DIV)
{
    StringDyn_crearDadoLargo(SUM,3);
    StringDyn_crearDadoLargo(RES,3);
    StringDyn_crearDadoLargo(MUL,3);
    StringDyn_crearDadoLargo(DIV,3);
    SUM[0] = 'S';
    SUM[1] = 'U';
    SUM[2] = 'M';
    SUM[3] = '\0';
    RES[0] = 'R';
    RES[1] = 'E';
    RES[2] = 'S';
    RES[3] = '\0';
    MUL[0] = 'M';
    MUL[1] = 'U';
    MUL[2] = 'L';
    MUL[3] = '\0';
    DIV[0] = 'D';
    DIV[1] = 'I';
    DIV[2] = 'V';
    DIV[3] = '\0';
}

void StringDynPROC_iniStrDynExtensionesArchivos(StringDyn &ext_csim, StringDyn &ext_vars, StringDyn &ext_inst)
{
    StringDyn_crear(ext_csim);
    StringDyn_crear(ext_vars);
    StringDyn_crear(ext_inst);

    ext_csim[0] = '.';
    ext_csim[1] = 'c';
    ext_csim[2] = 's';
    ext_csim[3] = 'i';
    ext_csim[4] = 'm';
    ext_csim[5] = '\0';

    ext_vars[0] = '.';
    ext_vars[1] = 'v';
    ext_vars[2] = 'a';
    ext_vars[3] = 'r';
    ext_vars[4] = 's';
    ext_vars[5] = '\0';

    ext_inst[0] = '.';
    ext_inst[1] = 'i';
    ext_inst[2] = 'n';
    ext_inst[3] = 's';
    ext_inst[4] = 't';
    ext_inst[5] = '\0';

}

void StringDynPROC_separarPrimerPalabra(StringDyn linea, StringDyn &palabra, StringDyn &restoLinea)
{
    int i=0,j=0;
    int largo = StringDyn_largo(linea);// + 1;

    //elimino palabra
//    StringDyn_destruir(palabra);
    //creo palabra como mucho el largo de la linea
    StringDyn_crearDadoLargo(palabra,largo);
    //cargo palabra con la primer palabra que encuentre hasta un espacio
    while ( (linea[i] != '\0') && (linea[i] != ' ') )
    {
        palabra[i] = linea[i];
        i++;
    }
    palabra[i] = '\0';
    if (linea[i] == ' ')
    {
        i++;
    }
    //elimino la var restoLinea
    StringDyn_destruir(restoLinea);
    //creo la variable restoLinea como mucho el largo de la linea
    StringDyn_crearDadoLargo(restoLinea,largo);
    //ahora cargo a partir donde me quede despues de palabra con el  i, de linea[i] a restoLinea

    j=0;
    while ( (linea[i] != '\0') )//&& (linea[i] != ' ') )
    {
        restoLinea[j] = linea[i];
        i++;
        j++;
    }
    restoLinea[j] = '\0';

    //ahora tengo a la linea original
    //+
    //la primer palabra de la linea original en la var palabra
    //+
    //el resto de la linea orginial, sin palabra, en la variable restoLinea

//solo retorno estas dos ultimas, pues, si palabra no esta vacia, la agrego al back de listaStrings
// y el restoLinea le se asignara a linea originial... para hacer este proceso iterativamente hasta que lineaResto este vacia.
}

int StringDynFUNC_stringToNumeric(StringDyn s1)
{
    int cantUnidades, nroParseado = 0;
    int i=0, j=0, n=0, x=0, y=0;
    boolean isNegativo = FALSE;
    if (s1[0] == '-')//por la logia del isNumeric, se que solo tengo que validar el [0]=='-', si es negativo levanto flag para hacer 0 - num al final, ademas nunca leo se - en el for
    {
        isNegativo = TRUE;
        StringDynPROC_quitarSimboloSignoNeg(s1);
    }
    cantUnidades = StringDyn_largo(s1);
    for (i=0; i<cantUnidades; i++)
    {
        n = s1[cantUnidades - (i+1)] - '0';
        x = n;
        y = i;
        for (j=0; j<y; j++)
        {
            x *= 10;
        }
        nroParseado = nroParseado + x;
    }

    if (isNegativo == TRUE)
    {
        nroParseado =  0-nroParseado;
        return nroParseado;
    }
    else
    {
        return nroParseado;
    }
}

void StringDynPROC_limpiarFinalLinea(StringDyn &s1)
{
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '\r')
        {
            s1[i] = '\0';
        }
        else if(s1[i] == '\n')
        {
            s1[i] = '\0';
        }
        else
        {
            i++;
        }
    }
}

void StringDynPROC_limpiarTabsLinea(StringDyn &s1){
    int i = 0;
    while (s1[i] != '\0')
    {
        if (s1[i] == '\t')
        {
            s1[i] = ' ';
        }
        i++;
    }
}

void StringDynPROC_siSoloEspaciosCaracterNulo(StringDyn &s1){
    boolean tieneAlgunCaracter = FALSE;
    int i = 0;
    while (   (s1[i] != '\0') &&  (!tieneAlgunCaracter)   )
    {
        if (s1[i] != ' ')
        {
            tieneAlgunCaracter = TRUE;
        }
        i++;
    }
    if (tieneAlgunCaracter == FALSE)
    {
        s1[0] = '\0';
    }
}

void StringDynPROC_quitarSimboloSignoNeg(StringDyn &s1){
    int i = 1;
    while (   (s1[i] != '\0')  )
    {
        s1[i-1] = s1[i];
        i++;
    }
    s1[i-1] = '\0';
}

boolean StringDyn_contiene_minusculasSolo(StringDyn s1)
{
    int i = 0;
    boolean hayOtrosChars = TRUE;
    while ((hayOtrosChars)  && (s1[i] != '\0'))
    {
        if ((s1[i] < 97) || (s1[i] > 122))  //((s1[i] <= 96) || (s1[i] >= 123))
            hayOtrosChars  = FALSE;
        i++;
    }
    return hayOtrosChars;
}
