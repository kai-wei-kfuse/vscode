#include <iostream>
#include <queue>
using namespace std;
char a[105][105];
int vis[105][105];
int xx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
int yy[] = {0, 1, 1, 1, 0, -1, -1, -1};
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    int sum = 0;
    queue<pair<int, int> > Q;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (vis[i][j] == 0 && a[i][j] == 'W') {
                Q.push(make_pair(i, j));
                while (!Q.empty()) {
                    int x_ = Q.front().first;
                    int y_ = Q.front().second;
                    Q.pop();
                    for (int i = 0; i < 8; i++) {
                        int x = x_ + xx[i];
                        int y = y_ + yy[i];
                        if (x > 0 && y > 0 && x <= n && y <= m &&
                            vis[x][y] == 0 && a[x][y] == 'W') {
                            vis[x][y] = 1;
                            Q.push(make_pair(x, y));
                        }
                    }
                }
                sum++;
            }
        }
    }
    cout << sum;
}