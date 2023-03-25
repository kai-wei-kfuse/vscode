#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1), suf(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        map<int, int> mp;
        int now = 0;
        for (int i = n; i >= 1; i--) {
            mp[ve[i]]++;
            while (mp[now] > 0) {
                now++;
            }
            suf[i] = now;
        }
        mp.clear();
        now = 0;
        int p;
        vector<int> ans;
        for (int i = 1, p = 1; i <= n; i++) {
            mp[ve[i]]++;
            while (mp[now] > 0) {
                now++;
            }
            if (now == suf[p]) {
                ans.push_back(now);
                p = i + 1;
                now = 0;
                mp.clear();
            }
        }
        cout << ans.size() << endl;
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
}