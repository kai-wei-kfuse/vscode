#include <algorithm>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
int sta[1010], map[1010][1010], in[1010];
bool vis[1010];
int main() {
    int t, n, m;
    queue<int> q;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        memset(vis, 0, sizeof(vis));
        cin >> t;
        for (int j = 1; j <= t; j++) {
            cin >> sta[j];
            vis[sta[j]] = true;
        }
        for (int j = sta[1]; j < sta[t]; j++) {
            if (!vis[j]) {
                vis[j] = true;
                for (int k = 1; k <= t; k++) {
                    if (map[j][sta[k]] == 0) {  //把没有停下的车站连接到停下的
                        map[j][sta[k]] = 1;
                        in[sta[k]]++;
                    }
                }
            }
        }
    }
    memset(vis, 0, sizeof(vis));
    int ans = 0;
    while (1) {  //只要还有数就一直循环
        for (int i = 1; i <= n; i++) {
            if (in[i] == 0 && !vis[i]) {
                q.push(i);
                vis[i] = true;
            }
        }
        if (q.empty())
            break;  //一旦都找完了，就跳出
        while (!q.empty()) {
            for (int i = 1; i <= n; i++) {
                if (map[q.front()][i] == 1) {
                    map[q.front()][i] = 0;
                    in[i]--;
                }
            }
            q.pop();  //每找完一个就把找的弹出来
        }
        ans++;
    }
    cout << ans;
}