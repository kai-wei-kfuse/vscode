#include <bits/stdc++.h>
using namespace std;

#define int long long
vector<int> edg[105], ins(105, 0);

signed main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        // cout << ve[i] << endl;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (i != j) {
                if (ve[i] / 3 == ve[j] && ve[i] % 3 == 0) {
                    // i->j
                    edg[i].push_back(j);
                    ins[j]++;
                }
                if (ve[i] == ve[j] / 3 && ve[j] % 3 == 0) {
                    // j->i
                    edg[j].push_back(i);
                    ins[i]++;
                }
                if (ve[j] / 2 == ve[i] && ve[j] % 2 == 0) {
                    // i->j
                    edg[i].push_back(j);
                    ins[j]++;
                }
                if (ve[i] / 2 == ve[j] && ve[i] % 2 == 0) {
                    // j->i
                    edg[j].push_back(i);
                    ins[i]++;
                }
            }
        }
    }
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (ins[i] == 0) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int now = q.front();
        q.pop();
        cout << ve[now] << ' ';
        for (auto i : edg[now]) {
            ins[i]--;
            if (ins[i] == 0) {
                q.push(i);
            }
        }
    }
}