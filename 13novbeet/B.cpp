#include<bits/stdc++.h>
using namespace std;

int main(){
    int N,k,m;
    do{
        cin >> N >> k >> m;
        bool S[N];
        for(int i=0;i<N;i++){
            S[i]=true;
        }
        int poss = 1;
        int posa = 0;
        bool C=true;
        while(C==true){
            cout << endl;
            int cont1=k; 
            int cont2=m;
            for(int i=poss;i<N;i++){
                if(cont1==1 && S[i]==true){
                    poss=i;
                    break;
                }
                if(S[i]==true){
                    cont1--;
                }
                if(i==N-1){
                    i=0;
                }
            }
            for(int i=posa;i>=0;i--){
                if(cont2==1 && S[i]==true){
                    posa=i;
                    break;
                }
                if(S[i]==true){
                    cont2--;
                }
                if(i<=0){
                    i=N;
                }
            }
            for(int i=0;i<N;i++){
                if(S[i]==true){
                    C=true;
                    break;
                }
            }           
            
            if(C==false){
                if(poss==posa){
                    S[poss]=false;
                    cout << " " << poss << endl;
                }else{
                    S[poss]=false;
                    S[posa]=false;
                    cout << "  " << poss << ",  " << posa << endl;
                }
            }else{
                if(poss==posa){
                    S[poss]=false;
                    cout << " " << poss << ",";
                }else{
                    S[poss]=false;
                    S[posa]=false;
                    cout << "  " << poss << ",  " << posa << ",";
                }
            }
            for(int i=0;i<N;i++){
                if(S[i]==true){
                    C=true;
                    break;
                }
            }
            if(C==true){
                for(int i=poss;i<N;i++){
                    if(S[i]==true){
                        poss=i;
                        break;
                    }
                    if(i==N-1){
                        i=0;
                    }
                }
                for(int i=posa;i>=0;i--){
                    if(S[i]==true){
                        posa=i;
                        break;
                    }
                    if(i==0){
                        i=N-1;
                    }
                }
            }
        }
    }while(N!=0 && k!=0 && m!=0);
}