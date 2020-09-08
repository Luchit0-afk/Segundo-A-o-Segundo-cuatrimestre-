#include <stdio.h>

int num;
#define min 100
#define max 200

void main (){
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	if(min<num && num<max){
		printf("El numero es mayor que %d y menor que %d \n",min,max);
	}
	else{
		printf("El numero puede ser mayor igual que %d o menor igual que %d \n",max,min);
	}
}
