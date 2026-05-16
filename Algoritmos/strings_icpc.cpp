// KMP / Z-Algorithm | O(n + m)
// Búsqueda de patrones en strings en tiempo lineal.

#include <bits/stdc++.h>
using namespace std;

// KMP: buscar patrón en texto
vector<int> kmp_search(string& text, string& pat) {
    string s = pat + "#" + text;
    int n = s.size();
    vector<int> fail(n, 0);
    for (int i = 1; i < n; i++) {
        int j = fail[i-1];
        while (j > 0 && s[i] != s[j]) j = fail[j-1];
        if (s[i] == s[j]) j++;
        fail[i] = j;
    }
    vector<int> res;
    int m = pat.size();
    for (int i = m+1; i < n; i++)
        if (fail[i] == m)
            res.push_back(i - 2*m); // posición en texto
    return res;
}

// Z-algorithm
vector<int> z_function(string& s) {
    int n = s.size();
    vector<int> z(n, 0);
    z[0] = n;
    int l = 0, r = 0;
    for (int i = 1; i < n; i++) {
        if (i < r) z[i] = min(r-i, z[i-l]);
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) z[i]++;
        if (i+z[i] > r) { l = i; r = i+z[i]; }
    }
    return z;
}

int main() {
    string text = "AABAACAADAABAABA";
    string pat = "AABA";
    auto pos = kmp_search(text, pat);
    cout << "KMP - Patron '" << pat << "' en '" << text << "':" << endl;
    cout << "Posiciones: ";
    for (int p : pos) cout << p << " ";
    cout << endl;

    string s = "aabxaa";
    auto z = z_function(s);
    cout << "Z-array de '" << s << "': ";
    for (int x : z) cout << x << " ";
    cout << endl;
    return 0;
}
