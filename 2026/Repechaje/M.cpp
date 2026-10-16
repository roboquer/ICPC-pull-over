#include<bits/stdc++.h>
using namespace std;
int main(){
    int n,max=0,min=100000;
    cin >> n;
    int a[n];
    for(int i = 0; i < n; i++){
        cin >> a[i];
        if(a[i] > max){
            max = a[i];
        }
        if(a[i] < min){
            min = a[i];
        }
    }
    int ran= (max-min)*2-1;
    if(ran <= 0){
        cout << "YES" << endl;
        for(int i = 0; i < n; i++){
            cout << "0 ";
        }
    }else{
        if(ran <= n){
            cout << "YES" << endl;
            int r[ran][n];
            bool un[n];
            for(int i = 0; i < n; i++){
                un[i] = true;
            }
            for(int i = 0; i < ran; i++){
                for(int j = 0; j < n; j++){
                    if(a[j] < max && un[j]==true){
                        cout << "1 ";
                        a[j]++;
                        un[j] = false;
                    }else{
                        cout << "0 ";
                        un[j] = true;
                    }
                }
                cout << endl;
            }
        }else{
            cout << "NO";
        } 
    }
    
}