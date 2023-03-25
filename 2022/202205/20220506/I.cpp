#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 1e7 + 5;
const int M = 1e9 + 1;
int x[N];
int p[N];
int sum[N];
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> x[i];
    }
    sum[0] = p[0];
    for (int i = 1; i < N; i++) {
        sum[i] = sum[i - 1] + p[i];
    }
    x[0] = -M;
    x[m + 1] = M;
    sort(x, x + m + 2);
    int maxn = 0;
    for (int k = 0; k <= n - 1; k++) {
        int ind = lower_bound(x, x + m + 2, k * 100) - x - 1;
        //        cout<<ind<<endl;
        double l = 100 * k - 1 / 2.0;
        double r = min((double)x[ind + 1], l + (x[ind + 1] - x[ind]) / 2.0);
        //        cout<<l<<" "<<r<<endl;
        int t = (int)((r - l) / 100.0);
        //		cout<<t<<endl;
        if (k - 1 >= 0) {
            maxn = max(maxn, sum[t + k] - sum[k - 1]);
        } else {
            maxn = max(maxn, sum[t + k] - 0);
        }
    }
    cout << maxn;
}
