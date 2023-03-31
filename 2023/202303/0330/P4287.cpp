#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 5e5 + 5;
int p[N << 1];
char a[N], ma[N << 1];
int l[N << 1], r[N << 1];

void manacher(char s[], int len) {
    int k = 0;
    ma[k++] = '$';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {
        ma[k++] = s[i];
        ma[k++] = '#';
    }
    // for (int i = 0; i < k; i++) {
    //     cout << ma[i] ;
    // }
    // cout << endl;
    int mr = 0, c = 0;
    for (int i = 1; i < k; i++) {
        if (i < mr) {
            p[i] = min(p[(c << 1) - i], p[c] + c - i);
        } else {
            p[i] = 1;
        }
        while (ma[p[i] + i] == ma[i - p[i]])
            p[i]++;
        if (p[i] + i > mr) {
            mr = p[i] + i;
            c = i;
        }
            l[i + p[i] - 1] = max(l[i + p[i] - 1], p[i] - 1);
            r[i - p[i] + 1] = max(r[i - p[i] + 1], p[i] - 1);
    }
}

signed main() {
    int n;
    cin >> n;
    cin >> a;
    // int len = strlen(a);
    manacher(a, n);
    // cout << ' ';
    for (int i = 1; i <= n * 2 + 1; i += 2) {
        r[i] = max(r[i], r[i - 2] - 2);
        // cout << r[i] << ' ';
    }
    // cout << endl;
    // cout << ' ';
    for (int i = n * 2 + 1; i >= 1; i -= 2) {
        l[i] = max(l[i], l[i + 2] - 2);
        //  cout << l[i] << ' ';
    }
    // cout << endl;
    int ans = 0;
    for (int i = 1; i < n * 2 + 1; i += 2) {
        if (r[i] && l[i] && r[i] == l[i] && p[i] - 1 == r[i] + l[i] && (p[i] - 1) % 4 == 0) {
            ans = max(ans, p[i] - 1);
        }
    }
    cout << ans << endl;
}