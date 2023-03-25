#include <cstring>
#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        string s;
        cin >> s;
        int len = s.length();
        int cnt1 = 0, x = -1, y = -1;
        for (int i = 0; i < len; i++) {
            if (s[i] == '1')
                cnt1++;
            if (x == -1 && s[i] == '1')
                x = i;
            if (s[i] == '1')
                y = len - i - 1;
        }
        // cout << x << y << endl;
        int ans = 0;
        // = cnt1 * 11;
        if (len == 1)
            cout << s << '\n';
        else {
            if (cnt1) {
                // int flagx = 1, flagy = 1;
                // if (flagx && flagy && x == 0 && y <= k) {
                //     ans -= 10;
                // } else {
                //     if (x == 0) {
                //         ans--;
                //         flagx = 0;
                //         cnt1--;
                //     }
                //     if (y == 0) {
                //         ans -= 10;
                //         flagy = 0;
                //         cnt1--;
                //     }
                if (k >= y && cnt1) {
                    ans += 1;
                    k -= y;
                    cnt1--;
                }
                if (k >= x && cnt1) {
                    ans += 10;
                    cnt1--;
                }
                // }
            }
            cout << cnt1*11+ans << '\n';
        }
        // if (cnt1 == 0) {  //全是0
        //     cout << '0' << '\n';
        // } else if (cnt1 == len) {  //全是1
        //     cout << cnt1 * 11 << '\n';
        // } else if (cnt1 > 0 && x == 0 && y == 0) {
        //     cout << cnt1 * 11 - 11 << '\n';
        // } else {
        //     if ((k < x && k < y)) {  //都移不到边界
        //         cout << cnt1 * 11 << '\n';
        //     } else if (k >= y) {
        //         cout << cnt1 * 11 - 10 << '\n';
        //     } else if (k >= x && k < y) {
        //         cout << cnt1 * 11 - 1 << '\n';
        //     } else if (k >= x + y) {
        //         cout << cnt1 * 11 - 11 << '\n';
        //     }
        // }
    }
}