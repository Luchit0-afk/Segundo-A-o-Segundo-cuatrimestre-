//Funcion de akerman

#include <stdio.h>

int m;
int n;
int res;

void main(){
	printf("Ingrese dos numero: ");
	scanf("%d",&m);
	scanf("%d",&n);
	res = akerman(m,n);
	printf("La funcion akerman para m = %d y n = %d es: %d \n",m,n,res);

}

int akerman (int m,int n){
	if (m == 0){
		return n + 1;
	}
	else{
		if(m > 0 && n == 0){
			return akerman(m-1,1);
		}
		else{
			if(m > 0 && n > 0){
				return akerman(m - 1, akerman(m,n - 1));
			}
			else{
				printf("Error \n");
				return 0;
			}
		}
	}
}