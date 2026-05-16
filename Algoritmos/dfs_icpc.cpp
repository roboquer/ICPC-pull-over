// DFS | O(V + E)
// Búsqueda en profundidad. Explora tan lejos como sea posible antes de retroceder.

#include <bits/stdc++.h>
using namespace std;

// DFS - Búsqueda en Profundidad (recursivo)
vector<bool> visited;

void dfs(int u, vector<vector<int>>& adj) {
    visited[u] = true;
    cout << u << " ";
    for (int v : adj[u]) {
        if (!visited[v])
            dfs(v, adj);
    }
}

// DFS iterativo con stack
void dfs_iter(int src, int n, vector<vector<int>>& adj) {
    vector<bool> vis(n, false);
    stack<int> st;
    st.push(src);
    while (!st.empty()) {
        int u = st.top(); st.pop();
        if (vis[u]) continue;
        vis[u] = true;
        cout << u << " ";
        for (int v : adj[u])
            if (!vis[v]) st.push(v);
    }
}

int main() {
    int n = 6;
    vector<vector<int>> adj(n);
    adj[0] = {1, 2};
    adj[1] = {0, 3, 4};
    adj[2] = {0, 5};
    adj[3] = {1};
    adj[4] = {1};
    adj[5] = {2};

    visited.assign(n, false);
    cout << "DFS recursivo desde 0: ";
    dfs(0, adj);
    cout << endl;

    cout << "DFS iterativo desde 0: ";
    dfs_iter(0, n, adj);
    cout << endl;
    return 0;
}
