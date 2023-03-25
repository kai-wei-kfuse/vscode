#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    IOS;
    int t, n;
    cin >> t;
    while (t--) {
        string s;
        cin >> n;
        cin >> s;
        int ans = 0;
        for (int i = 0; i <= n; i++) {
            map<char, int> mp;
            int maxn = 0;
            for (int l = i; l < n && l < i + 101; l++) {
                mp[s[l]]++;
                maxn = max(maxn, mp[s[l]]);

                if (maxn <= mp.size()) {
                    ans++;
                }
            }
        }
        cout << ans << endl;
    }
}