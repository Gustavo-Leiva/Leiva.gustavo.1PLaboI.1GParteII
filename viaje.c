#include <stdio.h>
#include <stdlib.h>


#include "empresa.h"
#include "viaje.h"


int inicializarViaje(eViaje vec[], int tamV)
{
    int todoOk = 0;

    if(vec!= NULL && tamV > 0)
    {

        for( int i = 0; i < tamV; i++)
        {
            vec[i].isEmpty = 1;
        }

        todoOk = 1;
    }


    return todoOk;
}







int altaViaje(eViaje vec[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,  int* pNextId)
{

    int todoOk = 0;
    int indice;
    int idMicro;
    int idDestino;
    eFecha fecha;
    eViaje nuevoViaje;


    if(vec != NULL  && micros != NULL && empresas != NULL && tipos != NULL  && destinos != NULL && tamV > 0 && tamM > 0 && tamE > 0 && tamT > 0 && tamD > 0 && pNextId != NULL)

    {
        system("cls");
        printf("                     ***ALTA DE VIAJES***          \n");
        printf("------------------------------------------------------------\n");
        buscarLibreViaje(vec, tamV, &indice); //esta funcion devuelve -1 sino hay lugar o el numero de indice proximo vacio.


        if (indice == -1)
        {
            printf("No hay lugar en el sistema\n");
        }

        else
        {
            nuevoViaje.id = *pNextId;



            //listar micros
            listarMicros(micros,tamM,empresas, tamE,tipos,tamT);
            printf("Ingrese  Id Micro: ");
            fflush(stdin);
            scanf("%d", &idMicro);
            while(validarMicro(micros,tamM, idMicro)==0)
            {
                printf("Reingrese  Id Micro: ");
                fflush(stdin);
                scanf("%d", &idMicro);
            }

            nuevoViaje.idMicro = idMicro;

            //listar destinos.
            listarDestinos(destinos, tamD);
            printf("Ingrese  Id Destino: ");
            fflush(stdin);
            scanf("%d", &idDestino);
            while(validarDestinos(destinos,tamD, idDestino)==0)
            {
                printf("Reingrese  Id Destino: ");
                fflush(stdin);
                scanf("%d", &idDestino);
            }

            nuevoViaje.idDestino = idDestino;


            while(pidoValidoFecha(&fecha)== 0)
            {
                printf("ingrese fecha de Ingreso dd/mm/aaaa:");
                scanf("%d/%d/%d",
                      &fecha.dia,
                      &fecha.mes,
                      &fecha.anio);

            }

            nuevoViaje.fecha = fecha;


            nuevoViaje.isEmpty = 0;
            //lo igual a cero porque digo que esa posicion no va a estar libre
            //recordar que isEmpty es 1 si esta libre. y 0 sin no lo esta


            vec[indice] = nuevoViaje;
            //aca lo inyecto en la lista de las altas.

            (*pNextId)++;
            //aca una vez inyectado tengo que actualizar a traves de *pNextId lo incremento en 1



            todoOk = 1;

        }




    }

    return todoOk;
}


int buscarLibreViaje(eViaje vec[], int tamV, int* pIndex)
{
    int todoOk;

    if(vec != NULL && pIndex != NULL && tamV > 0)
    {
        for(int i = 0; i < tamV ; i++)
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



int listarViajes(eViaje viajes[],  int tamV, eDestino destinos[], int tamD)
{
    int todoOk = 0;
    int flag = 1;

    if(viajes != NULL && destinos != NULL && tamV > 0 && tamD > 0)
    {

        printf("----------------------------------------------------------------\n");
        printf("|                ***LISTADO DE VIAJES***                       |\n");
        printf("----------------------------------------------------------------\n");
        printf("|   ID VIAJE   |    ID MICRO  |     ID DESTINO  |     FECHA    |\n");
        printf("----------------------------------------------------------------\n");

        for(int i = 0; i < tamV; i++)
        {

            if( !viajes[i].isEmpty)
            {
                mostrarViajeFila(viajes[i], destinos, tamD);
                flag = 0;
            }

        }
        printf("----------------------------------------------------------------\n");
        todoOk = 1;
    }

    if(flag)
    {

        printf("     no hay viajes en el sistema\n");
    }


    return todoOk;
}


void mostrarViajeFila (eViaje viajes, eDestino destinos[], int tamD)
{

    char descripcionDestino [20];


    if(destinos != NULL && tamD > 0)
    {
        cargarDescripcionDestino(destinos, tamD, viajes.idDestino, descripcionDestino);




        printf("|    %4d      |      %4d    |  %12s   |   %02d/%02d/%02d |\n",
               viajes.id,
               viajes.idMicro,
               descripcionDestino,
               viajes.fecha.dia,
               viajes.fecha.mes,
               viajes.fecha.anio
              );


    }

}


int harcodearViajes(eViaje vec[], int tamV, int cantV, int* pNextId)
{
    int todoOk = 0;

    eViaje viajes [15]=
    {
        {0, 8002, 20001,{10,7,2019},0},
        {0, 8002, 20001,{10,10,2019},0},
        {0, 8002, 20002,{9,9,2022},0},
        {0, 8006, 20003,{29,9,2021},0},
        {0, 8004, 20002,{11,8,2022},0},
        {0, 8005, 20001,{12,7,2022},0},
        {0, 8005, 20003,{14,6,2022},0},
        {0, 8003, 20002,{23,5,2022},0},
        {0, 8008, 20002,{19,4,2022},0},
        {0, 8005, 20000,{12,3,2022},0},
        {0, 8010, 20002,{26,2,2022},0},
        {0, 8010, 20002,{22,2,2020},0},
        {0, 8012, 20003,{12,1,2021},0},
        {0, 8012, 20003,{30,10,2022},0},
        {0, 8014, 20000,{17,8,2022},0}



    };

    if(vec != NULL && pNextId != NULL && tamV > 0 && tamV <=15 && cantV <= tamV)
    {
        for (int i = 0; i<cantV; i++)
        {
            vec[i]= viajes[i];
            vec[i].id = *pNextId;
            (*pNextId)++;

        }

        todoOk = 1;
    }

    return todoOk;
}






int menuInformesViajes()
{
    int opcion;

    system("cls");
    printf("********** INFORME DE VIAJES*******\n\n");
    printf("1. listar viajes de micros x Id\n");
    printf("2. listar costos de micros x Id\n");
    printf("3. listar micros segun id destino\n");
    printf("4. Listar viajes segun fecha seleccionada\n");
    printf("30. Salir\n");

    printf("ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);


    return opcion;

}


int InformesViajes(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV)
{
    int todoOk = 0;

    if(vec && tipos && empresas && destinos && viajes && tam > 0 && tamT > 0 && tamE > 0 && tamD > 0 && tamV > 0)
    {
        switch(menuInformesViajes())
        {
        case 1:
            viajesXIdMicro(vec, tam, tipos, tamT, empresas, tamE, destinos, tamD, viajes, tamV);
            break;
        case 2:
            costosXIdMicro(vec, tam, tipos, tamT, empresas, tamE, destinos, tamD, viajes, tamV);
            break;
        case 3:
            destinoMicros(vec, tam, tipos, tamT, empresas, tamE, destinos, tamD, viajes, tamV);
            break;
        case 4:
            viajesXFecha(vec, tam, tipos, tamT, empresas, tamE, destinos, tamD, viajes, tamV);
            break;


        }
    }
    else
    {
        printf("Para acceder a los informes primero debe cargar viajes en el sistema\n");
    }
    todoOk = 1;
    return todoOk;
}

/*
------------------------------------------------------------------------------------------------------------
punto 7)                         Pedir un micro y mostrar todos los viajes que hizo el mismo.
------------------------------------------------------------------------------------------------------------
*/

int viajesXIdMicro (eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV)
{
    int todoOk = 0;
    int bufferMicro;
    int flag = 0;

    if(vec != NULL && tipos != NULL && empresas != NULL && destinos != NULL && viajes != NULL && tam > 0 && tamT > 0 && tamE > 0 && tamD > 0 && tamV > 0)

    {

        listarMicros(vec, tam, empresas, tamE, tipos, tamT);
        printf("Ingrese Id de Micro: ");
        scanf("%d",&bufferMicro);
        while(validarMicro(vec, tam, bufferMicro)==0)
        {
            listarMicros(vec, tam,empresas, tamE, tipos, tamT),
            printf("Ingrese Id de Micro ");
            scanf("%d",&bufferMicro);
            validarMicro(vec, tam, bufferMicro);
        }
        printf("************  VIAJES PARA ID MICRO %d *************\n\n", bufferMicro);
        printf(" ID Viaje        ID MICRO       VIAJE              FECHA \n");
        printf("---------------------------------------------------\n\n");
        for(int i=0; i < tamV; i++)
        {
            if(!viajes[i].isEmpty && viajes[i].idMicro == bufferMicro)
            {
                mostrarViajeFila(viajes[i], destinos, tamD);
                flag = 1;
            }
        }
        todoOk = 1;

        if(!flag)
        {
            printf(" No hay viajes realizados con id %d en el sistema\n", bufferMicro);

        }


    }

    return todoOk;
}




/*
------------------------------------------------------------------------------------------------------------
punto 8)                Pedir un micro e informar la suma de los precios (costo) de todos los viajes que realizo
------------------------------------------------------------------------------------------------------------
*/



int costosXIdMicro (eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV  )
{

    int todoOk = 0;
    int bufferMicro;
    float acumCosto;

    if(vec != NULL && tipos != NULL && empresas != NULL && destinos != NULL && viajes != NULL && tam > 0 && tamT > 0 && tamE > 0 && tamD > 0 && tamV > 0)

    {


        listarMicros(vec, tam, empresas, tamE, tipos, tamT);
        printf("Ingrese Id de Micro: ");
        scanf("%d",&bufferMicro);
        while(validarMicro(vec, tam, bufferMicro)==0)
        {
            listarMicros(vec, tam,empresas, tamE, tipos, tamT);
            printf("Ingrese Id de Micro ");
            scanf("%d",&bufferMicro);
            validarMicro(vec, tam, bufferMicro);
        }


        printf("************  COSTOS PARA ID MICRO %d *************\n\n", bufferMicro);

        for(int i=0; i < tamV; i++) //recorro el array de viajes
        {
            if(!viajes[i].isEmpty && viajes[i].idMicro == bufferMicro)
            {
                for(int j = 0; j < tamD; j++) //recorro el array de destinos
                {
                    if(viajes[i].idDestino == destinos[j].id) //pregunto si el id destino que esta en viajes es == a id destinos.
                    {
                        acumCosto += destinos[j].precio;

                    }


                }
            }

        }


        printf("El total del costo id nro: %d es: $%.2f\n", bufferMicro, acumCosto);

    }
    return todoOk;


}

/*
------------------------------------------------------------------------------------------------------------
punto 9)                Pedir un destino y mostrar los micros que viajaron a ese destino y en qué fecha.
------------------------------------------------------------------------------------------------------------
*/

int destinoMicros(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV  )
{

    int todoOk = 0;
    int bufferDestino;
    int flag = 1;



    if(vec != NULL && tipos != NULL && empresas != NULL && destinos != NULL && viajes != NULL && tam > 0 && tamT > 0 && tamE > 0 && tamD > 0 && tamV > 0)

    {
        listarDestinos(destinos,tamD);
        printf("Ingrese Id de Destino: ");
        scanf("%d",&bufferDestino);
        while(validarDestinos(destinos, tamD, bufferDestino)==0)
        {
            listarDestinos(destinos, tamD);
            printf("Ingrese Id de Destino ");
            scanf("%d",&bufferDestino);
            validarDestinos(destinos, tamD, bufferDestino);
        }


        printf("************ VIAJES con Id %d: ************\n\n", bufferDestino);
        printf(" ID Viaje        ID MICRO       VIAJE              FECHA \n");
        printf("---------------------------------------------------\n\n");

        for(int i=0; i < tamV; i++) //recorro el array de viajes
        {
            if(!viajes[i].isEmpty && viajes[i].idDestino == bufferDestino)
            {
                for(int j = 0; j < tamD; j++) //recorro el array de destinos
                {
                    if(!viajes[i].isEmpty && viajes[i].idDestino == destinos[j].id) //pregunto si el id destino que esta en viajes es == a id destinos.
                    {
                        mostrarViajeFila(viajes[i], destinos, tamD);
                        flag= 0;

                    }


                }
            }

        }


         if(flag)
        {
            printf("No se realizaron viajes a ese destino\n");
        }
        todoOk = 1;
    }

    return todoOk;

}



/*
------------------------------------------------------------------------------------------------------------
punto 10)                Pedir un destino y mostrar los micros que viajaron a ese destino y en qué fecha.
------------------------------------------------------------------------------------------------------------
*/


int viajesXFecha(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV  )
{

    int todoOk = 0;
    eFecha bufferFecha;
    char descDestino[20];
    int flag = 1;

   if(vec != NULL && tipos != NULL && empresas != NULL && destinos != NULL && viajes != NULL && tam > 0 && tamT > 0 && tamE > 0 && tamD > 0 && tamV > 0)

    {
        listarViajes(viajes, tamV, destinos, tamD);
        printf("Ingrese fecha: \n");
        while(pidoValidoFecha(&bufferFecha)== 0)
        {
            if(pidoValidoFecha(&bufferFecha))
            {
                break;
            }
        }
        printf("Viajes realizados en la fecha: %2d/%2d/%d\n\n", bufferFecha.dia, bufferFecha.mes, bufferFecha.anio);
        for(int i=0; i < tamV; i++)
        {
            if(viajes[i].fecha.dia == bufferFecha.dia
                && viajes[i].fecha.mes == bufferFecha.mes
                && viajes[i].fecha.anio == bufferFecha.anio)
            {
                cargarDescripcionDestino(destinos, tamD,viajes[i].idDestino, descDestino);
                printf("** %10s\n", descDestino);
                flag = 0;
            }
        }
        if(flag)
        {
            printf("No se realizaron viajes en esa fecha\n");
        }
        todoOk = 1;
    }
    return todoOk;

}
