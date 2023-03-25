#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int flag = s[0] - '0';
        int tmp = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] - '0' == flag) {
                cout << tmp << ' ';
            } else {
                tmp = i + 1;
                flag = s[i] - '0';
                cout << tmp << ' ';
            }
        }
        cout << '\n';
    }
}