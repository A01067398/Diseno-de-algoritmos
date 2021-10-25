from pyvis.network import Network

class Graph:
      
    adj = []
  
    # matrix
    def _init_(self, v, e):
          
        self.v = v
        self.e = e
        Graph.adj = [[0 for i in range(v)] 
                        for j in range(v)]
  
    def addEdge(self, start, e):
        Graph.adj[start][e] = 1
        Graph.adj[e][start] = 1

    def DFS_run(self, start, visited):
          
        print(start, end = ' ')

        visited[start] = True
  
        for i in range(self.v):
            if (Graph.adj[start][i] == 1 and
                    (not visited[i])):
                self.DFS_run(i, visited)
  

v, e = 7, 10 # 5 vertices y 10 edges
visited = [False] * v # Nodos visitados, todo sin visitar
network = Network()
G = Graph(v, e) # grafo de 5 vertices y 10 conexiones

nodes = [0, 1, 6, 7, 3, 9, 8]
network.add_nodes(nodes) # Agregando nodos en la red


G.addEdge(0, 1)
network.add_edge(0, 1, weight=.87)
G.addEdge(0, 2)
network.add_edge(0, 6, weight=.87)
G.addEdge(2, 3)
network.add_edge(6, 7, weight=.87)
G.addEdge(3, 4)
network.add_edge(7, 3, weight=.87)
G.addEdge(4, 5)
network.add_edge(3, 9, weight=.87)
G.addEdge(5, 6)
network.add_edge(9, 8, weight=.87)
G.addEdge(6, 0)
network.add_edge(8, 1, weight=.87)


network.toggle_physics(True)
network.show('A01067398.html')
G.DFS_run(0, visited)
