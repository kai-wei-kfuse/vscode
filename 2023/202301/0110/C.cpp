#include <bits/stdc++.h>
using namespace std;
int fa[120];
int find(int x) {
    while (fa[x] != x) {
        x = fa[x] = fa[fa[x]];
    }
    return x;
}
void root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        fa[x_] = y_;
    }
}
int main() {
    int n, edg;
    cin >> n >> edg;
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 1; i <= edg; i++) {
        int x, y;
        cin >> x >> y;
        root(x, y);
    }
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        if (fa[i] == i)
            ans++;
    }
    cout << ans;
}