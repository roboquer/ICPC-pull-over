#include<bits/stdc++.h>
using namespace std;
int main(){
    int a, b, may, min;
    cin >> a >> b;
    if(a>b) may = a; else may = b;
    a = 6 - may + 1;
    b = 6;
    min = __gcd(a, b);
    a = a/min;
    b = b/min;
    cout << a << "/" << b;
    return 0;
}