#include <bits/stdc++.h>
using namespace std;

struct xx {
    int x, val;
    bool operator>(const xx& a) const { return val > a.val; };
};

vector<xx> edg[2505];
priority_queue<xx, vector<xx>, greater<xx> > Q;
long long dist[2505];
int vis[2505];

int main() {
    int t, c, s, e;
    cin >> t >> c;
    int x, y, val;
    for (int i = 1; i <= c; i++) {
        cin >> x >> y >> val;
        edg[x].push_back({y, val});
        edg[y].push_back({x, val});
    }
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    Q.push({1, 0});
    while (!Q.empty()) {
        int pos = Q.top().x;
        Q.pop();
        if (vis[pos]) continue;
        vis[pos] = 1;
        for (auto i : edg[pos]) {
            if (!vis[i.x] && dist[i.x] > dist[pos] + i.val) {
                dist[i.x] = dist[pos] + i.val;
                Q.push({i.x, (int)dist[i.x]});
            }
        }
    }
    long long maxn = 0;
    for (int i = 1; i <= t;i++){
        maxn = max(dist[i], maxn);
    }
    if(maxn>0x3f3f3f3f3f){
        cout << "-1";
    }else
    cout << maxn;
}