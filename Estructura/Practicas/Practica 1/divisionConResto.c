//Ingresas dos valores, te devuelve el cociente y el resto

#include<stdio.h>

int dividendo;
int divisor;
int cociente;
int resto;
int logico;

void main(){
	logico = 1;
	while(logico == 1){
		printf("Ingrese el dividendo: ");
		scanf("%d",&dividendo);
		printf("Ingrese el divisor: ");
		scanf("%d",&divisor);
		printf("\n");
		cociente = dividendo / divisor;
		resto = dividendo % divisor;
		printf("Cociente: %d \n",cociente);
		printf("Resto: %d \n",resto);
		printf("Desea continuar? (1,0)\n");
		scanf("%d",&logico);
	}

}
