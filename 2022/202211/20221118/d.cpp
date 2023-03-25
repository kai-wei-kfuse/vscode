#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int lcm(int x, int y) {
    return x * y / __gcd(x, y);
}
signed main() {
    int t;
    IOS;
    cin >> t;
    while (t--) {
        int v, k, n;
        cin >> v >> k;
        int ans = 0;
        n = v;
        int ten = 0, five = 0, two = 0;
        while (n % 10 == 0) {
            n /= 10;
            ten++;
        }
        while (n % 5 == 0) {
            n /= 5;
            five++;
        }
        while (n % 2 == 0) {
            n /= 2;
            two++;
        }
        int cnt = 1;
        while (cnt <= k && five > 0) {
            five--;
            cnt *= 2;
        }
        if (cnt > k)
            cnt /= 2;
        while (cnt <= k && two > 0) {
            two--;
            cnt *= 5;
        }
        if (cnt > k)
            cnt /= 5;
        while (cnt <= k) {
            cnt *= 10;
        }
        if (cnt > k)
            cnt /= 10;
        cnt = k / cnt * cnt;
        if (cnt == 1) {
            cout << v * k << endl;
        } else
            cout << v * cnt << endl;
    }
    // for (int i = 1; i <= 1000000; i *= 10) {
    //     cout << lcm(4, i) / 4 << endl;
    // }
}