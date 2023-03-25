#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y, a, b;
        cin >> x >> y >> a >> b;
        int flag = 0;
        int ans = 0;
        if (x == y) {
            cout << 2 << endl;
        }
        while (x != y) {
            /*        cout << x << " " << y; */
            if (x > y)
                swap(x, y);

            if ((x + y) & 1) {
                /*                cout << "gg" << endl; */
                /*                 cout << -1 << endl; */
                flag = 1;
                break;
            }
            y -= ((x + y) / 2);
            /*         cout << "aaaaa" << y << endl; */
            /* cout << y << endl; */
            ans++;
            if (x == y) {
                /*                 cout << "ok" << endl; */
                cout << ans + 2 << endl;
                break;
            }
        }
        if (flag) {
            cout << -1 << endl;
            continue;
        }
    }
}