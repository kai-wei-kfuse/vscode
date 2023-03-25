#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> P;
#define fi first
#define se second
void cf(P& a, P& b, P& c) {
    int x = abs(a.fi * b.se - a.se * b.fi) * abs(a.fi * b.se - a.se * b.fi);
    int y = a.se * b.se * a.se * b.se;
    c = {x / __gcd(x, y), y / __gcd(x, y)};
}
void jf(P& a, P& b) {
    int x = abs(a.fi * b.se + a.se * b.fi);
    int y = a.se * b.se;
    a = {x / __gcd(x, y), y / __gcd(x, y)};
}
int main() {
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    vector<int> b(16);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 15; j++) {
            if (a[i] & (1 << j)) {
                b[j]++;
            }
        }
    }
    bitset<16> bb[n + 1];
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 15; j++) {
            if (b[j]) {
                bb[i][j] = 1;
                b[j]--;
            }
        }
    }
    vector<int> sz(n + 1);
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j < 15; j++) {
            if (bb[i][j])
                sz[i] += (bb[i][j] << j);
        }
    }
    vector<P> ve(n + 1);
    P pj;
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        ve[i] = {sz[i], 1};
        sum += sz[i];
    }
    if (sum == 0) {
        cout << 0 << "/" << 1 << endl;
        return 0;
    }
    int yf = __gcd(sum, n);
    pj = {sum / yf, n / yf};
    P s = {0, 1};
    for (int i = 1; i <= n; i++) {
        P c;
        cf(ve[i], pj, c);
        jf(s, c);
    }
    int xx = s.se * n;
    s = {s.fi / __gcd(s.fi, xx), xx / __gcd(s.fi, xx)};
    cout << s.fi << "/" << s.se << endl;
}