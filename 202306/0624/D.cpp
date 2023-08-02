#include <bits/stdc++.h>
using namespace std;
string s;
#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0)
int calc(int l, int r, char c) {
    int mid = (l + r) / 2;
    if (l == r) {
        if (s[l] != c) {
            return 1;
        } else {
            return 0;
        }
    }
    int x =
        min(calc(l, mid, c + 1) +
                (r - mid - count(s.begin() + mid + 1, s.begin() + r + 1, c)),
            calc(mid + 1, r, c + 1) +
                (mid + 1 - l - count(s.begin() + l, s.begin() + mid + 1, c)));
    return x;
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        cin >> s;
        cout << calc(0, n - 1, 'a') << '\n';
    }
}