#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Employee.h"
#include "LinkedList.h"
#include "parser.h"

int employee_setId(Employee* this,int id){
	int retorno = 1;
	this->id = id;
	return retorno;
}

int employee_getId(Employee* this,int* id){
	int retorno = 1;
	*id = this->id;
	return retorno;
}

int employee_setNombre(Employee* this,char* nombre){
	int retorno = 1;
	strcpy(this->nombre,nombre);
	return retorno;
}

int employee_getNombre(Employee* this,char* nombre){
	int retorno = 1;
	strcpy(nombre,this->nombre);
	return retorno;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas){
	int retorno = 1;
	this->horasTrabajadas = horasTrabajadas;
	return retorno;
}

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas){
	int retorno = 1;
	*horasTrabajadas = this->horasTrabajadas;
	return retorno;
}

int employee_setSueldo(Employee* this,int sueldo){
	int retorno = 1;
	this->sueldo = sueldo;
	return retorno;
}

int employee_getSueldo(Employee* this,int* sueldo){
	int retorno = 1;
	*sueldo = this->sueldo;
	 return retorno;
}

int get_lastID(){

	FILE* archivoTemporal;
	char bufferTAM[10];
	int tamano;
	archivoTemporal = fopen("data.txt","r");
	if(archivoTemporal == NULL){
		printf("GET: ARCHIVO NO ENCONTRADO");
	}
	fscanf(archivoTemporal,"%s",bufferTAM);
	tamano = atoi(bufferTAM);

	fclose(archivoTemporal);

	return tamano;
}

void set_lastID(int lastID){

	FILE* archivoTemporal;
	archivoTemporal = fopen("data.txt","w");
	if(archivoTemporal == NULL){
		printf("GET: ARCHIVO NO ENCONTRADO");
		exit(1);
	}
	//impresion del tamaño
	fprintf(archivoTemporal,"%d",lastID);

	fclose(archivoTemporal);

}

Employee* employee_new(){
	Employee* pEmpleadoNuevo;

	pEmpleadoNuevo = malloc(sizeof(Employee));

	char bufferNombre[128];
	int bufferHoras,bufferSueldo,id;
	char respuesta;

	//luego autoincrementa independientemente de que ID haya al final
		//obtiene el ID por el data.txt
			//get_lastID
	id = get_lastID();

	do{
		printf("ingrese Nombre: ");
		scanf("%s",bufferNombre);
		printf("ingrese Horas Trabajadas: ");
		scanf("%d",&bufferHoras);
		printf("ingrese Sueldo del Empleado: ");
		scanf("%d",&bufferSueldo);


		printf("\nNombre: %s\n",bufferNombre);
		printf("Horas Trabajadas: %d\n",bufferHoras);
		printf("Sueldo: %d\n",bufferSueldo);
		printf("los datos son correctos? (S/N)\n");
		setbuf(stdin,NULL);
		scanf("%c",&respuesta);
		if(respuesta == 's'){
			//incrementamos uno al ID
				//var id + 1
			id++;
			//se lo asigna al empleado
				//employee_setID(empleado,id);
			employee_setId(pEmpleadoNuevo, id);
			employee_setNombre(pEmpleadoNuevo, bufferNombre);
			employee_setHorasTrabajadas(pEmpleadoNuevo, bufferHoras);
			employee_setSueldo(pEmpleadoNuevo, bufferSueldo);
			//graba el ID incrementado
				//set_lastID
			set_lastID(id);
		}
	}while(respuesta == 'n');

	return pEmpleadoNuevo;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr){

 	int id;
 	int horas;
 	int sueldo;
	Employee* pEmpleado;


	id = atoi(idStr);
 	horas = atoi(horasTrabajadasStr);
 	sueldo = atoi(sueldoStr);
	//primera vez toma el ID
		//punto 1/2 del menu
		//al cargar los datos se graba el ultimo ID en data.txt
			//set_lastID;

 	set_lastID(id);
 	pEmpleado = malloc(sizeof(Employee));
 	employee_setId(pEmpleado, id);
 	employee_setNombre(pEmpleado, nombreStr);
 	employee_setHorasTrabajadas(pEmpleado, horas);
 	employee_setSueldo(pEmpleado, sueldo);

 	return pEmpleado;
}

