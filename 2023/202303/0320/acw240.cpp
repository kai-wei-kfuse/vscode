#include <bits/stdc++.h>
using namespace std;

vector<int> dsu(500005);
vector<int> d(500005);

int find(int x) {
    if (x != dsu[x]) {
        int rot = dsu[x];
        dsu[x] = find(dsu[x]);
        d[x] = (d[rot] + d[x]) % 3;
    }
    return dsu[x];
}

int ans = 0;
void root(int x, int y, int v) {
    int x_ = find(x);
    int y_ = find(y);
    if (x_ == y_) {
        ans += (v != (d[y] - d[x] + 3) % 3);
        //cout << x << ' ' << y << ' ' << v << "?" << (d[y] - d[x] + 3) % 3 << endl;
    } else {
        dsu[x_] = y_;
        d[x_] = (v + d[y] - d[x]) % 3;
    }
}

int main() {
    int n, t;
    cin >> n >> t;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;
    }
    for (int i = 1; i <= t; i++) {
        int tmp, x, y;
        cin >> tmp >> x >> y;
        if (tmp == 2 && x == y)
            ans++;
        else if (x > n || y > n)
            ans++;
        else {
            root(x, y, tmp - 1);
        }
        cout << ans << endl;
    }
}