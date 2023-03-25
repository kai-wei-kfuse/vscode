#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        int gcd_ = ve[1];
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            gcd_ = __gcd(ve[i], gcd_);
        }
        if (gcd_ == 1) {
            cout << ve[n] << endl;
        } else {
            cout << ve[n] / gcd_ << endl;
        }
    }
}