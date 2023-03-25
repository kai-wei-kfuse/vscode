#include <algorithm>
#include <iostream>
using namespace std;
int lx[10][10], ly[10][10], la[10][10];
int m[10][10];
struct xx {
    int num, sum;
} node[10];
int ans = -1;
//如果无解就会无法搜到最后，就不会执行求值，所以ans一直为-1，最后输出即可
bool cmp(xx a, xx b) {
    return a.sum > b.sum;
}
void dfs(int x, int y) {
    int x_ = x;       // x代表自然行号
    x = node[x].num;  // x_为排序后的行号
    if (x_ == 10) {
        int sum = 0;
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                sum += m[i][j] * min(10 - abs(i - 5), 10 - abs(j - 5));
            }
        }
        ans = max(ans, sum);
        return;
    }
    if (y == 10) {
        dfs(x_ + 1, 1);
        return;
    }
    if (m[x][y]) {
        dfs(x_, y + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!lx[y][i] && !ly[x][i] &&
                !la[(x - 1) / 3 * 3 + (y - 1) / 3][i]) {
                lx[y][i] = 1;
                ly[x][i] = 1;
                la[(x - 1) / 3 * 3 + (y - 1) / 3][i] = 1;
                m[x][y] = i;
                dfs(x_, y + 1);
                lx[y][i] = 0;
                ly[x][i] = 0;
                la[(x - 1) / 3 * 3 + (y - 1) / 3][i] = 0;
                m[x][y] = 0;
            }
        }
    }
}
int main() {
    for (int i = 1; i <= 9; i++) {
        node[i].num = i;  //记录原本行号
        for (int j = 1; j <= 9; j++) {
            cin >> m[i][j];
            if (m[i][j] != 0) {  //统计当前行有几个已经填了的数字
                node[i].sum++;
                lx[j][m[i][j]] = 1;
                ly[i][m[i][j]] = 1;
                la[(i - 1) / 3 * 3 + (j - 1) / 3][m[i][j]] = 1;
            }
        }
    }
    sort(node + 1, node + 10, cmp);
    //按照已经填了的数字排序，已经填的多的房放前面
    dfs(1, 1);
    cout << ans;
}