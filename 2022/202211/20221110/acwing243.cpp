#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, k;
vector<int> tr1(100005), tr2(100005);
int lowbit(int x) {
    return x & (-x);
}
void add(vector<int> &tr, int i, int x) {
    while (i <= n) {
        tr[i] += x;
        i += lowbit(i);
    }
}
int query(vector<int> &tr, int i) {
    int res = 0;
    while (i) {
        res += tr[i];
        i -= lowbit(i);
    }
    return res;
}

signed main() {
    cin >> n >> k;
    vector<int> ve(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        int tmp = ve[i] - ve[i - 1];
        add(tr1, i, tmp);
        add(tr2, i, i * tmp);
    }
    for (int i = 1; i <= k; i++) {
        string s;
        cin >> s;
        if (s == "C") {
            int l, r, x;
            cin >> l >> r >> x;
            add(tr1, l, x);
            add(tr1, r + 1, -x);
            add(tr2, l, x * l);
            add(tr2, r + 1, -(r + 1) * x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << query(tr1, r) * (r + 1)  - query(tr2, r)  -
                        query(tr1, l - 1) * l  + query(tr2, l - 1) 
                 << endl;
        }
    }
}