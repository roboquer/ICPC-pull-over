#include<bits/stdc++.h>
using namespace std;
int main(){
    string na;
    cin >> na;
    int cant[142858];
    int m=0, c=0;
    for(int i = 0 ; i < na.size(); i ++){
        if(na[i] == 'm'){
            if(na[i+1] == 'e' && na[i+2] == 's' && na[i+3]== 'e' && na[i+4]=='r' && na[i+5] == 'o'){
                m++;
                cant[c]=i;
                c++;
                i=i+5;
            }
        }
    }
    c=0;
    if(m==0){
        cout << na;
    }else{
        int tam = na.size() + m;
        string me[tam];
        int k=0;
        for(int j=0; j<tam; j++){
            
            if(k!=cant[c]){
                me[j] = na[k];
                cout << me[j];
                k++;
            }else if(m>0){
                me[j] = 't';
                cout << me[j];
                me[j+1] = 'a';
                cout << me[j+1];
                me[j+2] = 'q';
                cout << me[j+2];

                me[j+3] = 'u';
                cout << me[j+3];

                me[j+4] = 'e';
                cout << me[j+4];

                me[j+5] = 'r';
                cout << me[j+5];

                me[j+6] = 'o';
                cout << me[j+6];
                j=j+6;
                k=k+6;
                c++;
                m--;
            }
        }
    }
}