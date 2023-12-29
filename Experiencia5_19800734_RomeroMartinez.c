#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Esta experiencia consta de la creacion del tribonacci.
* Es similar al fibonacci pero en vez de usar dos valores, se usan tres.
* Para mas informacion, buscar la secuencia de fibonacci.
* La idea de esta experiencia es trabajar el fibonacci de tres formas distintas, la manera recursiva de pila, cola e iterativa.
* Ademas tomamos en cuenta el tiempo de ejecucion de una manera u otra con el uso de la libreria time.
*
---------------------------------------------------------------------------------------------------------------------
*/
int tribonacci_recursivo_pila(int n){
	if (n==0){
		return 0;
	}
	else if(n==1 || n ==2){
		return 1;
	}
	else{
		return tribonacci_recursivo_pila(n-1) + tribonacci_recursivo_pila(n-2) + tribonacci_recursivo_pila(n-3);
	}
}

int tribonacci_iterativo(int n){
	if(n==0){
		return 0;
	}else if (n==1 || n == 2){
		return 1;
	}
	else{
		int valor_anterior_anterior_anterior = 0;
		int valor_anterior_anterior = 1;
		int valor_anterior = 1;
		int valor_actual = valor_anterior_anterior_anterior + valor_anterior_anterior + valor_anterior;
		int i = 4;
		while(i<=n){
			valor_anterior_anterior_anterior = valor_anterior_anterior;
			valor_anterior_anterior = valor_anterior;
			valor_anterior = valor_actual;
			valor_actual = valor_anterior + valor_anterior_anterior + valor_anterior_anterior_anterior;
			i = i + 1;
		}
		return valor_actual;
	}
}	

int tribonacci_cola(int n, int valor_anterior_anterior_anterior, int valor_anterior_anterior, int valor_anterior){
	if(n==0){
		return valor_anterior_anterior_anterior;
	}else if(n==1){
		return valor_anterior_anterior;
	}else if(n==2){
		return valor_anterior;
	}
	else{
		return tribonacci_cola(n-1,valor_anterior_anterior,valor_anterior , valor_anterior_anterior_anterior + valor_anterior_anterior + valor_anterior);
	}	
}

int main(){
	int num;
	printf("Ingrese un numero : ");
	scanf("%d",&num);
	time_t ini1 = time(NULL);
	int res_recursivo = tribonacci_recursivo_pila(num);
	printf("\n El resultado de tribonacci recursivo pila es %d",res_recursivo);
	time_t fin1 = time(NULL);
	printf("\n");
	printf("El tiempo de tribonacci recursivo pila es %f", difftime(fin1 , ini1));
	printf("\n");
	time_t ini2 = time(NULL);
	int res_iterativo = tribonacci_iterativo(num);
	printf("\n El resultado de tribonacci iterativo es %d",res_iterativo);
	time_t fin2 = time(NULL);
	printf("\n");
	printf("El tiempo de tribonacci iterativo es %f", difftime(fin2 , ini2));
	printf("\n");
	time_t ini3 = time(NULL);
	int res_cola = tribonacci_cola(num,0,1,1);
	printf("\n El resultado de tribonacci recursivo cola es %d",res_cola);
	time_t fin3 = time(NULL);
	printf("\n");
	printf("El tiempo de tribonacci recursivo cola es %f", difftime(fin3 , ini3));
	printf("\n");
	return 0;
}