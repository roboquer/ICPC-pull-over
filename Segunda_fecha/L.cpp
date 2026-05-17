#include<bits/stdc++.h>
using namespace std;
int cant(long long t){
    int cant=0;
    for(long long i=1;i<=t;i++){
        long long num = elevacion(i);
        if(primo(num)==1){
            cant++;
        }
    }
    return cant;
}
long long elevacion(long long n){
    n = (n*n)+1;
    return n;
}
bool primo(long long m){
    bool r=1;
    for(long long k=2; k<m;k++){
        if(m%k==0){
            r=0;
            break;
        }
    }
    return r;
}
int main(){
    long long c, cd;
    cin >> c;
    long long i,j;
    bool n=1;
    for(i=0;i<c;i++){
        cin >> cd;
        cout << cant(cd) << endl;
    }
}