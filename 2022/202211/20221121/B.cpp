#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        char a;
        int n;
        cin >> n;
        map<char, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> a;
            mp[a]++;
        }
        int ans = 0;
        for (auto i : mp) {
            ans = max(ans, i.first - 'a' + 1);
        }
        cout << ans << endl;
    }
}