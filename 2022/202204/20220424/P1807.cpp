#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
struct xx {
    int x, val;
};
queue<xx> Q;
vector<xx> edge[50005];
int dist[2000];
int main() {
    int n, m;
    cin >> n >> m;
    int x, y, val;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y >> val;
        edge[x].push_back({y, val});
    }
    Q.push({1, 0});

    memset(dist, -1, sizeof(dist));
    dist[1] = 0;
    while (!Q.empty()) {
        xx tmp = Q.front();
        Q.pop();
        for (int i = 0; i < edge[tmp.x].size(); i++) {
            xx now = edge[tmp.x][i];
            if (dist[now.x] < dist[tmp.x] + now.val) {
                dist[now.x] = dist[tmp.x] + now.val;
                Q.push(now);
            }
        }
    }
    cout << dist[n];
}