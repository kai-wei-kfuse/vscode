#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string ans = "";
    for (int i = 0; i < n; i++) {
        if (i + 1 < n && s[i + 1] == 'a' && s[i] == 'n') {
            i++;
            ans += "nya";
        } else {
            ans += s[i];
        }
    }
    cout << ans;
}