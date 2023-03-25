#include <algorithm>
#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int a[1000002];
int main() {
    IOS;
    int cnt = 0;
    for (int i = 2000; i <= 9999; i++) {
        if ((i % 4 == 0 && i % 100 != 0) || i % 400 == 0)
            day[2] = 29;
        else
            day[2] = 28;
        for (int j = 1; j <= 12; j++) {
            for (int k = 1; k <= day[j]; k++) {
                int x = i * 10000 + j * 100 + k;
                string tmp = to_string(x);
                if (tmp.find("202") != tmp.npos) {
                    // cout << cnt << ':' << x << endl;
                    a[++cnt] = x;
                }
            }
        }
    }
    int n;
    cin >> n;
    int ye1, ye2, m1, m2, d1, d2;
    while (n--) {
        cin >> ye1 >> m1 >> d1;
        cin >> ye2 >> m2 >> d2;
        int l = ye1 * 10000 + m1 * 100 + d1;
        int r = ye2 * 10000 + m2 * 100 + d2;
        int ans1 = lower_bound(a + 1, a + cnt + 1, l) - a;
        // int ans3 = lower_bound(a + 1, a + cnt + 1, r) - a;
        int ans2 = upper_bound(a + 1, a + cnt + 1, r) - a;
        // cout << a[ans1] << ' ' << a[ans2] << ' ' << a[ans3] << endl;
        cout << ans2 - ans1 << '\n';
    }
}