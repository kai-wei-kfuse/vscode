#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
vector<int> ve(N, 0);

struct node {
    int l, r;
    int gcd_;
    int sum;
} tr[N * 4];

void pushup(node& u, node& l, node& r) {
    u.sum = l.sum + r.sum;
    u.gcd_ = __gcd(l.gcd_, r.gcd_);
}
void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u] = {l, r, ve[r], ve[r]};
    } else {
        tr[u].l = l, tr[u].r = r;
        int mid = l + r >> 1;
        build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int x, int val) {
    if (tr[u].l == x && tr[u].r == x) {
        int v = tr[u].sum + val;
        tr[u] = {x, x, v, v};
    } else {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, val);
        else
            modify(u << 1 | 1, x, val);
        pushup(u);
    }
}

node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r) {
        return tr[u];
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid)
        return query(u << 1, l, r);
    else if (l > mid)
        return query(u << 1 | 1, l, r);
    else {
        auto R = query(u << 1, l, r);
        auto L = query(u << 1 | 1, l, r);
        node res;
        pushup(res, L, R);
        return res;
    }
}

signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    for (int i = n; i >= 1; i--) {
        ve[i] = ve[i] - ve[i - 1];
    }

    build(1, 1, n);
   // cout << "gg" << endl;
    for (int i = 1; i <= m; i++) {
        char a;
        cin >> a;
        if (a == 'Q') {
            int l, r;
            cin >> l >> r;
            node right({0, 0, 0, 0});
            if (l + 1 <= r)
                right = query(1, l + 1, r);
           // cout << "xx" << endl;
            cout << abs(__gcd(query(1, 1, l).sum, right.gcd_))<<endl;
        } else {
            int l, r, x;
            cin >> l >> r >> x;
            modify(1, l, x);
            if (r + 1 <= n)  // 别忘记边界条件
                modify(1, r + 1, -x);
        }
    }
}