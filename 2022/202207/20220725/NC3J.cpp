#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

struct xx {
    int x, y, val;
    bool operator>(const xx& a) const { return val > a.val; }
};
unordered_map<pair<int, int>, vector<xx> > edge;
unordered_map<pair<int, int>, int> dist;
unordered_map<pair<int, int>, int> vis;
int a[5];
priority_queue<xx, vector<xx>, greater<xx> > Q;

int main() {
    int n;
    IOS;
    cin >> n;
    int tmp;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= 4; j++) {
            cin >> a[j];
        }
        for (int j = 1; j <= 4; j++) {
            if (a[j] > 0) {
                for (int k = 1; k <= 4; k++) {
                    if (a[k] > 0) {
                        if (j - 1 == k || j - 1 + 4 == k) {
                            edge[{a[k], i}].push_back({i, a[j], 0});
                            // cout << a[k] << ' ' << i << ' ' << a[j] << ' '
                            //      << 'd' << ' ';
                        } else {
                            edge[{a[k], i}].push_back({i, a[j], 1});
                            // cout << a[k] << ' ' << i << ' ' << a[j] << ' '
                            //      << 's' << ' ';
                        }
                    }
                    dist[{a[k], i}] = dist[{1, a[j]}] = 0x3f3f3f;
                }
            }
            // 3,1   4,1
        }
        // cout << endl;
    }
    int s1, s2, t1, t2;
    cin >> s1 >> s2 >> t1 >> t2;
    // for (auto i : dist)
    //     i.second = 0x3f3f3f;
    dist[{s1, s2}] = 0;
    Q.push({s1, s2, 0});
    while (!Q.empty()) {
        pair<int, int> pos;
        pos.first = Q.top().x;
        pos.second = Q.top().y;
        Q.pop();
        // cout << 'x';
        if (vis[pos])
            continue;
        vis[pos] = 1;
        for (int i = 0; i < edge[pos].size(); i++) {
            pair<int, int> now;
            now.first = edge[pos][i].x;
            now.second = edge[pos][i].y;
            int val = edge[pos][i].val;
            // cout << dist[now] << ' ';
            if (!vis[now] && dist[now] > dist[pos] + val) {
                dist[now] = dist[pos] + val;
                Q.push({now.first, now.second, dist[now]});
                // cout << dist[{t1, t2}];
            }
        }
    }
    cout << dist[{t1, t2}];
}