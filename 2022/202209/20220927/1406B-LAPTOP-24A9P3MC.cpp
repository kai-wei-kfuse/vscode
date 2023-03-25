#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ull> a(n + 1);
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ull ans = 0, ans_ = 0x3f3f3f3f, res = 1;
        sort(a.begin() + 1, a.end());
        int front_ = 5, back_ = 0;
        while (front_ >= 0) {
            res = 1;
            int num = 0;
            for (int i = 1; i <= front_; i++) {
                cout << a[i] << ' ';
                if (a[i] < 0)
                    num++;
                res *= a[i];
            }
            for (int i = n; i > n - back_; i--) {
                res *= a[i];
                if (a[i] < 0)
                    num++;
                cout << a[i] << ' ';
            }
            cout << endl << res << endl;
            front_--;
            back_++;
            if (num % 2 == 0)
                ans = max(ans, res);
            else
                ans_ = min(ans_, res);
        }
        if (ans >= 0)
            cout << ans << endl;
        else
            cout << '-' << ans_ << endl;
    }
}