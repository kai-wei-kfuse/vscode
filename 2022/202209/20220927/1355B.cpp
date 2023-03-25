#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        sort(a.begin() + 1, a.end());
        int ans = 0, cur = 0;
        for (int i = 1; i <= n;i++) {
           if(++cur==a[i]){
               ans++;
               cur = 0;
           }
        }
        cout << ans << endl;
    }
}