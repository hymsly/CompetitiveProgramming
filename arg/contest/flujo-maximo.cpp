#include<bits/stdc++.h>
/*FLUJO MAXIMO*/
using namespace std;

/*
	Ford-Fulkerson O(maxFlow*E),O(n*m^2)
	Dinic O(n^2*m), mas rapido que Ford, pero es mas implementativo
*/
/*
	MinCut
	Costo minimo de separar la S y T en la red
	El valor del corte minimo coincide con el flujo maximo
	De la red residual corremos un dfs, y los nodos a los cuales se llega a la traves de S, pertenecen a su grupo,
*/
/*
	En caso se limita el flujo por un nodo, entonces:
	Se duplica en nodo, y se generea una nueva aristra
	v -> v' (con capacidad el limite), todos los in van a v, y todos los out van a v'
*/

/*
	PARA DAG's
	DILWORTH's Theorem
	cadena => conjuntos de nodos tal que hay camina de uno a otro
	anticadena => conjuntos de nodos incomparables
	Anticadena de mayor tamaño === La menor particiion en cadenas de los nodos del grafo
*/

int main(){


	return 0;
}

