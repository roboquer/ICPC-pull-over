// Segment Tree | Build: O(n), Query/Update: O(log n)
// Árbol de segmentos para consultas y actualizaciones de rango en O(log n).

#include <bits/stdc++.h>
using namespace std;

// Segment Tree de suma con point update y range query
struct SegTree {
    int n;
    vector<long long> tree;
    SegTree(int n) : n(n), tree(4*n, 0) {}

    void build(vector<int>& arr, int node, int lo, int hi) {
        if (lo == hi) { tree[node] = arr[lo]; return; }
        int mid = (lo + hi) / 2;
        build(arr, 2*node, lo, mid);
        build(arr, 2*node+1, mid+1, hi);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    void update(int node, int lo, int hi, int idx, int val) {
        if (lo == hi) { tree[node] = val; return; }
        int mid = (lo + hi) / 2;
        if (idx <= mid) update(2*node, lo, mid, idx, val);
        else update(2*node+1, mid+1, hi, idx, val);
        tree[node] = tree[2*node] + tree[2*node+1];
    }

    long long query(int node, int lo, int hi, int l, int r) {
        if (r < lo || hi < l) return 0;
        if (l <= lo && hi <= r) return tree[node];
        int mid = (lo + hi) / 2;
        return query(2*node, lo, mid, l, r) +
               query(2*node+1, mid+1, hi, l, r);
    }

    void build(vector<int>& arr) { build(arr, 1, 0, n-1); }
    void update(int idx, int val) { update(1, 0, n-1, idx, val); }
    long long query(int l, int r) { return query(1, 0, n-1, l, r); }
};

int main() {
    vector<int> arr = {1, 3, 5, 7, 9, 11};
    int n = arr.size();
    SegTree st(n);
    st.build(arr);
    cout << "Suma [1,3]: " << st.query(1, 3) << endl; // 3+5+7=15
    st.update(1, 10); // arr[1] = 10
    cout << "Suma [1,3] tras update: " << st.query(1, 3) << endl; // 10+5+7=22
    return 0;
}
