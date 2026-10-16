#include<bits/stdc++.h>
using namespace std;
int main(){
    bool ent = false;
    int n, q, ultimoentero;
    cin >> n >> q;
    int a[n];
    int x[q];
    int sum=0;
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i]>=0){
            ultimoentero = i;
        }
    }
    for(int j = 0; j < q; j++){
        cin >> x[j];
    }
    for(int j = 0; j < q; j++){
        if(x[j]==n-1){
            cout << a[n-1] << endl;
        }else{
            for(int k = x[j]; k <= ultimoentero; k++){
                if(ent == false){
                    if(a[k] > 0){
                        ent = true;
                        sum += a[k];
                    }
                }else{
                    sum += a[k];
                }   
            }
            ent = false;
            cout << sum << endl;
            sum = 0;
        }
    }
}