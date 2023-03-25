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
        map<char, int> mp;
        for (auto i : s) {
            mp[i]++;
        }
        int minn = 0x3f3f3f3f, tmp = 0;
        string ch = s;
        reverse(ch.begin(), ch.end());
        if (ch == s) {
            cout << "0" << endl;
            continue;
        }
        for (auto i : mp) {
            
        }
    }
}