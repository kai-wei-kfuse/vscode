#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tr(500005);
int lowbit(int x) {
    return x & (-x);
}
void add(int i, int x) {
    while (i <= n) {
        tr[i] += x;
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
int main() {
    int k;
    cin >> n >> k;
    int tmp;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int a, l, r, x;
    while (k--) {
        cin >> a;
        if (a == 1) {
            cin >> l >> r >> x;
            add(l, x);
            add(r + 1, -x);
        } else {
            cin >> x;
            cout << query(x)+ve[x] << endl;
        }
    }
}