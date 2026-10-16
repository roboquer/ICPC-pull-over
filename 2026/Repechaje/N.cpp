#include<bits/stdc++.h>
using namespace std;
int main(){
    int l,r,min,may,cum=0,i=0;
    cin >> l >> r;
    if(l!=1){
        for(int j = i+1; j <= l; j++){
            if(((l*(l+1)/2) - (i+1)*(i+1+1)/2)%2 == 0){
                cum++;
            }
            i++;
            l--;
            cum = cum*2;
            if(i==l){
                if(i%2==0){
                    cum++;
                }
            }
        }
    }
    i=1;
    if(r!=1){
        for(int j = i; j <= r; j++){
            cout << j << " " << r << endl;
            cout << i+1 << " " << r << " " << i <<endl;
            if(((r*(r+1)/2) - (j-1)*(j-1)/2)%2 == 0){
                cum++;
            }
            i++;
            r--;
            if(i==r){
                cum = cum*2;
                if(i%2==0){
                    cum++;
                }
            }
        }
    }
    cout << cum;
}