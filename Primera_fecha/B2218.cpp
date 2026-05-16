#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    int sum = 0;
    int may,ind;
    cin >> c;
    int ar[c][7];
    for(int i=0; i<c; i++){
        for(int j=0; j<7; j++){
            cin >> ar[i][j];
        }
    }
    for(int i=0; i<c; i++){
        may = ar[i][0];
        ind = 0;
        for(int j=1; j<7; j++){
            if(may>ar[i][j]){
                ar[i][j] = ar[i][j] * -1;
            }else{
                ar[i][ind] = ar[i][ind] * -1;
                ind = j;
                may = ar[i][j];
            }
        }
    }
    for(int i=0; i<c; i++){
        for(int j=0; j<7; j++){
            sum = sum + ar[i][j];
        }
        cout << sum << endl;
        sum=0;
    }
}