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
}

//Estructura para representar una arista con peso
struct edge {
    int v, w;
    bool operator < (const edge &o) const {
        return o.w < w;
    }
};


const int MX = 1000;
vector<edge> g[MX];
vector<bool> vis; //Marca los nodos ya visitados
vector<int> dist; //Almecena la distancia entre desde un nodo i hacia los demas :D



void dijkstra(int u) {
    priority_queue<edge> pq;
    pq.push({u, 0});
    dist[u] = 0;
    while (pq.size()) {
        u = pq.top().v; pq.pop();
        if (!vis[u]) {
            vis[u] = true;
            for (auto &ed : g[u]) {
                int v = ed.v;
                if (!vis[v] && dist[v] > dist[u] + ed.w) {
                    dist[v] = dist[u] + ed.w;
                    pq.push({v, dist[v]});
                }
            }
        }
    }
}



void addEdge(int u, int v, int w){
	g[u].push_back({v, w});
	g[v].push_back({u, w});
}

void init(int n) {
		int inf = 1e9;
    vis.assign(n+5, false);
    dist.assign(n+5, inf);
    for (int i = 0; i <= n; i++) {
        g[i].clear();
    }
}

int main(){
	int n = nodes.size();
	init(n);
	addEdge(25, 27, 4);
	addEdge(24, 27, 5);
	addEdge(23, 24, 0);
	addEdge(22, 27, 2);
	addEdge(22, 24, 2);
	addEdge(21, 26, 5);
	addEdge(21, 25, 0);
	addEdge(20, 26, 1);
	addEdge(19, 25, 1);
	addEdge(19, 24, 0);
	addEdge(19, 23, 0);
	addEdge(18, 22, 2);
	addEdge(18, 23, 1);
	addEdge(17, 19, 0);
	addEdge(16, 18, 2);
	addEdge(15, 23, 2);
	addEdge(15, 23, 2);
	addEdge(14, 17, 1);
	addEdge(13, 14, 2);
	addEdge(13, 17, 1);
	addEdge(13, 25, 0);
	addEdge(13, 21, 1);
	addEdge(13, 20, 5);
	addEdge(12, 20, 2);
	addEdge(11, 18, 2);
	addEdge(10, 15, 0);
	addEdge(10, 16, 1);
	addEdge(9, 17, 2);
	addEdge(9, 15, 0);
	addEdge(9, 14, 1);
	addEdge(8, 14, 0);
	addEdge(7, 12, 2);
	addEdge(6, 13, 1);
	addEdge(6, 8, 2);
	addEdge(6, 12, 2);
	addEdge(5, 11, 1);
	addEdge(5, 16, 1);
	addEdge(4, 7, 2);
	addEdge(4, 6, 2);
	addEdge(4, 8, 5);
	addEdge(3, 9, 0);
	addEdge(3, 10, 0);
	addEdge(3, 8, 1);
	addEdge(2, 3, 6);
	addEdge(2, 4, 4);
	addEdge(2, 3, 6);
	addEdge(1, 16, 1);
	addEdge(1, 5, 1);
	addEdge(1, 16, 1);
	addEdge(1, 16, 1);
	addEdge(0, 2, 3);
	addEdge(0, 1, 5);
	int ini = 0; 
	/**ini sera la ciudad desde donde se quiera partir, la ciudad es el indice en el vector nodes de la linea 4
	 * o sea, si quieres saber las distancias minimas desde tacuba hacia todas las demas pues haces 
	 * ini = 2, dijkstra(ini) o dijkstra(2)
	 */
	dijkstra(ini);
	for(int i = 0; i<n; i++){
		cout<<nodes[i]<<" "<<dist[i]<<endl;
	}
}
