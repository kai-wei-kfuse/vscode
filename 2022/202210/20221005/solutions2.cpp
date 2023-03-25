#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n, ans = 0x3f3f3f3f;
vector<int> ve, res;
void dfs(ll x, ll t) {
    if (x == n) {
        if (ans > t) {
            res = ve;
            ans = t;
        }
        return;
    }
    if (x > n) {
        return;
    }
    ve.push_back(1);
    dfs(x + 1, t + 1);
    ve.pop_back();
    if (x > 0) {
        ve.push_back(2);
        dfs(x * 3, t + 1);
        ve.pop_back();
    }
}

int main() {
    cin >> n;
    dfs(0, 0);
    cout << ans << endl;
    for (auto i : res) {
        cout << i << ' ';
    }
}