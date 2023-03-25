#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    n--;
    string s = "";
    for (int i = 1; i <= 9; i++) {
        s += to_string(n % 10);
        n /= 10;
    }
    // cout << s << endl;
    string ans = "";
    ans += s[1];
    ans += s[0];
    ans += s[1];
    ans += s[2];
    ans += s[2];
    ans += s[3];
    ans += s[4];
    ans += s[5] + 1;
    ans += s[5] + 1;
    for (int i = 8; i >= 0; i--) {
        cout << ans[i];
    }
}