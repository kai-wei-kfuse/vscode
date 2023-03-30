/// 欲戴皇冠，必承其重。
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<string, string> pii;
typedef unsigned long long ull;

#define x first
#define y second
#define PI acos(-1)
#define inf 0x3f3f3f3f
#define lowbit(x) ((-x) & x)
#define debug(x) cout << #x << ": " << x << endl;

const int MOD = 998244353;
const int mod = 998244353;
const int N = 5e5 + 10;
const int dx[] = {0, 1, -1, 0, 0, 0, 0};
const int dy[] = {0, 0, 0, 1, -1, 0, 0};
const int dz[] = {0, 0, 0, 0, 0, 1, -1};
int day[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

ll n, m;
ll a[N];
void solve() {
    scanf("%lld%lld", &n, &m);
    if (m > lowbit(n) - 1) {
        puts("Impossible");
    } else {
        for (int i = 1; i <= n; i++) {
            a[i] = i;
        }
        for (ll i = 1; i <= m; i++) {
            ll len = lowbit(i);
            for (ll j = 1; j <= n; j += (len << 1)) {
                for (ll k = 0; k < len; k++) {
                    swap(a[j + k], a[j + len * 2 - 1 - k]);
                }
            }
            for (int j = 1; j < n; j++) {
                cout << a[j] << " ";
            }
            cout << a[n] << endl;
        }
    }
}
int main() {
    ll t = 1;
    scanf("%lld", &t);
    while (t--) {
        solve();
    }
    return 0;
}
