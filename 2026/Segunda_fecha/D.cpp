#include<bits/stdc++.h>
using namespace std;
int main(){
    int c;
    cin >> c;
    int x, y, r, x2,y2,r2;
    int d;
    int dd;
    int may,men;
    for(int i=0; i<c; i++){    
        cin >> x >> y >> r;
        cin >> x2 >> y2 >> r2;
        cin >> d;
        if(r>=r2){
            may = r;
            men = r2;
        }else{
            may = r2;
            men = r;
        }
        dd = hypot(x-x2, y-y2);
        if(d  <= r*2 || d <= r2*2){
            cout << "YES" << endl;
        }else{
            if(dd > r+r2){
                cout << "NO" <<endl;
            }else{
                if(d < r*2 && d < r2*2){
                    cout << "YES" <<endl;
                }else if(dd == 0 && may*2 >= d){
                    cout << "YES" << endl;
                }else if(dd + men < may && d < may*2){
                    cout << "YES" <<endl;
                }else if(dd == men + may && d <= may*2+men*2){
                    cout << "YES" << endl;
                }else if(r == r2 && dd <= r*2 && r*2+dd>=d){
                    cout << "YES" << endl;
                }
                else{
                    cout << "NO" << endl;
                }
            }
        }
        
    }
}