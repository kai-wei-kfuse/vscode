#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    for (int i = 1; i < n; i++) {
        int ans = 0;
        for (int l = 0; l + i < n; l++) {
            if (s[l] == s[l + i]) {
                break;
            }
            ans++;
        }
        cout << ans << endl;
    }
}