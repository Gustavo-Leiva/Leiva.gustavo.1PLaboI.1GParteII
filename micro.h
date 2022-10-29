
#include "empresa.h"
#include "tipo.h"


#ifndef MICRO_H_INCLUDED
#define MICRO_H_INCLUDED

typedef struct
{

    int id;
    int idEmpresa;
    int idTipo;
    int capacidad;
    int isEmpty;



} eMicro;

#endif // MICRO_H_INCLUDED

/** \brief coloca el campo isEmpty de la estructura en 1
 *
 * \param vec[] eMicro array de estructura micros.
 * \param tam int tamanio de la estructura.
 * \return int devuelve 1 si se pudo inicilizar la estructura en 1 en el campo isEmpty.
 *
 */
int inicializarMicros(eMicro vec[], int tam);




/** \brief realiza el alta forzada de la estructura micros.
 *
 * \param vec[] eMicro array de estructura micros.
 * \param tam int tamaño de la estructura.
 * \param cantM int cantidad de micros que desea dar de alta.
 * \param pNextId int* direccion de memoria del proximo id que se dara de alta.
 * \return int devuelve 1 si el alta forzada fue exitosa.
 *
 */
int harcodearMicros(eMicro vec[], int tam, int cantM, int* pNextId);






/** \brief busca la primera estructuta libre en el arrays antes de dar de alta el ingreso de datos al sistema.
 *
 * \param vec[] eMicro  array de estructura micros.
 * \param tam int tamanio de la estructura.
 * \param pIndex int* direccion de memoria donde guardar el indice de la estructura vacia
 * \return int devuelve 1 si pudo encontrar una estructura vacia, -1 si no hay espacio vacia en el sistema,
 *
 */
int buscarLibreMicros(eMicro vec[], int tam, int* pIndex);




/** \brief imprime por pantalla las opciones del menu de micros.
 *
 * \return int retorna la opcion ingresada.
 *
 */
int menuMicro();




/** \brief realiza el alta de los datos solicitados por el sistema.
 *
 * \param vec[] eMicro array de la estructura micros.
 * \param tam int tamaño del array micros.
 * \param empresas[] eEmpresa array de la estructura empresas.
 * \param tamE int tamanio del array empresas.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamanio del array tipos.
 * \param pNextId int* direccion de memoria donde guarda el proximo id a dar de alta.
 * \return int devuelve 1 si el alta fue exitosa.
 *
 */
int altaMicro(eMicro vec[], int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT, int* pNextId);


/** \brief realiza la modificacion de los datos solicitados por el sistema.
 *
 * \param vec[] eMicro array de la estructura micros.
 * \param tam int tamanio del array micros.
 * \param empresas[] eEmpresa array de la estructura empresas.
 * \param tamE int tamanio del array empresas.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamanio del array tipos.
 * \return int devuelve 1 si la modificacion fue exitosa.
 *
 */
int modificarMicro(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);







/** \brief muestra por pantalla en forma de una tabla las estructura que no estan vacias de micros en el sistema.
 *
 * \param micros[] eMicro array de la estructura micros.
 * \param tamM int tamaño del array micros.
 * \param empresas[] eEmpresa array de la estructura micros.
 * \param tamE int tamanio del array micros.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamaño de la estructura tipos.
 * \return int devuelve 1 si se pudo mostrar las listas exitosamente.
 *
 */
int listarMicros(eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);







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
void mostrarMicroFila(eMicro micros, int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);





/** \brief recibe un id y busca en que posicion del array esta guardado el dato.
 *
 * \param micros[] eMicro  array de la estructura micros.
 * \param tamM int tamanio del array micros.
 * \param id int id que recibimos para que realice la busqueda del dato en el sistema.
 * \param pIndex int* direccion de memoria donde se guardara el valor del indicce en donde se encuentra.
 * \return int devuelve 1 si encontro el dato.
 *
 */
int buscarMicro(eMicro micros[], int tamM, int id, int* pIndex);









/** \brief recibe un id y valida si el id recibido se encuentra guardado en la estructura.
 *
 * \param micros[] eMicro  array de la estructura micros.
 * \param tamM int tamanio del array micros.
 * \param id int id que recibimos del usuario para que realice la validacion.
 * \return devuelve 1 si id se encuentra en el sistema.
 *
 */
int validarMicro (eMicro micros[], int tamM, int id);







/** \brief lista en el sistema los micros en forma de tabla.
 *
 * \param micros eMicro array de la estructura micros.
 * \param tam int tamanio del array micros.
 * \param empresas[] eEmpresa  array de la estructura empresas.
 * \param tamE int tamanio del array empresas.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamanio del array tipos
 * \return void
 *
 */
void mostrarMicro(eMicro micros, int tam, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);





/** \brief muestra por pantalla las opciones que existen para modificar.
 *
 * \return int devuelve la opcion ingresada.
 *
 */
int menuModificarMicro();






/** \brief realiza la baja de los datos solicitados por el sistema.
 *
 * \param vec[] eMicro array de la estructura micros.
 * \param tam int tamanio del array micros.
 * \param empresas[] eEmpresa array de la estructura empresas.
 * \param tamE int tamanio del array empresas.
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamanio del array tipos.
 * \return int devuelve 1 si la baja fue exitosa.
 *
 */
int bajaMicro (eMicro micros[], int tamM, eEmpresa empresas[], int tamE, eTipo tipos[], int tamT);






/** \brief ordena el array de manera ascendente por empresa y capacidad de pasajero
 *
 * \param vec[] eMicro array de la estructura micros.
 * \param tam int tamanio del array micros.
 * \return int devuelve 1 si pudo ordenar el array.
 *
 */
int ordenarMicroXEmpresaCapacidad(eMicro vec[], int tam);




//////////////////////////////////////////////////////////////////////////////////////////
//                                  DOCUMENTAR





int menuInformes();
int informes (eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);


int mostrarMicroXIdEmpresa(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);
int microsXIdEmpresa(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, int idEmpresa);


int microsXIdTipo(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE, int idTipo);
int mostrarMicroXIdTipo(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);


int mostrarMicroXEmpresas(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);
int porcentajeMicroVip (eMicro vec[], int tam, eEmpresa empresas[], int tamE);
int informeMicrosMayor(eMicro vec[], int tam, eTipo tipos[], int tamT, eEmpresa empresas[], int tamE);
int empresasMenosMicros(eMicro vec[], int tam, eEmpresa empresas[], int tamE);

