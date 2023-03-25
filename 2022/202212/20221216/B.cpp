#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<long long> ve(n + 1);
        long long ans = 0;
        cin >> ans;
        for (int i = 2; i <= n; i++) {
            cin >> ve[i];
        }
        sort(ve.begin() + 2, ve.end());
        for (int i = 2; i <= n;i++){
            if (ve[i] > ans)
                ans = (ans + ve[i] + 1) / 2;
        }
        cout << ans << endl;
    }
}