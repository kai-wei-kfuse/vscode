#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    int d;
    cin >> s >> d;
    int len = s.size();
    int pos = 0;
    int ans = 0;
    while (pos < len) {
        int maxn = d;
        for (int k = 1; k <= d; k++) {
            int i = pos;
            while (s[i] == s[i + k] && i < len)
                i++;
            maxn = max(maxn, i - pos + k);
            // cout << maxn << endl;
        }
       //cout << maxn << " " << pos << endl;
        ans++;
        pos = pos + maxn;
    }
    cout << ans << endl;
}