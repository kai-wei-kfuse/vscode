#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        for (int i = 1; i <= n+m;i++){
            int x;
            cin >> x;
        }
        if(n>m){
            cout << "No" << endl;
        }else{
            cout << "Yes" << endl;
        }
    }
}