#include <iostream>
using namespace std;

const int N=1e3; //Numero maximo de nodos
int nodos, ars;
int graph[N][N];
bool visited[N];


//Recorrido DFS, por defecto imprimira los nodos a los que el nodo U puede llegar (al inicio U = source)
void dfs(int u) {
    visited[u] = true;
    for(int i=0; i<nodos; i++){
		if(!visited[i] && graph[u][i] == 1){
			cout<<i + 1<<" ";
			dfs(i);
		}
	}
}


int main() {
	cout<<"Ingrese el numero de nodos y aristas: ";
	cin>>nodos>>ars; //lectura del numero de nodos y aristas
	
	/**
	 * Creacion de la matriz de adyacencia
	 */
    for(int i=0; i<ars; i++){
		int u, v;
		cin>>u>>v;
		u--, v--;
		graph[u][v] = 1;
		graph[v][u] = 1;
	}
	
	/**
	 * Source es el nodo inicial para empezar el recorrido
	 * el nodo source debera tener un valor entre 1 y el numero leido en la variable nodos
	 */
	cout<<"Ingrese el nodo en donde comezara el recorrido: ";
	int source;
	cin>>source;
	cout<<"El recorrido desde el nodo "<<source<<" es: ";
	cout<<source<<" --> ";
	dfs(source - 1);
	return 0;
}