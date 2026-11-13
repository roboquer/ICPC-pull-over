#include<bits/stdc++.h>
using namespace std;
int main(){
    int t=0,c=0,ini=0,fin=0;
    long long total=0, num=0;
    string s;
    string imp="";
    string temp="";
    cin >> t;
    for(int i=0;i<t;i++){
        cin >> s;
        cin >> c;
        int tam=s.size();
        if(tam>c){
            cout << "unfeasible" << endl;
        }else{
            for(int k = 0;k<tam;k++){
                ini = k;
                for(int j=k;j<tam;j++){
                    if(s[j]=='a'|| s[j]=='b'|| s[j]=='c'|| s[j]=='d'|| s[j]=='e'|| s[j]=='f'|| s[j]=='g'|| s[j]=='h'|| s[j]=='i'|| s[j]=='j'|| s[j]=='k'|| s[j]=='l'|| s[j]=='m'|| s[j]=='n'|| s[j]=='o'|| s[j]=='p'|| s[j]=='q'|| s[j]=='r'|| s[j]=='s'|| s[j]=='t'|| s[j]=='u'|| s[j]=='v'|| s[j]=='w'|| s[j]=='x'|| s[j]=='y'|| s[j]=='z'){
                        fin = j;
                        temp = s[j];
                        break;
                    }
                }
                if(k==fin){
                    total++;
                    imp = imp + temp;
                }else{
                    num = stoll(s.substr(ini,fin-ini));
                    total += num;
                    if(total<=c){
                        for(int p = 0;p<num;p++){
                            imp = imp + temp;
                        }
                    }else{
                        break;
                    }
                    k=fin;
                }
            }
            if(total>c){
                cout << "unfeasible" << endl;
                imp = "";
                total = 0;
            }else{
                cout << imp << endl;
                imp = "";
                total = 0;
            }
        }
    }
}