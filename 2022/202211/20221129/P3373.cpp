#include <bits/stdc++.h>
using namespace std;
#define int long long
int mod;
const int N = 1e5 + 5;
vector<int> ve(N);
struct node {
    int l, r;
    int sum;
    int add, mul;
} tr[N * 4];

void pushup(int u) {
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % mod;
}

void fuc(int u, int add, int mul) {
    tr[u].add = (tr[u].add * mul % mod + add) % mod;
    tr[u].mul = tr[u].mul * mul % mod;
    tr[u].sum =
        ((tr[u].r - tr[u].l + 1) * add % mod + tr[u].sum * mul % mod) % mod;
}

void pushdown(int u) {
    fuc(u<<1, tr[u].add, tr[u].mul);
    fuc(u<<1|1, tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, ve[r], 0, 1};
        return;
    }
    tr[u]={l, r, 0, 0, 1};
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void modify(int u, int l, int r, int add, int mul) {
    if (tr[u].l >= l && tr[u].r <= r) {
        fuc(u, add, mul);
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, add, mul);
    if (r > mid)
        modify(u << 1 | 1, l, r, add, mul);
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
        sum = (sum + query(u << 1 | 1, l, r)) % mod;
    return sum;
}

signed main() {
    int n;
    cin >> n >> mod;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    build(1, 1, n);
    int t;
    cin >> t;
    while (t--) {
        int q, l, r, x;
        cin >> q >> l >> r;
        if (q == 1) {  // mul
            cin >> x;
            modify(1, l, r, 0, x);
        } else if (q == 2) {
            cin >> x;
            modify(1, l, r, x, 1);
        } else {
            cout << query(1, l, r) << endl;
        }
    }
}