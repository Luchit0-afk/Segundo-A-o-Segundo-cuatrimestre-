#include <stdio.h>

#define max 250

typedef struct tArray{
	int cant;
	int a[max];
};

tArray arreglo;

int prueba;

//Make the array
tArray make (){
	tArray array;
	array.cant = 0;
	return array;
}

//returns if the list is empy or not
// 1 if succesfull
// 0 if list is not empty 
int is_empty (tArray array){
	if (array.cant == 0){
		return 1;
	}
	else{
		return 0;
	}
}

int main (){
	arreglo = make();
	prueba = is_empty(arreglo);
	return 0;
}




