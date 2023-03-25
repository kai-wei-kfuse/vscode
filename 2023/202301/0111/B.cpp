#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int N = 1e6 + 5;
int next_[N];

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        string s, a;
        cin >> s >> a;
        int n = s.size();
        int m = a.size();
        s = "?" + s;
        a = "?" + a;
        for (int i = 2, j = 0; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
        }
        int ans = 0;
        for (int i = 1, j = 0; i <= m; i++) {
            while (j && a[i] != s[j + 1])
                j = next_[j];
            if (a[i] == s[j + 1])
                j++;
            if (j == n) {
                ans++;
                // cout << i - n + 1 << ' ';
                j = next_[n];
            }
        }
        cout << ans << endl;
    }
}