int employee_edit(LinkedList* pArrayListEmployee){

	Employee* empleado;
	int idBuscada,id,horas,sueldo;
	char nombre[128];
	char respuesta;
	int tam = ll_len(pArrayListEmployee);
	int i;


	printf("que empleado desea editar (INGRESE ID)\n");
	setbuf(stdin,NULL);
	scanf("%d",&idBuscada);
	while(idBuscada > tam){
		printf("Id no encontrado ingrese ID nuevamente\n");
		printf("que empleado desea editar (INGRESE ID)\n");
			setbuf(stdin,NULL);
			scanf("%d",&idBuscada);
	}
	for(i = 0;i < tam;i++){
		empleado = ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);
		if(idBuscada == id){
			printf("ID del empleado: %d\n",id);
			printf("Nombre del Empleado: %s\n", nombre);
			printf("Horas de trabajo del Empleado: %d\n", horas);
			printf("Sueldo del Empleado: %d\n",sueldo);

			printf("\nEditar este Empleado? (S/N)\n");
			setbuf(stdin,NULL);
			scanf("%c",&respuesta);
			while(!(respuesta != 's' || respuesta != 'n')){
				printf("\nEditar este Empleado? (S/N)\n");
				setbuf(stdin,NULL);
				scanf("%c",&respuesta);
			}
			if(respuesta == 's'){
				printf("Nombre Nuevo: ");
				setbuf(stdin,NULL);
				scanf("%s",nombre);
				printf("Nuevos Horarios de Trabajo: ");
				setbuf(stdin,NULL);
				scanf("%d",&horas);
				printf("Nuevo Sueldo: ");
				setbuf(stdin,NULL);
				scanf("%d",&sueldo);
				employee_setNombre(empleado, nombre);
				employee_setHorasTrabajadas(empleado, horas);
				employee_setSueldo(empleado, sueldo);
				printf("\nModificacion realizada!\n");
				sleep(2);
				break;
			} else {
				printf("Cancelando Modificacion...\n");
				sleep(2);
				break;
			}
		}
	}
	return 1;
}

void employee_delete(LinkedList* this){

	int idBuscada;
	Employee* empleado;
	int bufferID;
	char bufferStr[100];
	int bufferHoras;
	int bufferSueldo;
	int i = 0;
	char respuesta;
	char reintentar = 'n';

	//XXX ERROR
	//	que empleado desea borrar? 200	| Alana    		| 220	| 30000
	printf("que empleado desea borrar (INGRESAR ID)");
//	ingreso ID
	scanf("%d",&idBuscada);
	while(idBuscada > ll_len(this)){
		//	En caso de no estar, se notifica y se pide un nuevo ID o cancelar
		printf("ID no encontrado ingrese nuevamente\nquiere intentarlo de nuevo? (S/N)");
		setbuf(stdin,NULL);
		scanf("%c",&reintentar);
			if(reintentar == 's'){
			printf("que empleado desea borrar (INGRESAR ID)");
		//	ingreso ID
			scanf("%d",&idBuscada);
		} else {
			break;
		}
	}
//	reviso ID de cada empleado
	if(reintentar == 'n'){
		for(i = 0;i < ll_len(this);i++){
			empleado = ll_get(this, i);
			employee_getId(empleado,&bufferID);
			if(idBuscada == bufferID){
				employee_getNombre(empleado, bufferStr);
				employee_getHorasTrabajadas(empleado, &bufferHoras);
				employee_getSueldo(empleado, &bufferSueldo);

				//	muestro ID del empleado encontrado
				printf("ID: %d\n",bufferID);
				printf("Nombre: %s\n",bufferStr);
				printf("Horas del empleado: %d\n",bufferHoras);
				printf("Sueldo del empleado: %d\n",bufferSueldo);

				//	confirmar que ese empleado se quiere borrar
				//	verificar ingreso de confirmacion
				printf("\nEs el empleado a borrar? (S/N)\n");
				setbuf(stdin,NULL);
				scanf("%c",&respuesta);
				respuesta = tolower(respuesta);
				while(!(respuesta == 's' || respuesta == 'n')){
					printf("entrada no valida ingrese nuevamente");
					printf("\nEs el empleado a borrar? (S/N)\n");
					setbuf(stdin,NULL);
					scanf("%c",&respuesta);
					respuesta = tolower(respuesta);
				}
				if(respuesta == 's'){
					//	borrar empleado
					ll_remove(this, i);
					//	empleado X borrado
					printf("Empleado %s borrado\n",bufferStr);
					break;
					break;
				} else {
					printf("Borrado cancelado...\n");
					break;
					break;
				}
			}
		}
	}
}


void MostrarUnEmpleado(LinkedList* lista,int index){

	char bufferStr[128];
	int bufferInt;
	Employee* bufferEmpleado;

	bufferEmpleado = ll_get(lista,index);
	employee_getId(bufferEmpleado, &bufferInt);
	printf("%d",bufferInt);
	employee_getNombre(bufferEmpleado, bufferStr);
	if(strlen(bufferStr) <= 5){
		printf("\t| %s    ",bufferStr);
	} else {
		printf("\t| %s",bufferStr);
	}
	employee_getHorasTrabajadas(bufferEmpleado, &bufferInt);
	if(strlen(bufferStr) <= 12){
		printf("\t\t| %d",bufferInt);
	} else {
		printf("\t| %d",bufferInt);
	}
	employee_getSueldo(bufferEmpleado, &bufferInt);
	printf("\t| %d\n",bufferInt);
}

