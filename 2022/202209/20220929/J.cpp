#include <bits/stdc++.h>
using namespace std;
#define int long long
#define IOS ios::sync_with_stdio(0),cin.tie(0)
int next_[10000005], suf[10000005];
signed main() {
    IOS;
    int x, y;
     cin >> x >> y;
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    a = " " + a;
    int len = a.length() - 1;
    for (int i = 2, j = 0; i <= len; i++) {
        if(a[i]=='.')
            break;
        while (j && a[i] != a[j + 1])
            j = next_[j];
        if (a[i] == a[j + 1])
            j++;
        next_[i] = j;
    }
   // cout << a << endl;
    int maxn = -LLONG_MAX;
    for (int i = 1; i <= len; i++) {
        if(a[i]=='.')
            break;
        suf[i] = i - next_[i];
        maxn = max(maxn, i * x - y * suf[i]);
/*         cout << suf[i] << ' '; */
    }
    cout << maxn << endl;
}