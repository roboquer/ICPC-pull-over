// GCD / LCM / Primos | GCD: O(log n), Criba: O(n log log n)
// Máximo común divisor, mínimo común múltiplo, criba de Eratóstenes y factorización.

#include <bits/stdc++.h>
using namespace std;

// GCD y LCM
long long gcd(long long a, long long b) { return b ? gcd(b, a%b) : a; }
long long lcm(long long a, long long b) { return a / gcd(a,b) * b; }

// Criba de Eratóstenes
vector<bool> sieve(int n) {
    vector<bool> is_prime(n+1, true);
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i*i <= n; i++)
        if (is_prime[i])
            for (int j = i*i; j <= n; j += i)
                is_prime[j] = false;
    return is_prime;
}

// Factorización prima
map<int,int> factorize(int n) {
    map<int,int> f;
    for (int i = 2; i*i <= n; i++)
        while (n % i == 0) { f[i]++; n /= i; }
    if (n > 1) f[n]++;
    return f;
}

// Exponenciación modular rápida
long long power(long long base, long long exp, long long mod) {
    long long result = 1;
    base %= mod;
    while (exp > 0) {
        if (exp & 1) result = result * base % mod;
        base = base * base % mod;
        exp >>= 1;
    }
    return result;
}

int main() {
    cout << "GCD(48,18) = " << gcd(48,18) << endl;
    cout << "LCM(4,6) = " << lcm(4,6) << endl;
    cout << "2^10 mod 1e9+7 = " << power(2,10,1e9+7) << endl;

    auto primes = sieve(30);
    cout << "Primos hasta 30: ";
    for (int i=2;i<=30;i++) if(primes[i]) cout<<i<<" ";
    cout << endl;

    cout << "Factores de 360: ";
    for (auto [p,e] : factorize(360))
        cout << p << "^" << e << " ";
    cout << endl;
    return 0;
}
