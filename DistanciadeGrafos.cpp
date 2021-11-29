#include <bits/stdc++.h>
using namespace std;

vector<string> nodes = {"El Rosario",
												"Instituto del Petroleo",
												"Tacuba",
												"Hidalgo",
												"Tacubaya", 
												"Deportivo 18 de Marzo",
												"Centro Medico",
												"Mixcoac", 
												"Balderas",
												"Bellas Artes", 
												"Guerrero",
												"Martin Carrera",
												"Zapata", 
												"Chabacano",
												"Salto del Agua", 
												"Garibaldi", 
												"La Raza",  
												"Pino Suarez", 
												"Consulado",
												"Candelaria",
												"Ermita",
												"Santa Anita",
												"Oceania",
												"Morelos",
												"San Lazaro",
												"Jamaica",
												"Atlalilco",
												"Pantitlan"
};

const int MX = 1000;
vector<int> g[MX];
vector<bool> vis; //Marca los nodos ya visitados
vector<int> dist; //Almecena la distancia entre desde un nodo i hacia los demas

void bfs(int u) {
    queue<int> q;
    q.push(u);
    dist[u] = 0;
    while (q.size()) {
        u = q.front();
        q.pop();
        for (auto &v : g[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1; // aÃ±ade 1 a la distancia de su predecesor
                q.push(v);
            }
        }
    }
}


void addEdge(int u, int v){
	g[u].push_back(v);
	g[v].push_back(u);
}

void init(int n) {
    vis.assign(n+5, false);
    dist.assign(n+5, -1);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

int main(){
	int n = nodes.size();
	init(n);
	addEdge(25, 27);
	addEdge(24, 27);
	addEdge(23, 24);
	addEdge(22, 27);
	addEdge(22, 24);
	addEdge(21, 26);
	addEdge(21, 25);
	addEdge(20, 26);
	addEdge(19, 25);
	addEdge(19, 24);
	addEdge(19, 23);
	addEdge(18, 22);
	addEdge(18, 23);
	addEdge(17, 19);
	addEdge(16, 18);
	addEdge(15, 23);
	addEdge(15, 23);
	addEdge(14, 17);
	addEdge(13, 14);
	addEdge(13, 17);
	addEdge(13, 25);
	addEdge(13, 21);
	addEdge(13, 20);
	addEdge(12, 20);
	addEdge(11, 18);
	addEdge(10, 15);
	addEdge(10, 16);
	addEdge(9, 17);
	addEdge(9, 15);
	addEdge(9, 14);
	addEdge(8, 14);
	addEdge(7, 12);
	addEdge(6, 13);
	addEdge(6, 8);
	addEdge(6, 12);
	addEdge(5, 11);
	addEdge(5, 16);
	addEdge(4, 7);
	addEdge(4, 6);
	addEdge(4, 8);
	addEdge(3, 9);
	addEdge(3, 10);
	addEdge(3, 8);
	addEdge(2, 3);
	addEdge(2, 4);
	addEdge(2, 3);
	addEdge(1, 16);
	addEdge(1, 5);
	addEdge(1, 16);
	addEdge(1, 16);
	addEdge(0, 2);
	addEdge(0, 1);
	int ini = 0; 
	bfs(ini); //lamado del bfs, para recorrer distancias minimas (grafo no ponderado)
	cout<<"Distancias desde la ciudad "<<nodes[ini]<<" hacia las demas ciudades:"<<endl;
	for(int i = 0; i<n; i++){
		if(i == ini)continue;
		cout<<"Desde "<<nodes[ini]<<" hasta "<<nodes[i]<<" con una distancia de: "<<dist[i]<<endl;
	}
}
