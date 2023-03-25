#include <cstring>
#include <iostream>
using namespace std;

int next_[70];
string s[15];

int kmp(string a, string b) {
    int tlen = a.size();
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
    for (int i = 1, j = 0; i <= 60; i++) {
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
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
        }
        string a;
        string anss;
        int maxn = 0;
        for (int l = 0; l < 60; l++) {
            for (int len = 3; len + l <= 60; len++) {
                a = s[1].substr(l, len);
                // cout << a << endl;
                if (kmp(a, s[2])) {
                    int ans = 2;
                    for (int i = 3; i <= n; i++) {
                        if (kmp(a, s[i])) {
                            ans++;
                            // cout << a << endl;
                        }
                    }
                    if (len > maxn && ans == n) {
                        maxn = len;
                        // cout << maxn << endl;
                        anss = a;
                    }
                }
            }
        }
        if (maxn < 3) {
            cout << "no significant commonalities" << endl;
        } else {
            cout << anss << endl;
        }
    }
}