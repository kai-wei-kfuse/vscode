#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0;
        return 0;
    }
    if (n % 2 == 0 && (n / 2) % 2 == 1) {
        cout << n - 1;
    } else {
        int x = 1, y = 1, i = 1;
        while (1) {
            // cout << x + y << ' ';
            int tmp = x;
            x = y;
            y = tmp + y;
            // cout << x << ' ' << y << ' ';
            if (x >= n || y >= n) {
                cout << i;
                break;
            }
            i++;
        }
    }
}