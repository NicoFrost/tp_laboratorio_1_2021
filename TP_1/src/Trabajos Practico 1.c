/*
 ============================================================================
 Name        : Trabajos.c
 Author      : Nicolas Gorza
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "libreria.h"
#include "OperacionesMate.h"

int main(void) {
	setbuf(stdout, NULL);
	int respuesta;

	int x = 0;
	int y = 0;
	int resultS;
	int resultR;
	float resultD;
	int resultM;
	int resultFA;
	int resultFB;
	int flag = 0;

	do{
		printf("X = %d\n", x);
		printf("Y = %d\n", y);
		respuesta = MenuGeneral("1. ingresar 1er operando","2. ingresar 2do operando","3. Calcular todas las operacion", "4. Informar resultados","","");

		switch (respuesta) {
		case 1:
			printf("ingrese operador A: ");
			scanf("%d", &x);
			break;
		case 2:
			printf("ingrese operador B: ");
			scanf("%d", &y);
			break;
		case 3:
			if(x == 0){
				printf("no se ingreso Operador A, se recomienda ingresar uno:");
				scanf("%d", &x);
			}
			if (y == 0){
				printf("no se ingreso Operador B, se recomienda ingresar uno:");
				scanf("%d", &y);
			}
			resultS = FSuma(x, y);
			resultR = FResta(x,y);
			if(y != 0){
			resultD = FDivision(x, y);
			}
			resultM = FMultiplicacion(x, y);
			resultFA = FFactorial(x);
			resultFB = FFactorial(y);
			flag = 1;
			break;
		case 4:
			if (flag == 0){
				printf("no se calculo ninguna operacion, intente nuevamente \no en el menu ingrese 3 para iniciar a calcular\n");
			} else {
				printf("la suma de los operadores A y B es: %d\n", resultS);
				printf("la resta entre los operadores A y B es: %d\n", resultR);
				if(y != 0){
				printf("la division de esta es: %.2f\n", resultD);
				} else {
					printf("la division no es posible ya que Y es igual a 0\n");
				}
				printf("la multiplicacion de estos numeros es: %d\n", resultM);
				if(x != 0){
					if(x > 17){
						printf("Factorial limite pasado(16)\n");
					} else {
						printf("Factorial A es: %d\n",resultFA);
					}

				} else {
					printf("Factorial A es: 0\n");
				}
				if(y != 0){
					if(y > 17){
						printf("Factorial limite pasado(16)\n");
					} else {
						printf("Factorial B es: %d\n", resultFB);
					}
				} else {
					printf("Factorial B es: 0\n");
				}
			}
			flag = 0;
			break;
		default :
			printf("ha ingresado una opcion que no existe intente nuevamente\n");
		}
	} while(respuesta != 0);
	printf("apagando");
	return 0;
}

