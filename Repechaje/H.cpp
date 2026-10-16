#include<bits/stdc++.h>
using namespace std;
int main(){
    int N;
    bool k = false;
    cin >> N;
    int M[N];
    int may,min;
    for(int i = 0; i < N; i++){
        cin >> M[i];
        if(i == 0){
            may = M[i];
            min = M[i];
        }
        if(i > 0){
            if(may <= M[i]){
                may = M[i];
            }
            if(min >= M[i]){
                min = M[i];
            }
        }
    }
    for(int i = 1; i < N; i++){
        if(M[i] == M[i-1]){
            k = true;
        }else{
            k = false;
            break;
        }
    }
    if(k == false){
        cout << may - min;
    }else{
        cout << 0;
    }
}