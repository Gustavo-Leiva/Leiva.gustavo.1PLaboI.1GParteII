#ifndef EMPRESA_H_INCLUDED
#define EMPRESA_H_INCLUDED

typedef struct
{
    int id;
    char descripcion[20];


} eEmpresa;

#endif // EMPRESA_H_INCLUDED

/** \brief recibe un id y carga la descripcion de ese id en una cadena de caracteres.
 *
 * \param empresas [] eEmpresa array de estructura empresas.
 * \param tamE int tamaño del array empresas.
 * \param id int id que recibe y lo busca en el array de empresas.
 * \param desc[] char array donde se carga la descripcion que recibe del id a buscar.
 * \return devuelve 1 si pudo encontrar el id y lo copiar su indice.
 *
 */
int cargarDescripcionEmpresa (eEmpresa empresas[], int tamE, int id, char desc[]);





/** \brief imprime en pantalla en forma de tabla la estructura de empresa.
 *
 * \param empresas[] eEmpresa array de estructuras de empresas
 * \param tamE int tamaño del array empresas.
 * \return int devuelve 1 si pudo listar las empresas.
 *
 */
int listarEmpresas(eEmpresa empresas[], int tamE);



/** \brief recibe un id (de la empresas) y busca el indice en donde esta esta guardado esa empresa en el array empresas.
 *
 * \param empresas[] eEmpresa array de estructuras de empresas
 * \param tamE int tamaño del array empresas.
 * \param id int tamanio del array empresas.
 * \param pIndex int* direccion donde se copia el id ingresado.
 * \return int devuelve 1 si pudo encontrar el indice y copiarlo.
 *
 */
int buscarEmpresas(eEmpresa empresas[], int tamE, int id, int* pIndex);


/** \brief valida si el id ingresado corresponde a una estructura válida.
 *
 * \param empresas[] eEmpresa array de estructuras de empresas
 * \param tamE int tamaño del array empresas.
*  \param id int id que es ingresado para su validacion.
 * \return int devuelve 1 si el id es valido o -1 si el id no existe.
 *
 */
int validarEmpresas(eEmpresa empresas[], int tamE, int id);


