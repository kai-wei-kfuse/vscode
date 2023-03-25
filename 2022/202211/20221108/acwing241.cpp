#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n;
vector<int> tr(200005), great(200005), low(200005);
int lowbit(int x) {
    return x & (-x);
}
void add(int i, int x) {
    while (i <= n) {
        tr[i]++;
        i += lowbit(i);
    }
}
int query(int i) {
    int res = 0;
    while (i != 0) {
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}
signed main() {
    cin >> n;
    vector<int> ve(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        great[i] = query(n) - query(ve[i]);
        low[i] = query(ve[i] - 1);
        add(ve[i], 1);
    }
    for (int i = 1; i <= n;i++) {
        tr[i] = 0;
    }
    int a = 0, b = 0;
    for (int i = n; i >= 1; i--) {
        a += great[i] * (query(n) - query(ve[i]));
        b += low[i] * query(ve[i] - 1);
        add(ve[i], 1);
    }
    cout << a << ' ' << b;
}