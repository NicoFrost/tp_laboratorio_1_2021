/*
 * libreria.c
 *
 *  Created on: 9 set. 2021
 *      Author: Javier
 */
#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include <ctype.h>

int MenuGeneral(char mensaje1[], char mensaje2[], char mensaje3[], char mensaje4[], char mensaje5[], char mensaje6[]){

	int respuesta;

	printf("\ningrese una opcion (en numeros)...\n");
	printf("%s", mensaje1);
	printf("%s", mensaje2);
	printf("%s", mensaje3);
	printf("%s", mensaje4);
	printf("%s", mensaje5);
	printf("%s", mensaje6);
	printf("o ingrese 0 para salir\n");
	setbuf(stdin, NULL);
	scanf("%d", &respuesta);
//	respuesta = toUpper(respuesta);
	return respuesta;
}


