#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int>> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i].first;
            ve[i].second = i;
        }
        sort(ve.begin() + 1, ve.end());
        cout << n - 1 << '\n';
        for (int i = 2; i <= n; i++) {
            int tmp = 0;
            tmp = ve[i].first % ve[i - 1].first;
            if (tmp>0) {
                ve[i].first += ve[i - 1].first - tmp;
                // cout << ve[i].first << endl;
                cout << ve[i].second << ' ' << ve[i - 1].first - tmp << '\n';
            }else{
                cout << ve[i].second << ' ' << 0 << '\n';
            }
            
        }
        // for (int i = 1; i <= n;i++){
        //     cout << ve[i].first << ' ';
        // }
    }
}