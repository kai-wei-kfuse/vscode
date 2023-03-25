// #include <bits/stdc++.h>
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 2e4 + 500;
vector<pair<int, int> > p(N);
vector<int> ve(2 * N), mp(2 * N);
int ans = 0;
struct node {
    int l, r;
    int lazy;
    int col;
} tr[N * 8];

void build(int u, int l, int r) {
    // tr[u] = {l, r, 0, 0};
    tr[u].l = l, tr[u].r = r, tr[u].lazy = 0;
    if (l == r) {
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

void pushdown(int u) {
    node &fa = tr[u], &L = tr[u << 1], &R = tr[u << 1 | 1];
    if (fa.lazy) {
        L.lazy = fa.lazy, R.lazy = fa.lazy;
        L.col = fa.col, R.col = fa.col;
        fa.lazy = 0;
    }
}

void modify(int u, int l, int r, int col) {
    if (tr[u].l >= l && tr[u].r <= r) {
        tr[u].lazy = col;
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        modify(u << 1, l, r, col);
    if (r > mid)
        modify(u << 1 | 1, l, r, col);
}

void query(int u, int l, int r) {
    if (tr[u].l == tr[u].r) {
        // cout << tr[u].lazy<< ' ';
        if (tr[u].lazy != 0 && mp[tr[u].lazy] == 0) {
            mp[tr[u].lazy] = 1;
            ans++;
        }
        return;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid)
        query(u << 1, l, r);
    if (r > mid)
        query(u << 1 | 1, l, r);
    return;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 0; i <= 2 * n; i++) {
            mp[i] = 0;
        }
        int cnt = 1;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
            ve[cnt++] = p[i].first, ve[cnt++] = p[i].second;
        }
        sort(ve.begin() + 1, ve.begin() + 2 * n + 1);
        int tot = unique(ve.begin() + 1, ve.begin() + 2 * n + 1) - ve.begin();
        cout << tot << endl;  // 1 2 3 4 6 7 8 10
        int tmp = tot;
        for (int i = 2; i < tmp; i++) {
            if (ve[i] - ve[i - 1] > 1) {
                ve[++tot] = ve[i - 1] + 1;
            }
        }
        sort(ve.begin() + 1, ve.begin() + tot);
        for (int i = 1; i < tot; i++) {
            cout << ve[i] << ' ';
        }
        cout << endl;
        build(1, 1, tot - 1);
        for (int i = 1; i <= n; i++) {
            int l, r;
            l = lower_bound(ve.begin() + 1, ve.begin() + tot, p[i].first) -
                ve.begin();
            r = lower_bound(ve.begin() + 1, ve.begin() + tot, p[i].second) -
                ve.begin();
            cout << l << ' ' << r << endl;
            modify(1, l, r, i);
        }
        ans = 0;
        query(1, 1, tot - 1);
        // cout << endl;
        cout << ans << endl;
    }
}