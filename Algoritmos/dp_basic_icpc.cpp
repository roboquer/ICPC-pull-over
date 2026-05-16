// DP Knapsack | O(n · W)
// Mochila 0/1: maximizar valor eligiendo items sin superar capacidad.

#include <bits/stdc++.h>
using namespace std;

// 0/1 Knapsack
int knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    // Optimizado en espacio: solo una fila
    vector<int> dp(W + 1, 0);
    for (int i = 0; i < n; i++)
        for (int w = W; w >= wt[i]; w--) // reverso para 0/1
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

// Knapsack ilimitado (unbounded): cada item puede usarse múltiples veces
int unbounded_knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<int> dp(W + 1, 0);
    for (int w = 1; w <= W; w++)
        for (int i = 0; i < n; i++)
            if (wt[i] <= w)
                dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
    return dp[W];
}

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt  = {10,  20,  30};
    int W = 50;

    cout << "0/1 Knapsack (W=50): " << knapsack(W, wt, val) << endl;
    cout << "Unbounded Knapsack:   " << unbounded_knapsack(W, wt, val) << endl;
    return 0;
}
