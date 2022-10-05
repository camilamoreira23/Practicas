#include <stdio.h>
#include <string.h>

int f_tramo();
void op_incorrecta();
int f_grua();
int emergencias();
int cont_grua1=0,cont_grua2=0,cont_grua3=0;
int cont_emerg1=0,cont_emerg2=0,cont_emerg3=0,cont_heridos1=0,cont_heridos2=0,cont_heridos3=0;
char operador[15];

void main(void)
{
	int opc=0,opc2=0,cont_llamadas=0,aux_tramo,cont_emerg=0,cont_grua=0;
	float porc_grua,porc_emerg;
	
	
	cont_llamadas=0;
	do{
		system("cls");                                            //Menu principal del proyecto
		printf("\n--< Bienvenidos a Emergencias >--\n\n");
		printf(" -- MENU DE OPCIONES --\n\n");
		printf("1- Ingrese Operador\n");
		printf("2- Recepcion de llamadas\n");
		printf("3- Datos estadisticos del dia\n");
		printf("4- Salir\n\n");
		printf("Opcion a escoger:  ");
		scanf("%d",&opc);
		
		switch(opc){
			case 1:
				system("cls");                                    //Opcion en donde se ingresa el usuario
				printf("Ingrese nombre del operador: "); 
				scanf("%s",operador);
				break;
			case 2:
				system("cls");                                    //Opcion que accede al 2do menu
				printf("--< Bienvenidos a Emergencias >--\n\n");  //de recepccion de llamadas
				printf("  -- RECEPCION DE LLAMADAS -- \n");
				printf("OPERADOR: %s\n\n",operador); 
				printf("1- Emergencia\n");
				printf("2- Grua\n");
				printf("3- Volver al menu principal\n\n");
				printf("Opcion a escoger:  ");
				scanf("%d",&opc2);
				switch (opc2){
					case 1:
						cont_llamadas++;
						cont_emerg++;
						aux_tramo=f_tramo("tramo");													//Funcion que asigna el tramo dependiendo del km.
						emergencias("tramo");	//Funcion que asigna el movil dependiendo del tramo
						break;														//y si hay heridos se pide ambulancia y policia.
					case 2:	
						cont_llamadas++;
						cont_grua++;
						aux_tramo=f_tramo("tramo");
						f_grua("aux_tramo");		//Funcion que asigna la grua dependiendo del tramo.
						break;
					case 3:
						break;
					default:
		 				op_incorrecta();	//Funcion del mensaje de opcion incorrecta.
						break;	
				}
				break;
			case 3:			//Al usar porcentajes no se puede dividir por cero, por eso se implemento el if
		        system("cls");
		        if (cont_llamadas==0){
				   	printf("*** No se registran llamadas ****");
				   	getch();}
		        else{
					porc_grua=(cont_grua*100)/cont_llamadas;
					porc_emerg=(cont_emerg*100)/cont_llamadas;
					printf("  -- DATOS ESTADISTICOS -- \n\n");                           //Insertar funcion con los datos estadisticos
					printf("\n			LLAMADAS ENTRANTES: %d\n",cont_llamadas);
					printf("\n< SERVICIOS DE GRUAS: %d - %.2f%%>	/	< SERVICIOS DE EMERGENCIAS: %d - %.2f%%>",cont_grua,porc_grua,cont_emerg,porc_emerg);
					printf("\n< GRUA 1: %d - %.2f%% >		/	< Movil 1: %d 		   >",cont_grua1,cont_emerg1);
					printf("\n< GRUA 2: %d         >		/	< Movil 2: %d 		   >",cont_grua2,cont_emerg2);
					printf("\n< GRUA 3: %d         >		/	< Movil 3: %d 		   >",cont_grua3,cont_emerg3);
					getch();}
		        break;
		    case 4:
				break;
			default:
				op_incorrecta();	//Funcion del mensaje de opcion incorrecta.
				break;	
		}
	}while(opc!=4);
}

void op_incorrecta(void){			//Funcion que pone en pantalla OPCION INCORRECTA
	system("cls");
	printf(" Opcion incorrecta!! \n Ingresar una opcion valida, por favor !!!");
	getch();
	}
	
int f_tramo(int llamada){					//Funcion que determina el tramo al que pertenece 
	float km=0;					//el km ingresado
	int tramo;
		
	system("cls");
	printf("\nIngrese el Kilometro: ");     
	scanf("%f",&km);
	if(km>=1 && km <=20)
		tramo=1;
	else
		if(km>=21 && km<=40)
			tramo=2;
		else
			if(km>=41 && km<=60)
				tramo=3;
			else
				{printf("--- FUERA DE JURISDICCION ---");
				km==0;
				getch();}
	return tramo;
}

int f_grua(int t,int c_g1,int c_g2,int c_g3){				//Funcion que asigna una grua segun el tramo
	int tramo;					//Notese que se asigna nuevamente la variable que toma de afuera
	system("cls");
	                            
	if(tramo==1){
		printf("SE DIRIGE: GRUA 1");
		cont_grua1++;}
	else
		if(tramo==2){
			printf("SE DIRIGE: GRUA 2");
			cont_grua2++;}
		else
			if(tramo==3){
				printf("SE DIRIGE: GRUA 3");
				cont_grua3++;}
	getch();
	return (cont_grua1,cont_grua2,cont_grua3);
}

int emergencias(int t,int c_e1,int c_e2,int c_e3,int c_h1,int c_h2,int c_h3)	//Funcion asigna un Movil de Seg, Vial dependiendo del km
{																				//Y solicita ambulancia y policia si hay heridos
	int tramo,total_movil,total_herido;
	char heridos[2];
		
	system("cls");
	
	if (tramo!=0){
		printf("\nHay heridos (s/n): ");     
		scanf("%s",&heridos);}
	switch(tramo){
		case 1:
			printf("Se dirige: Movil 1 ");
			cont_emerg1++;
			if ((strcmp(heridos,"s")==0)||(strcmp(heridos,"S")==0)){
				printf("\nSe envio Ambulancia y Policia.");
				cont_heridos1++;}
			getch();
			break;
		case 2:
			printf("Se dirige: Movil 2 ");
			cont_emerg2++;
			if ((strcmp(heridos,"s")==0)||(strcmp(heridos,"S")==0)){
				printf("\nSe envio Ambulancia y Policia.");
				cont_heridos2++;}
			getch();
			break;
		case 3:
			printf("Se dirige: Movil 3 ");
			cont_emerg3++;
			if ((strcmp(heridos,"s")==0)||(strcmp(heridos,"S")==0)){
				printf("\nSe envio Ambulancia y Policia.");
				cont_heridos3++;}
			getch();
			break;
	total_movil==cont_emerg1+cont_emerg2+cont_emerg3;
	total_herido==cont_heridos1+cont_heridos2+cont_heridos3;
	return (total_movil,total_herido);
	}
	

}
