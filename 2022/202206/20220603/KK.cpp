#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x;
        double y;
        cin >> x >> y;
        double ans = y;
        if (x > 10000000) {
            ans += 2.0;
        } else if (x < 9800000) {
            ans += (x - 9500000.0) / 300000.0;
        } else {
            ans += (1.0 + (x - 9800000.0) / 200000.0);
        }
        if (ans < 0)
            ans = 0;
        printf("%.8lf", ans);
        if (n >= 1)
            cout << '\n';
    }
}