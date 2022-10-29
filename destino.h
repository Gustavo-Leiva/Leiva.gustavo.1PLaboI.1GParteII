#ifndef DESTINO_H_INCLUDED
#define DESTINO_H_INCLUDED

typedef struct
{

    int id;
    char descripcion [25];
    float precio;

} eDestino;

#endif // DESTINO_H_INCLUDED




/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres.
 *
 * \param destino [] eDestino array de estructura destinos.
 * \param tamD int tamaño del array destino.
 * \param id int id que recibe y lo busca en el array de destino.
 * \param desc[] char array donde se carga la descripcion que recibe del id a buscar.
 * \return devuelve 1 si pudo encontrar el id y lo copiar su indice.
 *
 */
int cargarDescripcionDestino (eDestino destinos[], int tamD, int id, char desc[]);





/** \brief imprime en pantalla en forma de tabla la estructura de destinos
 *
 * \param destinos[] eDestino array de estructuras de destinos
 * \param tamD int tamaño del array destinos
 * \return int devuelve 1 si pudo listar los destinos.
 *
 */
int listarDestinos(eDestino destinos[], int tamD);







/** \brief recibe un id (del destino) y busca el indice en donde esta esta guardado ese destino en el array destinos.
 *
 * \param destinos[] eDestino array de la estructura destinos.
 * \param tamD int tamaño del array destinos
 * \param id int id que es ingresado
 * \param pIndex int* direccion donde se copia el id ingresado.
 * \return int devuelve 1 si pudo encontrar el indice y copiarlo.
 *
 */
int buscarDestinos(eDestino destinos[], int tamD, int id, int* pIndex);







/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param destinos[] eDestino array de la estructura destinos.
 * \param tamD int tamaño del array destinos.
 * \param id int id que es ingresado para su validacion.
 * \return int devuelve 1 si el id es valido o -1 si el id no existe.
 *
 */
int validarDestinos(eDestino destinos[], int tamD, int id);
