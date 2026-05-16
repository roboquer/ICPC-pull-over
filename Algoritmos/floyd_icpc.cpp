// Floyd-Warshall | O(V³)
// Todos los pares de caminos más cortos. Funciona con pesos negativos.

#include <bits/stdc++.h>
using namespace std;

const int INF = 1e9;

// Floyd-Warshall: dist[i][j] = costo mínimo de i a j
void floyd_warshall(int n, vector<vector<int>>& dist) {
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] != INF && dist[k][j] != INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    // Si dist[i][i] < 0, hay ciclo negativo
}

int main() {
    int n = 4;
    // Inicializar con INF, 0 en diagonal
    vector<vector<int>> dist(n, vector<int>(n, INF));
    for (int i = 0; i < n; i++) dist[i][i] = 0;
    // Aristas
    dist[0][1]=3; dist[0][3]=7;
    dist[1][0]=8; dist[1][2]=2;
    dist[2][0]=5; dist[2][3]=1;
    dist[3][0]=2;

    floyd_warshall(n, dist);

    cout << "Matriz de distancias minimas:" << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cout << (dist[i][j]==INF ? -1 : dist[i][j]) << "	";
        cout << endl;
    }
    return 0;
}
