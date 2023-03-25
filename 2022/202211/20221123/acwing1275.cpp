#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 200010;

struct node {
    int l, r;
    int val;
} tr[N * 4];

void pushup(int u) {
    tr[u].val = max(tr[u << 1].val, tr[u << 1 | 1].val);
}
void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r)
        return;
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u].val;
    int mid = tr[u].l + tr[u].r >> 1;
    int res = 0;
    if (l <= mid)
        res = query(u << 1, l, r);
    if (r > mid)
        res = max(res, query(u << 1|1, l, r));
    return res;
}

void modify(int u, int x, int val) {
    if (tr[u].l == x && tr[u].r == x)
        tr[u].val = val;
    else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, val);
        else
            modify(u << 1 | 1, x, val);
        pushup(u);
    }
}

signed main() {
    int n=0, m, p;
    cin >> m >> p;
    build(1, 1, m);
    char a;
    int x, tmp = 0;
    for (int i = 1; i <= m; i++) {
        cin >> a >> x;
        if (a == 'Q') {
            tmp = query(1, n - x + 1, n);
            cout << tmp << endl;
        } else {
            modify(1, n + 1, (tmp + x) % p);
            n++;
        }
    }
    return 0;
}