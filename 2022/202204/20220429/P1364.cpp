#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;
int dist[105][105];
int num[105], len[105];
int main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            dist[i][j] = 5000;
        }
    }
    int tmp, x, y;
    for (int i = 1; i <= n; i++) {
        cin >> num[i] >> x >> y;
        dist[i][i] = 0;
        if (x != 0) {
            dist[i][x] = 1;
            dist[x][i] = 1;
        }
        if (y != 0) {
            dist[y][i] = 1;
            dist[i][y] = 1;
        }
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= n; j++) {
    //         // len[i] += num[j] * dist[i][j];
    //         cout << dist[i][j] << ' ';
    //     }
    //     cout << endl;
    // }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (dist[i][j] > dist[i][k] + dist[k][j]) {
                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            len[i] += num[j] * dist[i][j];
            // cout << dist[i][j] << ' ';
        }
        // cout << endl;
    }
    int ans = 0x3f3f3f;
    for (int k = 1; k <= n; k++) {
        ans = min(ans, len[k]);
    }
    cout << ans;
}