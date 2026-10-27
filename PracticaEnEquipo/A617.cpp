#include<bits/stdc++.h>
using namespace std;

int main(){
    int n=0,suma=0,residuo=0;
    cin >> n;
    suma = n/5;
    residuo= n%5;
    if(residuo != 0){
        suma = suma + residuo / 4;
        residuo = residuo % 4;
        if(residuo != 0){
            suma = suma + residuo / 3;
            residuo = residuo % 3;
            if(residuo != 0){
                suma = suma + residuo / 2;
                residuo = residuo % 2;
                    if(residuo != 0){
                        suma = suma + residuo / 1;
                        residuo = residuo % 1;
                    }
            }
        }
    }
    cout << suma;
    return 0;
}