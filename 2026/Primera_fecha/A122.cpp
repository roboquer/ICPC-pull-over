#include <bits/stdc++.h>
using namespace std;
int main(){
    int n=0;
    cin>>n;
    string text = to_string(n);
    bool t=true;
    for(char f : text){
        if(f != '4' && f != '7'){
            t = false;
        }
    }
    if(t == true){
        cout << "YES";
    }else if(n%4==0 || n%7==0 || n%47==0){
        cout << "YES";
    }else{
        cout << "NO";
    }
}