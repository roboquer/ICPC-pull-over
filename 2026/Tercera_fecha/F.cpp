#include<bits/stdc++.h>
using namespace std;
int main(){
    int N,p;
    bool k = false;
    cin >> N;
    for(int i = N+1; k==true; i++){
        if(i%2 == 0){
            p = i;
            k = true;
        }else if(i%3 == 0){
            p = i;
            k = true;
    }
}