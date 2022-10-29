
#include "fecha.h"
#include "micro.h"
#include "tipo.h"
#include "destino.h"


#ifndef VIAJE_H_INCLUDED
#define VIAJE_H_INCLUDED

typedef struct
{
    int id;
    int idMicro;
    int idDestino;
    eFecha fecha;
    int isEmpty;

} eViaje;



#endif // VIAJE_H_INCLUDED


/** \brief coloca el campo isEmpty de la estructura en 1
 *
 * \param vec[] eViaje array de estructura viajes.
 * \param tamV int tamaño de la estructura.
 * \return int devuelve 1 si se pudo inicializar la estructura en 1 en el campo isEmpty.
 *
 */
int inicializarViaje(eViaje vec[], int tamV);







/** \brief busca la primera estructura libre en el arrays antes de dar de alta el ingreso de datos al sistema.
 *
 * \param vec[] eViaje  array de estructura micros.
 * \param tamV int tamaño de la estructura.
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int devuelve 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sistema,
 *
 */
int buscarLibreViaje (eViaje vec[], int tamV, int* pIndex);




/** \brief realiza el alta de los datos solicitados por el sistema.
 *
 *
 * \param vec[] eViaje array de la estructura viajes.
 * \param tamV int tamaño de viajes
 * \param micros[] eMicro array de la estructura micros.
 * \param tamM int tamaño de micros
 * \param empresas[] eEmpresa array de la estructura empresas.
 * \param tamE int tamaño de empresas
 * \param tipos[] eTipo array de la estructura tipos
 * \param tamT int tamaño de tipos
 * \param destinos[] eDestino array de la estructura destinos.
 * \param tamD int tamaño de destinos
 * \param pNextId int* direccion de memoria donde guarda el proximo id a dar de alta
 * \return int devuelve 1 si el alta fue exitosa.
 *
 */
int altaViaje(eViaje vec[], int tamV, eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, eDestino destinos[], int tamD,  int* pNextId);

/** \brief muestra por pantalla en forma de una tabla las estructura que no estan vacias de micros en el sistema.
 *
 * \param viajes[]  array de la estructura viajes.
 * \param tamV int tamaño de la estructura viajes.
 * \param destinos[] eDestino array de la estructura destinos.
 * \param tamD int tamaño de la estructura destinos.
 * \return int eViaje devuelve 1 si se listo exitosamente.
 *
 */
int listarViajes(eViaje viajes[],  int tamV, eDestino destinos[], int tamD);


/** \brief muestra por pantalla en filas las estructuras de micros que no estan vacias en el sistema.
 *
 * \param micros eMicro array de la estructura micros.
 * \param tamM int tamanio del array micros.
 * \param empresas[] eEmpresa array de la estrucutra empresas.
 * \param tamE int tamanio del array empresas.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamanio de la estructura tipos.
 * \return void
 *
 */
void mostrarViajeFila (eViaje viajes, eDestino destinos[], int tamD);













/** \brief realiza el alta forzada de la estructura viajes.
 *
 * \param vec[] eViaje array de estructura viajes.
 * \param tam int tamaño de la estructura.
 * \param cantV int cantidad de viajes que desea dar de alta.
 * \param pNextId int* direccion de memoria del proximo id que se dara de alta.
 * \return int devuelve 1 si el alta forzada fue exitosa.
 *
 */
int harcodearViajes(eViaje vec[], int tamV, int cantV, int* pNextId);



/** \brief imprime en pantalla las opciones de informes de viajes y permite al usuario ingresar una opcion
 *
 * \return int retorna la opcion ingresada.
 *
 */
int menuInformesViajes();

/** \brief realiza los llamados a las funciones segun la opcion ingresada por el usuario
 *
 * \param vec[] eMicro array  de micros
 * \param tam int tamaño del array micros
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño de tipos
 * \param empresas[] eEmpresa array de empresas
 * \param tamE int tamaño array de empresas
 * \param destinos[] eDestino array de destino.
 * \param tamD int tamaño de array destino
 * \param viajes[] eViaje array viaje
 * \param tamV int tamaño de array viaje
 * \return int devuelve 1 si pudo realizar el llamado a la funcion.
 *
 */
int InformesViajes(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV);



/** \brief realiza los llamados a las funciones segun la opcion ingresada por el usuario
 *
 * \param vec[] eMicro array  de micros
 * \param tam int tamaño del array micros
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño de tipos
 * \param empresas[] eEmpresa array de empresas
 * \param tamE int tamaño array de empresas
 * \param destinos[] eDestino array de destino.
 * \param tamD int tamaño de array destino
 * \param viajes[] eViaje array viaje
 * \param tamV int tamaño de array viaje
 * \return int devuelve 1 si pudo mostrar los viajes x id consultado.
 *
 */
int viajesXIdMicro(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV);







/** \brief  realiza el calculto total de los viajes realizados por el id seleccionado por el usuario.
 *
 * \param vec[] eMicro array  de micros
 * \param tam int tamaño del array micros
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño de tipos
 * \param empresas[] eEmpresa array de empresas
 * \param tamE int tamaño array de empresas
 * \param destinos[] eDestino array de destino.
 * \param tamD int tamaño de array destino
 * \param viajes[] eViaje array viaje
 * \param tamV int tamaño de array viaje
 * \return int devuelve 1 si pudo realizar el calculo del costo total.
 *
 */
int costosXIdMicro(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV);





/** \brief pide un destino por id y retorna la opcion seleccionada.
 *
 * \param vec[] eMicro array  de micros
 * \param tam int tamaño del array micros
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño de tipos
 * \param empresas[] eEmpresa array de empresas
 * \param tamE int tamaño array de empresas
 * \param destinos[] eDestino array de destino.
 * \param tamD int tamaño de array destino
 * \param viajes[] eViaje array viaje
 * \param tamV int tamaño de array viaje
 * \return int devuelve 1 si existe el destino a mostrar.
 *
 */
int destinoMicros(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV);



/** \brief permite al usuario ingresar una fecha y muestra todos los viajes que se hicieron en esa fecha
 *
 * \param vec[] eMicro array  de micros
 * \param tam int tamaño del array micros
 * \param tipos[] eTipo array de tipos
 * \param tamT int tamaño de tipos
 * \param empresas[] eEmpresa array de empresas
 * \param tamE int tamaño array de empresas
 * \param destinos[] eDestino array de destino.
 * \param tamD int tamaño de array destino
 * \param viajes[] eViaje array viaje
 * \param tamV int tamaño de array viaje
 * \return int  retorna 1 si pudo mostrar los viajes por fecha
 *
 */
int viajesXFecha(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, eDestino destinos[], int tamD, eViaje viajes[], int tamV);


