#include <bits/stdc++.h>
using namespace std;
#define ios                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);

int main() {
    ios int n;
    string s;
    char a, b;
    cin >> n >> s >> a >> b;
    int ans = 0;
    int len = s.length();
    for (int i = 0; i < len; i++) {
        if (s[i] == a) {
            for (int j = i + n - 1; j < len; j++) {
                if (s[j] == b) {
                    ans++;
                }
            }
        }
    }
    cout << ans << '\n';
}