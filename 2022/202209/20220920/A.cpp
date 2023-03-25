#include <bits/stdc++.h>
using namespace std;
using ll = long long;
int main() {
    ll n, m;
     cin >> n >> m;

/*     for (int n = 1; n <= 10; n++) {
        for (int m = 1; m <= 10; m++) { */
            ll ans1 = 0, ans2 = 0;
            for (int i = 2; i <= 1000; i += 2) {
                if(i<=n)
                {
                    ans1 += (n - i+1);
                }else
                {
                    break;
                }
            }
            for (int i = 2; i <= 1000; i += 2) {
                if(i<=m)
                {
                    ans2 += (m - i+1);
                }else
                {
                    break;
                }
            }
/*            // cout << ans1 << " " << ans2 << endl; */
            cout << ans1 * (m + 1) + ans2 * (n + 1) + ans1 * ans2 * 2 << " ";
/*         cout << endl; */
/*     } */
}/*  */