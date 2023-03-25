#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;

ll a[100005];

ll get(int i) {
    return max(0LL, max(a[i - 1], a[i + 1]) - a[i] + 1LL);
}

int main() {
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        ll sum = 0;
        for (int i = 2; i < n; i += 2) {
            sum += get(i);
        }
        if (n & 1) {
            cout << sum << '\n';
        } else {
            ll tmp = sum;
            for (int i = n - 1; i > 1; i -= 2) {
                sum = min(sum, tmp - get(i - 1) + get(i));
                tmp = tmp - get(i - 1) + get(i);
            }
            cout << sum << '\n';
        }
    }
}