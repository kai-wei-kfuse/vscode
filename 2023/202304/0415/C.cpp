#include <bits/stdc++.h>
using namespace std;

struct xx {
    int tag, l, r;
    // 构造函数
    xx() {
        tag = 0;
        l = 1e9;
        r = 0;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        map<int, xx> mp;
        int now = -1;
        int maxn = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            mp[a[i]].tag = 1;
            mp[a[i]].l = min(mp[a[i]].l, i);
            mp[a[i]].r = max(mp[a[i]].r, i);
            // cout << mp[a[i]].l << " " << mp[a[i]].r << endl;
            maxn = max(maxn, a[i]);
        }
        int mex = 0;
        for (int i = 0; i <= maxn + 1; i++) {
            if (mp[i].tag == 0) {
                mex = i;
                break;
            }
        }
        // cout << mex << endl;
        // cout << mp[mex + 1].l << " " << mp[mex + 1].r << endl;
        int flag = 0;
        for (int i = mp[mex + 1].l; i <= mp[mex + 1].r; i++) {
            if (a[i] < mex) {
                // cout << mp[a[i]].l << " " << mp[a[i]].r << " " << mp[mex].l
                //      << " " << mp[mex].r << endl;
                if (mp[a[i]].l >= mp[mex + 1].l &&
                    mp[a[i]].r <= mp[mex + 1].r) {
                    flag = 1;
                    break;
                }
            }
        }
        if (mex == n || flag == 1) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
    }
}