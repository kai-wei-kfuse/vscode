#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    vector<pair<int, int> > ve(n+1);
    for (int i = 1; i <= n;i++){
        cin >> ve[i].first >> ve[i].second;
    }
    sort(ve.begin() + 1, ve.end());
    vector<int> q(n + 1);
    int len = 0;
    int maxn = 0;
    for (int i = 1;i<=n;i++){
        if(q[len]<ve[i].second){
            q[++len] = ve[i].second;
        }else{
            int pos = lower_bound(q.begin() + 1, q.begin() + 1 + len, ve[i].second) - q.begin();
            q[pos] = ve[i].second;
            len = max(len, pos);
        }
    }
    cout << len;
}