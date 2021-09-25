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
	printf("%s\n", mensaje1);
	printf("%s\n", mensaje2);
	printf("%s\n", mensaje3);
	printf("%s\n", mensaje4);
	printf("%s\n", mensaje5);
	printf("%s\n", mensaje6);
	printf("ingrese una opcion (en numeros)...\n");
	printf("o ingrese 0 para salir\n");
	setbuf(stdin, NULL);
	scanf("%d", &respuesta);
//	respuesta = toUpper(respuesta);
	return respuesta;
}


