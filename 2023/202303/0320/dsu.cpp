#include <bits/stdc++.h>
using namespace std;

vector<int> dsu(200005);
vector<int> d(200005);
int ans = 0;

int find(int x) {
    if (x != dsu[x]) {
        int rot = dsu[x];
        x = find(dsu[x]);
        d[x] += d[rot];
    }
    return x;
}

void root(int x, int y, int v) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ == y_) {
        ans += (d[y] - d[x] != v);
    } else {
        dsu[x_] = y_;
        d[x_] = v + d[y] - d[x];
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
        d[i] = 0;
    }
    for (int i = 1; i <= m; i++) {
        int x, y, v;
        cin >> x >> y >> v;
        root(x, y, v);
    }
    cout << ans << endl;
}