#include <bits/stdc++.h>
using namespace std;
#define int long long

int vis[1005];
int flag = 0;
int a, b, c;
int n;

int fun(int x, int last, int flag) {
    if (x == 0 && flag == 0) {
        fun(n, c, 1);
    }
    if (x == 0 && flag == 1) {
        return last;
    }
    for (int i = x; i >= 1; i--) {
        if (last >= i && !vis[i]) {
            vis[i] = 1;
            fun(i - 1, last - i, flag);
            vis[i] = 0;
        }
    }
}

signed main() {
    int  k, e;
    cin >> n >> k >> e;
     a = e, b = k, c = n - a - b;
    vector<int> vis(n + 1, 0);
    // priority_queue<int> q;
    // q.push(a), q.push(c);
    vis[b] = 1;
    int ans = 0x3f3f3f3f;
    int res = 0;
    res += fun(n, a, 0);
    for (int i = 1; i <= n; i++) {
        vis[i] = 0;
    }

    cout << ans << endl;
}