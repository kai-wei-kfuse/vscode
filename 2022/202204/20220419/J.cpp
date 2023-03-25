#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
struct node {
    int pos;
    int high;
} h[100005];
bool cmp(node x, node y) {
    return x.high < y.high;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int t;
    int a[100005], b[100005];
    int cnt = 1;

    a[0] = -1;
    while (n--) {
        cin >> t;
        int x = 0;
        ll sum = 0;
        for (int i = 1; i <= t; i++) {
            cin >> a[i];
            sum += a[i];
            if (i == 2) {
                if (a[i] > a[1]) {
                    b[i] = 0;
                }
            }
        }
        int hig = 0;
        h[1].high = 0;
        for (int i = 2; i <= t; i++) {
            if (a[i] > a[i - 1])
                hig++;
            else
                hig--;
            h[i].high = hig;
        }
        sort(h + 1, h + t + 1, cmp);
        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += h[i].high - h[1].high;
        }
        // for (int i = 1; i <= t; i++) {
        //     cout << h[i].high - h[0].high << ' ';
        // }
        cout << ans << ' ';
        cout << sum - ans << ' ';
        if ((sum - ans) % 2 == 0) {
            printf("Case %d: Alice\n", cnt);
        } else {
            printf("Case %d: Bob\n", cnt);
        }
        cnt++;
    }
}