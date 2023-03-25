#include <iostream>
#include <queue>
using namespace std;
int n, m;
char a[302][302];
int vis[302][302];
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
struct xxx {
    int x, y, z;
};

queue<xxx> Q;
int main() {
    // freopen("in.txt", "r", stdin);
    // //输入重定向，输入数据将从in.txt文件中读取
    // freopen("out.txt", "w", stdout);
    // //输出重定向，输出数据将保存out.txt文件中
    cin >> n >> m;
    // cout << n << ' ' << m << endl;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            if (a[i][j] == '@') {
                vis[i][j] = 1;
                Q.push({i, j, 0});
            }
        }
    }
    while (!Q.empty()) {
        xxx tmp = Q.front();

        Q.pop();
        // cout << tmp.x << ' ' << tmp.y << endl;
        tmp.z++;
        // if (a[tmp.x][tmp.y] == '=') {
        //     cout << tmp.z - 1;
        //     return 0;
        // }
        if (a[tmp.x][tmp.y] >= 'A' && a[tmp.x][tmp.y] <= 'Z') {
            int flag = 1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (a[i][j] == a[tmp.x][tmp.y] &&
                        (tmp.x != i || tmp.y != j)) {
                        tmp.x = i;
                        tmp.y = j;
                        // vis[i][j] = 1;
                        flag = 0;
                        // cout << i << ' ' << j << endl;
                        break;
                    }
                }
                if (flag == 0)
                    break;
            }
        }

        for (int i = 0; i < 4; i++) {
            int x = tmp.x + xx[i];
            int y = tmp.y + yy[i];
            if (x > 0 && y > 0 && x <= n && y <= m && a[x][y] != '#' &&
                vis[x][y] == 0) {
                vis[x][y] = 1;
                // cout << x << ' ' << y << endl;
                if (a[x][y] == '=') {
                    cout << tmp.z;
                    return 0;
                }
                Q.push({x, y, tmp.z});
            }
        }
    }
}