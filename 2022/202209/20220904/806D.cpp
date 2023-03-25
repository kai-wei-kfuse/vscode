#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;

string s[100005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<string, int> mp;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> s[i];
            mp[s[i]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            int len = s[i].length();
            for (int j = 1; j < len; j++) {
                // cout << s[i].substr(0, j) << ' ' << s[i].substr(j, len) <<
                // '\n';
                if (mp[s[i].substr(0, j)] && mp[s[i].substr(j, len)]) {
                    ve[i] = 1;
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            if (ve[i] == 1)
                cout << ve[i];
            else
                cout << '0';
        }
        cout << '\n';
    }
}