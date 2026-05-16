// Centroid Decomposition | O(n log n)
// Descomposición de árboles para consultas de caminos en O(n log n).

#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> adj[100005];
int sz[100005];
bool removed[100005];

// Calcula tamaños de subárbol
void calc_size(int u, int p) {
    sz[u] = 1;
    for (int v : adj[u])
        if (v != p && !removed[v]) {
            calc_size(v, u);
            sz[u] += sz[v];
        }
}

// Encuentra el centroide del árbol con raíz u y tamaño tree_sz
int find_centroid(int u, int p, int tree_sz) {
    for (int v : adj[u])
        if (v != p && !removed[v] && sz[v] > tree_sz/2)
            return find_centroid(v, u, tree_sz);
    return u;
}

// Procesa el centroide (aquí: cuenta caminos de longitud k)
// Completar según el problema específico
void process_centroid(int c) {
    // Lógica específica del problema
    // Ejemplo: recolectar distancias desde c a todos los nodos
}

void decompose(int u) {
    calc_size(u, -1);
    int c = find_centroid(u, -1, sz[u]);
    removed[c] = true;
    process_centroid(c);
    for (int v : adj[c])
        if (!removed[v]) decompose(v);
}

int main() {
    n = 7;
    // Árbol: 1-2, 1-3, 2-4, 2-5, 3-6, 3-7 (1-indexed)
    auto addEdge = [](int u, int v){ adj[u].push_back(v); adj[v].push_back(u); };
    addEdge(1,2); addEdge(1,3); addEdge(2,4);
    addEdge(2,5); addEdge(3,6); addEdge(3,7);
    memset(removed, false, sizeof(removed));
    decompose(1);
    cout << "Centroid decomposition completada para " << n << " nodos" << endl;
    return 0;
}
