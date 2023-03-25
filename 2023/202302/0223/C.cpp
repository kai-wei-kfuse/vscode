#include <bits/stdc++.h>
using namespace std;
int main() {
    int x, y, xx, yy;
    cin >> x >> y;
    xx = x, yy = y;
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, aa, b, bb;
        cin >> a >> aa >> b >> bb;
        int sum = a + b;
        if (aa == sum && bb != sum) {
            x--;
        } else if (bb == sum && aa != sum) {
            y--;
        }
        if (x == 0) {
            cout << "A" << endl
                 << yy - y;
            return 0;
        } else if (y == 0) {
            cout << "B" << endl
                 << xx - x;
            return 0;
        }
    }
}