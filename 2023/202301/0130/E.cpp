#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(0), cout.tie(0)

#define int long long

signed main() {
    int t;
    IOS;
    cin >> t;
    vector<int> a;
    int res = 0;
    for (int i = 1; i <= t; i++) {
        int tmp;
        cin >> tmp;
        res += tmp;
        a.push_back(tmp);
    }
    if (res < 0 || res > 99999999) {
        cout << "Error";
        return 0;
    }
    // while (!q1.empty()) {
    //     cout << q1.top() << ' ';
    //     q1.pop();
    // }
    // cout << endl;
    // while (!q2.empty()) {
    //     cout << q2.top() << ' ';
    //     q2.pop();
    // }
    int ans = 0;
    vector<int> ve;

    // cout << endl;
    for (auto i : ve) {
        cout << i << '\n';
    }
}