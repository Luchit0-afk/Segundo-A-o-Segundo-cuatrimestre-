//pila polimorfica en c

#include <stdio.h>
#include <string.h>
#define max 250

typedef struct tPila{
	int cant;
	void* a[max];
}tPila;

tPila arreglo;
void *puntero; 
int inpNum;
char inpChar[1];
char inpString[120];
float inpFloat;
char add[1];


//Make de pila
tPila init(){
	tPila arreglo;
	arreglo.cant = 0;
	return arreglo;
}

//return if the list is empty
//1 empty
//0 not empty
int empty (tPila array){
	if(array.cant == 0){
		return 1;
	}
	else{
		return 0;
	}
}

//inserts the elem in the beginning of the list
tPila ins(tPila array,void* elem){
//Start the action
	if(array.cant == 0){
		//printf("prueba");
		array.a[0] = elem;
		array.cant = array.cant + 1;
	}
	else{
		int i;
		for(i = 0 ; i < array.cant ;i++){
			array.a[i] = array.a[i+1];
		}	
		array.a[0] = elem;
		array.cant = array.cant + 1;
	}
	return array;
}

//delete the elem in the beginning of the list
tPila del(tPila array, void* elem){
	if(array.cant == 0){
		printf("The list is empty\n");
	}
	else{
		int i;
		for(i = 1; i < array.cant ; i--){
			array.a[i-1] = array.a[i]; 
		}
		array.cant = array.cant - 1;
	}
	return array;
}

//return the firts element
void* tope(tPila array){
	return array.a[0];
}

//show the list
void show(tPila array){
	printf("[ ");
	int i;
	for(i = 0 ; i < array.cant ; i++){
		printf("%f",*(float *)array.a[i]);
	}
	printf("]\n");
}


void main(){
	arreglo = init();
	printf("-----PILA POLIMORFICA V 1.0------\n");
	printf("What do you want to add?? \n");
	printf("-I: Intergers\n");
	printf("-C: Characters\n");
	printf("-S: Strings\n");
	printf("-F: Float\n");
	gets(add);
	fflush(stdin);
	//printf("%s\n",add);
	if(strcmp(add,"i") == 0 || strcmp(add,"I") == 0){
		printf("Input the interger:");
		scanf("%d",&inpNum);
		fflush(stdin);
		puntero = &inpNum;
	}
	else{
		if(strcmp(add,"c") == 0 || strcmp(add,"C") == 0){
			printf("Input the character:");
			gets(inpChar);
			fflush(stdin);
			puntero = inpChar;
		}
		else{
			if(strcmp(add,"s") == 0 || strcmp(add,"S") == 0){
				printf("Input the string:");
				gets(inpString);
				fflush(stdin);
				puntero = inpString;
			}
			else{
				if(strcmp(add,"f") == 0 || strcmp(add,"F") == 0){
					printf("Input the float:");
					scanf("%f",&inpFloat);
					fflush(stdin);
					puntero = &inpFloat;
				}
				else{
					printf("Error \n");
				}
			}
		}
	}
	arreglo = ins(arreglo,puntero);
	show(arreglo);
}
