#include <stdio.h>

int num;

void main(){
	num == 0;
	printf("Ingrese un numero: ");
	scanf("%d",&num);
	printf("---.Secuencia---- \n");
	while (num != 1){
		if(num % 2 == 0){
			num = num / 2;
			printf("%d-",num);
		}
		else{
			num = num * 3 + 1;
			printf("%d-",num);
		}
	}
}
