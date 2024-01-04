#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Esta experiencia consta de la creacion de almacenado de una bodega utilizando punteros y estructura (struct).
* Para ello se debe implementar un menu en la cual se hara uso de llamado de funciones auxiliares.
* Las funciones tienen como base la estructura del almacen con sus respectivos atributos.
*
---------------------------------------------------------------------------------------------------------------------
*/
struct almacen{
	char* nombre;
	int numeroSerie;
	int precio;
	int peso;
	int volumen;
	int cantidadDisponible;
};

typedef struct almacen producto;

void imprimir_datos(producto consumo){
	printf("El nombre del producto es : %s\n",consumo.nombre);
	printf("El numero de Serie es: %d\n",consumo.numeroSerie);
	printf("El precio del producto es : %d\n",consumo.precio);
	printf("El peso del producto es: %d\n",consumo.peso);
	printf("El volumen del producto es %d\n",consumo.volumen);
	printf("La cantidad disponible que hay es : %d\n",consumo.cantidadDisponible);
	return;
}

producto solicitar_datos(){
	char nombre[200];
	int numeroSerie,precio,peso,volumen,cantidadDisponible;
	printf("Indique el nombre del producto : \n");
	scanf("%s",nombre);
	printf("Indique el numero de serie del producto: \n");
	scanf("%d",&numeroSerie);
	printf("Indique el precio del producto : \n");
	scanf("%d",&precio);
	printf("Indique el peso del producto : \n");
	scanf("%d",&peso);
	printf("Indique el volumen del producto : \n");
	scanf("%d",&volumen);
	printf("Indique la cantidad disponible : \n");
	scanf("%d",&cantidadDisponible);
	producto productos;
	productos.nombre = nombre;
	productos.numeroSerie = numeroSerie;
	productos.precio = precio;
	productos.peso = peso ;
	productos.volumen = volumen ;
	productos.cantidadDisponible = cantidadDisponible;
	
	return productos;
}


void buscar_numero_serie(producto * totalProductos,int cantidad){
	int i=0;
	int Buscado,a;
	printf("Indique el numero de serie que desea buscar :");
	scanf("%d",&Buscado);
	a = (totalProductos->numeroSerie);
	if (Buscado == a){
		printf("Su numero de serie coinicide con un valor encontrado\n");
		for(i=0;i<cantidad;i++){
			imprimir_datos(totalProductos[i]);
		}
	}
	else{
		printf("Su numero de serie es distinto o no existe");
	}

	return ; 
}

void buscar_nombre(producto *totalProductos, int cantidad){
	int i=0;
	char buscado[100];
	char* c;
	printf("Indique el nombre del producto a buscar : \n");
	scanf("%s",buscado);
	c=(totalProductos->nombre);
	if(strcmp(buscado,c)==0){
		printf("Se ha encontrado un producto con tal nombre\n");
		for(i=0;i<cantidad;i++){
			imprimir_datos(totalProductos[i]);
		}
	}else{
		printf("Su nombre es distinto o no existe\n");
	}
}

void disponible(producto * totalProductos, int cantidad){
	int d;
	char* e;
	e=(totalProductos->nombre);
	d=(totalProductos->cantidadDisponible);
	if(d>0){
		printf("El o los producto(s) disponible es %s\n",e);
		printf("Su cantidad disponible es %d\n",d);
		printf("\n");
	}else{
		printf("No hay ningun producto disponible");
	}
}

void precio_evaluar(producto * totalProductos, int cantidad){
	int j,k;
	char* E;
	E=(totalProductos->nombre);
	k=(totalProductos->precio);
	printf("Ingrese un precio fijo para evaluar : \n");
	scanf("%d",&j);
	if(j<k){
		printf("El o los producto(s) %s tiene(n) mayor precio al indicado",E);
	}else if(j==k){
		printf("El o los producto(s) %s tiene(n) el mismo precio al indicado",E);
	}else{
		printf("No hay producto(s) con un precio mayor al indicado");
	}
}

void fraccion(producto * totalProductos, int cantidad){
	int L,P;
	float fraccion;
	L=(totalProductos->precio);
	P=(totalProductos->volumen);
	fraccion = (L/P);
	printf("La fraccion Precio Volumen es la siguiente %f",fraccion);
}

void venta(producto * totalProductos, int cantidad){
	int M,venta,asignacion;
	M = (totalProductos->precio);
	printf("Indique cuanto ganancia obtuvo en forma de dinero :\n");
	scanf("%d",&venta);
	asignacion = venta / M ;
	printf("Las N cantidades que se vendieron fueron %d",asignacion);
}

