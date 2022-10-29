#include <stdio.h>
#include <stdlib.h>

#include "micro.h"
#include "empresa.h"
#include "tipo.h"


#include "validaciones.h"

#include <string.h>
#include <ctype.h>
#include <string.h>




/*
---------------------------------------------------------------------------------------
                                  Inicializar Arrays
---------------------------------------------------------------------------------------
*/

int inicializarMicros(eMicro vec[], int tam)
{
    int todoOk = 0;

    if(vec!= NULL && tam > 0)
    {

        for( int i = 0; i < tam; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}


/*
---------------------------------------------------------------------------------------
                                 HARCODEO DE FUNCIONES
---------------------------------------------------------------------------------------
*/


int harcodearMicros(eMicro vec[], int tamM, int cantM, int* pNextId)
{
    int todoOk = 0;

    eMicro micros [15]=
    {
        {0, 1000, 5000, 30,0},
        {0, 1001, 5003, 40,0},
        {0, 1002, 5001, 20,0},
        {0, 1003, 5002, 50,0},
        {0, 1004, 5001, 40,0},
        {0, 1004, 5000, 34,0},
        {0, 1002, 5003, 48,0},
        {0, 1001, 5002, 40,0},
        {0, 1003, 5001, 35,0},
        {0, 1000, 5000, 29,0},
        {0, 1004, 5003, 30,0},
        {0, 1002, 5002, 40,0},
        {0, 1000, 5000, 35,0},
        {0, 1003, 5001, 45,0},
        {0, 1004, 5002, 30,0}

    };

    if(vec != NULL && pNextId != NULL && tamM> 0 && tamM <=15 && cantM <= tamM)
    {
        for (int i = 0; i<cantM; i++)
        {
            vec[i]= micros[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}


/*
---------------------------------------------------------------------------------------
                                  ALTA  DE DATOS
---------------------------------------------------------------------------------------
*/

int menuMicro()
{
    int opcion;

    system("cls");
    printf("********** ABM MICRO*******\n\n");
    printf("1.  Alta Micro\n");
    printf("2.  Modificar Micro\n");
    printf("3.  Baja Micro\n");
    printf("4.  Listar Micro\n");
    printf("5.  Listar Empresas\n");
    printf("6.  Listar Tipos\n");
    printf("7.  Listar Destinos\n");
    printf("8.  Alta de Viaje\n");
    printf("9.  Listar Viajes\n");
    printf("10. Informes\n");
    printf("11. Informes Viajes\n");



    printf("30. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}





int buscarLibreMicros(eMicro vec[], int tam, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tam > 0)
    {
        for(int i = 0; i < tam ; i++)
        {
            *pIndex = -1;

            if(vec[i].isEmpty)
            {
                *pIndex = i;
                break;
            }

        }

        todoOk = 1;

    }

    return todoOk;

}







int altaMicro(eMicro vec[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idEmpresa;
    int idTipo;
    int auxCapPas;
    eMicro nuevoMicro;


    if(vec != NULL  && empresas != NULL  && tipos != NULL  && tamM > 0 && tamE > 0 && tamT > 0 && pNextId != NULL)

    {
        system("cls");
        printf("***************Alta Micro********\n");
        printf("----------------------------------\n");
        buscarLibreMicros(vec, tamM, &indice);


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoMicro.id = *pNextId;




            //listar empresas
            listarEmpresas(empresas, tamE);
            printf("Ingrese  Id Empresa: ");
            fflush(stdin);
            scanf("%d", &idEmpresa);
            while(validarEmpresas(empresas,tamE, idEmpresa)==0)
            {
                printf("Reingrese  Id Empresa: ");
                fflush(stdin);
                scanf("%d", &idEmpresa);
            }

            nuevoMicro.idEmpresa = idEmpresa;

            //listar tipos.
            listarTipos(tipos, tamT);
            printf("Ingrese  Id tipo: ");
            fflush(stdin);
            scanf("%d", &idTipo);
            while(validarTipos(tipos,tamT, idTipo)==0)
            {
                printf("Reingrese  Id tipos: ");
                fflush(stdin);
                scanf("%d", &idTipo);
            }

            nuevoMicro.idTipo = idTipo;


            pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");
            while(auxCapPas <1 || auxCapPas > 50)
            {
                printf("Error, maximo permitido 50 pasajeros\n");
                pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");

            }


            nuevoMicro.capacidad = auxCapPas;


            nuevoMicro.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoMicro;
            //aca lo inyecto en la lista de las altas.

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1


            todoOk = 1;

        }




    }

    return todoOk;
}



/*
---------------------------------------------------------------------------------------
                                 MODIFICAR DATOS
---------------------------------------------------------------------------------------
*/

int modificarMicro(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    int idTipo;
    int auxCapPas;
    char confirma;
    char opcion [] = {"1,2,"};



    if(micros != NULL && tamM > 0 && empresas != NULL && tipos != NULL && tamT >0)
    {
        listarMicros(micros, tamM, empresas, tamE, tipos, tamT); //tiene listar y lista fila.
        printf("Ingrese Id:");
        scanf("%d", &id);

        system("cls");
        printf("*********Datos del Micros a Modificar*******\n");

        if(buscarMicro(micros, tamM, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe un micro con Id %d en el sistema\n", id);
            }

            else
            {
                mostrarMicro(micros[indice], tamM, empresas, tamE, tipos, tamT);

                switch(menuModificarMicro())
                {
                case 1:

                    listarTipos(tipos, tamT);
                    printf("Ingrese el id del Tipo: \n");
                    fflush(stdin);
                    scanf("%d", &idTipo);
                    while(validarTipos(tipos, tamT, idTipo)==0)
                    {
                        printf("Error!! Reingrese el id del Tipo: \n");
                        fflush(stdin);
                        scanf("%d", &idTipo);

                    }


                    micros[indice].idTipo = idTipo;
                    if(confirmarCarga(&confirma))
                    {

                        micros[indice].idTipo = idTipo;
                    }
                    break;



                case 2:
                    pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");
                    while(auxCapPas <1 || auxCapPas > 50)
                    {
                        printf("Error, debe ingresar entre 1 y 50\n");
                        pedirValidarNumero(&auxCapPas, "cantidad de pasajero: ");

                    }



                    if(confirmarCarga(&confirma))
                    {

                        micros[indice].capacidad = auxCapPas;
                    }

                    break;


                default:
                    validarOpcion(opcion);
                    break;



                }

            }

            todoOk = 1;

        }

    }

    return todoOk;
}





int listarMicros(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int flag = 1;
    if(micros != NULL  && empresas!= NULL  && tipos != NULL && tamM > 0 && tamE > 0 && tamT > 0)
    {
        //system("cls");
        printf("------------------------------------------------------------\n");
        printf("|               *** LISTADO DE MICROS ***                   |\n");
        printf("------------------------------------------------------------\n");
        printf("|ID  MICRO |       EMPRESA   |        TIPO     |  CAPACIDAD |\n");
        printf("------------------------------------------------------------\n");

        for(int i = 0; i< tamM; i++)
        {
            if(!micros[i].isEmpty)//es un filtro que dice que no se muestra cuando el campo isEmpty no esta vacio. es lo mismo que decir vec[i].isEmpty ==0
            {
                mostrarMicroFila(micros[i], tamM, empresas, tamE, tipos, tamT);
                flag = 0;

            }


        }

        printf("------------------------------------------------------------\n");

        if(flag)
        {

            printf("     no hay micros en el sistema\n");
        }
    }


    return todoOk;
}


void mostrarMicroFila(eMicro micros, int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{

    char descripcionEmpresa [20];
    char descripcionTipo [20];

    cargarDescripcionEmpresa(empresas, tamE, micros.idEmpresa, descripcionEmpresa);
    cargarDescripcionTipos(tipos, tamT, micros.idTipo, descripcionTipo);


    printf("|   %4d   |    %10s   |   %10s    |      %2d    |\n",
           micros.id,
           descripcionEmpresa,
           descripcionTipo,
           micros.capacidad
          );

}




int buscarMicro(eMicro micros[], int tamM, int id, int* pIndex)
{
    int todoOk = 0;

    if(micros != NULL && tamM > 0  && pIndex != NULL)
    {

        *pIndex = -1;
        for(int i = 0; i < tamM; i++)
        {

            //aca busco que la estructura no este vacia y que el id que busco coincida con ese lugar.
            if(!micros[i].isEmpty && micros[i].id == id)
            {
                *pIndex = i;
                break;

            }

        }

        todoOk = 1;
    }


    return todoOk;
}




int validarMicro (eMicro micros[], int tamM, int id)
{
    int esValido = 0;
    int indice;

    if(buscarMicro(micros, tamM, id, &indice))
    {
        if(indice!=-1)
        {
            esValido=1;
        }
    }

    return esValido;
}



void mostrarMicro(eMicro micros, int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    char descripcionEmpresa [20];
    char descripcionTipo [20];

    cargarDescripcionEmpresa(empresas, tamE, micros.idEmpresa, descripcionEmpresa);
    cargarDescripcionTipos(tipos, tamT, micros.idTipo, descripcionTipo);


    printf("Id: %d\n", micros.id);
    printf("Empresa: %s\n", descripcionEmpresa);
    printf("Tipo: %s\n", descripcionTipo);
    printf("Capacidad: %d\n", micros.capacidad);


}




int menuModificarMicro()
{
    int opcion;
    printf("--------------------------------\n");
    printf("|   *** CAMPO A MODIFICAR ***  |\n");
    printf("--------------------------------\n");
    printf("1. Tipo\n");
    printf("2. Capacidad\n");
    printf("3. Salir:\n");
    printf("Ingrese Opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;


}








/*
---------------------------------------------------------------------------------------
                                  BAJA DE DATOS
---------------------------------------------------------------------------------------
*/


int bajaMicro (eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice;
    int id;
    char confirma;

    if(micros != NULL && tamM > 0 && empresas != NULL && tamE > 0 && tipos != NULL && tamT >0)
    {
        listarMicros(micros, tamM, empresas, tamE, tipos, tamT);

        printf("Ingrese Id:");
        scanf("%d", &id);
        if(buscarMicro(micros,tamM, id, &indice)==1)
        {
            if(indice == -1)
            {
                printf("no existe ese Micro con ese Id %d en el sistema\n", id);
            }

            else
            {
                mostrarMicro(micros[indice], tamM, empresas,tamE, tipos, tamT);
                printf("confirma baja?\n");
                fflush(stdin);
                scanf("%c", &confirma);

                if(confirma == 's' || confirma == 'S')
                {

                    micros[indice].isEmpty = 1;
                    printf("Baja exitosa\n");
                }

                else
                {
                    printf("Baja cancelada por el usuario\n");
                }

            }

            todoOk = 1;

        }



    }


    return todoOk;

}




int ordenarMicroXEmpresaCapacidad(eMicro vec[], int tam)
{
    int todoOk = 0;
    eMicro auxMicro;

    if(vec != NULL && tam > 0)
    {
        for(int i = 0; i < tam -1; i++)
        {
            for(int j = i +1; j < tam; j++)
            {
                if(((vec[i].idEmpresa == vec[j].idEmpresa) && (vec[i].capacidad > vec[j].capacidad))

                        ||((vec[i].idEmpresa != vec[j].idEmpresa) && (vec[i].idEmpresa > vec[j].idEmpresa)))
                {

                    auxMicro = vec[i];
                    vec[i]= vec[j];
                    vec[j]= auxMicro;

                }
            }
        }

        todoOk = 1;
    }


    return todoOk;
}






/*

-------------------------------------------------------------------------------------------------------

                                     INFORMES

-------------------------------------------------------------------------------------------------------

*/


int menuInformes()
{
    int opcion;

    printf("-------------------------------------------------------\n");
    printf("|                *** MENU DE INFORMES ***             |\n");
    printf("-------------------------------------------------------\n");

    printf("1- Mostrar micros de empresa seleccionada X usuario\n");
    printf("2- Mostrar micros de un tipo seleccionado\n");
    printf("3- Mostrar porcentaje de micros Comun\n");
    printf("4- Mostrar un listado de micros separadas por empresas\n");
    printf("5- Mostrar la empresa que transporta mas pasajero\n");
    printf("6- Mostrar la empresa con menor cantidad de micros\n");
    printf("7-Salir\n");
    printf("\n\n");

    printf("ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    return opcion;
}



int informes (eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{

    int todoOk = 0;

    if(vec != NULL && tipos != NULL && empresas != NULL && tam >0 && tamT > 0 && tamE > 0)
    {
        switch(menuInformes())
        {
        case 1:
            mostrarMicroXIdEmpresa(vec, tam, tipos, tamT,empresas, tamE);
            break;

        case 2:
            mostrarMicroXIdTipo(vec, tam, tipos, tamT,empresas, tamE);
            break;

        case 3:
            porcentajeMicroVip(vec,tam, empresas, tamE);
            break;

        case 4:
            mostrarMicroXEmpresas(vec, tam, tipos, tamT, empresas, tamE);
            break;

        case 5:
            informeMicrosMayor(vec, tam, tipos, tamT, empresas, tamE);
            break;


        case 6:
            empresasMenosMicros(vec, tam, empresas, tamE);
            break;


        }



        todoOk = 1;
    }





    return todoOk;
}





/*

                                         INFORMES

-------------------------------------------------------------------------------------------------------

 PUNTO 1)                     MOSTRAR MICRO DE LA EMPRESA SELECCIONADA POR USUARIO

-------------------------------------------------------------------------------------------------------
*/



int mostrarMicroXIdEmpresa(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    int idEmpresa;


    if(vec != NULL && tam > 0 && tipos != NULL && tamT > 0 && empresas != NULL && tamE >0)
    {

        system("cls");
        printf("---------------------------------------------\n");
        printf("|INFORME DE MICRO DE UNA EMPRESA SELECCIONADA|\n");
        printf("---------------------------------------------\n");

        listarEmpresas(empresas, tamE);

        printf("ingrese el id de la Empresa: \n");
        scanf("%d", &idEmpresa);

        while(!validarEmpresas(empresas, tamE, idEmpresa))
        {
            printf("id Invalido. Reingrese el id de la empresa: \n");
            scanf("%d", &idEmpresa);
        }

        microsXIdEmpresa(vec, tam, tipos, tamT, empresas, tamE, idEmpresa);

        todoOk = 1;
    }

    return todoOk;
}





int microsXIdEmpresa(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, int idEmpresa)
{
    int todoOk = 0;
    char descripcionEmpresa [20];

    int flag = 1;

    if(vec != NULL && tam > 0 && tipos != NULL && tamE > 0 && empresas != NULL && tamE > 0)
    {
        cargarDescripcionEmpresa(empresas, tamE, idEmpresa, descripcionEmpresa);


        printf("\nMicros Empresas %s\n\n", descripcionEmpresa);
        printf("-------------------------------------------------------------\n");
        printf("|ID MICROS |     EMPRESA     |       TIPO      | CAPACIDAD  |\n");
        printf("-------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idEmpresa == idEmpresa)
            {
                mostrarMicroFila(vec[i], tam, empresas, tamE, tipos, tamE);
                flag = 0;
            }
        }

        printf("-------------------------------------------------------------\n");


        if(flag)
        {

            printf("no hay micros de esa Empresa con ese ID cargado en el sistema\n");
        }


        todoOk = 1;

    }

    return todoOk;

}



/*
-------------------------------------------------------------------------------------------------------

PUNTO 2)                               MOSTRAR X TIPO SELECCIONADO  X USUARIO

-------------------------------------------------------------------------------------------------------
*/



int mostrarMicroXIdTipo(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    int idTipo;


    if(vec != NULL && tam > 0 && tipos != NULL && tamT > 0 && empresas != NULL && tamE >0)
    {

        system("cls");
        printf("--------------------------------------------\n");
        printf("| *INFORME DE MICRO DE UN TIPO SELECCIONADO*|\n");
        printf("--------------------------------------------\n");

        listarTipos(tipos, tamT);

        printf("ingrese el id del tipo: \n");
        scanf("%d", &idTipo);

        while(!validarTipos(tipos, tamT, idTipo))
        {
            printf("id Invalido. Reingrese el id del tipo: \n");
            scanf("%d", &idTipo);
        }

        microsXIdTipo(vec, tam, tipos, tamT, empresas, tamE, idTipo);

        todoOk = 1;
    }

    return todoOk;
}





int microsXIdTipo(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, int idTipo)
{
    int todoOk = 0;
    char descripcionTipo [20];
    int flag = 1;

    if(vec != NULL && tam > 0 && tipos != NULL && tamE > 0 && empresas != NULL && tamE > 0)
    {
        cargarDescripcionTipos(tipos, tamT, idTipo, descripcionTipo);


        printf("\nMicros Tipos %s\n\n", descripcionTipo);

        printf("-------------------------------------------------------------\n");
        printf("|ID MICROS |     EMPRESA     |       TIPO      | CAPACIDAD  |\n");
        printf("-------------------------------------------------------------\n");
        for(int i = 0; i< tam; i++)
        {

            if(!vec[i].isEmpty && vec[i].idTipo == idTipo)
            {
                mostrarMicroFila(vec[i], tam, empresas, tamE, tipos, tamE);
                flag = 0;
            }
        }

        printf("-------------------------------------------------------------\n");

        if(flag)
        {

            printf("no hay micros de ese tipo con ese ID cargado en el sistema\n");
        }


        todoOk = 1;

    }

    return todoOk;

}



/*
--------------------------------------------------------------------------------------------------------

PUNTO 3)                 MOSTRAR PORCENTAJE DE MICRO VIP SOBRE EL TOTAL DE UNA EMPRESA

--------------------------------------------------------------------------------------------------------

*/



int porcentajeMicroVip (eMicro vec[], int tam, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    int idEmpresa;
    int contadorMicros = 0;
    int contadorVip = 0;
    float porcentaje;

    if (vec != NULL && tam > 0 && empresas != NULL && tamE > 0)

    {
        printf("\n**** PORCENTAJE DE MICROS VIP POR TOTAL EMPRESA   ****\n");

        listarEmpresas(empresas, tamE);
        printf("Ingrese ID de la empresa: \n");
        scanf("%d", &idEmpresa);
        while (!validarEmpresas(empresas,tamE,idEmpresa))
        {
            printf("\n Id Empresa. invalido. Reingrese ID de empresa: \n");
            scanf("%d", &idEmpresa);
        }

        for(int i = 0; i < tam; i++)
        {
            if(vec[i].idEmpresa == idEmpresa)
            {
                contadorMicros++;
                if( vec[i].isEmpty == 0 && vec[i].idTipo == 5003)
                {
                    contadorVip++;
                }
            }
        }

        if (contadorMicros == 0)
        {
            printf("\nNo se encontraron micros en la empresa\n");
        }
        else
        {
            porcentaje = ((contadorVip * 100) / contadorMicros);
            printf("\nPorcentaje de micros tipo vip: %5.2f\n", porcentaje);
        }
        todoOk = 1;
    }

    return todoOk;
}






/*
-------------------------------------------------------------------------------------------------------

  PUNTO 4                    MOSTRAR LISTADO DE MICROS SEPARADOS X EMPRESA

-------------------------------------------------------------------------------------------------------
*/


int mostrarMicroXEmpresas(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;




    if(vec != NULL && tam > 0 && tipos != NULL && tamT > 0 && empresas != NULL && tamE >0)
    {
        system("cls");
        printf("-----------------------------------------------------------\n");
        printf("|         ***INFORME MICROS SEPARADOS POR EMPRESAS***      |\n");
        printf("-----------------------------------------------------------\n");

        for(int i = 0;  i < tamE; i ++)
        {

            microsXIdEmpresa(vec, tam, tipos, tamT, empresas, tamE,empresas[i].id) ;
        }



        todoOk = 1;
    }

    return todoOk;
}


/*
 ------------------------------------------------------------------------------------------------------

                          BUSCAR EMPRESA CON MAYOR CANTIDAD DE PASAJEROS

-------------------------------------------------------------------------------------------------------
*/
int informeMicrosMayor(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE)
{
    int todoOk= 0;
    int mayorMicro;
    int flag = 0;




    if(vec!=NULL && tam > 0)
    {
        system("cls");
        printf("***********Informes Empresas Mayor cantidad Pasajeros********\n");
        printf("      ID        EMPRESA             TIPO          CANTIDAD  \n");
        printf("---------------------------------------------------------------\n");


        for(int i = 0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                if(flag == 0 || vec[i].capacidad >= mayorMicro)
                {
                    mayorMicro = vec[i].capacidad;
                    flag = 1;
                }
            }

        }



        for(int i = 0; i<tam; i++)
        {
            if(!vec[i].isEmpty)
            {
                if(vec[i].capacidad == mayorMicro)
                {
                    mostrarMicroFila(vec[i],tam, empresas, tamE,tipos,tamT);
                }

            }

        }



        if(!flag)
        {
            printf(" No hay micros cargados en el sistema\n");

        }


        todoOk = 1 ;

    }

    return todoOk;

}



/*
 ------------------------------------------------------------------------------------------------------

 PUNTO 6)                       BUSCAR EMPRESA CON MENOR CANTIDAD DE MICROS

-------------------------------------------------------------------------------------------------------
*/


int totalMicrosXIdEmpresa(eMicro vec[], int tam, eEmpresa empresas[], int tamE, int idEmpresa, int* pTotal)
{

    int todoOk = 0;
    int contMicros = 0;

    if(vec != NULL && tam > 0 && empresas != NULL && tamE > 0 && pTotal != NULL)
    {
        system("cls");
        printf("            ****Empresa/s donde hay menos micros*****  \n");
        printf("-----------------------------------------------------------\n");


        for(int i = 0; i < tam; i++)//recorro el array de micros
        {

            if(!vec[i].isEmpty && vec[i].idEmpresa == idEmpresa)

            {
                contMicros++;

            }

        }

        *pTotal = contMicros;

        todoOk = 1;


    }



    return todoOk;
}






int empresasMenosMicros(eMicro vec[], int tam, eEmpresa empresas[], int tamE)
{
    int todoOk = 0;
    //int totales[5]= {0}; // una forma de hacerlo. vector de flotante del mismo tamaño del vector de sectores.
    int cantEmp[tamE]; //segunda forma de hacerlo es por extension.
    int flag = 1;
    int menor;

    if(vec != NULL && tam > 0 && empresas != NULL && tamE > 0)
    {
        for(int i = 0; i < tamE; i++)
        {
            cantEmp[i]=0;
        }

        for(int i = 0; i < tamE; i++)
        {
            totalMicrosXIdEmpresa(vec, tam, empresas, tamE, empresas[i].id, &cantEmp[i]); //tengo la cantidad de micros cargadas en mi vector paralelo.
        }

        for( int i = 0; i<tamE; i++) //recorro el vector buscando el menor.
        {
            if(flag || cantEmp[i]< menor)
            {
                menor = cantEmp[i];
                flag= 0;
            }

        }

        printf("empresa/s donde hay %d  micros es : \n", menor);

        for(int i = 0; i <tamE; i++)//cuando conozco el mayor recorro el vector de totales y cuando encuentro una posicion donde se
            //guarda el mayor en la misma posicion del sector esta la descripcion del sector que cobra eso entonces lo muestro.
        {

            if(cantEmp[i]==menor)
            {
                printf("%s\n", empresas[i].descripcion);
            }
        }
        printf("\n\n");
        todoOk = 1;

    }

    return todoOk;
}


