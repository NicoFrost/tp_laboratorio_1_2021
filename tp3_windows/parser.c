#include "parser.h"
#define TAM 50

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee){

 	char parID[TAM];
 	char parNombre[TAM];
 	char parHoras[TAM];
 	char parSueldo[TAM];
 	Employee* Empleado;
	while(!feof(pFile)){
 		fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",parID,parNombre,parHoras,parSueldo);
 		if((strcmp(parID,"id")) != 0){
 			Empleado = employee_newParametros(parID,parNombre, parHoras,parSueldo);
 			ll_add(pArrayListEmployee, Empleado);
 		}
	}

	return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
 	Employee auxiliar;
 	Employee* auxiliar2;
// 	char EmpleadoBruto[sizeof(Employee)+3];
 	int cantidadLeida;
 	char parID[20],parHoras[20],parSueldo[20],nombre[128];
 	int id,horas,sueldo;
 	while(!feof(pFile)){
 		cantidadLeida = fread(&auxiliar,sizeof(Employee),1,pFile);
 		employee_getId(&auxiliar, &id);
 		employee_getNombre(&auxiliar, nombre);
 		employee_getHorasTrabajadas(&auxiliar, &horas);
 		employee_getSueldo(&auxiliar, &sueldo);
		itoa(id,parID,10);
		itoa(horas,parHoras,10);
		itoa(sueldo,parSueldo,10);
		auxiliar2 = employee_newParametros(parID, nombre, parHoras, parSueldo);
		ll_add(pArrayListEmployee, auxiliar2);
		if(cantidadLeida < 1){
			printf("Error de escritura");
		}
	}
// 		fread(EmpleadoBruto,sizeof(Employee)+3,1,pFile);
// 		printf("%s",EmpleadoBruto);


 	return 1;
}

int parser_EmployeeToText(FILE* pFile , LinkedList* pArrayListEmployee){

	char nombre[TAM];
 	int id,horas,sueldo;
 	Employee* empleado;

 	fprintf(pFile,"id,nombre,horas,sueldo\n");
 	for(int i = 0; i<ll_len(pArrayListEmployee);i++){
		empleado = ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);

		fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horas,sueldo);
 	}

	return 1;
}

int parser_EmployeeToBinary(FILE* pFile , LinkedList* pArrayListEmployee){

	int cantidadEscrita = 0;
	Employee* empleado;
	char nombre[TAM];
 	int id,horas,sueldo;

 	for(int i = 0; i<ll_len(pArrayListEmployee);i++){
		empleado = ll_get(pArrayListEmployee, i);
		employee_getId(empleado, &id);
		employee_getNombre(empleado, nombre);
		employee_getHorasTrabajadas(empleado, &horas);
		employee_getSueldo(empleado, &sueldo);

		cantidadEscrita = fwrite(empleado,sizeof(Employee),1,pFile);
		if(cantidadEscrita < 1){
			printf("ERROR de escritura");
		}
 	}
	return 1;
}
