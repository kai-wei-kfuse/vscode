#include <bits/stdc++.h>
using namespace std;
struct xx {
    int l, r, a;
};
int main() {
    int n;
    cin >> n;
    vector<xx> ve;
    int maxn = 0;
    for (int i = 1; i <= n; i++) {
        int x, r, a;
        cin >> x >> r >> a;
        ve.push_back({max(x - r, 0), r + x, a});
        maxn = max(maxn, r + x);
    }
    vector<int> s(maxn + 2, 0);
    for (auto [l, r, a] : ve) {
        s[l] += a;
        s[r + 1] -= a;
    }
    int ans_ = 0, ans_i;
    for (int i = 1; i < maxn + 1; i++) {
        s[i] = s[i] + s[i - 1];
        if (ans_ < s[i]) {
            ans_ = s[i];
            ans_i = i;
        }
    }
    cout << ans_i << endl;
}