#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;

char a[1000005], b[1000005];
int next_[1000005], z[1000005], p[1000005];

int main() {
    cin >> a + 1;
    int len = strlen(a + 1);
    int ans = 0;
    z[1] = len - 1;
    for (int i = 2, l, r = 0; i < len; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        while (i + z[i] < len && a[1 + z[i]] == a[i + z[i]])
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        ans = max(ans, z[i]);
    }
    p[1] = len;
    for (int i = 2, l, r = 0; i <= len; i++) {
        if (i <= r)
            p[i] = min(p[i - l + 1], r - i + 1);
        while (a[1 + p[i]] == a[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }

    // for (int i = 1; i < len; i++) {
    //     cout << z[i] << ' ';
    // }
    // cout << endl;
    //ans = min(ans, len);
    // cout << next_[len] << ' ' << ans << endl;
    int flag = 1;
    for (int i = len - ans + 1; i <= len; i++) {
        if (p[i] == len - i + 1) {
            for (int j = i; j <= len; j++) {
                cout << a[j];
            }
            flag = 0;
            break;
        }
    }
    if (flag)
        cout << "Just a legend";
}