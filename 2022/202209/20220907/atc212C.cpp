#include <algorithm>
#include <iostream>
using namespace std;
int a[200005], b[200005];
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i];
    }
    sort(a + 1, a + n + 1);
    sort(b + 1, b + 1 + m);
    int minn = 0x3f3f3f3f;
    // for (int i = 1; i <= m; i++) {
    //     int idx = upper_bound(a + 1, a + 1 + n, b[i]) - a;
    //    // cout << idx << endl;
    //     if (idx <= n)
    //         minn = min(minn, abs(a[idx] - b[i]));
    //     if (idx > 1)
    //         minn = min(minn, abs(a[idx - 1] - b[i]));
    // }
    // for (int i = 1; i <= n; i++) {
    //     int idx = lower_bound(b + 1, b + 1 + n, a[i]) - b;
    //    // cout << idx << endl;
    //     if (idx <= n)
    //         minn = min(minn, abs(b[idx] - a[i]));
    //     if (idx > 1)
    //         minn = min(minn, abs(b[idx - 1] - a[i]));
    // }
    int x = 1, y = 1;
    while (x <= n && y <= m) {
        minn = min(minn, abs(a[x] - b[y]));
        if (a[x] > b[y])
            y++;
        else
            x++;
    }
    cout << minn << '\n';
}
/* 10 10
5 14 23 34 45 56 67 78 89 100
1 10 20 40 40 50 60 75 80 90
*/