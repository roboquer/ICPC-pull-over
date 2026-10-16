#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,b;
    cin >> a >> b;
    int i, sum1 = 0, sum2 = 0;
    int a1[a], b1[b];
    for(i=0; i < a; i++){
        cin >> a1[i];
    }
    for(i=0; i < b; i++){
        cin >> b1[i];
    }
    for(i=0; i < a; i++){
        sum1 = sum1 + a1[i];
    }
    for(i=0; i < b; i++){
        sum2 = sum2 + b1[i];
    }
    sum1 = sum1 * 1.1;
    if(sum2 >= sum1){
        cout << "YES";
    }else{
        cout << "NO";
    }

    return 1;
}