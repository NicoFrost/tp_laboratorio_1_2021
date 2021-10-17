#include "ArrayEmployees.h"
#include "Funciones adicionales.h"

int initEmployees(Employee* list, int len)
{

	list->isEmpty = 0;

	return 0;
}

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */




int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{

	getString(name, "Ingrese nombre: ", len);
	while(!(SoloLetras(name))){
		printf("ERROR NOMBRE INVALIDO\n");
		getString(name, "ingrese nombre SIN NUMEROS: ", len);
	}
	getString(lastName, "Ingrese Apellido: ", len);
	while(!(SoloLetras(lastName))){
		printf("ERROR APLLIDO INVALIDO \n");
		getString(lastName, "ingrese apellido SIN NUMEROS: ", len);
	}
	VerifFlotante(&salary,"Ingresar salario: ","ERROR. No ingresar letras: ");
	VerifEntero(&sector, "Ingrese Sector: ", "ERROR. SECTOR CON NUMERO: ");



	strcpy(list->name,name);
	strcpy(list->lastName,lastName);
	list->salary = salary;
	list->sector = sector;
	list->isEmpty = 1;
	return -1;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 *
*/



int findEmployeeById(Employee* list, int len,int id)
{
	int ubicacion = -1;
	for(int i = 0; i < len;i++){
		if(id == list[i].id && list[i].isEmpty == 1){
			ubicacion = i;
			break;
		}
	}

 return ubicacion;
}

/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */



int removeEmployee(Employee* list, int len, int id)
{
	list[id].isEmpty = 0;

	return -1;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */



int sortEmployees(Employee* list, int len, int order)
{
	int i,j;
	int Iaux;
	float fAux;
	char cadenaAux[51];
	for(i = 0; i < len-1;i++){
		for(j = i+1; j < len;j++){
			if(list[i].sector < list[j].sector){
				Iaux = list[i].id;
				list[i].id = list[j].id;
				list[j].id = Iaux;

				strcpy(cadenaAux,list[i].name);
				strcpy(list[i].name,list[j].name);
				strcpy(list[j].name,cadenaAux);

				strcpy(cadenaAux,list[i].lastName);
				strcpy(list[i].lastName,list[j].lastName);
				strcpy(list[j].lastName,cadenaAux);

				fAux = list[i].salary;
				list[i].salary = list[j].salary;
				list[j].salary = fAux;

				Iaux = list[i].sector;
				list[i].sector = list[j].sector;
				list[j].sector = Iaux;

				Iaux = list[i].isEmpty;
				list[i].isEmpty = list[j].isEmpty;
				list[j].isEmpty = Iaux;

			}
		}
	}

 return 0;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */



int printEmployees(Employee* list, int length)
{
	printf("|  ID  | NOMBRE APELLIDO SALARIO SECTOR |\n");
	for(int i = 0;i < length;i++){
		if(list[i].isEmpty == 1){
			printf("| %04d | %s %s $%.2f %d |\n",list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
		}
	}
	printf("-----------------------------------------\n");
 return 0;

}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */



