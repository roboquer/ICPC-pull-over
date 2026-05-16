// Orden Topológico | O(V + E)
// Ordenamiento lineal de nodos de un DAG. Usa Kahn (BFS) o DFS.

#include <bits/stdc++.h>
using namespace std;

// Orden topológico con Kahn (BFS)
vector<int> topo_sort(int n, vector<vector<int>>& adj) {
    vector<int> indegree(n, 0);
    for (int u = 0; u < n; u++)
        for (int v : adj[u]) indegree[v]++;

    queue<int> q;
    for (int i = 0; i < n; i++)
        if (indegree[i] == 0) q.push(i);

    vector<int> order;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        order.push_back(u);
        for (int v : adj[u])
            if (--indegree[v] == 0) q.push(v);
    }
    if ((int)order.size() != n) return {}; // hay ciclo
    return order;
}

int main() {
    // DAG: 5 nodos (cursos con prereqs)
    int n = 6;
    vector<vector<int>> adj(n);
    adj[5] = {2, 0};
    adj[4] = {0, 1};
    adj[2] = {3};
    adj[3] = {1};

    vector<int> order = topo_sort(n, adj);
    if (order.empty()) cout << "El grafo tiene ciclos" << endl;
    else {
        cout << "Orden topologico: ";
        for (int x : order) cout << x << " ";
        cout << endl;
    }
    return 0;
}
