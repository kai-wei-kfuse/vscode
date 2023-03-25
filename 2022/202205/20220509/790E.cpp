#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;
ll a[200000];
ll sum[200000];
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        for (int i = 1; i <= x; i++) {
            cin >> a[i];
        }
        sort(a + 1, a + x + 1, greater<int>());
        for (int i = 1; i <= x; i++) {
            sum[i] = sum[i - 1] + a[i];
        }
        int tmp;
        for (int i = 1; i <= y; i++) {
            cin >> tmp;
            int ans = lower_bound(sum + 1, sum + x + 1, tmp) - sum;
            if (ans == x + 1)
                cout << "-1" << '\n';
            else
                cout << ans << '\n';
        }
    }
}