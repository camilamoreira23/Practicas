/*/El Ministerio de Transporte de un municipio desea evaluar una línea de colectivos que
recorre algunos de los barrios de su ciudad.
Esta línea de colectivos tiene paradas prefijadas en los distintos barrios de la misma.
Las paradas de colectivos están codificadas con un número entero de 1 a 10 y los barrios
están codificados con un carácter: ‘c’ Caballito, ‘f’ Flores, ‘p’ Palermo y ‘l’ Liniers.
Se conoce también en qué barrio está cada parada de colectivos:
 Parada Barrio
de 1 a 3 ‘l’ Liniers
de 4 a 5 ‘f’ Flores
de 6 a 7 ‘c’ Caballito
de 8 a 10 ‘p’ Palermo
Se desea desarrollar una aplicación en la cual se puedan registrar los datos del recorrido
de la línea de colectivos, para luego evaluar si cubre las necesidades de transporte
público de esos barrios.
Se conocen las paradas de colectivos correspondientes a su recorrido, y de cada parada
de colectivos se conoce el número de la misma:
Número de parada de colectivo (valor entero de 1 a 10).
La aplicación deberá tener las siguientes opciones:
Opción 1 – Ingresar datos de paradas de la línea de colectivos:
En esta opción, se deberá ingresar por teclado el número de una parada de colectivos.
Deberá encontrar el código de barrio al que pertenece el número de parada ingresado.
Luego, deberá llamar a una función que tenga al menos como parámetros el número de
parada y el código de barrio y 2 vectores, y guarde esos datos en los 2 vectores
respectivamente.
En esta opción se irán cargando de a una por vez y en orden las paradas de la línea de
colectivo.
Opción 2 – Consultas de la información sobre la línea de colectivos:
En esta opción, se deberá llamar a una función que tenga como parámetros al menos los
2 vectores cargados en la opción 1, y los utilice para informar los datos de cada parada y
lo siguiente:
a) Indicar la cantidad de paradas por barrio que tiene la línea de colectivos, y un
cartel que indique si todas las paradas de la línea son del mismo barrio o no.
b) Indicar con un cartel si la línea de colectivos comienza y finaliza su recorrido
en el mismo barrio, considerando que la cabecera y la terminal son
respectivamente la primera y última parada del recorrido en el orden que han
sido ingresadas. Si el resultado es sí, indicar además ese código de barrio.
Ejercicio para practicar
Opción 3 – Salir
Diseñar un algoritmo en lenguaje C. Considerar que los datos ingresados son válidos.
Usar aritmética de punteros en las funciones de opciones 1 y 2, para el manejo de
vectores./*/



#include <stdio.h>
#include <stdlib.h>

void carvectores(int num_p,int *pun_num,char codi_p,char *pun_cod,int j);
void informe(int *pum_num,char *pun_cod,int i);


int main() {
	int op=0,num_p=0,pun_num[50]={0},i=0;
	char codi_p,pun_cod[50]={' '};
	
	while(op!=3){
	printf("Ingrese opcion\n1.Ingresar datos de paradas de la linea de colectivos.\n2.Consultas de la informacion sobre la linea de colectivos\n3.Salir\n");
	scanf("%d",&op);
	
	switch(op){
			case 1:
				printf("\nIngrese numero de la parada de colectivo (1 a 10)\n");		
				scanf("%d",&num_p);	
					if (num_p>=1 && num_p<=3){
					printf("Liniers\n");
			        codi_p='l';
					}
					else if (num_p>=4 && num_p<=5){
					printf("Flores\n");
			        codi_p='f';
					}
					else if (num_p>=6 && num_p<=7){
					printf("Caballito\n");
			        codi_p='c';
					}
					else if (num_p>=8 && num_p<=10){
					printf("Palermo\n");
			        codi_p='p';
					}
				carvectores(num_p,pun_num,codi_p,pun_cod,i);
				i=i+1;
				getch();
		  		system("cls");
							
			break;
			
			case 2:
			
				informe(pun_num,pun_cod,i);				
			break;
			
			case 3:
				op=3;
			break;
				}
}
	return 0;
}

void carvectores(int num_p,int *pun_num,char codi_p,char *pun_cod,int j){
*(pun_num+j)=num_p;
*(pun_cod+j)=codi_p;
}

void informe(int *pum_num,char *pun_cod,int i){
int j=0,cant=0,cantl=0,cantf=0,cantc=0,cantp=0;
char barrioparadai=' ',barrioparadaf=' ';

for(j=0;j<i;j++){
cant++;
   printf("Nro de parada %d\t Barrio %c\n",*(pum_num+j),*(pun_cod+j));
	switch (*(pun_cod+j))
    {
    case 'l':
	cantl=cantl+1;
	break;	
	case 'f':
	cantf=cantf+1;
	break;	
	case 'c':
	cantc=cantc+1;
	break;	
	case 'p':
	cantp=cantp+1;
	break;	
	}	
	 // guardo el barrio de la primera y última parada
			 if (j==0) { barrioparadai=*(pun_cod+j);
			 }
			 
			 if (j==i-1) { barrioparadaf=*(pun_cod+j);
			 }
		
	}
    
	printf("Cantidad de barrio Liniers %d \nCantidad de barrio Flores  %d \nCantidad de barrio Caballito %d \nCantidad de barrio Palermo %d \n",cantl,cantf,cantc,cantp);
    
      if (cant==cantl || cant==cantf || cant==cantc || cant== cantp) {
        printf("Todas las paradas son del mismo barrio\n");}
        else  {printf("\nNo todas las paradas son del mismo barrio\n");}

     if(barrioparadai==barrioparadaf){
     	printf("Comienza y finaliza su recorrido en el mismo barrio\n",barrioparadai);
     	
	 }



}













