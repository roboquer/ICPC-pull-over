// Búsqueda Binaria | O(log n)
// Encuentra un elemento en un arreglo ordenado dividiéndolo a la mitad en cada paso.

#include <bits/stdc++.h>
using namespace std;

// Búsqueda binaria clásica
// Retorna índice del elemento, -1 si no existe
int binary_search(vector<int>& arr, int target) {
    int lo = 0, hi = (int)arr.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (arr[mid] == target) return mid;
        else if (arr[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}

// Binary search on answer: ¿es posible con valor mid?
// Ejemplo: mínima velocidad para terminar en T horas
bool feasible(int speed, vector<int>& piles, int T) {
    long long hours = 0;
    for (int p : piles) hours += (p + speed - 1) / speed;
    return hours <= T;
}

int min_speed(vector<int>& piles, int T) {
    int lo = 1, hi = *max_element(piles.begin(), piles.end());
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (feasible(mid, piles, T)) hi = mid;
        else lo = mid + 1;
    }
    return lo;
}

int main() {
    vector<int> arr = {1,3,5,7,9,11,13,15};
    cout << "Buscar 7: indice " << binary_search(arr, 7) << endl;
    cout << "Buscar 6: indice " << binary_search(arr, 6) << endl;

    // lower_bound / upper_bound de STL
    auto it = lower_bound(arr.begin(), arr.end(), 7);
    cout << "lower_bound(7): posicion " << (it - arr.begin()) << endl;

    vector<int> piles = {3,6,7,11};
    cout << "Min speed (T=8): " << min_speed(piles, 8) << endl;
    return 0;
}
