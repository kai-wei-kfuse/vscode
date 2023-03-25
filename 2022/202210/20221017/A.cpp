#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(10, 0);
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            ve[tmp]++;
        }
        int res = 0;
        for (int i = 0; i <= 9; i++) {
            if (ve[i] == 0) {
                res++;
            }
        }
        int ans1 = 1, ans2 = 1;
        // cout << res << endl;
        for (int i = 1; i <= res; i++) {
            ans1 *= i;
        }
        for (int i = 1; i <= res - 2; i++) {
            ans2 *= i;
        }
        cout << 6 * ans1 / (2 * ans2) << endl;
    }
}