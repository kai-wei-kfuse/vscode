#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        vector<int> ve(n + 1);

        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int ans = 0;
        int l = 1, r = 1;
        for (int i = 2; i <= n; i++) {
            if (ve[i] * 2 > ve[i - 1]) {
                r++;
            } else {
                l = i, r = i;
            }
            if (r - l > k)
                l++;
            if (r - l == k) {
                ans++;
            }
        }
        cout << ans << endl;
    }
}