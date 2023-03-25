#include <cmath>
#include <iostream>
typedef long long ll;
using namespace std;
int a[10000];
int main() {
    int n, k;
    cin >> k >> n;
    ll cnt = 0;
    while (n) {
        a[cnt++] = n & 1;
        n >>= 1;
    }
    cnt--;
    ll ans = 0;
    while (cnt >= 0) {
        ans += pow(k, cnt) * a[cnt];
        cnt--;
    }
    cout << ans;
}