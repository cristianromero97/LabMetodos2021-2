#include<stdio.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Experiencia Anexa.
* La idea es encontrar los numeros amigos, para saber si un numero es amigo con otro buscar mas informacion en internet.
* Se hace uso de ciclos for y while en esta experiencia.
---------------------------------------------------------------------------------------------------------------------
*/
int main(){
	int programa;

	printf("Programa para conocer si dos numeros son amigos\n\n");
	printf("para comenzar a utilizar el programa presione 1 para cerra el programa presione 2\n\n");
	scanf("%d",&programa);	

	while (programa ==1){ 

	int numero1;
	int numero2;
	int divisor1 = 0;
	int divisor2 = 0;

	printf("Por favor ingresar los numeros que desee calcular\n");
	printf("Numero 1 : ");
	scanf("%d",&numero1);
	printf("Numero 2 : ");
	scanf("%d",&numero2);

	for (int i = 1 ; i <= numero1 / 2 ; i++){
		if(numero1 % i == 0)
			divisor1 = divisor1 + i;
	}
    for (int i = 1 ; i <= numero2 / 2 ; i++){
		if(numero2 % i == 0)
			divisor2 = divisor2 + i;
    }

    if (numero1 == divisor2 && numero2 == divisor1){

    	printf("%d,%d Son amigos",numero1,numero2);

    }
    else{
    	printf("%d,%d No son amigos",numero1,numero2);
    }



	printf("\n\n¿Desea continuar con el programa? [SI=1/NO=2]\n");
	scanf("%d",&programa);

	}

	if(programa==2){
		printf("Gracias por utilizar el programa");

	}
	return 0;
}