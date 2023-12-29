#include <stdio.h>
#include <stdlib.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Esta experiencia consta de buscar la secuencia constante mas larga.
* Por ejemplo tenemos 1 - 2 - 3 - 4 - 90 - 3 - 51 - 52 - 53 - 54 - 55 - 56
* En este caso la secuencia mas larga constante parte desde 51 y termina en 56.
* Asumiendo que 1 esta en la posicion 0, entonces la secuencia mas larga esta en la pos 6 - 11 (termina en la pos 11).
* Se hacen uso de arreglos dinamicos, absolutos y memoria en general. 
*
---------------------------------------------------------------------------------------------------------------------
*/
int * agregar(int* arreglo,int* tamanio, int elemento){
	//Se crea un nuevo arreglo de tamanio + 1 elementos
	int * nuevo_arreglo = (int *)malloc(sizeof(int)*(*tamanio+1));
	//Se copian los elementos de arreglo en nuevo_arreglo
	int i = 0;
	for(i=0;i<*tamanio;i++){
		nuevo_arreglo[i]=arreglo[i];
	}
	//Se agrega el elemento que se quiere agregar
	nuevo_arreglo[*tamanio] = elemento;
	//Se aumenta el tamanio del arreglo
	*tamanio = *tamanio+1;
	//Se libera de memoria el arreglo viejo
	free(arreglo);
	//se retorna el nuevo arreglo
	return nuevo_arreglo;
}

//Funcion que realiza la resta entre posiciones
//Verifica que la diferencia sea solo de 1
int resta(int val1, int val2){
	if((abs(val1 - val2))==1 || (abs(val1 -val2 == 0))){
		return 1;
	}else{
		return 0;
	}
}
int * sub_secuencia_creciente(int * secuencia, int tamanio, int inicio, int fin){
	if(inicio == fin){//Arreglo de un solo elemento
		int * posiciones = (int*)malloc(sizeof(int)*2);
		posiciones[0] = inicio;
		posiciones[1] = fin;
		return posiciones;
	}else if(fin < inicio){//Arreglo de 0 elementos
		int * posiciones = (int*)malloc(sizeof(int)*2);
		posiciones[0] = -1;
		posiciones[1] = -1;
		return posiciones;
	}else{
		//Calculamos la posición central del arreglo
		int pivote = inicio + (fin - inicio)/2;
		//Calculamos la sub secuencia mas larga por el lado izquierdo
		int * subSecuencia_izquierda = (int*)malloc(sizeof(int)*2);
		subSecuencia_izquierda = sub_secuencia_creciente(secuencia, tamanio, inicio, pivote - 1);
		//Calculamos la sub secuencia mas larga por el lado derecho
		int * subSecuencia_derecha = (int*)malloc(sizeof(int)*2);
		subSecuencia_derecha = sub_secuencia_creciente(secuencia, tamanio, pivote + 1, fin);
		//Ahora trabajamos con los elementos centrales
		int * subSecuencia_central = (int*)malloc(sizeof(int)*2);
		subSecuencia_central[0] = pivote; //Desde donde inicia
		subSecuencia_central[1] = pivote; //Hasta donde llega
		int i = pivote-1;
		while(i >= inicio){
			if(resta(secuencia[subSecuencia_central[0]],secuencia[i]) == 1){
				subSecuencia_central[0] = i;
				i = i - 1;
			}else{
				i = inicio-1;
			}
		}
		int j = pivote + 1;
		while(j <= fin){
			if(resta(secuencia[subSecuencia_central[1]] ,secuencia[j]) == 1){
				subSecuencia_central[1] = j;
				j = j + 1;
			}else{
				j = fin+1;
			}
		}
		//calculo tamaños
		int lado_izquierdo = subSecuencia_izquierda[1] - subSecuencia_izquierda[0];
		int lado_derecho = subSecuencia_derecha[1] - subSecuencia_derecha[0];
		int centro = subSecuencia_central[1] - subSecuencia_central[0];
		if(lado_izquierdo >= lado_derecho && lado_izquierdo >= centro){
			return subSecuencia_izquierda;	
		}else if(lado_derecho >= lado_izquierdo && lado_derecho >= centro){
			return subSecuencia_derecha;
		}else{
			return subSecuencia_central;
		}

	}
}

int main(){
	//Se crea un arreglo vacio
	int tamanio_arreglo = 0;
	int* arreglo = (int *)malloc(sizeof(int)*tamanio_arreglo);
	//Se le preguntará al usuario si desea o no agregar elementos
	int opcion;
	do{
		//Se le solicita un número al usuario
		int numero;
		printf("Ingrese un numero: ");
		scanf("%d", &numero);
		
		//Se agrega el numero al arreglo
		arreglo = agregar(arreglo, &tamanio_arreglo, numero);

		//Se le solicita la opción al usuario
		printf("\n");
		printf("¿Desea agregar otro numero al arreglo? (1-. Si/Otro-. No)");
		scanf("%d", &opcion);

	}while(opcion == 1);

	int i = 0;
	for(i=0;i<tamanio_arreglo;i++){
		printf("%d - ",arreglo[i]);
	}
	printf("\n");
	int * posiciones = (int *)malloc(sizeof(int)*2);
	posiciones = sub_secuencia_creciente(arreglo, tamanio_arreglo, 0, tamanio_arreglo-1);
	printf("La secuencia más larga casi constante esta entre las posiciones %d y %d \n", posiciones[0], posiciones[1]);
	printf("En caso de salir -1 y -1 cuenta como que la posicion es vacio y no existe equivalente a 0 y 0\n");
	return 0;
}