#include <iostream>
#include <map>
using namespace std;
#define int long long

int a[105], val[105], dp[105];
struct xx {
    int num, lim, val;
};

signed main() {
    int m, n;
    cin >> m >> n;
    int v = 21 - m;
    map<string, xx> mp;  // pair<数量，上限>
    int b, c, lim, cnt = 0;
    string str;
    for (int i = 1; i <= n; i++) {
        cin >> b >> c >> lim >> str;
        mp[str].lim = lim;
        mp[str].val = c;
        mp[str].num += b;
    }
    for (auto i : mp) {
        if (i.second.num > 0) {
            for (int j = 1; j <= i.second.num / i.second.lim; j++)
                val[++cnt] = i.second.lim * i.second.val;
            if (i.second.num % i.second.lim > 0)
                val[++cnt] = i.second.num % i.second.lim * i.second.val;
        }
    }
    // for (int i = 1; i <= cnt; i++) {
    //     cout << val[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= cnt; i++) {
        for (int j = v; j >= 1; j--) {
            dp[j] = max(dp[j], dp[j - 1] + val[i]);
        }
    }
    cout << dp[v];
}
/*
19 3
63 1 64 yinshifen
1 70 1 men
10 1 64 yinshifen
*/