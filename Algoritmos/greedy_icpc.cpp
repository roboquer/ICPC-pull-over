// Greedy clásicos | O(n log n)
// Interval scheduling, activity selection, fractional knapsack.

#include <bits/stdc++.h>
using namespace std;

// Activity Selection: máximo número de actividades no solapadas
int activity_selection(vector<pair<int,int>>& acts) {
    sort(acts.begin(), acts.end(), [](auto& a, auto& b){
        return a.second < b.second; // ordenar por fin
    });
    int count = 0, end = -1;
    for (auto [s, e] : acts) {
        if (s >= end) { count++; end = e; }
    }
    return count;
}

// Interval covering: mínimo número de puntos para cubrir todos los intervalos
int min_points(vector<pair<int,int>>& intervals) {
    sort(intervals.begin(), intervals.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });
    int count = 0;
    int point = INT_MIN;
    for (auto [l, r] : intervals) {
        if (point < l) { point = r; count++; }
    }
    return count;
}

// Fractional knapsack
double fractional_knapsack(int W, vector<int>& wt, vector<int>& val) {
    int n = wt.size();
    vector<pair<double,int>> ratio(n);
    for (int i = 0; i < n; i++) ratio[i] = {(double)val[i]/wt[i], i};
    sort(ratio.rbegin(), ratio.rend());
    double total = 0;
    for (auto [r, i] : ratio) {
        if (W >= wt[i]) { total += val[i]; W -= wt[i]; }
        else { total += W * r; break; }
    }
    return total;
}

int main() {
    vector<pair<int,int>> acts = {{1,4},{3,5},{0,6},{5,7},{3,9},{5,9},{6,10},{8,11}};
    cout << "Max actividades: " << activity_selection(acts) << endl;

    vector<pair<int,int>> ivs = {{1,3},{2,5},{3,6}};
    cout << "Min puntos de cobertura: " << min_points(ivs) << endl;

    vector<int> val = {60,100,120}, wt = {10,20,30};
    cout << "Fractional knapsack (W=50): " << fractional_knapsack(50,wt,val) << endl;
    return 0;
}
