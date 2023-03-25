#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int numa = 0, numb = 0;
        int len = s.size();

        if (s[0] == s[len - 1]) {
            cout << s[0] << ' ';

            for (int i = 1; i < len - 1; i++) {
                cout << s[i];
            }
            cout << ' ';
            cout << s.back() << endl;
        } else {
            if (s[0] == 'a') {
                cout << s.substr(0, len - 2) << ' ' << s.substr(len - 2, 1)
                     << ' ' << s.back() << endl;
            } else {
                cout << s[0] << ' ' << s[1] << ' ' << s.substr(2) << endl;
            }
        }
    }
}