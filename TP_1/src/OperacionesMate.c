/*
 * OperacionesMate.h
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "OperacionesMate.h"

int FSuma(int x,int y){
	int resultado;

	resultado = x + y;

	return resultado;
}

int FResta(int x,int y){
	int resultado;

	resultado = x - y;

	return resultado;
}

float FDivision(int x,int y){
	float resultado;

	resultado = (float)x / y;

	return resultado;
}

int FMultiplicacion(int x,int y){
	int resultado;

	resultado = x * y;

	return resultado;
}

int FFactorial(int numeroFactorear){
	int resultado = 0;
	int F;

	if(numeroFactorear != 0){
	F = numeroFactorear;

	for(int n = 1;n < F;n++){
	numeroFactorear = numeroFactorear*n;
	}

	resultado = numeroFactorear;
	}

	return resultado;

}
