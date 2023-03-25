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
        int flag = 1;
        for (int i = 0; i < n - 1; i++) {
            if (s[i] == 'R' && s[i + 1] == 'L') {
                cout << 0 << endl;
                flag = 0;
                break;
            }
            if (s[i] == 'L' && s[i + 1] == 'R') {
                cout << i + 1 << endl;
                flag = 0;
                break;
            }
        }
        if (flag) {
            cout << "-1" << endl;
        }
    }
}