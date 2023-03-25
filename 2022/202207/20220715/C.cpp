#include <cstring>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
string a;
struct xx {
    ll a, b, c, d;
};
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y, z;
        cin >> x >> y >> z;
        cin >> a;
        ll r, l;
        vector<xx> ve;
        ve.push_back({1, x, 1, x});
        ll len = 0;
        for (int i = 1; i <= y; i++) {
            cin >> l >> r;
            ve.push_back({l, r, x + len + 1, r - l + 1 + len + x});
            // cout << l << ' ' << r << ' ' << x + len + 1 << ' '
            //<< r + r - l + 1 + len + x << '\n';
            len += r - l + 1;
        }
        ll tmp;
        // cout << ve.size() << endl;
        for (int i = 1; i <= z; i++) {
            cin >> tmp;
            while (tmp > x)
                for (auto j : ve) {
                    // cout << j.d << ' ' << j.c << '|' << tmp << endl;
                    if (tmp <= j.d && tmp >= j.c) {
                        tmp -= (j.c - j.a);
                        // tmp++;
                        // cout << tmp << '|' << endl;
                    }
                }
            // cout << tmp << endl;
            cout << a[tmp - 1] << '\n';
        }
    }
}