#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ans;
        int l = 1, r = 0;
        while (l <= n) {
            r = n / (n / l);
            ans.push_back(r);
            l = r + 1;
        }
        sort(ans.begin(), ans.end());
        cout << ans.size()+1 << endl
             << 0 << ' ';
        for (auto i : ans) {
            cout << i << ' ';
        }
        cout << endl;
    }
}