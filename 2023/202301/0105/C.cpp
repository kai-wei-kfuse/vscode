#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int flag = 0;
        vector<int> ve(n + 2), pos[n + 2];
        priority_queue<int, vector<int>, greater<int>> q;
        vector<int> ans1(n + 2), ans2(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            pos[ve[i]].push_back(i);
            if (pos[ve[i]].size() > 2) {
                flag = 1;
            }
        }
        if (pos[1].size() >= 2) {
            flag = 1;
        }
        if (!flag) {
            for (int i = 1; i <= n; i++) {
                if (pos[i].size() == 1) {
                    ans1[pos[i][0]] = ans2[pos[i][0]] = i;
                } else if (pos[i].size() == 0) {
                    q.push(i);
                } else {
                    if (q.empty()) {
                        flag = 1;
                        break;
                    } else {
                        int minn = q.top();
                        q.pop();
                        if (minn > i) {
                            flag = 1;
                            break;
                        }
                        ans1[pos[i][0]] = minn;
                        ans1[pos[i][1]] = i;
                        ans2[pos[i][0]] = i;
                        ans2[pos[i][1]] = minn;
                    }
                }
            }
        }
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
            for (int i = 1; i <= n; i++) {
                cout << ans1[i] << ' ';
            }
            cout << endl;
            for (int i = 1; i <= n; i++) {
                cout << ans2[i] << ' ';
            }
            cout << endl;
        }
    }
}