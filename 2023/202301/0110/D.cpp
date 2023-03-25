#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int p, q;
        for (int i = 2; i * i * i <= n; i++) {
            if (n % i == 0) {
                n /= i;
                if (n % i == 0) {
                    p = i;
                    q = n / i;
                } else {
                    q = i;
                    p = sqrt(n);
                }
                break;
            }
        }
        cout << p << ' ' << q << endl;
    }
}