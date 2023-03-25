#include <iostream>
using namespace std;
int lx[10][10], ly[10][10], la[10][10];
int m[10][10];
void dfs(int x, int y) {
    if (x == 10) {
        for (int i = 1; i <= 9; i++) {
            for (int j = 1; j <= 9; j++) {
                cout << m[i][j] << ' ';
            }
            cout << endl;
        }
        return;
    }
    if (y == 10) {
        dfs(x + 1, 1);
        return;
    }
    if (m[x][y]) {
        dfs(x, y + 1);
    } else {
        for (int i = 1; i <= 9; i++) {
            if (!lx[y][i] && !ly[x][i] &&
                !la[(x - 1) / 3 * 3 + (y - 1) / 3][i]) {
                lx[y][i] = 1;
                ly[x][i] = 1;
                la[(x - 1) / 3 * 3 + (y - 1) / 3][i] = 1;
                m[x][y] = i;
                dfs(x, y + 1);
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
        for (int j = 1; j <= 9; j++) {
            cin >> m[i][j];
            if (m[i][j] != 0) {
                lx[j][m[i][j]] = 1;
                ly[i][m[i][j]] = 1;
                la[(i - 1) / 3 * 3 + (j - 1) / 3][m[i][j]] = 1;
            }
        }
    }
    dfs(1, 1);
}