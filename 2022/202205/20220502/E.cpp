#include <algorithm>
#include <iostream>
#define int long long
using namespace std;
int a[200005];
int chack(int a, int b) {
    if (a < b)
        swap(a, b);
    if (a >= b * 2)
        return (a - 1) / 2 + 1;
    else {
        return (a + b - 1) / 3 + 1;
    }
}
signed main() {
    int n;
    cin >> n;
    cin >> a[1];
    int ans = 0x3f3f3f;
    for (int i = 2; i <= n; i++) {
        cin >> a[i];
        ans = min(ans, chack(a[i], a[i - 1]));
    }
    for (int i = 2; i < n; i++) {
        ans = min(ans, (a[i - 1] + a[i + 1] - 1) / 2 + 1);
    }
    sort(a + 1, a + n + 1);
    int x = 0;
    if (a[1] % 2 == 0) {
        x += a[1] / 2;
    } else {
        x += (a[1] - 1) / 2 + 1;
    }
    // cout << x << endl;
    if (a[2] % 2 == 0) {
        x += a[2] / 2;
    } else {
        x += (a[2] - 1) / 2 + 1;
    }
    ans = min(ans, x);
    cout << ans;
}