#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int x, y;
        int maxnr = 0, maxnu = 0, maxnl = 0, maxnd = 0;
        for (int i = 1; i <= n; i++) {
            cin >> x >> y;
            if (x > 0 && y == 0) {
                maxnr = max(maxnr, x);
            }
            if (x == 0 && y > 0) {
                maxnu = max(maxnu, y);
            }
            if (x < 0 && y == 0) {
                maxnl = min(maxnl, x);
            }
            if (x == 0 && y < 0) {
                maxnd = min(maxnd, y);
            }
        }
        cout << (maxnr + maxnu - maxnl - maxnd) * 2 << '\n';
    }
}