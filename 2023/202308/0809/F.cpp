#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            mp[tmp]++;
        }
        int q;
        cin >> q;
        for (int i = 1; i <= q; i++) {
            int b, c;
            cin >> b >> c;
            int der = b * b - 4 * c;
            int der_ = sqrt(der);
            if (der_ * der_ != der || der < 0) {
                cout << 0 << ' ';
                continue;
            }
            int x = (b + der_) / 2;
            int y = (b - der_) / 2;
            if ((b + der_)%2 || (b - der_)%2) {
                cout << 0 << ' ';
                continue;
            }
            // cout<<x<<' '<<y<<endl;
            if (x != y)
                cout << mp[x] * mp[y] << " ";
            else {
                cout << (mp[x] * (mp[x] - 1)) / 2 << " ";
            }
        }
        cout << endl;
    }
}