#include <bits/stdc++.h>
using namespace std;
#define int long long 
int n;
vector<int> tr(200005, 0);

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
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        // vector<int> ve(n + 1);
        // iota(tr.begin(), tr.begin()+n+1, 0);
        for (int i = 1; i <= n; i++) {
            tr[i] = 0;
        }
        int tmp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            ans += query(n) - query(tmp - 1);
           // cout << query(n) << ' ' << query(tmp - 1) << endl;
            add(tmp, 1);
        }
        cout << ans << endl;
    }
}