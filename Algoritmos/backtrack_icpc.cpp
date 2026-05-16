// Backtracking | O(n!) a O(2^n)
// Exploración exhaustiva con poda. Permutaciones, subconjuntos, N-Reinas.

#include <bits/stdc++.h>
using namespace std;

// Todas las permutaciones
void permutations(vector<int>& arr, int start, vector<vector<int>>& res) {
    if (start == (int)arr.size()) { res.push_back(arr); return; }
    for (int i = start; i < (int)arr.size(); i++) {
        swap(arr[start], arr[i]);
        permutations(arr, start+1, res);
        swap(arr[start], arr[i]);
    }
}

// N-Reinas
int nQueens(int n) {
    int count = 0;
    vector<int> cols(n, 0), diag1(2*n, 0), diag2(2*n, 0);
    function<void(int)> solve = [&](int row) {
        if (row == n) { count++; return; }
        for (int col = 0; col < n; col++) {
            if (cols[col] || diag1[row-col+n] || diag2[row+col]) continue;
            cols[col] = diag1[row-col+n] = diag2[row+col] = 1;
            solve(row+1);
            cols[col] = diag1[row-col+n] = diag2[row+col] = 0;
        }
    };
    solve(0);
    return count;
}

// Subsets / subconjuntos de potencia
void subsets(vector<int>& arr, int idx, vector<int>& cur, vector<vector<int>>& res) {
    res.push_back(cur);
    for (int i = idx; i < (int)arr.size(); i++) {
        cur.push_back(arr[i]);
        subsets(arr, i+1, cur, res);
        cur.pop_back();
    }
}

int main() {
    vector<int> arr = {1,2,3};
    vector<vector<int>> perms;
    permutations(arr, 0, perms);
    cout << "Permutaciones de {1,2,3}: " << perms.size() << endl;

    cout << "Soluciones N-Reinas (8x8): " << nQueens(8) << endl;

    vector<vector<int>> subs;
    vector<int> cur;
    subsets(arr, 0, cur, subs);
    cout << "Subconjuntos de {1,2,3}: " << subs.size() << endl;
    return 0;
}
