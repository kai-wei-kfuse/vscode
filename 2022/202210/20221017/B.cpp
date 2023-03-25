#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans(n + 1, 0);
        int cnt = 1;
        for (int i = 1; i <= n; i += 2) {
            ans[i] = cnt++;
        }
        int j = n;
        if (ans[n] != 0)
            j = n - 1;
        for (int i = j; i >= 1; i -= 2) {
            ans[i] = cnt++;
        }
        for (int i = 1; i <= n; i++) {
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}