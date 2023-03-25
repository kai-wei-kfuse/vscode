#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            sum += ve[i];
        }
        if (sum & 1) {
            int ans=0x3f3f3f3f;
            for (int i = 1; i <= n; i++) {
                int tmp = ve[i];
                sum -= tmp;
                int res = 0;
                while ((sum + tmp) & 1) {
                    tmp /= 2;
                    res++;
                }
                sum += ve[i];
                ans = min(ans, res);
            }
            cout << ans << '\n';
        } else {
            cout << 0 << '\n';
        }
    }
}