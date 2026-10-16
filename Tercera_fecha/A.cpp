#include<bits/stdc++.h>
using namespace std;
int main(){
    int c1, c2, N, N2, i, j;
    int Sc=0, Sv=0;
    cin >> N;
    int A1[N][2]; int A3[N];
    for(i = 0; i < N; i++){
        cin >> A1[i][0] >> A1[i][1];
        Sc += A1[i][0];
        Sv += A1[i][1];
        A3[i] = Sc - Sv;
    }
    cin >> N2;
    int A2[N2];
    for(i = 0; i < N2; i++){
        cin >> A2[i];
        
    }
    for(i = 0; i < N2; i++){
        if(A3[A2[i]-1] > 0){
            cout << "COMPRA" << endl;
        }else if(A3[A2[i]-1] < 0){
            cout << "VENDA" << endl;
        }else{
            cout << "NEUTRO" << endl;   
        }
    }
}