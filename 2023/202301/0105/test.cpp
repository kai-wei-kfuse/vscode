#include <bits/stdc++.h>
using namespace std;
#define int long long
int n;
vector<int> tr(500005);
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
    vector<pair<int, int>> ve(n + 1);
    vector<int> t(n + 1);
    int a = 0;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i].first;
        ve[i].second = i;
    }
    sort(ve.begin() + 1, ve.end());
    for (int i = 1; i <= n; i++) {
        t[ve[i].second] = i;
    }
    for (int i = 1; i <= n; i++) {
        a += query(n) - query(t[i]);
        add(t[i], 1);
    }
    cout << a;
}