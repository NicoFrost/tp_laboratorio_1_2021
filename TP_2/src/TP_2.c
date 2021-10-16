/*
 ============================================================================
 Name        : TP_2.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style



 Terminar ordenamiento 4 y empezar punto 4.2

 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "libreria.h"
#include "Funciones adicionales.h"

#define TAM 1000
#define LIBRE 0
#define OCUPADO 1
#define SUBMENU 1
#define MENU 0

int main(void){
	setbuf(stdout, NULL);
	int respuesta;
	int subRespuesta;
	Employee Empleado[TAM];
	Employee* PuntAux;
	int ubicacion;
	int id = 1;
	int buscID;
	int flag = 0;
	int contador = 0;
	int acumulador = 0;
	int Iaux,i,j;
	float fAux;
	char cadenaAux[51];
	int sumaSalario = 0;
	float promedio;


	for(int i = 0;i < TAM;i++){
		PuntAux = &Empleado[i];
		initEmployees(PuntAux, TAM);
		Empleado[i] = *PuntAux;
	}
	do{
		respuesta = MenuGeneral("1.Alta\n", "2.Modificar\n", "3.Baja\n", "4.Informar\n", "", "","","", MENU);

		switch (respuesta){
		case 1:
			//1 INICIO
			acumulador++;
			if(acumulador != TAM){
				ubicacion = buscarEspacioLibre(Empleado, TAM);
				addEmployee(&Empleado[ubicacion], TAM, id, Empleado[ubicacion].name, Empleado[ubicacion].lastName, Empleado[ubicacion].salary, Empleado[ubicacion].sector);
				Empleado[ubicacion].id = id;
				id++;
				flag = 1;
			}
			//1 FIN
			break;
		case 2:
			//2 INICIO
			if(flag == 1){
				printEmployees(Empleado, TAM);
				buscID = BusquedaID(Empleado, TAM);
				addEmployee(&Empleado[buscID], TAM, buscID, Empleado[buscID].name, Empleado[buscID].lastName , Empleado[buscID].salary, Empleado[buscID].sector);
			} else {
				printf("No hay Empleados dados de alta, ingrese por lo menos 1 para empezar");
			}
			//2 FIN
			break;
		case 3:
			//3 INICIO
			if(flag == 1){
				printEmployees(Empleado, TAM);
				buscID = BusquedaID(Empleado, TAM);
				removeEmployee(Empleado, TAM, buscID);
				contador = 0;
				for(int x = 0;x < TAM;x++){
					if(Empleado[x].isEmpty == 1){
						contador++;
					}
				}
				if(contador == 0){
					flag = 0;
				}
			} else {
				printf("No hay Empleados dados de alta, ingrese por lo menos 1 para empezar");
			}
			//3 INICIO
			break;
		case 4:
			//4.1 INICIO

			if(flag == 1){
				do{
					subRespuesta = MenuGeneral("1.Listado Empleados ordenados\n", "2.Total y promedio de salarios\n", "", "", "", "", "","", SUBMENU);
					switch (subRespuesta){
						case 1:

							for(i = 0; i < TAM-1;i++){
								for(j = i+1; j < TAM;j++){
									if(Empleado[i].isEmpty == 1 || Empleado[j].isEmpty == 1){
										if(strcmp(Empleado[i].lastName,Empleado[j].lastName) > 0){

											Iaux = Empleado[j].id;
											Empleado[j].id = Empleado[i].id;
											Empleado[i].id = Iaux;

											strcpy(cadenaAux,Empleado[j].name);
											strcpy(Empleado[j].name,Empleado[i].name);
											strcpy(Empleado[i].name,cadenaAux);

											strcpy(cadenaAux,Empleado[j].lastName);
											strcpy(Empleado[j].lastName,Empleado[i].lastName);
											strcpy(Empleado[i].lastName,cadenaAux);

											fAux = Empleado[j].salary;
											Empleado[j].salary = Empleado[i].salary;
											Empleado[i].salary = fAux;

											Iaux = Empleado[j].sector;
											Empleado[j].sector = Empleado[i].sector;
											Empleado[i].sector = Iaux;

											Iaux = Empleado[j].isEmpty;
											Empleado[j].isEmpty = Empleado[i].isEmpty;
											Empleado[i].isEmpty = Iaux;
										} else {
											if(strcmp(Empleado[i].lastName,Empleado[j].lastName) == 0){
												sortEmployees(Empleado, j, i);
											}
										}
									}
								}
							}
							printEmployees(Empleado, TAM);
						//4.1 FIN
							break;
						case 2:
							//4.2 INICIO
							contador = 0;
							//inicializacion hecha porque aun no es funcion
							sumaSalario = 0;
							promedio = 0;

							for(int x = 0;x < TAM;x++){
								if(Empleado[x].isEmpty == 1){
									sumaSalario += Empleado[x].salary;
									contador++;
								}
							}
							promedio = sumaSalario / contador;
									contador = 0;
							for(int x = 0;x < TAM;x++){
								if(Empleado[x].isEmpty == 1 && Empleado[x].salary > promedio){
									contador++;
								}
							}
							printf("-----SALARIO-----\n");
							printf("|TOTAL:    $%04d  \n", sumaSalario);
							printf("|PROMEDIO: $%04.2f  \n", promedio);
							printf("|empleados superando promedio: %d\n",contador);
							printf("-----------------");
							//4.2 FIN
							break;
					}
				}while(subRespuesta != 0);
			} else {
				printf("No hay Empleados dados de alta, ingrese por lo menos 1 para empezar");
			}
			break;
		}
	}while(respuesta != 0);
	return 0;
}
