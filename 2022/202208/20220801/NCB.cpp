#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
struct xx {
    ll x, i;
};
bool cmp(xx a, xx b) {
    return a.x < b.x;
}

int main() {
    int n, m;
    while (cin >> n >> m) {
        ll sum = 0, ans = 0;
        vector<xx> a(n + 1);
        vector<ll> s(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i].x;
        }
        sort(a.begin(), a.end(), cmp);
        for (int i = 1; i <= n; i++) {
            s[i] = s[i - 1] + a[i].i;
        }
        for (int j = 0; j < n;) {
            int i = j + 1;
            if (sum + i * a[i].i + s[i - 1] + a[i].x <= m) {
                sum = sum + i * a[i].i + s[i - 1] + a[i].x;
                j++;
            } else {
                ans = j;
                break;
            }
        }
        cout << ans << '\n';
    }
}