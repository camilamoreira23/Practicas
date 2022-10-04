

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













