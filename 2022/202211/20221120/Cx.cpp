#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<char>> edg(n + 1, vector<char>(n + 1));
        vector<int> ins(n + 1, 0);
        vector<set<int>> se(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cin >> edg[i][j];
                if (edg[i][j] == '1') {
                    ins[j]++;
                }
            }
        }
        queue<int> Q;
        for (int i = 1; i <= n; i++) {
            if (ins[i] == 0) {
                Q.push(i);
            }
            se[i].insert(i);
        }
        while (!Q.empty()) {
            int u = Q.front();
            Q.pop();
            for (int i = 1; i <= n; i++) {
                if (edg[u][i] == '1') {
                    // se[i].insert(i);
                    for (auto k : se[u]) {
                        // cout << k << ' ';
                        se[i].insert(k);
                    }
                    // cout << endl;
                    if (!--ins[i]) {
                        Q.push(i);
                    }
                }
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << se[i].size() << ' ';
            for (auto x : se[i]) {
                cout << x << ' ';
            }
            cout << endl;
        }
    }
}