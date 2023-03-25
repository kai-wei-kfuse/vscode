#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin >> t;
    while(t--){
        int a, b, c, d, e, f;
        cin >> a >> b >> c >> d >> e >> f;
        map<int, int> mp1,mp2;
        mp1[a]++;
        mp1[c]++;
        mp1[e]++;
         mp2[b]++;
        mp2[d]++;
        mp2[f]++;
        if(mp1.size()==2&&mp2.size()==2){
            cout << "NO" << endl;
        }else{
            cout << "YES" << endl;
        }
    }
}