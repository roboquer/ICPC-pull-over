#include<bits/stdc++.h>
using namespace std;
int main(){
    long long t, n, k, total;
    cin >> t;
    for(int i = 0; i < t; i++){
        cin >> n >> k;
        total = (((n*(n+1))/2) + n + 1) * (k+1) % 1e6 + 7;
        if(total < 0){
            cout << 1000000007 << endl;
        }else{
            cout << total << endl;
        }
    }
}