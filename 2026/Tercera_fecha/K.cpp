#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,min=100000,sum=0;
    cin >> N;
    int M[2][N];
    for(int i = 0; i < N; i++){
        cin >> M[0][i];
        sum += M[0][i];
        
    }
    for(int i = 0; i < N; i++){
        cin >> M[1][i];
        if((M[0][i] - M[1][i]) < 0){
            min = -1;
            break;
        }else if((M[0][i] - M[1][i]) < min){
            min = (M[0][i] - M[1][i]);
        }
    }
    if(min == -1){
        cout << min;
    }else{
        cout << sum - min;
    }
    return 0;
}