#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "libreria.h"

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pArchivo;

	pArchivo = fopen(path,"r");
	if(pArchivo == NULL){
		printf("ERROR:no existe el archivo");
		exit(1);
	}
	printf("\nCargando datos...\n");
	parser_EmployeeFromText(pArchivo, pArrayListEmployee);
	fclose(pArchivo);

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE *pArchivo;
	char respuesta;

	pArchivo = fopen(path,"rb");
	if(pArchivo == NULL){
		printf("ERROR:no existe el archivo\n");
		printf("desea cargar desde Texto? (S/N)");
		IngresarRespuesta(&respuesta);
		if(respuesta == 's'){
			controller_loadFromText("data.csv",pArrayListEmployee);
        	printf("\nCargando datos...\n");
		}
	} else {
		printf("\nCargando datos...\n");
		parser_EmployeeFromBinary(pArchivo, pArrayListEmployee);
		fclose(pArchivo);
	}

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	//no puede tomar el tamaño del archivo como referencia para crear el nuevo ID

	Employee* EmpleadoNuevo;
	EmpleadoNuevo = employee_new();
	ll_add(pArrayListEmployee,EmpleadoNuevo);
	return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	if(ll_len(pArrayListEmployee) != 0){
		employee_edit(pArrayListEmployee);
	} else {
		printf("no se pueden hacer cambios ya que no hay ningun empleado cargado\n");
		printf("Sugerencia: cargar datos con la opcion 1 del menu");
	}
	return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	if(ll_len(pArrayListEmployee) != 0){
		employee_delete(pArrayListEmployee);
	} else {
		printf("no se puede eliminar lo que no existe...\n");
		printf("Sugerencia: cargar datos con la opcion 1 del menu");
	}
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int cantidad = ll_len(pArrayListEmployee);
	printf("ID\t| NOMBRE\t\t| HORAS\t| SUELDO\n");
	printf("--------------------------------------------------\n");
	for(int i = 0;i < cantidad;i++){
		MostrarUnEmpleado(pArrayListEmployee,i);
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	//llamar a funcion ordenar le llevamos el linkedlist
	ordenarEmpleados(pArrayListEmployee,0);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
//	controller_saveAsBinary(path, pArrayListEmployee);
	ordenarEmpleados(pArrayListEmployee, 1);
	FILE *pArchivo;

	pArchivo = fopen(path,"w");
	if(pArchivo == NULL){
		printf("ERROR:no existe el archivo");
		exit(1);
	}
	parser_EmployeeToText(pArchivo, pArrayListEmployee);
	fclose(pArchivo);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	controller_saveAsText(path, pArrayListEmployee);
//	ordenarEmpleados(pArrayListEmployee, 1);
	FILE *pArchivo;

	pArchivo = fopen(path,"wb");
	if(pArchivo == NULL){
		printf("ERROR:no existe el archivo");
		exit(1);
	}
	parser_EmployeeToBinary(pArchivo, pArrayListEmployee);
	fclose(pArchivo);
    return 1;
}

