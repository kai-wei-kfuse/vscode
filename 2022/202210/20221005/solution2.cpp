#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    ll n;
    cin >> n;
    vector<ll> ans;
    while(n>0){
        if(n%3==1){
            ans.push_back(1);
            n--;
        }else if(n%3==2){
            ans.push_back(1);
            ans.push_back(1);
            n -= 2;
        }else if(n%3==0){
            ans.push_back(2);
            n /= 3;
        }
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size()<<endl;
    for(auto i:ans){
        cout << i << ' ';
    }    
}