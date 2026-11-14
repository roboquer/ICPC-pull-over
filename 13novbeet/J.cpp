#include<bits/stdc++.h>
using namespace std;
int main(){
    long long N, sum=0, cant=0;
    cin >> N;
    if(N==2 || N==3){
        cout << 2 << " " << N+1 << endl;
    }else{
        if(N%2==0){
            for(long long i=1;i<=N;i=i*2){
                if(N%i==0){
                    cant=cant+2;
                    sum = sum + i + (N/i);
                }
            }
            cout << cant << " " << sum << endl;
        }else if(N%3==0){
            for(long long i=1;i<=N;i=i*3){
                if(N%i==0){
                    cant=cant+2;
                    sum = sum + i + (N/i);
                }
            }
            cout << cant << " " << sum << endl;
        }else{
            cout << 2 << " " << N+1 << endl;
        }
    }
    return 0;
}