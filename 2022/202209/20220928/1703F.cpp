#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a, cnt = 0;
        vector<int> ve(n + 1),ve2;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
       // sort(ve.begin() + 1, ve.end());
        long long ans = 0;
        for (int i = 1; i <= n;i++) {
            if(ve[i]>=i)continue;
            ans += lower_bound(ve2.begin(), ve2.end(), ve[i]) - ve2.begin();
            ve2.push_back(i);
        }
        cout << ans << endl;
        // for (int i = 1; i <= cnt; i++) {
        //     // ans += ve.end() -
        //     // cout <<
        //     upper_bound(ve + 1, ve+n+1, ve[i].second,cmp);
        //     // -ve.begin();
        // }
        // cout << ans << endl;
    }
}