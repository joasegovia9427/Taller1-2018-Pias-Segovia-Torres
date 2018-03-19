#include "boolean.h"

void booleanPROC_carga(boolean &booleanoAcargar)
{
    char opcion;
    do
    {
        fflush(stdin);
        printf("\nIngrese una opci%sn(S o N): ", LETRA_o);
        scanf("%c",&opcion);
        switch (opcion)
        {
        case 's':
            booleanoAcargar=TRUE;
            break;
        case 'S':
            booleanoAcargar=TRUE;
            break;
        case 'n':
            booleanoAcargar=FALSE;
            break;
        case 'N':
            booleanoAcargar=FALSE;
            break;
        default:
            printf("\nError al leer dato, reintente...");
            break;
        }
    }
    while (opcion != 'S' && opcion != 's' && opcion != 'N' && opcion != 'n');
}

void booleanPROC_mostrar(boolean booleanoAdesplegar)
{
    switch (booleanoAdesplegar)
    {
    case FALSE:
        printf(" Falso");
        break;
    case TRUE:
        printf(" Verdadero");
        break;
    }
}
