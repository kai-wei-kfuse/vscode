#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> a(100005);
signed main() {
    int t;
    cin >> t;
    int cnt = 0;
    while (t--) {
        int n, v;
        cin >> n >> v;
        cnt++;
        vector<pair<int, int> > ve(n + 1);
        vector<int> dp(v, 0);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i].first;
        }
        for (int i = 1;i<=n;i++){
            cin >> ve[i].second;
        }
        sort(ve.begin() + 1, ve.end());
        int ans = 0;
        int cn = 0;
        for (int i = 1; i <= n;i++)
        {
            if(ans+ve[i].second<=v)
            {
                cn++;
                ans += ve[i].second;
            }else
            {
                break;
            }
        }
            cout << "Case " << cnt << ": " << cn << endl;
    }
}