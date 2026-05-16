// DSU / Union-Find | O(α(n))
// Estructura de conjuntos disjuntos. Detecta ciclos y componentes conexas.

#include <bits/stdc++.h>
using namespace std;

// DSU con path compression y union by rank
struct DSU {
    vector<int> par, rank_;
    DSU(int n) : par(n), rank_(n, 0) {
        iota(par.begin(), par.end(), 0);
    }
    int find(int x) {
        if (par[x] != x) par[x] = find(par[x]); // path compression
        return par[x];
    }
    bool unite(int x, int y) {
        x = find(x); y = find(y);
        if (x == y) return false; // mismo conjunto = ciclo
        if (rank_[x] < rank_[y]) swap(x, y);
        par[y] = x;
        if (rank_[x] == rank_[y]) rank_[x]++;
        return true;
    }
    bool same(int x, int y) { return find(x) == find(y); }
};

int main() {
    DSU dsu(6);
    vector<pair<int,int>> edges = {{0,1},{1,2},{3,4},{4,5},{2,3}};
    for (auto [u, v] : edges) {
        if (dsu.unite(u, v))
            cout << "Union " << u << "-" << v << " OK" << endl;
        else
            cout << "Ciclo detectado: " << u << "-" << v << endl;
    }
    cout << "¿0 y 5 conectados? " << (dsu.same(0,5) ? "Si" : "No") << endl;
    return 0;
}
