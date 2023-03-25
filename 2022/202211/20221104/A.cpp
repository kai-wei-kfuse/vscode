#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int sum1 = 0, sum2 = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            sum1 += ve[i];
        }
        cout << abs(sum1) << endl;
    }
}