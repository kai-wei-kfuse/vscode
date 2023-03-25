#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        x -= y;
        if (y > 1)
            cout << 1LL + (x + y - 1LL - 1LL) / (y - 1LL) * 2 << endl;
        else {
            cout << "-1" << endl;
        }
    }
}