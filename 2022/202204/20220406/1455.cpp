#include <algorithm>
#include <iostream>
using namespace std;
char a[32][52];
int vis[32][52];
int xx[] = {1, 0, 0, -1};
int yy[] = {0, -1, 1, 0};
int strings[] = {'D', 'L', 'R', 'U'};
string s;
int minn = 0x3f3f3f, minnn = 0x3f3f3f;
void dfs(int ax, int by, int sum, int dsum) {
    if (ax == 30 && by == 50) {
        if (sum <= minn) {
            minn = sum;
            if (dsum <= minnn) {
                minnn = dsum;
                cout << s << endl;
            }
        }
        return;
    }
    for (int i = 0; i <= 3; i++) {
        int x = ax + xx[i];
        int y = by + yy[i];
        if (x >= 1 && y >= 1 && x <= 30 && y <= 50 && a[x][y] == '0' &&
            vis[x][y] == 0) {
            vis[x][y] = 1;
            s += strings[i];
            dfs(x, y, sum + 1, dsum + i + 1);
            s.pop_back();
            vis[x][y] = 0;
        }
    }
}
int main() {
    freopen("in.txt", "r", stdin);  //输入重定向，输入数据将从in.txt文件中读取
    // freopen("out.txt", "w", stdout);
    // //输出重定向，输出数据将保存out.txt文件中
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 50; j++) {
            cin >> a[i][j];
        }
    }
    vis[1][1] = 1;
    dfs(1, 1, 0, 0);
    cout << "1";
}