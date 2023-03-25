#include<bits/stdc++.h>
using namespace std;

#define int long long
signed main(){
    int n, k;
    cin >> n >> k;
    vector<int> ve(n + 4),pre(n+4,0);
    vector<int> t(n + 5);
    for (int i = 1; i <= n;i++){
        cin >> ve[i];
    }
    int res = 0;
    int ans = 0;
    for (int i = 1; i <= n;i++){
        cin >> t[i];
        if(t[i]==1){
            pre[i] = pre[i - 1];
            res += ve[i];
        }else{
            pre[i] = pre[i - 1] + ve[i];
        }
    } 
    int maxn = 0;
    for (int i = k; i <= n;i++){
        maxn = max(pre[i] - pre[i - k],maxn);
    }
    cout << maxn+res;
}