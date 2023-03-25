#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int x;
        vector<int> ve[n + 2];
        for (int i = 1; i <= n; i++) {
            cin >> x;
            int tmp, flag = 1;
            for (int j = 1; j <= x; j++) {
                cin >> tmp;
                ve[i].push_back(tmp);
                mp[tmp]++;
            }
        }
        int xx = 0;
        for (int i = 1; i <= n; i++) {
            int flag = 1;
            for (auto x : ve[i]) {
                if (mp[x] < 2) {
                    flag = 0;
                }
            }
            if (flag) {
                cout << "YES" << endl;
                xx = 1;
                break;
            }
        }
        if (xx == 0) {
            cout << "NO" << endl;
        }
    }
}