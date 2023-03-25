#include <algorithm>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;
struct xxx {
    int x, y, t;
};
int xx[] = {-1, 0, 1, 0};
int yy[] = {0, 1, 0, -1};
int vis[305][305];
queue<xxx> Q;
int main() {
    int n;
    int tmpt, tmpx, tmpy;
    memset(vis, -1, sizeof(vis));
    freopen("in.txt", "r", stdin);  //输入重定向，输入数据将从in.txt文件中读取
    freopen("out.txt", "w", stdout);
    // //输出重定向，输出数据将保存out.txt文件中
    cin >> n;
    cout << n;
    for (int i = 1; i <= n; i++) {
        cin >> tmpx >> tmpy >> tmpt;
        // cout << 'd';
        cout << tmpt;
        if (vis[tmpx][tmpy] != -1)
            vis[tmpx][tmpy] = min(vis[tmpx][tmpy], tmpt);
        else
            vis[tmpx][tmpy] = tmpt;
        for (int j = 0; j < 4; j++) {
            int x = tmpx + xx[j];
            int y = tmpy + yy[j];
            if (x >= 0 && y >= 0 && x <= 300 && y <= 300) {
                if (vis[x][y] != -1)
                    vis[x][y] = min(vis[x][y], tmpt);
                else
                    vis[x][y] = tmpt;
            }
        }
        cout << vis[tmpx][tmpy] << endl;
    }
    // for (int i = 0; i <= 300; i++) {
    //     for (int j = 0; j <= 300; j++) {
    //         printf("%3d", vis[i][j]);
    //     }
    //     cout << endl;
    // }
    Q.push({0, 0, 0});
    if (vis[0][0] == -1) {
        cout << "0";
        return 0;
    }
    vis[0][0] = -2;
    while (!Q.empty()) {
        xxx tmp = Q.front();
        Q.pop();

        tmp.t++;
        for (int i = 0; i < 4; i++) {
            int x = tmp.x + xx[i];
            int y = tmp.y + yy[i];

            // cout << x << ' ' << y << ' ' << vis[x][y] << tmp.t << endl;
            if (x >= 0 && y >= 0 && x <= 300 && y <= 300 && vis[x][y] != -2) {
                if (tmp.t < vis[x][y]) {
                    // cout << x << ' ' << y << ' ' << tmp.t << endl;
                    vis[x][y] = -2;
                    Q.push({x, y, tmp.t});
                }
                if (vis[x][y] == -1) {
                    cout << tmp.t;
                    return 0;
                }
            }
        }
    }
    cout << "-1";
}