void ordenarEmpleados(LinkedList* lista,int order){

	int i,j,tam;
	Employee* bufferCompA;
	Employee* bufferCompB;
	int idAux,horasAux,sueldoAux,intAux,idEmpA,idEmpB;
	char strAux[128],strAux2[128];
	char nombreEmpA[128];
	char nombreEmpB[128];

	tam = ll_len(lista);
	//preguntar orden buscado
	printf("Ordenado!");
//		printf("Como desea ordenar los empleados?\n1.NOMBRE\n2.HORAS LABORALES\n3.SUELDO");
//		scanf("%d",&ordenamiento);
//		switch (ordenamiento){
//		case 1:
//			//ordenado AZ - ZA
//			printf("1.A a Z\n2.Z a A");
//			scanf("%d",alfabeto);
//			break;
//		case 2:
//			//ordenado por hora - mayor menor / menor mayor
//			printf("1.MAYOR a MENOR\n2.MENOR a MAYOR");
//			scanf("%d",mayores);
//			break;
//		case 3:
//			//ordenado salario - mayor menor / menor mayor
//			printf("1.MAYOR a MENOR\n2.MENOR a MAYOR");
//			scanf("%d",mayores);
//		}
			//burbujeo
	if(order == 0){
		for(i = 0; i < tam-1;i++){
			//BufferCompA = ll_get(lista, i);
			bufferCompA = ll_get(lista, i);
			employee_getNombre(bufferCompA, nombreEmpA);
			for(j = i+1; j < tam;j++){
				//BufferCompB = ll_get(lista, j);
				bufferCompB = ll_get(lista, j);
				//obtener el nombre del compA y del compB
				employee_getNombre(bufferCompB, nombreEmpB);
				//comparar A y B
				if(strcmp(nombreEmpA,nombreEmpB) > 0){
				//seteo ID,Nombre,Horas,Sueldo
					//strAux = A
					employee_getNombre(bufferCompA, strAux);
					//A = B
					employee_getNombre(bufferCompB, strAux2);
					employee_setNombre(bufferCompA, strAux2);
					//B = strAux
					employee_setNombre(bufferCompB, strAux);

					//idAux = idA
					employee_getId(bufferCompA, &idAux);
					//idA = idB
					employee_getId(bufferCompB, &intAux);
					employee_setId(bufferCompA, intAux);
					//idB = idAux
					employee_setId(bufferCompB, idAux);

					strcpy(strAux,nombreEmpB);
					strcpy(nombreEmpB,nombreEmpA);
					strcpy(nombreEmpA,strAux);

					//horas = A
					employee_getHorasTrabajadas(bufferCompA, &horasAux);
					//A = B
					employee_getHorasTrabajadas(bufferCompB, &intAux);
					employee_setHorasTrabajadas(bufferCompA, intAux);
					//B = horas
					employee_setHorasTrabajadas(bufferCompB, horasAux);

					//sueldo = A
					employee_getSueldo(bufferCompA, &sueldoAux);
					//A = B
					employee_getSueldo(bufferCompB, &intAux);
					employee_setSueldo(bufferCompA, intAux);
					//B = sueldo
					employee_setSueldo(bufferCompB, sueldoAux);
				}
			}
		}
	} else {
			if(order == 0){
				for(i = 0; i < tam-1;i++){
					employee_getId(bufferCompA, &idEmpA);
					for(j = i+1; j < tam;j++){
						bufferCompB = ll_get(lista, j);
						//obtener el ID del compA y del compB
						employee_getId(bufferCompB, &idEmpB);
					if(idEmpA < idEmpB){
					//seteo ID,Nombre,Horas,Sueldo
						//strAux = A
						employee_getNombre(bufferCompA, strAux);
						//A = B
						employee_getNombre(bufferCompB, strAux2);
						employee_setNombre(bufferCompA, strAux2);
						//B = strAux
						employee_setNombre(bufferCompB, strAux);

						//idAux = idA
						employee_getId(bufferCompA, &idAux);
						//idA = idB
						employee_getId(bufferCompB, &intAux);
						employee_setId(bufferCompA, intAux);
						//idB = idAux
						employee_setId(bufferCompB, idAux);

						strcpy(strAux,nombreEmpB);
						strcpy(nombreEmpB,nombreEmpA);
						strcpy(nombreEmpA,strAux);

						//horas = A
						employee_getHorasTrabajadas(bufferCompA, &horasAux);
						//A = B
						employee_getHorasTrabajadas(bufferCompB, &intAux);
						employee_setHorasTrabajadas(bufferCompA, intAux);
						//B = horas
						employee_setHorasTrabajadas(bufferCompB, horasAux);

						//sueldo = A
						employee_getSueldo(bufferCompA, &sueldoAux);
						//A = B
						employee_getSueldo(bufferCompB, &intAux);
						employee_setSueldo(bufferCompA, intAux);
						//B = sueldo
						employee_setSueldo(bufferCompB, sueldoAux);
					}
				}
			}
		}
	}
}
