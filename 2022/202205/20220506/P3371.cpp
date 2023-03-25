#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
struct xx {
    int x, val;
};
ll dist[10005];
int vis[10005];
vector<xx> edge[10005];
int main() {
    int n, m, s;
    cin >> n >> m >> s;
    int x;
    xx tmp;
    for (int i = 1; i <= m; i++) {
        cin >> x >> tmp.x >> tmp.val;
        edge[x].push_back(tmp);
    }
    //---------------
    for (int i = 1; i <= n; i++) {
        dist[i] = 2147483647;
    }
    dist[s] = 0;
    for (int i = 1; i <= n; i++) {
        int pos;
        int minn = 2147483647;
        for (int j = 1; j <= n; j++) {
            if (!vis[j] && dist[j] < minn) {
                minn = dist[j];
                pos = j;
            }
        }
        vis[pos] = 1;
        for (int i = 0; i < edge[pos].size(); i++) {
            int now = edge[pos][i].x;
            int val = edge[pos][i].val;
            if (!vis[now] && dist[now] > dist[pos] + 1LL * val) {
                dist[now] = dist[pos] + val;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << dist[i] << ' ';
    }
}