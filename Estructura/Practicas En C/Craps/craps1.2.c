/* El juego de dados conocido como "craps" (tiro perdedor) es muy popular, realice un programa que simule dicho juego, a
continuacion se muestran las reglas para los jugadores.
- Un jugador tira dos dados. Cada dato tiene seis caras. Las caras contienen 1, 2, 3, 4, 5 y 6 puntos.
- Una vez que los dados se hayan detenido, se calcula la suma de los puntos en las dos caras superiores.
- Si a la primera tirada, la suma es 7, o bien 11, el jugador gana.
- Si a la primera tirada la suma es 2, 3 o 12 (conocido como "craps"), el jugador pierde (es decir la casa "gana").
- Si a la primera tirada la suma es 4, 5, 6, 8, 9 o 10, entonces dicha suma se convierte en el "punto" o en la "tirada".
- Para ganar, el jugador deberá continuar tirando los dados hasta que haga su “tirada”.
- El jugador perderá si antes de hacer su tirada sale una tirada de 7. 
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int volvJugL;
int dinero;
int apuesta;

void main(){
	Interfaz();
	volvJugL = 0;
	dinero = 200;
	printf("\nA jugar... \n \n");
	while (volvJugL == 0){
		printf("Tienes %d para apostar. \n",dinero);
		printf("Cuantos deseas poner en la mesa? ");
		scanf("%d",&apuesta);
		juego(&dinero,&apuesta);
		if (dinero == 0){
			printf("No te queda mas dinero para jugar. \n");
			volvJugL = 1;
		}
		else{
			if(dinero <= 0){
				printf("Nos debe dinero, deberas pagarle al creador. \n");
				volvJugL = 1;
			}
			else{
				volvJugL = volverAJugar(dinero);
			}
		}

	}
}

void Interfaz(){
//local lexicon
	char reglas;
	int reglaslogico;
	char buf[128];
//Start the accion	
	reglaslogico = 0;
	printf("-------------------------------------------");
	printf("\n------------Juego de Craps V 1.2-----------\n");
	printf("-------------------------------------------\n\n");
	while (reglaslogico == 0){
		printf("Conoces las reglas? (Y/N)\n");
		while (fgets(buf, sizeof buf, stdin)) {
        	reglas = buf[0];
        	if (reglas == 'y' || reglas == 'Y' || reglas == 'n' || reglas == 'N') {
            	if (buf[1] == '\n') break;
        	}
        	printf("Ingrese Y para jugar y N para aprender a jugar.\n");
   		} 
		if(reglas == 'y' || reglas == 'Y'){
			reglaslogico = 1;
		}
		else{
			if(reglas == 'n' || reglas == 'N'){
				reglasInterfaz();
				reglaslogico = 1;
			}
			else{
				printf("ERROR \n");
			}
		}
	}
}

int tirarDado(){
	srand (time(NULL));
	return rand()%6+1;
}

void juego(int *dinero, int *apuesta){
//local lexicon
	int dado1,dado2,sumadados;
	int ganado; //0 seguir jugando, 1 gana el jugador, 2 gana la maquina
	int tirada1,tirada2,tiradaNueva;
	int craps1,craps2,craps3;
//Start the action
	tiradaNueva = 0;
	ganado = 0;
	tirada1 = 7;
	tirada2 = 11;
	craps1 = 2;
	craps2 = 3;
	craps3 = 12;
	while(ganado == 0){
		printf("Pulsa Enter para tirar los dados. \n\n");
		getchar();
		dado1 = tirarDado();
		dadoInterfaz(dado1);
		dado2 = tirarDado();
		dadoInterfaz(dado2);
		sumadados = dado1 + dado2;
		if(sumadados == tirada1 || sumadados == tirada2 || sumadados == tiradaNueva){
			ganadorInterfaz(sumadados);
			*dinero = *dinero + *apuesta;
			printf("Tu actual dinero es %d \n",*dinero);
			ganado = 1;
		}
		else{
			if(sumadados == craps1 || sumadados == craps2 || sumadados == craps3){
				perdedorInterfaz(sumadados);
				*dinero = *dinero - *apuesta;
				printf("Tu actual dinero es %d \n",*dinero);
				ganado = 2;
			}
			else{
				tiradaNueva = sumadados;
				nuevaTirada(tiradaNueva);
				tirada1 = 0;
				tirada2 = 0;
				craps1 = 0;
				craps2 = 0;
				craps3 = 7;
			}
		}
	}
}

int volverAJugar(int dinero){
//Local lexicon
	char buf1[128];
	char volvJug;
//Start accion	
	printf("Desea volver a jugar?(Y/N) \n");
	while (fgets(buf1, sizeof buf1, stdin)) {
       	volvJug = buf1[0];
       	if (volvJug == 'y' || volvJug == 'Y' || volvJug == 'n' || volvJug == 'N') {
       		if (buf1[1] == '\n') break;
       	}
       	printf("Ingrese Y para volver a jugar y N para salir el juego.\n");
   	} 
   	if (volvJug == 'n' || volvJug == 'N'){
   		printf("\nAdios!! \n");
   		printf("Te retiras con %d\n",dinero);
   		return 1;
   	}
   	else{
   		printf("\nBuena suerte!!! :) \n\n");
   		return 0;
   	}
}

void ganadorInterfaz(int num){
	printf("Sacaste %d \n \n",num);
	printf("x x x x x x x x x x x x x\n");
	printf("x x x x x x x x x x x x x\n");
	printf("x x x   GANADOR!!!  x x x\n");
	printf("x x x  FELICIDADES  x x x\n");
	printf("x x x x x x x x x x x x x\n");
	printf("x x x x x x x x x x x x x\n\n");
}

void perdedorInterfaz(int num){
	printf("Sacaste %d \n \n",num);
	printf(":C :C :C :C :C :C :C :C \n");
	printf(":C :C :C :C :C :C :C :C \n");
	printf(":C :C  PERDISTE!! :C :C\n");
	printf(":C :C LA CASA GANA   :C\n");
	printf(":C :C :C :C :C :C :C :C \n");
	printf(":C :C :C :C :C :C :C :C \n\n");
}

void nuevaTirada(int tirada){
	printf("La nueva tirada es: %d \n\n",tirada);
}

void dado1Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x               x\n");
	printf("x               x\n");
	printf("x      xxx      x\n");
	printf("x      xxx      x\n");
	printf("x      xxx      x\n");
	printf("x               x\n");
	printf("x               x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dado2Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x          xxx  x\n");
	printf("x          xxx  x\n");
	printf("x          xxx  x\n");
	printf("x               x\n");
	printf("x  xxx          x\n");
	printf("x  xxx          x\n");
	printf("x  xxx          x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dado3Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x               x\n");
	printf("x      xxx      x\n");
	printf("x      xxx      x\n");
	printf("x      xxx      x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dado4Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x               x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dado5Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x      xxx      x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x  xxx     xxx  x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dado6Interfaz(){
	printf("xxxxxxxxxxxxxxxxx\n");
	printf("x               x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x               x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x  xxx xxx xxx  x\n");
	printf("x               x\n");
	printf("xxxxxxxxxxxxxxxxx\n\n");
}

void dadoInterfaz(int num){
	switch(num){
		case 1 : dado1Interfaz();
		break;
		case 2 : dado2Interfaz();
		break;
		case 3 : dado3Interfaz();
		break;
		case 4 : dado4Interfaz();
		break;
		case 5 : dado5Interfaz();
		break;
		case 6 : dado6Interfaz();
		break;
	}
}

void reglasInterfaz(){
	printf("Te explicaremos el juego, a continuacion: \n");
	printf("-Un jugador tira dos dados. \n");
	printf("-Una vez que los dados se hayan tirada se calcula la suma \n");
	printf(" de los puntos en las dos caras \n" );
	printf("-Si a la primera tirada, la suma es 7, o bien 11, el jugador gana.\n");
	printf("-Si a la primera tirada la suma es 2, 3 o 12 el jugador pierde\n");
	printf("-Si a la primera tirada la suma es 4, 5, 6, 8, 9 o 10 \n");
	printf(" entonces dicha suma se convierte en la tirada.\n");
	printf("-Para ganar, el jugador debera continuar tirando los dados \n");
	printf(" hasta que haga su tirada.\n");
	printf("-Ahora que sabes jugar, aprieta Enter para continuar.\n");
	getchar();
}
