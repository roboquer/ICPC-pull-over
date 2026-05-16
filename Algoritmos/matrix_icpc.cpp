// Exponenciación de Matrices | O(k³ log n)
// Calcula potencias de matrices en O(log n). Fibonacci en O(log n).

#include <bits/stdc++.h>
using namespace std;

typedef vector<vector<long long>> Matrix;
const long long MOD = 1e9 + 7;

Matrix multiply(const Matrix& A, const Matrix& B) {
    int n = A.size();
    Matrix C(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++)
        for (int k = 0; k < n; k++) if (A[i][k])
            for (int j = 0; j < n; j++)
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
    return C;
}

Matrix mat_pow(Matrix A, long long p) {
    int n = A.size();
    Matrix res(n, vector<long long>(n, 0));
    for (int i = 0; i < n; i++) res[i][i] = 1; // identidad
    while (p > 0) {
        if (p & 1) res = multiply(res, A);
        A = multiply(A, A);
        p >>= 1;
    }
    return res;
}

// Fibonacci en O(log n)
long long fibonacci(long long n) {
    if (n <= 1) return n;
    Matrix A = {{1,1},{1,0}};
    Matrix R = mat_pow(A, n-1);
    return R[0][0];
}

int main() {
    cout << "Fibonacci(10) = " << fibonacci(10) << endl;  // 55
    cout << "Fibonacci(50) = " << fibonacci(50) << endl;
    cout << "Fibonacci(1e18) mod 1e9+7 = " << fibonacci(1000000000LL) << endl;
    return 0;
}
