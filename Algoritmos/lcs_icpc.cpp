// LCS / LIS | LCS: O(n·m), LIS: O(n log n)
// Subsecuencia común más larga y subsecuencia creciente más larga.

#include <bits/stdc++.h>
using namespace std;

// LCS - Longest Common Subsequence
int lcs(string& a, string& b) {
    int n = a.size(), m = b.size();
    vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i-1] == b[j-1]) dp[i][j] = dp[i-1][j-1] + 1;
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
    return dp[n][m];
}

// LIS - Longest Increasing Subsequence en O(n log n)
int lis(vector<int>& arr) {
    vector<int> tails;
    for (int x : arr) {
        auto it = lower_bound(tails.begin(), tails.end(), x);
        if (it == tails.end()) tails.push_back(x);
        else *it = x;
    }
    return tails.size();
}

int main() {
    string a = "ABCBDAB", b = "BDCAB";
    cout << "LCS de '" << a << "' y '" << b << "': " << lcs(a, b) << endl;

    vector<int> arr = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "LIS de {10,9,2,5,3,7,101,18}: " << lis(arr) << endl;
    return 0;
}
