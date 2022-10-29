#ifndef TIPOS_H_INCLUDED
#define TIPOS_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eTipo;


#endif // TIPOS_H_INCLUDED


/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres.
 *
 * \param tipos [] eDestino array de estructura tipos.
 * \param tamT int tamanio del array destino.
 * \param id int id que recibe y lo busca en el array de tipos.
 * \param desc[] char array donde se carga la descripcion que recibe del id a buscar.
 * \return devuelve 1 si pudo encontrar el id y lo pudo copiar su indice.
 *
 */
int cargarDescripcionTipos (eTipo tipos[], int tamT, int id, char desc[]);


/** \brief imprime en pantalla en forma de tabla la estructura de tipos
 *
 * \param tipos[] eTipo array de estructuras de tipos.
 * \param tamT int tamaño de la estructura tipos.
 * \return int devuelve 1 si pudo listar los destinos.
 *
 */
int listarTipos(eTipo tipos[], int tamT);


/** \brief recibe un id (del tipo) y busca el indice en donde esta esta guardado ese tipo en el array tipos.
 *
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamaño del array tipos
 * \param id int que es ingresado para su validacion.
 * \param pIndex int* direccion donde se copia el id ingresado.
 * \return int devuelve 1 si pudo encontrar el indice y copiarlo.
 *
 */
int buscarTipos(eTipo tipos[], int tamT, int id, int* pIndex);


/** \brief valida si el id ingresado corresponde a una estructura valida
 *
 * \param tipos[] eTipo array de la estructura tipos.
 * \param tamT int tamaño del array destinos.
 * \param id int id que es ingresado para su validacion.
 * \return int devuelve 1 si el id es valido o -1 si el id no existe.
 *
 */
int validarTipos(eTipo tipos[], int tamT, int id);
