#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int a[100010];
int n, m;
int chack(int len) {
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += a[i] / len;
    }
    if (sum >= m)
        return 1;
    else
        return 0;
}
int main() {
    cin >> n >> m;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        maxn = max(a[i], maxn);
    }
    int l = 0, r = maxn + 1, mid;
    while (l + 1 != r) {
        if (r == 0) {
            cout << "0";
            return 0;
        }
        mid = l + ((r - l) >> 1);
        if (chack(mid))
            l = mid;
        else
            r = mid;
    }
    cout << l;
}