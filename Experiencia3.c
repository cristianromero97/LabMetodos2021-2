#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Esta experiencia consta del uso de matrices y arreglos dinamicos.
* Para ello se debe crear una matriz de tamaño n x m utilizando arreglos. 
* Luego mostrarlos por pantalla y finalmente verificar si una matriz es Par o Impar.
---------------------------------------------------------------------------------------------------------------------
*/
int main(){
	srand(time(NULL));
	int filas,columnas;
	printf("Ingrese el numero de filas de la matriz : ");
	scanf("%d",&filas);
	printf("Ingrese el numero de columnas de la matriz : ");
	scanf("%d",&columnas);
	printf("\n");
	printf("MATRIZ RANDOM ORIGINAL\n");
	int **a =(int **)malloc(sizeof(int *)*filas);
	for(int i=0;i<filas;i++){
		a[i] = (int *)malloc(sizeof(int)*columnas);
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			a[i][j] = 1 + rand() % 9;
		}
	}
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			//printf("\n El valor guardado en (%d,%d) es %d",i,j,a[i][j]);  // (REVISAR VALOR POR VALOR)
			printf("%d\t",a[i][j]);
			}
		printf("\n");
		}
		
	printf("\n");
	printf("MATRIZ PAR\n");

	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(((i+j) % 2 == 0 )&&(i%2==0)){
				printf("%d\t",a[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");
	printf("MATRIZ IMPAR");
	for(int i=0;i<filas;i++){
		for(int j=0;j<columnas;j++){
			if(((i+j) % 2 == 0 )&&(i%2==1)){
				printf("%d\t",a[i][j]);
			}
		}
		printf("\n");
	}
	printf("\n");

	for(int i=0;i<filas;i++){
		free(a[i]);
	}
	free(a);

	return 0;
}