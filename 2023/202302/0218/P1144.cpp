#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
const int mod = 100003;
vector<int> edg[N];
int vis[N], dp[N],dep[N];

int main() {
    int n, m;
    cin >> n >> m;
    // memset(dp, 127, sizeof dp);
    for (int i = 1; i <= m; i++) {
        int x, y;
        cin >> x >> y;
        edg[x].push_back(y);
        edg[y].push_back(x);
    }
    queue<int> q;
    q.push(1);
    dp[1] = 1;
    dep[1] = 1;
    vis[1] = 1;
    while (!q.empty()) {
        int pos = q.front();
        q.pop();
       // if (vis[pos]) continue;
        //vis[pos] = 1;
        for (auto i : edg[pos]) {
            if(!vis[i]){
                q.push(i);
                dep[i] = dep[pos] + 1;
                vis[i] = 1;
            }
            if(dep[pos]+1==dep[i]){
                dp[i] =(dp[i]+ dp[pos])%mod;
            }
        }
    // for (int i = 1; i <= n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    }
    for (int i = 1; i <= n; i++) {
        cout << dp[i] << '\n';
    }
}