// Fenwick Tree (BIT) | O(log n)
// Binary Indexed Tree. Sumas de prefijo y actualizaciones en O(log n). Más simple que Segment Tree.

#include <bits/stdc++.h>
using namespace std;

struct BIT {
    int n;
    vector<long long> bit;
    BIT(int n) : n(n), bit(n+1, 0) {}

    void update(int i, long long delta) {
        for (++i; i <= n; i += i & -i)
            bit[i] += delta;
    }

    long long query(int i) { // prefijo [0..i]
        long long s = 0;
        for (++i; i > 0; i -= i & -i)
            s += bit[i];
        return s;
    }

    long long query(int l, int r) { // rango [l..r]
        return query(r) - (l > 0 ? query(l-1) : 0);
    }
};

int main() {
    vector<int> arr = {2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = arr.size();
    BIT bit(n);
    for (int i = 0; i < n; i++) bit.update(i, arr[i]);

    cout << "Suma [0,4]: " << bit.query(0, 4) << endl; // 9
    cout << "Suma [3,7]: " << bit.query(3, 7) << endl; // 23
    bit.update(3, 6); // suma 6 al índice 3
    cout << "Suma [0,4] tras update: " << bit.query(0, 4) << endl;
    return 0;
}
