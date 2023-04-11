#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<int> > a(n + 1, vector<int>(n + 1, 0));

    for (int i = 1; i < n; i++) {
        for (int j = i + 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    vector<int> b(n + 1, 0x3f3f3f3f);
    b[1] = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            b[i] = min(b[i], b[j] + a[j][i]);
        }
    }
    cout << b[n] << endl;
}
