#include<bits/stdc++.h>
using namespace std;
int main(){
    int t, c ,k;
    cin >> t >> c >> k;
    if((t*k) <= c){
        cout << (t*k);
    }else{
        cout << c;
    }
}