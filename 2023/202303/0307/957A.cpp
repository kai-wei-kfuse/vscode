#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int flag = 0, x = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == s[i - 1] && s[i] == '?') {
            flag = 1;
        }
        if (i > 1 && s[i] == s[i - 2] && s[i - 1] == '?') {
            flag = 1;
        }
        if (s[i] == s[i - 1] && s[i] != '?') {
            x = 0;
        }
    }
    if (s[0]=='?' || s[n - 1] == '?') flag = 1;
    if (flag&&x) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}