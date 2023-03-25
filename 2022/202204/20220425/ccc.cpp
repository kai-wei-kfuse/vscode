#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
typedef long long ll;
ll vis1[27], vis2[27];
int main() {
    // freopen("concatenation.in", "r", stdin);
    // freopen("concatenation.out", "w", stdout);
    string a, b;
    cin >> a >> b;
    ll lena = a.length();
    ll lenb = b.length();
    ll lenx = max(lena, lenb);
    for (ll i = 1; i < lena; i++) {
        vis1[a[i] - 'a']++;
    }
    for (ll j = 0; j < lenb - 1; j++) {
        vis2[b[j] - 'a']++;
    }
    // for (int i = 0; i < 26; i++) {
    //     cout << vis1[i] << ' ';
    // }
    // cout << endl;
    // for (int j = 0; j < 26; j++) {
    //     cout << vis2[j] << ' ';
    // }
    ll ans = lena * lenb;
    ll res = 0;
    for (int i = 0; i < 26; i++) {
        res += vis1[i] * vis2[i];
    }
    cout << ans - res;
}