// Bellman-Ford | O(V · E)
// Camino más corto con aristas de peso negativo. Detecta ciclos negativos.

#include <bits/stdc++.h>
using namespace std;

struct Edge { int u, v, w; };
const int INF = 1e9;

// Bellman-Ford
// Retorna {} si hay ciclo negativo alcanzable desde src
vector<int> bellman_ford(int src, int n, vector<Edge>& edges) {
    vector<int> dist(n, INF);
    dist[src] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (auto& [u, v, w] : edges) {
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    // Detección de ciclo negativo
    for (auto& [u, v, w] : edges) {
        if (dist[u] != INF && dist[u] + w < dist[v]) {
            cout << "Ciclo negativo detectado!" << endl;
            return {};
        }
    }
    return dist;
}

int main() {
    int n = 4;
    vector<Edge> edges = {
        {0,1,1}, {1,2,-3}, {2,3,2}, {0,2,4}
    };
    vector<int> dist = bellman_ford(0, n, edges);
    if (!dist.empty()) {
        cout << "Distancias desde 0:" << endl;
        for (int i = 0; i < n; i++)
            cout << "  Nodo " << i << ": " << (dist[i]==INF?-1:dist[i]) << endl;
    }
    return 0;
}
