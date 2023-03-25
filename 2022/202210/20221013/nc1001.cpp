#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        string x;
        cin >> x;
        int flag = 1;
        if (x[0] == '-') {
            flag = 0;
        } else {
            x = " " + x;
        }
        int l, r;
        cin >> l >> r;
        int f = 0;
        int L = 0;
        for (int i = 1; x[i] != '.'; i++, L = i + 1) {
            f = f * 10 + x[i] - '0';
        }
        //cout << L << endl;
        for (int i = L; i < L - 1 + l; i++) {

            f = f * 10 + x[i] - '0';
        }
        L = L - 1 + l;
        //cout << f << endl;
        int xiaoshu = 0;
        for (int i = L; i <= L + r - l; i++) {
            xiaoshu = (x[i] - '0') + xiaoshu * 10;
        }
        //cout << xiaoshu << endl;
        int base = 0;
        for (int i = 0; i <= r - l; i++) {
            base = base * 10 + 9;
        }
        //cout << xiaoshu << "/" << base << endl;
        int fengzi = f * base + xiaoshu;
        //cout << fengzi << "/" << base << endl;
        for (int i = 1; i <= l - 1; i++) {
            base *= 10;
        }
        int gcd_ = __gcd(fengzi, base);
        if (flag == 0)
            cout << "-";
        if (base / gcd_ == 1) {
            cout << fengzi / gcd_ << endl;
        } else
            cout << fengzi / gcd_ << "/" << base / gcd_ << endl;
    }
}