#include <stdio.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Experiencia Anexa..
* En esta experiencia la idea es encontrar todos los divisores de un numero puesto por consola.
---------------------------------------------------------------------------------------------------------------------
*/
int main ( int argc, char * argv[]){
	int numero;
	int i;
	do{
		printf("Introduce un numero: ");
		scanf("%d", &numero);

	}while(numero<= 0);

	for(i=1; i<=numero/2; i++){
		if (numero % i == 0){
			printf("%d " , i );
		}
	}
	printf("%d", numero );	
	return 0
}