// Two Pointers / Sliding Window | O(n)
// Técnica lineal para subarreglos con restricciones de suma o ventana.

#include <bits/stdc++.h>
using namespace std;

// Two Pointers: pares con suma = target (arreglo ordenado)
vector<pair<int,int>> two_sum_sorted(vector<int>& arr, int target) {
    vector<pair<int,int>> res;
    int lo = 0, hi = (int)arr.size()-1;
    while (lo < hi) {
        int s = arr[lo] + arr[hi];
        if (s == target) { res.push_back({arr[lo], arr[hi]}); lo++; hi--; }
        else if (s < target) lo++;
        else hi--;
    }
    return res;
}

// Sliding Window: max suma de subarray de tamaño k
int max_sum_window(vector<int>& arr, int k) {
    int n = arr.size(), win = 0, best;
    for (int i = 0; i < k; i++) win += arr[i];
    best = win;
    for (int i = k; i < n; i++) {
        win += arr[i] - arr[i-k];
        best = max(best, win);
    }
    return best;
}

// Subarray de suma >= target (suma mínima)
int min_subarray_len(int target, vector<int>& arr) {
    int n = arr.size(), lo = 0, sum = 0, res = INT_MAX;
    for (int hi = 0; hi < n; hi++) {
        sum += arr[hi];
        while (sum >= target) {
            res = min(res, hi - lo + 1);
            sum -= arr[lo++];
        }
    }
    return res == INT_MAX ? 0 : res;
}

int main() {
    vector<int> arr = {1,2,3,4,5,6,7,8,9};
    auto pairs = two_sum_sorted(arr, 10);
    cout << "Pares con suma 10: ";
    for (auto [a,b] : pairs) cout << "("<<a<<","<<b<<") ";
    cout << endl;

    vector<int> arr2 = {2,3,1,2,4,3};
    cout << "Max suma ventana k=3: " << max_sum_window(arr2, 3) << endl;
    cout << "Min subarray suma>=7: " << min_subarray_len(7, arr2) << endl;
    return 0;
}
