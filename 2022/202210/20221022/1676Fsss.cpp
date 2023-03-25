#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        int minn = 0x3f3f3f3f, maxn = 0;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            mp[tmp]++;
        }

        vector<int> a;
        for (auto [f, s] : mp) {
            if (s >= k) {
                a.push_back(f);
            }
        }
        if (a.empty()) {
            cout << "-1" << endl;
            continue;
        }
        sort(a.begin(), a.end());
        // for (auto i : a) {
        //     cout << i << ' ';
        // }
        // cout << endl;

        int l = 0, r = 0, len = a.size();
        int ans = -1, ansl, ansr;
        for (int i = 0; i < len; i++) {
            l = a[i];
            r = a[i];
            while (i + 1 < len && a[i + 1] == a[i] + 1) {
                r = a[i + 1];
                i++;
            }
            if (ans < r - l) {
                ansl = l;
                ansr = r;
                ans = r - l;
            }
        }
        cout << ansl << ' ' << ansr << endl;
    }
}