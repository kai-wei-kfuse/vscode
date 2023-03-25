#include <bits/stdc++.h>
using namespace std;

struct xx{
    int s, e, l;
    bool operator<(const xx& a) const { return s * a.l < a.s * l; }
};

int main() {
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        int n;
        cin>>n;
        vector<xx> ve(n+1);
        int m = 0;
        for (int i = 1; i <= n;i++){
            cin >> ve[i].s >> ve[i].e >> ve[i].l;
            m += ve[i].s;
        }
        sort(ve.begin() + 1, ve.end());
        int tt = 0;
        vector<int> dp(1e5 + 5,-0x3f3f3f3f);
        dp[0] = 0;
        int maxn = 0;
        for (int i = 1; i <= n;i++){
            for (int j = m; j >= ve[i].s;j--){
                dp[j] = max(dp[j], dp[j - ve[i].s] + ve[i].e - (j - ve[i].s) * ve[i].l);
            }
        }
        for (int i = 1; i <= m;i++){
            maxn = max(dp[i], maxn);
        }
        cout <<"Case #"<< cnt++ << ": ";
        cout << maxn << endl;
    }
}