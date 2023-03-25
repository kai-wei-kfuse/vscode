#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ll;

const int P = 131;
ll h1[1000005], h2[1000005], p[1000005];

ll get1(int l, int r) {
    return h1[r] - h1[l - 1] * p[r - l + 1];
}

ll get2(int l, int r) {
    return h2[r] - h2[l - 1] * p[r - l + 1];
}

int main() {
    int n, m;
    string a, b;
    cin >> a >> b;
    a = "?" + a;
    b = "?" + b;
    n = a.size();
    m = b.size();
    p[0] = 1;
    for (int i = 1; i <= n; i++) {
        p[i] = p[i - 1] * P;
        h1[i] = h1[i - 1] * P + a[i];
    }
    for (int i = 1; i <= m; i++) {
        p[i] = p[i - 1] * P;
        h2[i] = h2[i - 1] * P + b[i];
    }
    ll all = h2[m];
    // cout << all << "x" << endl;
    vector<int> ans;
    for (int i = 1; i <= n; i++) {
        // cout << h1[i - 1] * p[n - i] + get1(i + 1, n) << endl;
        if (h1[i - 1] * p[n - i] + get1(i + 1, n) == all) {
            ans.push_back(i);
        }
    }
    cout << ans.size() << endl;
    if (!ans.empty()) {
        for (auto i : ans) {
            cout << i << ' ';
        }
    }
    cout << endl;
}
