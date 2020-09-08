#include <stdio.h>

#define max 250

typedef struct tArray{
	int cant;
	int a[max];
}tArray;

tArray arreglo;
int prueba;

//Make the array(tested)
tArray make (){
	tArray array;
	array.cant = 0;
	return array;
}

//returns if the list is empy or not
// 1 if succesfull
// 0 if list is not empty (tested)
int is_empty (tArray array){
	if (array.cant == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//adds an element at the beginning of the list(tested)
tArray add(tArray *array, int elem){
	int i;
	for(i = array->cant - 1; i >= 0;i--){
		array->a[i + 1] = array->a[i];
	}
	array->a[0] = elem;
	array->cant = array->cant + 1;
}

//inserts an element in a position in the list
//i assume what the pos is adequate (tested)
void ins(tArray *array, int pos, int elem){
	array->a[pos] = elem;
}

//adds an element at the end of the list(tested)
void end(tArray *array, int elem){
	array->a[array->cant] = elem;
	array->cant = array->cant + 1;
}

//remove the head the list
void bhd(tArray *array){
	int i;
	for(i = 0; i < array->cant - 1;i++){
		array->a[i] = array->a[i+1];
	}
	array->cant = array->cant - 1;
}

//return the element at the indicated position
//the position should the adequeate(tested)
int at(tArray array, int pos){
	return array.a[pos];
}

//delete an element in the indicated position
//the position should the adequeate(tested)
void del(tArray *array,int pos){
	int i;
	for(i = pos; i < array->cant - 1;i++){
		array->a[i] = array->a[i+1];
	}
	array->cant = array->cant - 1;
}

//the reverse list(tested)
tArray reverse(tArray array){
	int i;
	tArray arrayR;
	arrayR = make();
	for(i = 0; i < array.cant;i++){
		add(&arrayR,array.a[i]);
	}
	arrayR.cant = array.cant;
	return arrayR;
}

//returns the firts element a non-empty list
int hd(tArray array){
	return array.a[0];
}

//delete the firts element a list
void tl(tArray *array){
	del(array,0);
}

//Show the array(Testeada)
void show(tArray array){
	int i;
	printf("\n");
	printf("[");
	for(i = 0; i < array.cant ; i++){
		printf("%d ",array.a[i]); 
	}
	printf("]");
}

void main (){
	arreglo = make();
	int i;
	for(i = 0; i < 10 ;i++){
		arreglo.a[i] = i;
		arreglo.cant = arreglo.cant + 1;
	}
	show(arreglo);
	ins(&arreglo,2,15);
	show(arreglo);
	end(&arreglo,10);
	show(arreglo);
	add(&arreglo,-1);
	show(arreglo);
	bhd(&arreglo);
	show(arreglo);
	printf("\nLa pos es: %d",at(arreglo,2));
	del(&arreglo,2);
	show(arreglo);
	tArray lReverse;
	lReverse = reverse(arreglo);
	show(lReverse);
	show(arreglo);

}




