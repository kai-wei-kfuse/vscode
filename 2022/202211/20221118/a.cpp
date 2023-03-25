#include <bits/stdc++.h>
using namespace std;
map<char, char> mp;
int main() {
    int t;
    cin >> t;
    mp['Y'] = 'e';
    mp['e'] = 's';
    mp['s'] = 'Y';
    while (t--) {
        string s;
        cin >> s;
        int i = 1;
        while (i < s.size() && mp[s[i - 1]] == s[i]) {
            i++;
        }
        if (s.size() == 1) {
            if (s[0] == 'Y' || s[0] == 'e' || s[0] == 's') {
                cout << "Yes" << endl;
            } else {
                cout << "No" << endl;
            }
            continue;
        }
        if (i > 1 && i == s.size()) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }
}