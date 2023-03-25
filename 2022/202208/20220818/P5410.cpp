#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;

char a[20000005], b[20000005];
int z[20000005], p[20000005];

int main() {
    cin >> a + 1 >> b + 1;
    int lenb = strlen(b + 1);
    int lena = strlen(a + 1);
    z[1] = lenb;
    ll ans = 0 ^ (z[1] + 1);
    for (int i = 2, l = 0, r = 0; i <= lenb; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);
        while (b[1 + z[i]] == b[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;
        ans ^= 1ll * i * (z[i] + 1);
    }

    // for (int i = 1; i <= lenb; i++) {
    //     ans ^= i * (z[i] + 1);
    // }
    cout << ans << '\n';
    ans = 0;
    for (int i = 1, l = 0, r = 0; i <= lena; i++) {
        if (i <= r)
            p[i] = min(z[i - l + 1], r - i + 1);
        while (1 + p[i] <= lenb && i + p[i] <= lena &&
               b[1 + p[i]] == a[i + p[i]]) {
            p[i]++;
        }
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
        ans ^= 1ll * i * (p[i] + 1);
    }
    // for (int i = 1; i <= lena; i++) {
    //     ans ^= i * (p[i] + 1);
    // }
    cout << ans;
}