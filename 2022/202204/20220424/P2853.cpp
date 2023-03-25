#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int cow[105];
int vis[1005], vis2[10005];
int mp[2005][2005];
int sum, ans;
int k, n, m;
void dfs(int x) {
    for (int i = 1; i <= n; i++) {
        if (vis[i] == 0 && mp[x][i] == 1) {
            vis[i] = 1;
            vis2[i]++;
            dfs(i);
        }
    }
    return;
}
int main() {
    cin >> k >> n >> m;
    int tmp;
    for (int i = 1; i <= k; i++) {
        int l;
        cin >> l;
        cow[i] = l;
        // mp[cow][cow] = 2;
    }
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        mp[x][y] = 1;
    }
    for (int i = 1; i <= k; i++) {
        // sum = 0;
        //  if (cow[i])
        //      sum++;
        memset(vis, 0, sizeof(vis));
        vis[cow[i]] = 1;
        vis2[cow[i]]++;
        dfs(cow[i]);
        // if (sum == k)
        //     ans++;
    }
    for (int i = 1; i <= n; i++) {
        if (vis2[i] == k)
            ans++;
    }
    cout << ans;
}
/*
2 4 4
2
3
1 2
1 4
2 3
3 4
*/