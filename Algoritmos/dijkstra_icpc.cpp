// Dijkstra | O((V+E) log V)
// Camino más corto desde un nodo fuente en grafos con pesos no negativos.

#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
const int INF = 1e9;

// Dijkstra con cola de prioridad
// adj[u] = {v, peso}
vector<int> dijkstra(int src, int n, vector<vector<pii>>& adj) {
    vector<int> dist(n, INF);
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    dist[src] = 0;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d, u] = pq.top(); pq.pop();
        if (d > dist[u]) continue; // nodo obsoleto
        for (auto [v, w] : adj[u]) {
            if (dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main() {
    int n = 5;
    vector<vector<pii>> adj(n);
    // Grafo: {destino, peso}
    adj[0] = {{1,10},{2,3}};
    adj[1] = {{3,2}};
    adj[2] = {{1,4},{3,8},{4,2}};
    adj[3] = {{4,5}};
    adj[4] = {{3,1}};

    vector<int> dist = dijkstra(0, n, adj);
    cout << "Distancias desde nodo 0:" << endl;
    for (int i = 0; i < n; i++)
        cout << "  Nodo " << i << ": " << (dist[i]==INF ? -1 : dist[i]) << endl;
    // Salida: 0,7,3,9,5
    return 0;
}
