#include<bits/stdc++.h>
using namespace std;
int output(int tam);
int main(){
    int i;
    int c;
    cin >> c;
    int M[c];
    for(i=0; i<c; i++){
        cin >> M[i];
    }
    for(i=0;i<c;i++){
        if(M[i]<3){
            cout << 0;
        }else{
            output(M[i]);
        }
        cout << "\n";
    }
    
    return 0;
}
int output(int tam){
    int i,j,k;
    int sum1;
    int sum2;
    long long pares=0;
    for(i=1;i<=tam-2;i++){
        for(j=i+1;j<=tam-1;j++){
            sum1 = i + j;
            for(k=j+1;k<=tam;k++){
                sum2 = sum1 + k;
                if(sum2%2 == 0){
                    pares++;
                }
            }
        }
    }
    if(pares >= 1000000007){
        cout << 1000000007;
    }else{
        cout << pares;
    }
}