producto * agregar_producto(producto * totalProductos,int cantidad, producto nuevo_producto){

	producto * nuevos_productos = (producto*)malloc(sizeof(producto)*cantidad+1);
	int i =0;
	while ( i < cantidad){
		nuevos_productos[i] = totalProductos[i];
		i=i+1;

	}
	for(i=0;i<cantidad;i++){
		    nuevos_productos[cantidad] = solicitar_datos();
		    nuevos_productos[cantidad]= nuevo_producto;
		}
	free(totalProductos);
	return nuevos_productos;

}
/* ESTE APARTADO CORRESPONDE A UNA FUNCION NO IMPLEMENTADA. PERO TE DEJO LA IDEA BASE */

/*producto * agregar_dato(producto * totalProductos, int cantidad, producto añadido){
	producto * nuevo_arreglo_producto = (producto *)malloc(sizeof(producto)*cantidad+1);
	int i=0;
	cantidad = cantidad +1;
	for(i=0;i<cantidad;i++){
		nuevo_arreglo_producto[i].nombre= totalProductos[i].nombre;
		nuevo_arreglo_producto[i].numeroSerie= totalProductos[i].numeroSerie;
		nuevo_arreglo_producto[i].precio= totalProductos[i].precio;
		nuevo_arreglo_producto[i].peso= totalProductos[i].peso;
		nuevo_arreglo_producto[i].volumen= totalProductos[i].volumen;
		nuevo_arreglo_producto[i].cantidadDisponible= totalProductos[i].cantidadDisponible;
	}
	free(totalProductos);
	nuevo_arreglo_producto[cantidad].nombre = añadido.nombre;
	nuevo_arreglo_producto[cantidad].numeroSerie = añadido.numeroSerie;
	nuevo_arreglo_producto[cantidad].precio = añadido.precio;
	nuevo_arreglo_producto[cantidad].peso = añadido.peso;
	nuevo_arreglo_producto[cantidad].volumen = añadido.volumen;
	nuevo_arreglo_producto[cantidad].cantidadDisponible = añadido.cantidadDisponible;
	return nuevo_arreglo_producto;
}*/

int main(){
	int cantidad;
	printf("Ingrese la cantidad de productos que desea :\n");
	scanf("%d",&cantidad);
	producto* totalProductos = (producto *)malloc(sizeof(producto)*cantidad);
	int i;
	for(i=0;i<cantidad;i++){
		totalProductos[i]= solicitar_datos();
	}
	printf("Finalizando los registros...");
	printf("\n");
	printf("Abriendo el menu\n");
	printf("Por favor espere.......\n");
	printf(".......\n");
	printf("\n");
	printf("Bienvenido al menu principal\n");
	printf("1- Buscar producto por nombre o numero de serie\n");
	printf("2- Mostrar los nombres de los productos disponibles\n");
	printf("3- Mostrar los nombres de los productos con precio mayor a cierto numero ingresado\n");
	printf("4- Mostrar cual es el producto con mayor fraccion Precio/Volumen\n");
	printf("5- Agregar un nuevo producto\n");
	printf("6- Sacar por venta n unidades de un producto\n");
	printf("7- Mostrar los datos de todos los productos\n");
	printf("8- Cerrar el progama\n");
	int a,b;
	while(a!=8){
		switch(a){
			case 1:
					printf("¿Como desea buscar? Nombre[0] - Numero[1]\n");
					scanf("%d",&b);
					if (b==0){
						buscar_nombre(totalProductos,cantidad);
						printf("\n");
					}else if (b==1){
						buscar_numero_serie(totalProductos,cantidad);
						printf("\n");
					}else{
						printf("Coloce bien la opcion\n");
					}						
				break; 
					
			case 2:
					disponible(totalProductos,cantidad);
					printf("\n");
					break;
			
			case 3:
					precio_evaluar(totalProductos,cantidad);
					printf("\n");
					break;
					
			case 4:
					fraccion(totalProductos,cantidad);
					printf("\n");
					break;

		        case 5:	
					agregar_producto(totalProductos,cantidad,totalProductos[i-1]);
					break;
			
			case 6:
					venta(totalProductos,cantidad);
					printf("\n");
					break;
			
			case 7: 
					printf("\n");
					printf("Datos Iniciales\n");
					printf("\n");
					for(i=0;i<cantidad;i++){
						imprimir_datos(totalProductos[i]);
					}
					printf("\n");
					/*printf("Datos Agregados\n");
					for(i=0;i<cantidad;i++){
						imprimir_datos(totalProductos[i]);
					}
					printf("\n");
					*/	
					break;

			default:
					printf("\n");
					printf("AVERTENCIA ESTE ERROR SALDRA AL COLOCAR UNA OPCION INVALIDA!\n");
					printf("\n");
		}
		printf("Eliga una opcion para poder recorrer el menu\n");
		scanf("%d",&a);

	}
	if(a==8){
		printf("Cerrando el programa....\n");
	}
	//Liberacion de memoria
	free(totalProductos);

	return 0;
}
