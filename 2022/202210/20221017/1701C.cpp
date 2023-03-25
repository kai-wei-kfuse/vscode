#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ve(k + 1);
        vector<int> mp(k+1,0);
        for (int i = 1; i <= k; i++) {
            cin >> ve[i];
            mp[ve[i]]++;
        }
        auto chack = [&](int t) {
            int last = 0, more = 0;
            for (int i = 1; i <= n;i++) {
                if (t >= mp[i]) {
                    last += (t - mp[i]) / 2;
                    //时间足够，last是多出来的时间所能做的工作数
                } else {
                    more += (mp[i] - t);
                    //时间不够，需要别人来帮忙的工作数量
                }
            }
           // cout << more << ' ' << last << endl;
            return more <= last;
            //如果多出来能做的工作数大于等于需要帮忙的工作数，说明在t时间内可以做完。
        };
        int l = 0, r = 2 * k, mid;
        int res;
        while (l<r) {
            mid = (r + l) >> 1;
           // cout << mid << ' ';
            if (chack(mid)) {
                //cout << res << endl;
               // res = mid;
                r = mid;
            } else {
                l = mid+1;
            }
        }
        cout << r << endl;
    }
}