// Merge Sort | O(n log n)
// Divide y conquista. Estable. Base para contar inversiones.

#include <bits/stdc++.h>
using namespace std;

long long inversions = 0; // bonus: contar inversiones

void merge(vector<int>& arr, int lo, int mid, int hi) {
    vector<int> L(arr.begin()+lo, arr.begin()+mid+1);
    vector<int> R(arr.begin()+mid+1, arr.begin()+hi+1);
    int i = 0, j = 0, k = lo;
    while (i < (int)L.size() && j < (int)R.size()) {
        if (L[i] <= R[j]) arr[k++] = L[i++];
        else {
            inversions += L.size() - i; // elementos de L mayores que R[j]
            arr[k++] = R[j++];
        }
    }
    while (i < (int)L.size()) arr[k++] = L[i++];
    while (j < (int)R.size()) arr[k++] = R[j++];
}

void merge_sort(vector<int>& arr, int lo, int hi) {
    if (lo >= hi) return;
    int mid = (lo + hi) / 2;
    merge_sort(arr, lo, mid);
    merge_sort(arr, mid+1, hi);
    merge(arr, lo, mid, hi);
}

int main() {
    vector<int> arr = {38, 27, 43, 3, 9, 82, 10};
    inversions = 0;
    merge_sort(arr, 0, arr.size()-1);
    cout << "Arreglo ordenado: ";
    for (int x : arr) cout << x << " ";
    cout << endl;
    cout << "Inversiones: " << inversions << endl;
    return 0;
}
