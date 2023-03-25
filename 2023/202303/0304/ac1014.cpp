#include <bits/stdc++.h>
using namespace std;
vector<int> q(10005, 0);
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    int len = 0;

    vector<int> up(n + 1, 0), down(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (q[len] < ve[i]) {
            q[++len] = ve[i];
        } else {
            int pos = lower_bound(q.begin() + 1, q.begin() + len + 1, ve[i]) - q.begin();
            q[pos] = ve[i];
            len = max(len, pos);
            //  cout << len << enl;
        }
        up[i] = len;
        // cout << len << endl;
    }
    len = 0;
    vector<int> q2(n + 1, 0);
    for (int i = n; i >=1; i--) {
        if (q2[len] < ve[i]) {
            q2[++len] = ve[i];
        } else {
            int pos = lower_bound(q2.begin() + 1, q2.begin() + len + 1, ve[i]) - q2.begin();
            q2[pos] = ve[i];
            len = max(len, pos);

            // cout << len << endl;
        }
        down[i] = len;
    }
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        // cout << up[i] << '|' << down[i] << ' ';
        maxn = max(up[i] + down[i]-1, maxn);
    }
    cout << maxn;
}