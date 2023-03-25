#include <algorithm>  //c
#include <iostream>
using namespace std;
typedef long long ll;
int a[100005];
ll sum1[100005];
ll sum2[100005];
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        if (n % 2 == 0) {
            sum = 0x3f3f3f;
            for (int i = 2; i < n; i += 2) {
                if (a[i] <= a[i - 1] || a[i] <= a[i + 1])
                    sum1[i] = max(a[i - 1], a[i + 1]) - a[i] + 1 + sum1[i - 2];
                else {
                    sum1[i] = sum1[i - 2];
                }
                // cout << sum1[i] << ' ';
            }
            // cout << endl;
            for (int i = n - 1; i > 2; i -= 2) {
                if (a[i] <= a[i - 1] || a[i] <= a[i + 1])
                    sum2[i] = max(a[i - 1], a[i + 1]) - a[i] + 1 + sum2[i + 2];
                else {
                    sum2[i] = sum2[i + 2];
                }
                // cout << sum2[i] << ' ';
            }
            // cout << endl;
            for (int i = 1; i <= n; i += 2) {
                sum = min(sum, sum2[i + 2] + sum1[i - 1]);
            }
        } else if (n % 2 == 1) {
            for (int i = 2; i <= n; i += 2) {
                if (a[i] <= a[i - 1] || a[i] <= a[i + 1])
                    sum += max(a[i - 1], a[i + 1]) - a[i] + 1;
            }
        }
        cout << sum << '\n';
    }
}