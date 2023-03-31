#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1, 0), b(n + 1, 0);
    int un = 0, dn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i] - a[i - 1];
        if (i > 1)
            if (b[i] > 0) {
                un += b[i];
            } else if (b[i] < 0) {
                dn += -b[i];
            }
    }
    cout << max(un, dn) << endl;
    cout << max(un, dn) - min(un, dn) << endl;
}