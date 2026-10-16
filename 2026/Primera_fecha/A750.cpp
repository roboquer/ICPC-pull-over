#include<bits/stdc++.h>
using namespace std;
int main(){
    int n, k;
    cin >> n >> k;
    k = 60*4-k;
    int c = 0;
    int pro;
    for(int i = 1; i<=n; i++){
        c = c + 5 * i;
        if(c > k){
            pro = i-1;
            break;
        }else{
            pro = i;
        }
    }
    cout << pro;
    return 0;
}