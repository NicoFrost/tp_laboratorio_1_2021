#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include <unistd.h>
#include "libreria.h"
#include <time.h>

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

#define TAM 5


int main()
{
	setbuf(stdout,NULL);
    int option = 0;
    char continuar;
    LinkedList* myList = ll_newLinkedList();
    set_lastID(0);
    char archivoTexto[10] = "data.csv";
    char archivoBinario[10] = "data.bin";

    do{
    	if(option == 6 || option == 7){
			do{
				printf("ingrese C para continuar...\n");
				setbuf(stdin,NULL);
				scanf("%c",&continuar);
				continuar = tolower(continuar);
			}while(continuar != 'c');
    	}
    	printf("\ningrese una opcion (en numeros)...\n");
    	printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    	printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    	printf("3. Alta de empleado\n");
    	printf("4. Modificar datos de empleado\n");
    	printf("5. Baja de empleado\n");
    	printf("6. Listar empleados\n");
    	printf("7. Ordenar empleados\n");
    	printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    	printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    	printf("10. Salir\n");

    	printf(">");
    	scanf("%d", &option);
    	switch(option)
        {
            case 1:
            	controller_loadFromText(archivoTexto,myList);
            	break;
			case 2:
				controller_loadFromBinary(archivoBinario, myList);
				break;
            case 3:
            	controller_addEmployee(myList);
            	break;
            case 4:
            	controller_editEmployee(myList);
            	break;
            case 5:
            	controller_removeEmployee(myList);
            	break;
            case 6:
            	controller_ListEmployee(myList);
            	break;
            case 7:
            	controller_sortEmployee(myList);
            	break;
            case 8:
            	controller_saveAsText(archivoTexto, myList);
            	break;
            case 9:
            	controller_saveAsBinary(archivoBinario, myList);
            	break;
        }

    }while(option != 10);
	ll_deleteLinkedList(myList);

    return 0;
}

