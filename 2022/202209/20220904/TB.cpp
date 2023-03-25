#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 2);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int ansl = 1, ansr = n;
        int l = 1, r = 1, cnt = 0, cnt2 = 0, res = 1, ans = 0;
        while (r <= n) {
            while (r <= n && ve[r] != 0) {
                if (ve[r] < 0)
                    cnt++;
                if (ve[r] == 2 || ve[r] == -2)
                    cnt2++;
                if (cnt % 2 == 0) {
                    // cout << (int)pow(2, cnt2) << '|';
                    if (ans < cnt2) {
                        //ansl = l - 1, ansr = n - r;
                        ansl = l , ansr = r;
                        ans = cnt2;
                    }
                }
                r++;
            }
            // cout << ans<<'\n';
            // cout << r << '|' << endl;
            // cout << ansl - 1 << ' ' << n - ansr << '\n';
            while (l <= r) {
                if (ve[l] < 0)
                    cnt--;
                if (ve[l] == 2 || ve[l] == -2)
                    cnt2--;
                if (cnt % 2 == 0) {
                    if (ans < cnt2) {
                        //ansl = l, ansr = n - r + 1;
                        ansl = l+1, ansr = r - 1;
                        ans = cnt2;
                    }
                    while (r <= n && ve[r] == 0)
                        r++;
                    l = r;
                    cnt2 = 0, cnt = 0;
                    // cout << l << ':' << r << endl;
                    break;
                }
                l++;
            }
            // cout << ansl - 1 << ' ' << n - ansr << '\n';
        }
        if (ans == 0) {
            cout << '0' << ' ' << n << '\n';
        } else
            cout << ansl-1 << ' ' << n-ansr << '\n';
    }
}
/* 5
4
1 2 -1 2
3
1 1 -2
5
2 0 -2 2 -1
3
-2 -1 -1
3
-1 -2 -2 */