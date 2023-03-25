#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int dist[105][105];
int mp[105][105];
int main() {
    int n, m;
    cin >> m >> n;
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= m; j++) {
            dist[i][j] = 1e8;
            mp[i][j] = 1e8;
        }
        dist[i][i] = 0;
        mp[i][i] = 0;
    }
    int x, y, tmp;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y >> tmp;
        mp[x][y] = tmp;
        mp[y][x] = tmp;
        dist[x][y] = tmp;
        dist[y][x] = tmp;
    }
    int ans = 1e8;
    for (int k = 1; k <= m; k++) {
        for (int i = 1; i < k; i++) {
            for (int j = i + 1; j < k; j++) {
                ans = min(ans, dist[i][j] + mp[j][k] + mp[k][i]);
            }
        }
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= m; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    if (ans == 1e8)
        cout << "No solution.";
    else {
        cout << ans;
    }
}