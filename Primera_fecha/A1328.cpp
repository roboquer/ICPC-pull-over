#include<bits/stdc++.h>
using namespace std;
int main(){
    int c,i,j;
    cin >> c;
    int arr[c][2];
    for(i = 0; i < c; i++){
        for(j = 0; j < 2; j++){
            cin >> arr[i][j];
        }
    }
    int cant;
    for(i = 0; i < c; i++){
        if(arr[i][0] % arr[i][1] == 0){
            cout << 0 << endl;
        }else{
            cant = (arr[i][0] / arr[i][1] + 1) * arr[i][1] - arr[i][0];
            cout << cant << endl;
        }
    }
    return 0;
}