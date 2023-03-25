#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int len, n, m, minn;
int a[500005];
int chack(int x) {
    int sum = 0, last = 0, pull = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] - a[last] < x) {
            sum++;
            pull++;
        } else
            last += pull, pull = 1;
    }
    return sum <= m;
}
int main() {
    cin >> len >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        minn = min(a[i] - a[i - 1], minn);
    }
    ll l = minn, r = len + 1, mid;
    while (l + 1 != r) {
        mid = l + ((r - l) >> 1);
        if (chack(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
}