#include <bits/stdc++.h>
const double pi = 3.1415926535897932384626433832795028841971693993751;
const double xx = 1.00914177324;
const double yy = 0.5176380902050;
// 0.5176380902050;
//  1.008934682;
// 1.00914177324;
using namespace std;
int main() {
    int n;
    string a;
    cin >> n;
    cin >> a;
    int len = n - 1;
    double ans = 0;
    if (n == 1) {
        if (a[0] == 'S') {
            ans += 4.0;
        }
        if (a[0] == 'T') {
            ans += 3.0;
        }
        if (a[0] == 'C') {
            ans += pi;
        }
    } else {
        if (a[0] == 'S') {
            ans += 3.0;
        }
        if (a[0] == 'C') {
            ans += pi * 0.5 + 1.0;
        }
        if (a[0] == 'T') {
            ans += 2.5;
            for (int i = 0; i < n; i++) {
                if (a[i] != 'T') {
                    if (a[i] == 'S') {
                        ans +=
                            sqrt(7.0 / 4.0 - sqrt(3.0) + (i - 0.5) * (i - 0.5));
                        ans -= i - 0.5;
                    }
                    if (a[i] == 'C') {
                        double d1 =
                            sqrt(3.0 / 4.0 - sqrt(3.0) / 2.0 + i * 1.0 * i);
                        ans += 0.5 * (pi / 2.0 - atan(d1 / 0.5) -
                                      atan(((sqrt(3) - 1.0) / 2.0) / i)) +
                               d1;
                        ans -= 1.0 * i;
                    }
                    break;
                }
            }
        }
        //++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
        if (a[len] == 'S') {
            ans += 3.0;
        }
        if (a[len] == 'C') {
            ans += pi * 0.5 + 1.0;
        }
        if (a[len] == 'T') {
            ans += 2.5;
            int cnt = 0;
            for (int i = len; i >= 0; i--) {
                if (a[i] != 'T') {
                    if (a[i] == 'S') {
                        ans += sqrt(7.0 / 4.0 - sqrt(3) +
                                    (cnt - 0.5) * (cnt - 0.5));
                        ans -= cnt - 0.5;
                    }
                    if (a[i] == 'C') {
                        double d1 =
                            sqrt(3.0 / 4.0 - sqrt(3) / 2.0 + cnt * 1.0 * cnt);
                        ans += 0.5 * (pi / 2.0 - atan(d1 / 0.5) -
                                      atan(((sqrt(3) - 1) / 2.0) / cnt)) +
                               d1;
                        ans -= 1.0 * cnt;
                    }
                    break;
                }
                cnt++;
            }
        }
        ///++++
        // printf("%.11lf\n", ans);
        if (n > 2) {
            ans += (double)(n - 2) * 2.0;
        }
    }
    printf("%.11lf\n", ans);
}
/*
3
TTS
*/