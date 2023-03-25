#include <iostream>
using namespace std;

const int N = 200010;
long long a[N], b[N], as[N], bs[N], next_[N];

int main() {
    int t;
    cin >> t;

    while (t--) {
        long long n, m, k;
        cin >> n >> m >> k;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 2; i <= n; i++) {
            as[i - 1] = (a[i]%k - a[i - 1]%k + k) % k;
            //cout << as[i - 1]<<' ';
        }
        //cout << endl;
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        for (int i = 2; i <= m; i++) {
            bs[i - 1] = (b[i]%k - b[i - 1]%k + k) % k;
             //cout << bs[i - 1] << ' ';
        }
        // cout << endl;
        for (int i = 2, j = 0; i < m; i++) {
            while (j && bs[i] != bs[j + 1])
                j = next_[j];
            if (bs[i] == bs[j + 1])
                j++;
            next_[i] = j;
        }
        long long ans = 0;
        for (int i = 1, j = 0; i < n; i++) {
            while (j && (as[i] + bs[j + 1]) % k != 0)
                j = next_[j];
            if ((as[i] + bs[j + 1]) % k == 0)
                j++;
            if (j == m - 1) {
                ans++;
                j = next_[j];
            }
        }
        cout << ans << '\n';
    }
}