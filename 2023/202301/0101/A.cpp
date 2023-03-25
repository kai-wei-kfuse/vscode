#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        int flag = 0;
        cin >> s;
        if (s[0] == '1') {
            flag = 1;
        }
        for (int i = 1; i < n; i++) {
            if (s[i] == '0') {
                cout << "+";
            } else {
                if (flag) {
                    cout << "-";
                    flag = 0;
                } else {
                    flag = 1;
                    cout << "+";
                }
            }
        }
        cout << '\n';
    }
}