#include "Funciones adicionales.h"
#include "ArrayEmployees.h"

int buscarEspacioLibre(Employee* list,int len)
{
	int ubicacionLibre = -1;

	if(list != NULL && len > 0){
		for(int i = 0; i < len; i++){
			if(list[i].isEmpty == 0)
			{
				ubicacionLibre = i;
				break;
			}
		}
	}

	return ubicacionLibre;
}

int BusquedaID(Employee* Empleado,int len){
	int bid;
	int retorno;

	printf("Ingrese ID a Buscar: ");
	scanf("%d", &bid);
	retorno = findEmployeeById(Empleado, len, bid);
	while(retorno == -1 || bid == 0){
		printf("ID no encontrado");
		scanf("%d", &bid);
		retorno = findEmployeeById(Empleado, len, bid);
	}
	return retorno;
}

void VerifFlotante(float* retorno, char mensaje[], char errorMensaje[]){
	int tam = 51;
	char cadenaAux[tam];
	fflush(stdin);
	getString(cadenaAux, mensaje, tam);
	while(!(esNumeroFlotante(cadenaAux))){
		fflush(stdin);
		getString(cadenaAux, errorMensaje, tam);
	}

	*retorno = atof(cadenaAux);
}

void VerifEntero(int* retorno,char mensaje[],char errormensaje[]){
	int tam = 51;
	char cadenaAux[tam];
	fflush(stdin);
	getString(cadenaAux, mensaje, tam);
	while(!(esNumerico(cadenaAux))){
		fflush(stdin);
		getString(cadenaAux, errormensaje, tam);
	}

	*retorno = atoi(cadenaAux);

}
//Funcion hecha para no mostrar todo en el Main
void MostrarSalarios(Employee* Empleado, int len)
{
	int contador;
	//inicializacion hecha porque aun no es funcion
	int sumaSalario;
	float promedio;

	for(int x = 0;x < len;x++){
		if(Empleado[x].isEmpty == 1){
			sumaSalario += Empleado[x].salary;
			contador++;
		}
	}
	promedio = sumaSalario / contador;
	contador = 0;
	for(int x = 0;x < len;x++){
		if(Empleado[x].isEmpty == 1 && Empleado[x].salary > promedio){
			contador++;
		}
	}
	printf("-----SALARIO-----\n");
	printf("|TOTAL:    $%04d  \n", sumaSalario);
	printf("|PROMEDIO: $%04.2f  \n", promedio);
	printf("|empleados superando promedio: %d\n",contador);
	printf("-----------------");
}
