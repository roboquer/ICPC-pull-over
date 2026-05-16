// Hashing de Strings | Preproceso: O(n), Query: O(1)
// Polynomial rolling hash para comparación y búsqueda de patrones en O(1) por query.

#include <bits/stdc++.h>
using namespace std;

// Double hashing para evitar colisiones
struct StringHash {
    static const long long MOD1 = 1e9+7, MOD2 = 1e9+9;
    static const long long B1 = 131, B2 = 137;
    int n;
    vector<long long> h1, h2, pw1, pw2;

    StringHash(string& s) : n(s.size()), h1(n+1,0), h2(n+1,0),
                             pw1(n+1,1), pw2(n+1,1) {
        for (int i = 0; i < n; i++) {
            h1[i+1] = (h1[i]*B1 + s[i]) % MOD1;
            h2[i+1] = (h2[i]*B2 + s[i]) % MOD2;
            pw1[i+1] = pw1[i]*B1 % MOD1;
            pw2[i+1] = pw2[i]*B2 % MOD2;
        }
    }

    // Hash de s[l..r] (0-indexed)
    pair<long long,long long> get(int l, int r) {
        long long v1 = (h1[r+1] - h1[l]*pw1[r-l+1] % MOD1 + MOD1*2) % MOD1;
        long long v2 = (h2[r+1] - h2[l]*pw2[r-l+1] % MOD2 + MOD2*2) % MOD2;
        return {v1, v2};
    }

    bool equal(int l1, int r1, int l2, int r2) {
        return get(l1,r1) == get(l2,r2);
    }
};

int main() {
    string s = "abacabacaba";
    StringHash sh(s);
    // ¿s[0..2] == s[4..6]?
    cout << "s[0..2]='" << s.substr(0,3) << "' == s[4..6]='" << s.substr(4,3) << "'? ";
    cout << (sh.equal(0,2,4,6) ? "Si" : "No") << endl;
    // Verificar palíndromos usando reverse hash
    string r = s; reverse(r.begin(), r.end());
    StringHash sr(r);
    int n = s.size();
    // ¿s[2..8] es palíndromo?
    int l=2,ri=8, len=ri-l+1;
    bool pal = sh.get(l,ri) == sr.get(n-1-ri, n-1-l);
    cout << "s[2..8]='" << s.substr(2,7) << "' es palindromo? " << (pal?"Si":"No") << endl;
    return 0;
}
