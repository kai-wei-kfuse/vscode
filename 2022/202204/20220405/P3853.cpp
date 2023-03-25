#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int len, k, n;
int al[100005];
ll maxn = 0;
int chack(int maxs) {
    int sum = 0;
    for (int i = 2; i <= n; i++) {
        if (al[i] - al[i - 1] > maxs) {
            sum += (al[i] - al[i - 1]) / maxs;
            if ((al[i] - al[i - 1]) % maxs == 0)
                sum--;
        }
    }
    // cout << sum << endl;
    //  return sum <= maxs;
    if (sum <= k)
        return 1;
    else
        return 0;
}
int main() {
    cin >> len >> n >> k;
    int tmp;
    for (int i = 1; i <= n; i++) {
        cin >> al[i];
        maxn = max((al[i] - al[i - 1]) * 1LL, maxn);
    }
    ll l = 0, r = maxn + 1, mid;
    while (l + 1 != r) {
        mid = l + ((r - l) >> 1);
        // cout << mid << ":";
        if (chack(mid))
            r = mid;
        else
            l = mid;
    }
    cout << r;
}