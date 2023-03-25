#include <bits/stdc++.h>
using namespace std;

int edg1[505][505], edg2[505][505];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int x, y, ty;
        cin >> x >> y >> ty;
        int t, l;
        cin >> l >> t;
        if (ty == 0) {
            edg1[x][y] = l;
            edg2[x][y] = t;
            edg1[y][x] = l;
            edg2[y][x] = t;
        }
    }
}