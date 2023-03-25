#include <bits/stdc++.h>
using namespace std;

struct xx {
    int id, x;
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        map<string, xx> mp, mp2;
        vector<string> a;
        for (int i = 1; i <= n; i++) {
            string x;
            cin >> x;
            a.push_back(x);
            mp2[x].x++;
            // mp[x].id = i;
        }
        vector<pair<int, string> > ans;
        int num = 0, num2 = 0;
        for (auto i : a) {
            mp[i].x++;
            ++num;
            if (mp[i].x > 1) {
                for (int j = 0; j < 4; j++) {
                    string tmp = i;
                    string nm = tmp;
                    for (char k = '0'; k <= '9'; k++) {
                        if (k != nm[j]) {
                            tmp[j] = k;
                            if (mp[tmp].x == 0 && mp2[tmp].x == 0) {
                                mp[tmp].x++;
                                mp[nm].x--;
                                num2++;
                                ans.push_back({num, tmp});
                                if (mp[nm].x == 1) {
                                    break;
                                }
                            }
                        }
                    }
                    if (mp[nm].x == 1) {
                        break;
                    }
                }
            } else
                ans.push_back({num, i});
        }
        cout << num2 << endl;
        sort(ans.begin(), ans.end());
        for (auto i : ans) {
            cout << i.second << endl;
        }
    }
}