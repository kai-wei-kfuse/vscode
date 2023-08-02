#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int len = s.size();
        int n;
        cin >> n;
        vector<pair<char, char> > ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i].first;
        }
        for (int i = 1; i <= n; i++) {
            cin >> ve[i].second;
        }
        vector<vector<int> > cnt(10, vector<int>(len + 2));
        for (int i = len; i >= 1; i--) {
            for (int j = 0; j <= 9; j++) {
                cnt[j][i - 1] = cnt[j][i];
            }
            cnt[s[i - 1] - '0'][i - 1] = i;
        }
        // vector<int> p(10);
        // for (int i = 1; i <= 9; i++) {
        //     p[i] = cnt[i][0];
        //     cout << p[i] << ' ';
        // }
        // cout << endl;
        // for (int i = 1; i <= 9; i++) {
        //     for (int j = 0; j <= len; j++) {
        //         cout << cnt[i][j] << ' ';
        //     }
        //     cout << endl;
        // }
        // cout << endl;
        int flag = 0;
        set<int> vis;
        vis.insert(0);
        for (int i = 1; i <= n; i++) {
            set<int > tmp;
            for(auto j:vis){
              // cout << j << ' ';
                for (int k = ve[i].first - '0'; k <= ve[i].second - '0'; k++) {
                    if (cnt[k][j] != 0) {
                        tmp.insert(cnt[k][j]);
                        //cout << k << ":" << cnt[k][j] << endl;
                    } else {
                        flag = 1;
                        break;
                    }
                }
            }
           // cout << endl;
            vis = tmp;
            if (flag) {
                break;
            }
        }
        if (flag) {
            cout << "Yes" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}