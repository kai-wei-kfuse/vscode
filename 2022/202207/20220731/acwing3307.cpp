#include <algorithm>
#include <iostream>

int a[200005];

using namespace std;
int main() {
    int n;
    cin >> n;
    int cnt = 1;
    while (n--) {
        int m;
        cin >> m;
        for (int i = 1; i <= m; i++) {
            cin >> a[i];
        }
        // a[m + 1] = 0x3f3f3f;
        int ans = 0;
        int maxn = 0;
        for (int i = 1; i <= m; i++) {
            if (a[i] > maxn && a[i] > a[i + 1])
                ans++;
            maxn = max(a[i], maxn);
        }
        cout << "Case #" << cnt << ": ";
        cout << ans << '\n';
        cnt++;
    }
}