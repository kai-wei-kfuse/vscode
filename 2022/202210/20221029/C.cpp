#include <bits/stdc++.h>
using namespace std;
#define int long long
bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first == b.first)
        return a.second > b.second;
    else
        return a.first < b.first;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int ans = 0;

        sort(ve.begin() + 1, ve.end());
        ve.erase(unique(ve.begin() + 1, ve.end()), ve.end());
        if (ve.size() == 2) {
            cout << "0" << '\n';
            continue;
        } else if (ve.size() == 3) {
            cout << (ve[2] - ve[1]) * 2 << endl;
            continue;
        }
        n = ve.size();
        // for (int i = 1; i + 2 < ve.size(); i++) {
        //     ans = max(ans, abs(ve[i] - ve[i + 1] + ve[i] - ve[ve.size() -
        //     1]));
        // }
        // for (int i = ve.size() - 1; i - 2 >= 1; i--) {
        //     ans = max(abs(ve[i] - ve[i - 1] + ve[i] - ve[1]), ans);
        // }
        // cout << ans << endl;

        vector<pair<int, int>> sumx(n + 1);
        for (int i = 2; i <= n; i++) {
            sumx[i].first = ve[i] - ve[i - 1];
            sumx[i].second = i;
        }
        sort(sumx.begin() + 2, sumx.end(), cmp);
        int maxr = sumx[n].second;
        int maxl = sumx[n - 1].second;
        // cout << maxr << ' ' << maxl << endl;
        //   8 | 17 19 | 45
        int ans1 = abs(ve[maxr] - ve[maxl - 1]);  // 45-8
        int ans2 = abs(ve[maxr] - ve[maxl]);      // 45-17
        int ans3 = abs(ve[maxl] - ve[maxl - 1]);  // 17-8
        int ans4 = abs(ve[maxr] - ve[maxr - 1]);  // 45-19
        cout << max(ans1 + ans4, ans1 + ans3) << endl;
    }
}