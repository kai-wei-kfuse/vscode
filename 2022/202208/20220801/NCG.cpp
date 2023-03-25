#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 7;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    IOS;
    int n;
    while (cin >> n) {
        string s;
        cin >> s;
        map<char, int> mp;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            for (int j = i; j < len; j++) {
                if (s[j] == s[i] &&
                    (s[i] == 'k' || s[i] == 'f' || s[i] == 'c')) {
                    string ss = s.substr(i, j - i + 1);
                    string s0 = ss;
                    reverse(ss.begin(), ss.end());
                    if (ss == s0) {
                        mp[s[j]]++;
                    }
                }
            }
        }
        cout << mp['k'] << " " << mp['f'] << " " << mp['c'] << '\n';
    }
}