#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        if (s.length() == 1) {
            if (s[0] == '_') {
                cout << 2 << endl;
            } else {
                cout << 1 << endl;
            }
            continue;
        }
        s = "_" + s + "_";
        int len = s.length();
        int ans = 0;
        for (int i = 1; i < len; i++) {
            if (s[i] == '_' && s[i - 1] == '_') {
                ans++;
            }
        }
        cout << ans << endl;
    }
}