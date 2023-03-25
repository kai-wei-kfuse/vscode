#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, m;
    cin >> n >> m;
    vector<int> ve[n + 1];
    for (int i = 0; i <= 9; i++) {
        ve[0][i] = i;
    }
    for (int i = 1; i <= n; i++) {
        int l, r;
        cin >> l >> r;
        ve[i] = ve[i - 1];
        swap(ve[i][l], ve[i][r]);
    }
    for (int i = 1; i <= m; i++) {
        int l, r;
        cin >> l >> r;
        vector<int> tmp(10);
        for (int i = 0; i <= 9; i++) {
            tmp[ve[l - 1][i]] = i;
        }
        for (int i = 0; i <= 9; i++) {
            cout << tmp[ve[r][i]] << ' ';
        }
        cout << '\n';
    }
}