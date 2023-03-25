#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
ll parent[100005];
ll num[100005];
struct xx {
    ll x, y;
} a[100005];
ll lsh1[200010];
ll ans = 0;
ll find(ll x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}
void root(ll x, ll y) {
    ll x_ = find(x);
    ll y_ = find(y);
    if (x_ != y_) {
        num[y_] += num[x_];
        ans = max(ans, num[y_]);
        parent[x_] = y_;
    }
}
int main() {
    IOS;
    int t;
    cin >> t;
    int n;
    while (t--) {
        cin >> n;
        ans = 0;
        memset(lsh1, 0, sizeof(lsh1));
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            num[i] = 1;
        }
        ll tot1 = 1;
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x >> a[i].y;
            lsh1[tot1++] = a[i].x;
            lsh1[tot1++] = a[i].y;
        }
        sort(lsh1 + 1, lsh1 + tot1);
        tot1 = unique(lsh1 + 1, lsh1 + tot1) - lsh1;
        sort(lsh1 + 1, lsh1 + tot1);
        for (int i = 1; i <= n; i++) {
            int x, y;
            x = lower_bound(lsh1 + 1, lsh1 + tot1, a[i].x) - lsh1;
            y = lower_bound(lsh1 + 1, lsh1 + tot1, a[i].y) - lsh1;
            // cout << x << ' ' << y << endl;
            root(x, y);
        }
        // for (int i = 1; i <= 25; i++) {
        //     cout << num[i] << ' ';
        // }
        cout << ans << '\n';
    }
}
/*
1
5
1 8
8 9
1 9
20 21
20 21

*/