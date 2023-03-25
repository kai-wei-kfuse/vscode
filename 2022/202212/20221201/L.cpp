#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int n;
    cin >> n;
    vector<int> ve(n + 1), pref(n + 1, 0);
    for (int i = 1; i <= n; i++) 
    {
        cin >> ve[i];
    }
    sort(ve.begin() + 1, ve.end());
    for (int i = 1; i <= n; i++) 
    {
        pref[i] = ve[i] + pref[i - 1];
    }
    int l = 1;
    int ans = 0, avg = ve[1];
    for (int i = 2; i <= n; i++) 
    {
        avg = pref[i] / i;
        while (l <= n && ve[l] <= avg)
            l++;
        ans = max(ans, i - l + 1);
    }
    cout << ans;
}