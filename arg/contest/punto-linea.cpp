#include<bits/stdc++.h>
/*Tranformar rectas en puntos*/

using namespace std;

struct Punto{
	int x,y;//(x,y)
};

struct Recta{
	int a,b;//y=ax+b
};

/*Unicamente se diferencian en los nombres, a excepcion de rectas verticales*/
/*
Rectas no verticles == funciones lineas == puntos del plano
pendiente mayor => coordenada x mayor
rectas paralelas => alineado en la vertical
rectas concurrentes => alineado salvo verticales
Evaluar y para un x dado (y=ax+b) => y=(a,b).(x,1)
Encontrar el punto de interseccion a 2 rectas, es evaluar la normal al vector formador por los 2 puntos
TEOREMA DE DICK WORTH
*/

struct Interval{
	int s,e;//start , end [s,e { ] , > }
};/*se puede utilizar e < s, en caso usemos circulos*/

/*
Los intervalos que se encuentran contenidos en otro intervalos, se representan dentro del area formada por las x',y',x=y, a partir del puntos
Uso de BIT 2D
*/



int main(){


	return 0;
}

