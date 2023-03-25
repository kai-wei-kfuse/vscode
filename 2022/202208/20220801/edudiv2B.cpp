#include <iostream>
using namespace std;
typedef long long ll;

ll a[100005], ans[100005], ans2[100005];

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i - 1] > a[i]) {
            ans[i] += a[i - 1] - a[i] + ans[i - 1];
            ans2[i] = ans2[i - 1];
        } else if (a[i - 1] < a[i]) {
            if (i != 1)
                ans2[i] += a[i] - a[i - 1] + ans2[i - 1];
            ans[i] = ans[i - 1];
        } else {
            ans2[i] = ans2[i - 1];
            ans[i] = ans[i - 1];
        }
    }
    int x, b;
    for (int i = 1; i <= m; i++) {
        cin >> x >> b;
        if (x <= b)
            cout << ans[b] - ans[x] << '\n';
        else
            cout << ans2[x] - ans2[b] << '\n';
    }
}
