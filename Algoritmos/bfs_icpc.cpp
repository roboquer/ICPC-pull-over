// BFS | O(V + E)
// Búsqueda en anchura. Recorre grafos nivel por nivel. Ideal para encontrar el camino más corto en grafos no ponderados.

#include <bits/stdc++.h>
using namespace std;

// BFS - Búsqueda en Anchura
// Entrada: grafo como lista de adyacencia, nodo inicial
// Salida: distancias mínimas desde el nodo fuente

vector<int> bfs(int src, int n, vector<vector<int>>& adj) {
    vector<int> dist(n, -1);
    queue<int> q;
    dist[src] = 0;
    q.push(src);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : adj[u]) {
            if (dist[v] == -1) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
    return dist;
}

int main() {
    // Ejemplo: grafo con 6 nodos (0-5)
    int n = 6;
    vector<vector<int>> adj(n);
    // Aristas: 0-1, 0-2, 1-3, 2-4, 3-5
    adj[0] = {1, 2};
    adj[1] = {0, 3};
    adj[2] = {0, 4};
    adj[3] = {1, 5};
    adj[4] = {2};
    adj[5] = {3};

    vector<int> dist = bfs(0, n, adj);

    cout << "Distancias desde nodo 0:" << endl;
    for (int i = 0; i < n; i++)
        cout << "  Nodo " << i << ": " << dist[i] << endl;
    // Salida: 0:0, 1:1, 2:1, 3:2, 4:2, 5:3
    return 0;
}
