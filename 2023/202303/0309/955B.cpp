#include <bits/stdc++.h>
using namespace std;
int main() {
    string s;
    cin >> s;
    map<char, int> mp;
    int len = s.size();
    for (int i = 0; i < len; i++) {
        mp[s[i]]++;
    }
    int flag = 1;
    if (len < 4 || mp.size() < 2 || mp.size() > 4) {
        flag = 0;
    }
    if (mp.size() == 2) {
        for (auto i : mp) {
            if (i.second < 2) {
                flag = 0;
            }
        }
        }
    if (flag) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}