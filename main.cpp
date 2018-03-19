////UDE, Lic. En Informática, Curso 2017/18 - Nocturno - Taller 1 - Tutor: Gómez, Federico
////Integrantes Grupo FG2: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4 ; Torres, Mathias - 4.223.291-4

#include "validaciones.h"

int main()
{
    // redimensiona la consola
    system(REDIM);
    system(COLOR);
    system(TITULO);

    if(archivoFUNC_existeArchivo("titulo.tit") == TRUE)
        system(LOGO);

    int opcion = 1;
    StringDyn lineaComando;
    StringDyn_crear(lineaComando);   //la creo en cada ite del while

    StringDyn salir, compilar, ejecutar;
    StringDynPROC_iniStrDynVarsMain(salir, compilar, ejecutar);

    StringDyn nombreProgConcatenado;
    StringDyn_crear(nombreProgConcatenado);

    StringDyn ext_csim, ext_vars, ext_inst;
    StringDynPROC_iniStrDynExtensionesArchivos(ext_csim, ext_vars, ext_inst);

    listaStrings ls;
    listaStringsPROC_crearLista(ls);   //la creo en cada ite del while

    printf("\n**********BIENVENIDO A PROGRAMA CalcuSimple_PSTCompiler***********");
    printf("\n\n***********(Compilador del lenguaje CalcuSimple)******************\n\n");
    archivoPROC_guardarLog("Inicio el programa");

    do
    {
        fflush(stdin);
        opcion = 1;
        listaStringsPROC_destruirLista(ls);
        StringDyn_destruir(lineaComando);

        StringDyn_crear(lineaComando);
        listaStringsPROC_crearLista(ls);

        printf("\n\n\nIngrese comando: ");
        archivoPROC_guardarLog("Ingreso de comando");

        StringDyn_scan(lineaComando);

        archivoPROC_guardarLog(lineaComando);

        PROC_partirStrEnSubStrs(lineaComando, ls);

        if (listaStringsFUNC_largo(ls) != 0)
        {
            if (StringDyn_contiene_MAYUSCULAS(listaStringsFUNC_darPRIMERstr(ls)))
            {
                printf("\n***Error: el comando ingresado solo puede contener letras min%ssculas",LETRA_u); //tilde
                archivoPROC_guardarLog("Error el comando ingresado solo puede contener letras minúsculas");

            }
            else if (StringDyn_contiene_numeros(listaStringsFUNC_darPRIMERstr(ls)))
            {
                printf("\n***Error: el comando ingresado no puede tener n%smeros",LETRA_u); //tilde
                archivoPROC_guardarLog("Error el comando ingresado no puede tener números");
            }
            else if (listaStringsFUNC_largo(ls) == 1)
            {
                if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(ls),salir))
                {
                    opcion = 0; // no vuelvo al prompt y salgo del programa
                }
                else
                {
                    printf("\n***Error: el comando ingresado no es valido, el %snico comando sin argumentos en CalcuSimple es 'salir'",LETRA_u); //tilde
                    archivoPROC_guardarLog("Error el comando ingresado no es valido, el único comando sin argumentos en CalcuSimple es 'salir'");
                }
            }
            else if (listaStringsFUNC_largo(ls) == 2)
            {

                if (StringDyn_contiene_MAYUSCULAS(listaStringsFUNC_darPRIMERstr(ls)))
                {
                    printf("\n***Error: el comando ingresado solo puede contener letras min%ssculas", LETRA_u); //tilde
                    archivoPROC_guardarLog("Error el comando ingresado solo puede contener letras minúsculas");
                }
                else if (StringDyn_contiene_numeros(listaStringsFUNC_darPRIMERstr(ls)))
                {
                    printf("\n***Error: el comando ingresado no puede tener n%smeros",LETRA_u); //tilde
                    archivoPROC_guardarLog("Error el comando ingresado no puede tener números");
                }
                else
                {
                    nombreProgConcatenado = StringDyn_concatenarFUNC(listaStringsFUNC_darSEGUNDOstr(ls),ext_csim);

                    if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(ls),compilar))
                    {
                        if (StringDyn_contiene_MAYUSCULAS(listaStringsFUNC_darSEGUNDOstr(ls)))
                        {
                            printf("\n***Error: el argumento '");
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("' a compilar ingresado solo puede contener letras min%ssculas",LETRA_u); //tilde
                        }
                        else if (StringDyn_contiene_numeros(listaStringsFUNC_darSEGUNDOstr(ls)))
                        {
                            printf("\n***Error: el argumento '");
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("' a compilar ingresado no puede contener n%smeros",LETRA_u); //tilde
                        }
                        else if (archivoFUNC_existeArchivo( nombreProgConcatenado ) )
                        {
                            if (archivoFUNC_isArchivoVacio( nombreProgConcatenado ))
                            {
                                printf("\n***Error de compilaci%sn: El archivo ", LETRA_o); //tilde
                                StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                                printf(".csim esta vac%so.", LETRA_i);
                            }
                            else
                            {
                            //if devuelve true, existe entonces intento compilar
                            /*CÓDIGO CORRESPONDIENTE A compilar */
                                PROC_compilar(listaStringsFUNC_darSEGUNDOstr(ls));
                            }
                        }
                        else
                        {
                            printf("\n***Error: no existe el archivo de c%sdigo fuente con el nombre de programa '",LETRA_o);
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("'.csim a compilar, por favor aseg%srese de crearlo previamente",LETRA_u);
                        }
                    }
                    else if (StringDyn_equal(listaStringsFUNC_darPRIMERstr(ls),ejecutar))
                    {
                        if (StringDyn_contiene_MAYUSCULAS(listaStringsFUNC_darSEGUNDOstr(ls)))
                        {
                            printf("\n***Error: el argumento '");
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("' a ejecutar ingresado solo puede contener letras min%ssculas",LETRA_u); //tilde
                        }
                        else if (StringDyn_contiene_numeros(listaStringsFUNC_darSEGUNDOstr(ls)))
                        {
                            printf("\n***Error: el argumento '");
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("' a ejecutar ingresado no puede contener n%smeros",LETRA_u);//tilde
                        }
                        else if (      archivoFUNC_existeArchivo( StringDyn_concatenarFUNC(listaStringsFUNC_darSEGUNDOstr(ls),ext_inst) )    &&
                                       archivoFUNC_existeArchivo( StringDyn_concatenarFUNC(listaStringsFUNC_darSEGUNDOstr(ls),ext_vars) )    )
                        {
    //validar si se valida la existencia de algo en cada archivo de compilacion
                        //if devuelve true, existen  entonces intento ejecutar

                        /*CÓDIGO CORRESPONDIENTE A ejecutar */
                            PROC_ejecutar(listaStringsFUNC_darSEGUNDOstr(ls));
                        }
                        else
                        {

                            printf("\n***Error: no existe los archivos de compilaci%sn con el nombre de programa '", LETRA_o);
                            StringDyn_print(listaStringsFUNC_darSEGUNDOstr(ls));
                            printf("' a ejecutar, por favor aseg%srese de compilar previamente",LETRA_u);
                        }
                    }
                    else
                    {
                        printf("\n***Error: el comando ingresado no es valido, solo existen los comandos 'compilar' o 'ejecutar' para un argumento (nombre de programa)"); //tilde
                        archivoPROC_guardarLog("Error el comando ingresado no es valido, solo existen los comandos 'compilar' o 'ejecutar' para un argumento (nombre de programa)");
                    }
                }
            }
            else
            {
                printf("\n***Error: el comando ingresado no es valido, no existen comandos con un argumento (nombre de programa) compuesto por mas de una palabra");
                archivoPROC_guardarLog("Error el comando ingresado no es valido, no existen comandos con un argumento (nombre de programa) compuesto por mas de una palabra");
            }
        }
        else
        {
            printf("\n***Error: ingrese comando");
            archivoPROC_guardarLog("Error ingrese comando");
        }

    }while (opcion != 0);

    StringDyn_destruir(lineaComando);
    StringDyn_destruir(salir);
    StringDyn_destruir(compilar);
    StringDyn_destruir(ejecutar);
    StringDyn_destruir(nombreProgConcatenado);
    listaStringsPROC_destruirLista(ls);
    cierrePrograma(opcion);
}
////UDE, Lic. En Informática, Curso 2017/18 - Nocturno - Taller 1 - Tutor: Gómez, Federico
////Integrantes Grupo FG2: Pías, Richard - 1.924.591-2 ; Segovia, Joaquín - 4.739.544-4 ; Torres, Mathias - 4.223.291-4
