#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;

const ull p_ = 13331;
const int N = 1005;
char s[N][N], a[N][N];
ull h[N][N], p[N];
map<int, int> mp;

int main() {
    int hei, wei;
    cin >> hei >> wei;
    int x, y;
    cin >> x >> y;
    p[0] = 1;
    for (int i = 1; i <= max(hei, wei); i++) {
        p[i] = p[i - 1] * p_;
    }
    for (int i = 1; i <= hei; i++) {
        for (int j = 1; j <= wei; j++) {
            cin >> s[i][j];
            h[i][j] =
                p_ * (h[i - 1][j] + h[i][j - 1] - h[i - 1][j - 1]) + s[i][j];
            if (i - x + 1 >= 1 && j - y + 1 >= 1) {
                ull tmp = h[i][j] - h[i - y][j] * p[y] - h[i][];
                mp[h[i][j]] = 1;
            }
        }
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; i++) {
        for (int l = 1; l <= x; l++) {
            for (int k = 1; k < y; k++) {
            }
        }
    }
}