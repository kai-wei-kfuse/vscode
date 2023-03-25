
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

const int N = 2e4 + 500;
vector<pair<int, int> > p(N);
vector<int> ve, mp(2 * N);
int ans = 0;
struct node {
    int l, r;
    int col;
    int lazy;
} tr[N * 8];

void build(int u, int l, int r) {
    // tr[u] = {l, r, 0, 0};
    tr[u].l = l, tr[u].r = r, tr[u].lazy = 0, tr[u].col = 0;
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
        tr[u].col = col;
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
        // cout << tr[u].col << ' ';
        if (tr[u].col != 0 && mp[tr[u].col] == 0) {
            mp[tr[u].col] = 1;
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
        ve.clear();
        for (int i = 0; i <= 2 * n; i++) {
            mp[i] = 0;
        }
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            cin >> p[i].first >> p[i].second;
            ve.push_back(p[i].first), ve.push_back(p[i].second);
        }
        sort(ve.begin(), ve.end());
        ve.erase(unique(ve.begin(), ve.end()), ve.end());
        int tmp = ve.size();

        for (int i = 1; i < tmp-1; i++) {
            if (ve[i] - ve[i - 1] > 1) {
                ve.push_back(ve[i - 1] + 1);
            }
        }
        tmp = ve.size();
        build(1, 1, tmp);
        sort(ve.begin(), ve.end());
        for (int i = 1; i <= n; i++) {
            int l, r;
            l = lower_bound(ve.begin(), ve.end(), p[i].first) - ve.begin();
            r = lower_bound(ve.begin(), ve.end(), p[i].second) - ve.begin();
             //cout << l+1  << ' ' << r+1  << endl;
            modify(1, l+1 , r+1 , i);
        }
        ans = 0;
        query(1, 1, tmp);
        // cout << endl;
        cout << ans << endl;
    }
}