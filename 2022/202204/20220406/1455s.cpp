#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
char a[32][52];
int vis[32][52];
int xx[] = {1, 0, 0, -1};
int yy[] = {0, -1, 1, 0};
int strings[] = {'D', 'L', 'R', 'U'};
string s;
struct node {
    int x, y;
    string s;
    node(int a, int b, string c) : x(a), y(b), s(c) {}
};
queue<node> Q;
int main() {
    freopen("in.txt", "r", stdin);
    for (int i = 1; i <= 30; i++) {
        for (int j = 1; j <= 50; j++) {
            cin >> a[i][j];
        }
    }
    vis[1][1] = 1;
    Q.push(node(1, 1, ""));
    while (!Q.empty()) {
        node now = Q.front();
        Q.pop();
        if (now.x == 30 && now.y == 50) {
            cout << now.s;
            break;
        }
        for (int i = 0; i <= 3; i++) {
            int x = now.x + xx[i];
            int y = now.y + yy[i];
            if (x >= 1 && y >= 1 && x <= 30 && y <= 50 && a[x][y] == '0' &&
                vis[x][y] == 0) {
                string s = now.s;
                s += strings[i];
                vis[x][y] = 1;
                Q.push(node(x, y, s));
            }
        }
    }
}