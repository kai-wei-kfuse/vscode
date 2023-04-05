#include <algorithm>
#include <iostream>
#define mod 1000000007
typedef long long ll;
using namespace std;
int a[100005];
int b[100005];
int main() {
    int n;
    cin >> n;
    int x, y;
    cin >> x;
    int xx = 0, yy = 0;
    for (int i = 1; i <= x; i++) {
        cin >> a[i];
    }
    cin >> y;
    for (int i = 1; i <= y; i++) {
        cin >> b[i];
    }
    ll jw = 1;
    int maxn;
    for (int i = x, j = y; i >= 1, j >= 1; i--, j--) {
        if (j >= 1)
            maxn = max(a[i], b[j]);
        else
            maxn = a[i];
        xx = (xx + a[i] * jw % mod) % mod;
        if (j >= 1)
            yy = (yy + b[j] * jw % mod) % mod;
        if (maxn != 0)
            jw *= (maxn + 1);
        else
            jw *= 2;
    }
    // cout << xx << ' ' << yy << endl;
    cout << (xx - yy + mod) % mod;
    return 0;
}