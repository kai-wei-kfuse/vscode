#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int>> pref(1e5 + 7);
int main() {
    int n, q, k;
    cin >> n >> q >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= q; i++) {
        int l, r;
        cin >> l >> r;
        cout << k - a[r] + a[l] - 1 + 2 * (a[r] - a[l] - (r - l)) << endl;
    }
}
// 1 3 5 7 9