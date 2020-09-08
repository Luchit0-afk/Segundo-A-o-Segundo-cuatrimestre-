/* El juego de dados conocido como “craps” (tiro perdedor) es muy popular, realice un programa que simule dicho juego, a
continuación se muestran las reglas para los jugadores.
• Un jugador tira dos dados. Cada dato tiene seis caras. Las caras contienen 1, 2, 3, 4, 5 y 6 puntos.
• Una vez que los dados se hayan detenido, se calcula la suma de los puntos en las dos caras superiores.
• Si a la primera tirada, la suma es 7, o bien 11, el jugador gana.
• Si a la primera tirada la suma es 2, 3 o 12 (conocido como “craps”), el jugador pierde (es decir la casa “gana”).
• Si a la primera tirada la suma es 4, 5, 6, 8, 9 ó 10, entonces dicha suma se convierte en el “punto” o en la “tirada”.
• Para ganar, el jugador deberá continuar tirando los dados hasta que haga su “tirada”.
• El jugador perderá si antes de hacer su tirada sale una tirada de 7. 
*/

#include <stdio.h>
#include <stdlib.h>

int dado1;
int dado2;
int sumadados;
int tiradaNueva;
int ganado; // 0 es seguir jugando, 1 gana el jugador, 2 gana la maquina
int tirada1 ;
int tirada2 ;
#define craps1 2
#define craps2 3 
#define craps3 12

void main(){
	srand (time(NULL));
	ganado == 0;
	tiradaNueva == 0;
	tirada1 = 7;
	tirada2 = 11;
	while (ganado == 0){
		printf("Tira los dados: \n \n");
		dado1 = tirarDado();
		dado2 = tirarDado();
		printf("Los dados salieron: %d %d \n \n",dado1,dado2);
		sumadados = dado1 + dado2;
		printf("La suma de los dados son %d \n \n",sumadados);
		if(sumadados == tirada1 || sumadados == tirada2 || sumadados == tiradaNueva){
			printf("Ganaste!!! \n");
			ganado = 1;
		}
		else {
			if(sumadados == craps1 || sumadados == craps2 || sumadados == craps3){
				printf("Perdiste, gana la maquina :( \n");
				ganado = 2;
			}
			else{
				tiradaNueva = sumadados;
				printf("La nueva y unica tirada ganadora es: %d \n",tiradaNueva);
				tirada1 = 0;
				tirada2 = 0;

			}
		}
	}
	
}

int tirarDado(){
	return rand()%6+1;
}

void Inter