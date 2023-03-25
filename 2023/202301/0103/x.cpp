#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define ll long long
const int maxn = 1e6 + 10;
const int mod = 1e9 + 7;

ll a[maxn];
priority_queue<ll> p;
void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    ll sum = 0;
    ll now = 0;
    for (int i = k + 1; i <= n; i++) {
        if (a[i] >= 0) {
            now += a[i];
        } else {
            now += a[i];
            p.push(-a[i]);
            if (now < 0) {
                while (now < 0) {
                    now += 2 * p.top();
                    p.pop();
                    sum++;
                }
            }
        }
    }
    while (!p.empty())
        p.pop();

    now = 0;
    for (int i = k; i >= 2; i--) {
        if (a[i] <= 0) {
            now += a[i];
        } else {
            now += a[i];
            p.push(a[i]);
            while (now > 0) {
                now -= 2 * p.top();
                p.pop();
                sum++;
            }
        }
    }
    cout << sum << endl;
    while (!p.empty())
        p.pop();
}

int main() {
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}