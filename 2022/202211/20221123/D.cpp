#include <bits/stdc++.h>
using namespace std;
#define int long long

int n, k;
vector<int> ve(3e5 + 5);

int chack(int x) {
    int res = 0, idx = 1;
 //cout << "x=" << x << endl;
    vector<int> back(x + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (ve[i] >= back[idx] * 2) {
            back[idx] = ve[i];
           // cout << back[idx] << ' ';

            if (idx == x) {
                res++;
                idx = 1;
               // cout << endl;
            } else
                idx++;
        }
    }
    // cout << res << endl;
    if (res >= k) {
        return 1;
    } else {
        return 0;
    }
}
signed main() {
    int t,ca=1;
    cin >> t;
    while (t--) {
        cin >> n >> k;

        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        sort(ve.begin() + 1, ve.begin()+n+1);
        int l = 0, r = n/k;
        while (l < r) {
            int mid = (l + r + 1) / 2;
            if (chack(mid)) {
                l = mid;
            } else {
                r = mid - 1;
            }
        }
        cout << "Case #" << ca++ << ": ";
        cout << l << endl;

    }
}