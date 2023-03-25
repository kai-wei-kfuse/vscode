#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
ll a;
int main() {
    int n;
    ll numm = 6 * 4 / __gcd(6, 4);
    cin >> n;
    while (n--) {
        cin >> a;
        ll sum1 = 0, sum2 = 0;
        if ((a % 4) % 6 != 0 && (a % 6) % 4 != 0) {
            cout << "-1" << '\n';
        } else {
            ll tmp = a;
            ll tmp2 = a;
            if (tmp % 4 == 0 && tmp != 0) {
                sum1 = tmp / 4;
            } else {
                ll cnt = 0;
                while (tmp % 4 != 0) {
                    tmp--;
                    cnt++;
                }
                while (tmp % 6 != 0) {
                    tmp -= 4;
                }
                sum1 = tmp / 4;
                sum1 += cnt / 6;
            }
            if (tmp2 % 6 == 0 && tmp2 != 0) {
                sum2 = tmp2 / 6;
            } else {
                ll cnt = 0;
                while (tmp2 % 6 != 0) {
                    tmp2--;
                    cnt++;
                }
                cout << tmp2 << endl;
                while (tmp2 % 4 != 0) {
                    tmp2 -= 6;
                }
                cout << tmp2 << endl;
                sum2 = tmp2 / 6;
                sum2 += cnt / 4;
            }
            cout << sum2 << ' ' << sum1 << '\n';
        }
    }
}