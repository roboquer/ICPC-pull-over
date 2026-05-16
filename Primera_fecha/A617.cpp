#include<bits/stdc++.h>
using namespace std;
int main(){
    int a,sum=0;
    cin >> a;
    for(int i = 5; i>0; i--){
        sum = a / i + sum;
        a = a % i;
        if(a == 0){
            break;
        }
    }
    cout << sum;
    return 0;
}