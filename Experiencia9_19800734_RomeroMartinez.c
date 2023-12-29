#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Experiencia Anexa a la experiencia 3.
* En esta ocacion crearemos matrices de n x m a travez de funciones externas.
* Se hace uso de arreglos dinamicos y medimos el tiemmpo de ejecion con la libreria time.
---------------------------------------------------------------------------------------------------------------------
*/
void llenar_Matriz(int filas, int columnas, int matriz[filas][columnas]);
void mostrar_matriz(int filas,int columnas, int matriz[filas][columnas]);

void llenar_Matriz_1(int filas_1, int columnas_1, int matriz_1[filas_1][columnas_1]);
void mostrar_matriz_1(int filas_1,int columnas_1, int matriz_1[filas_1][columnas_1]);

int main(){
	
	srand(time(NULL));
	int fila;
	int columna;
	int fila_1;
	int columna_1;
	printf("INGRESE LA CANTIDAD DE FILAS");
	printf("\n");
	printf("ATENCION DEBE INGRESAR EL MISMO NUMERO DOS VECES : ");
	scanf("%d",&fila);
	scanf("%d",&fila_1);
	printf("\n");
	printf("INGRESE LA CANTIDAD DE COLUMNAS ");
	printf("\n");
	printf("ATENCION DEBE INGRESAR EL MISMO NUMERO DOS VECES : ");
	scanf("%d",&columna);
	scanf("%d",&columna_1);
	printf("\n");
	printf("PRIMERA MATRIZ OBTENIDA");
	printf("\n");
	int matriz[fila][columna];
	llenar_Matriz(fila,columna,matriz);
	mostrar_matriz( fila,columna,  matriz);
	printf("\n");
	printf("\n");
	printf("SEGUNDA MATRIZ OBTENIDA");
	printf("\n");
	int matriz_1[fila_1][columna_1];
	llenar_Matriz_1(fila_1,columna_1,matriz_1);
	mostrar_matriz_1( fila_1,columna_1,  matriz_1);
	return 0;
}

//FUNCION PARA MOSTRAR Y LLENAR LA PRIMERA MATRIZ
void mostrar_matriz(int fila, int columna , int matriz[fila][columna]){
	int i,j;
	for(i=0; i<fila ; i++){
		for(j=0;j<columna;j++){
			printf("%d\t",matriz[i][j]);
		}
		printf("\n");
	}
}
void llenar_Matriz(int fila,int columna, int matriz[fila][columna]){
	int i,j ;
	for(i=0; i<fila ; i++){
		for(j=0;j<columna;j++){
			matriz[i][j] = 1 + rand() % 9;
		}
	}
}
// FUNCION PARA MOSTRAR Y LLENAR LA SEGUNDA MATRIZ
void mostrar_matriz_1(int fila_1, int columna_1 , int matriz_1[fila_1][columna_1]){
	int i,j;
	for(i=0; i<fila_1 ; i++){
		for(j=0;j<columna_1;j++){
			printf("%d\t",matriz_1[i][j]);
		}
		printf("\n");
	}
}
void llenar_Matriz_1(int fila_1,int columna_1, int matriz_1[fila_1][columna_1]){
	int i,j ;
	for(i=0; i<fila_1 ; i++){
		for(j=0;j<columna_1;j++){
			matriz_1[i][j] = 1 + rand() % 9;
		}
	}
}

