#include <iostream>
using namespace std;

int a[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (i <= k && a[i] > k)
                ans++;
        }
        cout << ans << '\n';
    }
}