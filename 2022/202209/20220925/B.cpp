#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        string s;
        cin >> s;
        map<int, pair<int, int>> mp;
        int len = s.length();
        for (int i = 0; i < len; i++) {
            mp[s[i] - '0'].first = i;
            mp[s[i] - '0'].second++;
        }
        vector<int> ans;
        int flag = 0;
        for (auto i : mp) {
            if (flag > i.second.first)
                continue;
            for (int j = flag; j <= i.second.first; j++) {
                if (s[j] - '0' != i.first) {
                    ans.push_back(min(s[j] - '0' + 1, 9));
                    i.second.second--;
                } else {
                    ans.push_back(i.first);
                }
            }
            flag = i.second.first + 1;
        }
        sort(ans.begin(), ans.end());

        for (auto i : ans) {
            cout << i;
        }
        cout << endl;
    }
}