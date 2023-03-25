#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int num1 = 0, num0 = 0;
        vector<int> ty(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ty[i];
            if (ty[i] == 1)
                num1++;
            else
                num0++;
        }
        vector<int> a1, b2;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            if (ty[i] == 1) {
                a1.push_back(tmp);
            } else {
                b2.push_back(tmp);
            }
        }
        if (!a1.empty())
            sort(a1.begin(), a1.end(), greater<int>());
        if (!b2.empty())
            sort(b2.begin(), b2.end(), greater<int>());
        // for (int i = 0, j = 0; i < a1.size() && j < b2.size();i++,j++){

        // }
        int ans = 0;
        // ans += min(a1[0], b2[0]);
        int time = min(num1, num0);
        for (int i = 0; i < time; i++) {
            ans += a1[i] * 2LL;
            ans += b2[i] * 2LL;
        }
        // cout << ans << endl;
        if (num1 > 0 && time < num1) {
            for (int i = time; i < num1; i++) {
                ans += a1[i];
            }
        }
        if (num0 > 0 && time < num0) {
            for (int i = time; i < num0; i++) {
                ans += b2[i];
            }
        }
        // cout << ans << endl;
        if (num1 == num0)
            ans -= min(a1[num1 - 1], b2[num0 - 1]);
        cout << ans << endl;
    }
}