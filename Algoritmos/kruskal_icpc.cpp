// Kruskal (MST) | O(E log E)
// Árbol de expansión mínima. Ordena aristas por peso y une componentes.

#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> par, rnk;
    DSU(int n): par(n), rnk(n,0) { iota(par.begin(),par.end(),0); }
    int find(int x){ return par[x]==x?x:par[x]=find(par[x]); }
    bool unite(int a,int b){
        a=find(a); b=find(b);
        if(a==b) return false;
        if(rnk[a]<rnk[b]) swap(a,b);
        par[b]=a; if(rnk[a]==rnk[b]) rnk[a]++;
        return true;
    }
};

struct Edge { int u, v, w; };

int main() {
    int n = 5;
    vector<Edge> edges = {
        {0,1,2},{0,3,6},{1,2,3},{1,3,8},{1,4,5},{2,4,7},{3,4,9}
    };
    sort(edges.begin(), edges.end(), [](auto& a, auto& b){ return a.w < b.w; });

    DSU dsu(n);
    int mst_cost = 0;
    cout << "Aristas del MST:" << endl;
    for (auto& [u, v, w] : edges) {
        if (dsu.unite(u, v)) {
            cout << "  " << u << " - " << v << " (peso " << w << ")" << endl;
            mst_cost += w;
        }
    }
    cout << "Costo total MST: " << mst_cost << endl;
    return 0;
}
