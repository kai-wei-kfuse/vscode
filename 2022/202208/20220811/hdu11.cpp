#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, k;
        cin >> n >> m >> k;
        int ans = 0;
        if (m / k > 0) {
            ans = m / k - 1 + n - 1;
        } else {
            int tmp = k / m;
            if (k % m != 0)
                tmp++;
            ans = n / tmp - 1;
        }
        cout << ans << '\n';
    }
}