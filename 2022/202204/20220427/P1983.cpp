#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int vis[1005], sta[1005], in[1005];
int mp[1005][1005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int tmp;
        memset(vis, 0, sizeof(vis));
        cin >> tmp;
        for (int j = 1; j <= tmp; j++) {
            cin >> sta[j];
            vis[sta[j]] = 1;
        }
        for (int j = sta[1]; j <= sta[tmp]; j++) {
            if (vis[j] == 0) {
                vis[j] = 1;
                for (int k = 1; k <= tmp; k++) {
                    if (mp[sta[k]][j] == 0) {
                        mp[sta[k]][j] = 1;
                        in[sta[k]]++;
                    }
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    queue<int> Q;
    while (1) {
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0 && vis[i] == 0) {
                Q.push(i);
                vis[i] = 1;
            }
        }
        if (Q.empty())
            break;
        while (!Q.empty()) {
            int x = Q.front();
            Q.pop();
            for (int i = 1; i <= n; i++) {
                if (mp[i][x] == 1) {
                    mp[i][x] = 0;
                    in[i]--;
                }
            }
        }
        ans++;
    }
    cout << ans;
}