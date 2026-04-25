#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    int sum = 0;
    int may;
    cin >> c;
    int ar[c][7];
    for(int i=0; i<c; i++){
        for(int j=0; j<7; j++){
            cin >> ar[i][j];
            if(j != 6){
                ar[i][j] = ar[i][j] * -1;
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