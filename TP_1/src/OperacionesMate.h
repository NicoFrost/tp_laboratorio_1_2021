/*
 * OperacionesMate.h
 *
 *  Created on: 12 set. 2021
 *      Author: Javier
 */

#ifndef OPERACIONESMATE_H_
#define OPERACIONESMATE_H_

int FSuma(int x,int y);
int FResta(int x,int y);
float FDivision(int x,int y);
int FMultiplicacion(int x,int y);
int FFactorial(int numeroFactorear);

/// \fn int FSuma(int x,int y);
/// \brief la funcion suma dos numeros "X" y "Y"
/// \param operador X y operador Y.
/// \return devuelve el resultado de la suma entre los paramentros ingresados

/// \fn int FResta(int x,int y);
/// \brief la funcion restara los numeros "X" y "Y"
/// \param operador X y operador Y.
/// \return devuelve el resultado de la resta entre los paramentros ingresados

/// \fn int FDivision(int x,int y);
/// \brief la funcion dividira los dos numeros "X" y "Y"
/// \param operador X y operador Y.
/// \return devuelve el resultado de la division entre los paramentros ingresados

/// \fn int FMultiplicacion(int x,int y);
/// \brief la funcion multiplicara los dos numeros "X" y "Y"
/// \param operador X y operador Y
/// \return devuelve el resultado de la multiplicacion de los parametros ingresados


///\fn int FFactorial(int numeroFactorear)
/// \brief la funcion realiza Factoriales(n!) del parametro ingresado
/// \param operador a Factorizar(n!)
/// \return devuelve el resultado de Factorizar el numero ingresado
#endif /* OPERACIONESMATE_H_ */
