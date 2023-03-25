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
        if (n % 2 != 0) {
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
                for (int i = 2; i <= n; i += 2) {
                    if (num != num_ && ve[i] == 1) {
                        a.push_back({i - 1, i});
                        // cout << i - 1 << ' ' << -i << endl;
                        ans--;
                        num--, num_++;
                    } else {
                        a.push_back({i - 1, i - 1});
                        a.push_back({i, i});
                        // cout << i << ' ' << i << endl;
                    }
                }
            } else if (num < num_) {  //-1多
                for (int i = 2; i <= n; i += 2) {
                    if (num != num_ && ve[i] == -1) {
                        a.push_back({i - 1, i});
                        // cout << i - 1 << ' ' << -i << endl;
                        ans--;
                        num++, num_--;

                    } else {
                        a.push_back({i - 1, i - 1});
                        a.push_back({i, i});
                        // cout << i << ' ' << i << endl;
                    }
                }
            }
            cout << ans << endl;
            for (auto [i, j] : a) {
                cout << i << ' ' << j << endl;
            }
        }
    }
}