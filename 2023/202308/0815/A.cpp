#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        if(c&1){
            if(a>=b){
                cout<<"First\n";
            }else{
                cout<<"Second\n";
            }
        }else{
            if(a>b){
                cout<<"First\n";
            }else{
                cout<<"Second\n";
            }
        }
    }
}