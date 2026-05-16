#include <bits/stdc++.h>
using namespace std;
int main(){
    int e;
    bool n=false;
    string text;
    cin >> e;
    while(n==false){
        e++;
        text = to_string(e);
        if(text[0] != text[1] && text[0] != text[2] && text[0] != text[3] &&text[1] != text[2] && text[1] != text[3] && text[2] != text[3]){
            n = true;
        }
    }
    cout << e;

}
