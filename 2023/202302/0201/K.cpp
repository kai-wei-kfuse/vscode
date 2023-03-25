#include <bits/stdc++.h>
using namespace std;

int next_[200005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        s = "?" + s;
        int j = 0;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            while (j && s[i] != s[j + 1])
                j = next_[j];
            if (s[i] == s[j + 1])
                j++;
            next_[i] = j;
            ans = (ans + 1) % 10007;
            if (next_[i] != 0)
                ans = (ans + 1) % 10007;
        }
        cout << ans + 1 << endl;
    }
}