#include <iostream>
#include <vector>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1), b(n + 1);
        vector<pair<int, int> > ans(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; i++) {
            cin >> b[i];
        }
        int l = n, r = n;
        for (int i = n; i >= 1; i--) {
            while (l >= 2 && b[l - 1] >= a[i])
                l--;
            if (l == i) {
                ans[i].first = b[l] - a[i];
                ans[i].second = b[r] - a[i];
                r = i - 1;
            } else {
                ans[i].first = b[l] - a[i];
                ans[i].second = b[r] - a[i];
            }
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i].first << ' ';
        }
        cout << '\n';
        for (int i = 1; i <= n; i++) {
            cout << ans[i].second << ' ';
        }
        cout << '\n';
    }
}