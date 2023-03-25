#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int ans = 9;
        int c1 = 0, c2 = 0, tot = 0;
        int sum1 = 5, sum2 = 5;
        for (int i = 0; i < 10; i++) {
           // cout << s[i] << ' ';

            if (i % 2 == 0) {
                if (s[i] == '1') {
                    c1++;
                } else if (s[i] == '?')
                    c1++;
                sum1--;
            } else if (i % 2 != 0) {
                if (s[i] == '1')
                    c2++;
                sum2--;
            }
            if (sum2 < c1 - c2) {
                ans = min(ans, i);
            }
            if (sum1 < c2 - c1) {
                ans = min(ans, i);
            }
            // cout << c1 << ' ' << c2 << ' ' << i << ' ' << sum1 << ' ' << sum2
            //      << ' ' << ans << endl;
        }
        
        sum1 = 5, sum2 = 5;
        c1 = 0, c2 = 0, tot = 0;
        for (int i = 0; i < 10; i++) {
            //cout << s[i] << ' ';

            if (i % 2 != 0) {
                if (s[i] == '1') {
                    c1++;
                } else if (s[i] == '?') {
                    c1++;
                }
                sum1--;
            } else if (i % 2 == 0) {
                if (s[i] == '1')
                    c2++;
                sum2--;
            }
            if (sum2 < c1 - c2) {
                ans = min(ans, i);
            }
            if (sum1 < c2 - c1) {
                ans = min(ans, i);
            }
            // cout << c1 << ' ' << c2 << ' ' << i << ' ' << sum1 << ' ' << sum2
            //      << ' ' << ans << endl;
        }
        cout << ans + 1 << endl;
    }
}