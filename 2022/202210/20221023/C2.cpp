#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int num = 0, num_ = 0;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            if (ve[i] == 1)
                num++;
            else if (ve[i] == -1)
                num_++;
        }
        if ((num + num_) % 2 != 0) {
            cout << "-1" << endl;
            continue;
        } else {
            vector<pair<int, int>> a;
            int ans = n;
            if (num == num_) {
                // cout << n << endl;
                for (int i = 1; i <= n; i++) {
                    // cout << i << ' ' << i << endl;
                    a.push_back({i, i});
                }
            } else if (num > num_) {
                // 1个数多
                int flag = 0;
                for (int i = 1; i <= n; i++) {
                    if (flag == 1 && num != num_ && ve[i] == 1) {
                        a.pop_back();
                        a.push_back({i - 1, i});
                        ans--;
                        num_++, num--;
                        // cout << num << ' ' << num_ << endl;
                        flag = 0;
                    } else {
                        // a.push_back({i - 1, i - 1});
                         a.push_back({i, i});
                        flag = 1;
                        // cout << i << ' ' << i << endl;
                    }
                }
            } else if (num < num_) {  //-1多
                int flag = 0;
                for (int i = 1; i <= n; i++) {
                    if (flag == 1 && num != num_ && ve[i] == -1) {
                        a.pop_back();
                        a.push_back({i - 1, i});
                        ans--;
                        num++, num_--;
                        // cout << num << ' ' << num_ << endl;
                        flag = 0;
                    } else {
                        flag = 1;
                        // a.push_back({i - 1, i - 1});
                         a.push_back({i, i});
                        // cout << i << ' ' << i << endl;
                    }
                }
            }
            cout << ans << endl;
            //int cnt = 1;
            for (auto [i, j] : a) {
                // for (; cnt < i; cnt++) {
                //     cout << cnt << " " << cnt << endl;
                // }
                cout << i << ' ' << j << endl;
                // cnt = j + 1;
            }
            // for (; cnt <= n; cnt++) {
            //     cout << cnt << ' ' << cnt << endl;
            // }
        }
    }
}