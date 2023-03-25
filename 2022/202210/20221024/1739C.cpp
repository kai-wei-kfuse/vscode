#include <bits/stdc++.h>
using namespace std;
#define int long long
int p[62][62];
const int mod = 998244353;
// pair<int, int> ans[65];
int ans1[65], ans2[65];
void init() {
    p[0][0] = 1;  //注意C(0,0)的情况！！！！
    for (int i = 1; i <= 60; i++) {
        p[i][0] = 1;
        for (int j = 1; j <= i; j++)
            p[i][j] = (p[i - 1][j - 1] + p[i - 1][j]) ;
    }
    ans1[2] = 1, ans2[2] = 0;
    for (int i = 4; i <= 60; i += 2) {
        ans1[i] = (ans2[i - 2] + p[i - 1][i / 2 - 1]);
        ans2[i] = p[i][i / 2] - ans1[i] - 1;
    }
}

signed main() {
    int t;
    cin >> t;
    init();
    while (t--) {
        int n;
        // for (int i = 2; i <= 60;i+=2){
        //     cout << ans1[i] << ' ' << ans2[i] << endl;
        // }
            cin >> n;
        cout << ans1[n]%mod << ' ' << ans2[n]%mod<< ' ' << "1" << endl;
    }
}