#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int x, y;
        cin >> x >> y;
        if (__gcd(x, y) == 1) {
            cout << "1" << endl;
            cout << x << ' ' << y << '\n';
        } else {
            cout << "2" << endl;
            cout << 1 << ' ' << y - 1 << '\n';
            cout << x << ' ' << y << '\n';
        }
    }
}