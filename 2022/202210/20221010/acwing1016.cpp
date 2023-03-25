#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1);
    vector<int> q(n + 1), sum(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
        sum[i] = ve[i];
        q[i] = 1;
    }
    int len = 0, ans = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < i; j++) {
            if (ve[j] < ve[i]) {
                sum[i] = max(sum[i], ve[i] + sum[j]);
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        ans = max(ans, sum[i]);
    }
    cout << ans << endl;
}