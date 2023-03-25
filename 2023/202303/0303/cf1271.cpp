#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x >> y;
    int u = 0, l = 0, d = 0, r = 0;
    for (int i = 1; i <= n; i++) {
        int a, b;
        cin >> a >> b;
        if (a < x) {
            if (b < y) {
                l++;
                u++;
            } else if (b > y) {
                r++;
                u++;
            } else {
                u++;
            }
        } else if (a > x) {
            if (b < y) {
                l++;
                d++;
            } else if (b > y) {
                r++;
                d++;
            } else {
                d++;
            }
        } else if (a == x) {
            if (y < b) {
                r++;
            } else {
                l++;
            }
        }
    }
    cout << max({u, d, r, l})<<endl;
    // cout << r << ' ' << l << ' ' << d << ' ' << u << endl;
    if (u >= r && u >= l && u >= d) {
        cout << x - 1 << ' ' << y << endl;
    } else if (r >= u && r >= l && r >= d) {
        cout << x << ' ' << y + 1 << endl;
    } else if (l >= r && l >= u && l >= d) {
        cout << x << ' ' << y - 1 << endl;
    } else if (d >= r && d >= u && d >= l) {
        cout << x + 1 <<' '<< y << endl;
    }
}