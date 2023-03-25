#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        if (n % m != 0) {
            cout << "-1" << endl;
            continue;
        }
        vector<int> ans;
        ans.push_back(-1);
        ans.push_back(m);
        for (int i = 2; i < n; i++) {
            if (i != m) {
                ans.push_back(i);
            } else {
                ans.push_back(n);
            }
        }
        ans.push_back(1);
        int tmp = n / m;
        int idx = m;
        for (int i = 2; i*i <= tmp; i++) {
            if (tmp % i == 0) {
                tmp/= i;
                ans[idx] = idx * i;
                idx = idx * i;
                while (tmp % i == 0) {
                    tmp /= i;
                    ans[idx] = idx * i;
                    idx = idx * i;
                }
            }
        }
        if (tmp > 1) ans[idx] = idx * tmp;
        for (int i = 1; i <= n;i++){
            cout << ans[i] << ' ';
        }
        cout << endl;
    }
}