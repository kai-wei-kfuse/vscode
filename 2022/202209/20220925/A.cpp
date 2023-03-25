#include <bits/stdc++.h>
using namespace std;
map<int, int> mp;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, c;
        cin >> n >> c;
        int tmp;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            mp[tmp]++;
        }
        for (auto i : mp) {
            if (i.second >= c) {
                ans += c;
            } else {
                ans += i.second;
            }
        }
        mp.clear();
        cout << ans << endl;
    }
}