#include<bits/stdc++.h>
using namespace std;
void ordenar(int c[], int N){
    bool ordenado=true;
    for(int i=0;i<N;i++){
        if(c[i]>c[i+1] && i<N-1 && ordenado==true){
            int aux=c[i];
            c[i]=c[i+1];
            c[i+1]=aux;
            ordenado=false;
        }else if(c[i]>c[i+1] && i<N-1 && ordenado==false){
            int aux=c[i];
            c[i]=c[i+1];
            c[i+1]=aux;
        }
    }
    
    if(ordenado==false){
        ordenar(c, N);
    }
}
int main(){
    int N,total=0;
    cin >> N;
    int c[N];
    for(int i=0;i<N;i++){
        cin >> c[i];
    }
    ordenar(c, N);
    for(int i=1;i<N;i=i+2){
        total += c[i];
    }
    cout << total << endl;
    return 0;
}