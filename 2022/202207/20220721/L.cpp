#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
int main() {
    int n;
    cin >> n;
    while (n--) {
        ll tmp;
        ll ans = 0;
        cin >> tmp;
        ans += (tmp / 79205) * 7LL * 31LL;
        tmp %= 79205;
        ll num365 = tmp / 365;
        ll tmp1 = tmp;
        ll ans1 = 0x3f3f3f;
        int flag = 1;
        for (int i = num365; i >= 0; i--) {
            tmp = tmp1;
            ll res = 0;
            ll num31 = (tmp - i * 365) / 31;
            res += i;
            for (int j = num31; j >= 0; j--) {
                ll num7 = (tmp - j * 31 - i * 365) / 7;
                res = i;
                res += j;
                if ((tmp - j * 31 - i * 365) % 7 == 0) {
                    res += (tmp - j * 31 - i * 365) / 7;
                    ans1 = res;
                    flag = 0;
                    break;
                }
            }
            if (flag == 0)
                break;
        }
        if (flag) {
            cout << "-1" << '\n';
        } else
            cout << ans + ans1 << '\n';
    }
}