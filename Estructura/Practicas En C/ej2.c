#include <stdio.h>
#include <math.h>

int num1;
int num2;

void main(){
	printf("Ingrese dos numeros: \n");
	scanf("%d %d",&num1,&num2);
	if (num1 % num2 == 0){
		printf("El %d es divisor del %d. \n",num2, num1);
	}
	else{
		if(num2 % num1 == 0){
			printf("El %d es divisor del %d. \n",num1,num2);
		}
		else{
			printf("Los numeros no son divisibles. \n");
		}
	}
}