#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // for (int i = 1; i <= 100; i++) {
        //  n = i;
        int ans = 0;
        // int w = 0;
        while (n > 1) {
            //  cout << n << " " << ans << endl;
            if (n % 3 == 0) {
                n /= 3;
                ans++;
                // cout << "/3" << endl;
            } else if (n % 2 == 0) {
                if ((n & (n - 1)) == 0) {
                    n /= 2;
                    ans++;
                    // cout << "/2" << endl;
                    continue;
                }
                if (n % 3 == 1 && ((n - 1) % 9 == 0 || (n - 1) % 6 == 0)) {
                    n--;
                    ans++;
                    // cout << "-1" << endl;
                    continue;
                }
                n /= 2;
                ans++;
                // cout << "/2" << endl;
            } else {
                n--;
                // cout << "-1" << endl;
                ans++;
            }
        }
        // cout << n << endl;
        cout << ans << endl;
    }
    // }
}