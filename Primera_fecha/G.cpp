
#include<bits/stdc++.h>
using namespace std;
int main(){
    int tamano;
    cin >> tamano;
    int M[tamano], C[tamano];
    int contador=0, i;

    for(i=0; i<tamano; i++){
        cin >> M[i];
        C[i] = 0;
    }
    for(i = 0; i<tamano; i++){
        C[M[i]-1]++;
    }
    for(i=0; i<tamano; i++){
        if(C[i]>1){
            contador = contador + C[i] - 1;
        }
    }
    cout << contador;
    return 0;
}