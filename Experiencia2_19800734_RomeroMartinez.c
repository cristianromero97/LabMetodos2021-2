#include <stdio.h>
/*
* Autor : Cristian Romero
* Seccion : L-1 
* Curso : Metodos de programacion
*------------------------------------------------------------------------------------------------------------------
* Instrucciones: Esta experiencia consta del acertijo de cruzar al otro lado del rio.
* Para ello contara con un pato, zorro, trigo y una unica bote donde se podran llevar a dos individuos a la vez,
* es decir, usted mismo y un animal o objeto. Hay ciertas reglas como que un animal no puede quedarse con otro, o
* un objeto no puede quedarse con otro y la idea del problema es que todos pasen el rio....
---------------------------------------------------------------------------------------------------------------------
*/
int main(){

	int a;
	printf("Bienvenido al menu principal\n");
	printf("1-cruzar pato\n");
	printf("2-cruzar zorro\n");
	printf("3-cruzar trigo\n");
	printf("4-cruzar solo\n");
	printf("5-abandonar\n");
	while(a!=5 && a!=1){
	   switch(a){
		case 2:
		     printf("No puedes dejar al pato con el trigo\n");
		     break;
		case 3:
		     printf("No puedes dejar al zorro con el pato\n");
		     break;
		case 4:
		     printf("No puedes dejar todo atras\n");
		     break;
		default:
		     printf("Error no existe esa opcion\n");
	   }
         printf("Escoga una opcion : ");
	 scanf("%d",&a);
         }
	 if(a==5){
		printf("Derrota");
	 }
	 if(a==1){
		printf("Haz cruzado con el pato el rio\n");
		printf("\n");
		while(a!=5 && a!=4){
	  		 switch(a){
				case 1:
		     			printf("Avertencia no puedes colocar 1 nuevamente\n");
		     			break;
				case 2:
		     			printf("No hay zorro en esta parte del rio\n");
		     			break;
				case 3:
		     			printf("No hay trigo en esta parte del rio\n");
		     			break;
				default:
		     			printf("Error no existe esa opcion\n");
	   		}
         	printf("Escoga una opcion : ");
	 	scanf("%d",&a);
         	}
		if(a==5){
			printf("Derrota");
	 	}
		if(a==4){
			printf("Haz cruzado solo dejando al pato en la otra parte del rio\n");
			printf("\n");
			while(a!=5 && a!=3){
	  		 	switch(a){
					case 1:
		     				printf("No hay pato en esta parte del rio\n");
		     				break;
					case 2:
		     				printf("No puedes llevarte al zorro debido al pato que esta al otro lado\n");
		     				break;
					case 4:
		     				printf("Avertencia no puedes colocar 4 nuevamente\n");
		     				break;
					default:
		     				printf("Error no existe esa opcion\n");
	   			}
         		printf("Escoga una opcion : ");
	 		scanf("%d",&a);
         		}
			if(a==5){
				printf("Derrota");
	 		}
			if(a==3){
			    printf("Haz cruzado con el trigo\n");
			    printf("\n");
			    while(a!=5 && a!=1){
	  		 	   switch(a){
					 case 3:
		     				printf("Avertencia no puedes colocar 3 nuevamente\n");
		     				break;
					 case 2:
		     				printf("No hay zorro en esta parte\n");
		     				break;
					 case 4:
		     				printf("No valdria la pena el viaje\n");
		     				break;
					 default:
		     				printf("Error no existe esa opcion\n");
	   			  }
         		  printf("Escoga una opcion : ");
	 		  scanf("%d",&a);
         		  }
			  if(a==5){
				printf("Derrota");
	 		  }
			  if(a==1){
			  	 printf("Haz cruzado con el pato devuelta\n");
			   	 printf("\n");
			    	 while(a!=5 && a!=2){
	  		 	   	switch(a){
					 	case 3:
		     					printf("No hay trigo en esta parte\n");
		     					break;
						 case 1:
		     					printf("Avertencia no puedes colocar 1 nuevamente\n");
		     					break;
						 case 4:
		     					printf("No valdria la pena el viaje\n");
		     					break;
						 default:
		     					printf("Error no existe esa opcion\n");
	   			 	 }
         		 	printf("Escoga una opcion : ");
	 		 	scanf("%d",&a);
         		 	}
			  	if(a==5){
					printf("Derrota");
	 		 	}
				if(a==2){
				  	printf("Haz cruzado con el zorro al otro lado\n");
			   	 	printf("\n");
			    		while(a!=5 && a!=4){
	  		 	   		switch(a){
					 		case 3:
		     						printf("No hay trigo en esta parte\n");
		     						break;
							case 2:
		     						printf("Avertencia no puedes colocar 2 nuevamente\n");
		     						break;
						 	case 1:
		     						printf("No pato en esta parte\n");
		     						break;
						 	default:
		     						printf("Error no existe esa opcion\n");
	   			 	 	}
         		 		printf("Escoga una opcion : ");
	 		 		scanf("%d",&a);
         		 		}
			  		if(a==5){
						printf("Derrota");
	 		 		}
					if(a==4){
					    printf("Haz cruzado solo dejando todo al zorro y el trigo al otro lado\n");
					    printf("\n");
					    while(a!=5 && a!=1){
	  		 				switch(a){
								case 3:
		     							printf("En esta parte no hay trigo\n");
		     							break;
								case 2:
		     							printf("En esta parte no hay zorro\n");
		     							break;
								case 4:
		     							printf("Avertencia no puedes colocar 4 nuevamente\n");
		     							break;
								default:
		     							printf("Error no existe esa opcion\n");
	   						}
         				   printf("Escoga una opcion : ");
	 				   scanf("%d",&a);
         				   }
					   if(a==5){
						printf("Derrota");
	 				   }if(a==1){
						printf("Victoria\n");
						printf("\n");
			  		   }
				     }
			      } 
			   }
			}
		}
	 }
	 if(a==5){
		printf("Derrota");
	 }
 return 0;
}