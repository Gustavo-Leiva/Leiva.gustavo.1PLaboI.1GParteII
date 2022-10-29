#include <stdio.h>
#include <stdlib.h>

#include "empresa.h"

#include "string.h"

int cargarDescripcionEmpresa (eEmpresa empresas[], int tamE, int id, char desc[])
{
    int todoOk = 0;

    if(empresas != NULL && tamE > 0 && desc != NULL)
    {

        for(int i = 0; i < tamE ; i++)
        {

            if(empresas[i].id == id)
            {
                strcpy(desc, empresas[i].descripcion);
                todoOk = 1;
                break;

            }
        }



    }


    return todoOk;
}




int listarEmpresas(eEmpresa empresas[], int tamE)
{
    int todoOk = 0;

    if(empresas != NULL && tamE > 0)
    {
        printf("--------------------------------------------\n");
        printf("|        ***LISTADO DE EMPRESAS***         |\n");
        printf("--------------------------------------------\n");
        printf("|         ID           |     DESCRIPCION   |\n");
        printf("--------------------------------------------\n");


        for(int i = 0 ; i < tamE; i++)
        {

            printf("|        %4d          |%15s    |\n", empresas[i].id, empresas[i].descripcion);

        }

        printf("-------------------------------------------\n\n");
        todoOk = 1;

    }


    return todoOk;
}



int buscarEmpresas(eEmpresa empresas[], int tamE, int id, int* pIndex)
{
    int todoOk = 0;

    if(empresas != NULL && tamE > 0 && pIndex != NULL)
    {
        *pIndex = -1;

        for(int i = 0;  i < tamE; i++)
        {

            if(empresas[i].id == id)
            {
                *pIndex = i;
                break;
            }
        }
        todoOk = 1;
    }
    return todoOk;
}

int validarEmpresas(eEmpresa empresas[], int tamE, int id)
{
    int esValido = 0;
    int indice;

    if(buscarEmpresas(empresas, tamE, id, &indice))
    {
        if(indice != -1)
        {
            esValido = 1;
        }
    }

    return esValido;
}
