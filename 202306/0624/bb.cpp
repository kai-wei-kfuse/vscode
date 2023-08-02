#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector<vector<int> > ve(3, vector<int>(n + 1, 0));
        map<int, int> mp;
        mp[0] = 1;
        for (int i = 1; i <= n; i++) {
            cin >> ve[0][i];
            ve[0][i] |= ve[0][i - 1];
            mp[ve[0][i]] = 1;
        }
        for (int i = 1; i <= n; i++) {
            cin >> ve[1][i];
            ve[1][i] |= ve[1][i - 1];
            mp[ve[1][i]] = 1;
            for (int j = 0; j <= n; j++) {
                mp[ve[1][i] | ve[0][j]] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            cin >> ve[2][i];
            ve[2][i] |= ve[2][i - 1];
            mp[ve[2][i]] = 1;
            for (int j = 0; j <= n; j++) {
                mp[ve[2][i] | ve[0][j]] = 1;
                mp[ve[2][i] | ve[1][j]] = 1;
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                for (int k = 1; k <= n; k++) {
                    mp[ve[0][i] | ve[1][j] | ve[2][k]] = 1;
                }
            }
        }
        if (mp[m])
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}