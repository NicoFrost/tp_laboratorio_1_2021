/*
 * Funciones adicionales.h
 *
 *  Created on: 15 oct. 2021
 *      Author: Javier
 */

#ifndef FUNCIONES_ADICIONALES_H_
#define FUNCIONES_ADICIONALES_H_
#include "ArrayEmployees.h"
#include "libreria.h"

int buscarEspacioLibre(Employee* list,int len);
int BusquedaID(Employee* Empleado,int len);

void VerifFlotante(float* retorno, char mensaje[], char errorMensaje[]);
void VerifEntero(int* retorno,char mensaje[],char errormensaje[]);

void MostrarSalarios(Employee* Empleado, int len);

#endif /* FUNCIONES_ADICIONALES_H_ */
