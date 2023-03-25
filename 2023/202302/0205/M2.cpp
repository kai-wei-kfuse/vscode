#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int next_[101];
string s[101];

int kmp(string a, string b) {
    int tlen = a.size();
    int slen = b.size();
    // cout << a << endl << b << endl;
    a = "?" + a;
    b = "?" + b;
    for (int i = 2, j = 0; i <= tlen; i++) {
        while (j && a[i] != a[j + 1])
            j = next_[j];
        if (a[i] == a[j + 1])
            j++;
        next_[i] = j;
    }
    for (int i = 1, j = 0; i <= slen; i++) {
        while (j && b[i] != a[j + 1])
            j = next_[j];
        if (b[i] == a[j + 1])
            j++;
        if (j == tlen) {
            return 1;
        }
    }
    return 0;
}

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        string a, b;
        string anss;
        int maxn = 0;
        int l1 = s[1].size();
        for (int l = 0; l < l1; l++) {
            for (int len = 1; len + l <= l1; len++) {
                a = s[1].substr(l, len);
                b = a;
                reverse(b.begin(), b.end());
                // cout << a << ' ' << b << endl;
                int ans = 1;
                for (int i = 2; i <= n; i++) {
                    if (kmp(a, s[i]) || kmp(b, s[i])) {
                        ans++;
                        // cout << kmp(a, s[i]) << "|" << kmp(b, s[i]) << "|"
                        //  << s[i] << endl;
                    }
                }
                if (len > maxn && ans == n) {
                    maxn = len;
                    // cout << maxn << endl;
                    anss = a;
                }
            }
        }
        cout << maxn << endl;
    }
}