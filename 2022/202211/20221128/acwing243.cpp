#include <bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e5 + 5;
vector<int> ve(N);
struct node {
    int l, r;
    int sum;
    int lazy;
} tr[N * 4];

void pushup(int u) {
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u) {
    auto &fa = tr[u], &l = tr[u << 1], &r = tr[u << 1 | 1];
    if (fa.lazy) {
        l.lazy += fa.lazy, r.lazy += fa.lazy;
        l.sum += (l.r - l.l + 1) * fa.lazy;
        r.sum += (r.r - r.l + 1) * fa.lazy;
        fa.lazy = 0;
    }
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, ve[r], 0};
        return;
    }
    tr[u].r = r, tr[u].l = l;
    int mid = r + l >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u].sum;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    int sum = 0;
    if (l <= mid)
        sum = query(u << 1, l, r);
    if (r > mid)
        sum += query(u << 1 | 1, l, r);
    return sum;
}

void modify(int u, int l, int r, int x) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].lazy += x;
        tr[u].sum += (tr[u].r - tr[u].l + 1) * x;
    } else {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, x);
        if (r > mid)
            modify(u << 1 | 1, l, r, x);
        pushup(u);
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    build(1, 1, n);
    while (k--) {
        char c;
        cin >> c;
        int l, r, d;
        if (c == 'Q') {
            cin >> l >> r;
            cout << query(1, l, r) << endl;
        } else {
            cin >> l >> r >> d;
            modify(1, l, r, d);
        }
    }
}