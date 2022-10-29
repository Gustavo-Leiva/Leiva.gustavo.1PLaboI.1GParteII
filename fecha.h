#ifndef FECHA_H_INCLUDED
#define FECHA_H_INCLUDED

typedef struct
{
    int dia;
    int mes;
    int anio;


} eFecha;

#endif // FECHA_H_INCLUDED


/** \brief  valida si el dato ingresado es un valor de acuerdo a la cantidad de dias que tenga cada mes.
 *
 * \param dia int parametro a validar
 * \return int devuelve 1 si es valido.
 *
 */
int validoDia(int dia);




/** \brief valida si el dato ingresado es un mes valido dentro de un rango.
 *
 * \param mes int parametro a validar.
 * \return int devuelve 1 si valido.
 *
 */
int validoMes(int mes);



/** \brief  valida si el dato ingresado es un anio correcto dentro un rango establecido.
 *
 * \param anio int parametro a validar.
 * \return int devuelve 1 si es correcto.
 *
 */
int validoAnio(int anio);



/** \brief valida si el anio ingresado corresponde a un anio bisiesto
 *
 * \param anio int parametro a validar.
 * \return int devuelve 1 si es valido.
 *
 */
int validoAnioBisiesto(int anio);



/** \brief valida si el numero que se ingresa en el campo dia y mes condicen segun la cantidad de dias que tiene cada mes
 *
 * \param mes int parametro mes a validar.
 * \param dia int parametro dia a validar.
 * \param anio int parametro anio a validar.
 * \return int devuevle 1 si es valido.
 *
 */
int validoDiaMes(int mes, int dia, int anio);






/** \brief pide el ingreso de una fecha al usuario y valida si sus campos; dia, mes, anio es valido.
 *
 * \param fecha eFecha* direccion donde se guarda los datos ingresados por el usuario.
 * \return int devuelve 1 si la fecha es valida y se puede cargar en la esctructura fecha.
 *
 */
int pidoValidoFecha(eFecha* fecha);
