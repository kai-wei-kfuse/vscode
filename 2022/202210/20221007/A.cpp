#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        map<char, int> mp;
        for (char i = 'a'; i <= 'z'; i++) {
            mp[i] = 0;
        }
        for (int i = 0; i < n; i++) {
            mp[s[i]]++;
        }
        string ans = "";
        for (int i = 1; i <= k; i++) {
            char cnt = 'a';
            int cnt_ = 0;
            // for (auto j : mp) {
            //     cout << cnt << endl;
            //     if (cnt_ == n / k) {
            //         break;
            //     }
            //     if (j.second > 0) {
            //         cout << j.second << " ";
            //         j.second--;
            //         cout << j.second << endl;
            //         cnt++;
            //         cnt_++;
            //         // for (auto x : mp) {
            //         //     cout << x.second << ' ';
            //         // }
            //         // cout << endl;
            //     } else if (j.second == 0) {
            //         break;
            //     }
            // }
            for (char j = 'a'; j < 'z'; j++) {
                if (cnt_ == n / k) {
                    break;
                }
                if (mp[j] > 0) {
                    mp[j]--;
                    cnt++;
                    cnt_++;
                } else if (mp[j] == 0) {
                    break;
                }
            }
            ans += cnt;
        }
        cout << ans << endl;
    }
}