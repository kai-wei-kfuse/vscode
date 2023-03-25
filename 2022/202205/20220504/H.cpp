#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0), cin.tie(0)
signed main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        set<int> se;
        int a, b;
        cin >> a >> b;
        int x = __gcd(a - 1, b - 1);
        int y = __gcd(a - 2, b);
        int z = __gcd(a, b - 2);
        for (int i = 1; i * i <= x; ++i) {
            if (x % i == 0) {
                se.insert(i);
                se.insert(x / i);
            }
        }
        for (int i = 1; i * i <= y; ++i) {
            if (y % i == 0) {
                se.insert(i);
                se.insert(y / i);
            }
        }
        for (int i = 1; i * i <= z; ++i) {
            if (z % i == 0) {
                se.insert(i);
                se.insert(z / i);
            }
        }
        cout << se.size() << " ";
        for (auto it : se) {
            cout << it << " ";
        }
        cout << endl;
    }
}
