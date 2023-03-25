#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> pref(n + 1, 0);
    for (int i = 0; i < n - 1; i++) {
        if (s[i] == '1') {
            pref[i + 1] = 1;
        }
    }
    long long ans = 0;
    for (int i = 1; i <= n; i++) {
        pref[i] += pref[i - 1];
        pref[i] %= mod;
        pref[i] += pref[i - 1];
        pref[i] %= mod;
        if (s[i - 1] == '1') {
            ans += pref[i];
            ans %= mod;
        }
    }
    cout << ans << endl;
}