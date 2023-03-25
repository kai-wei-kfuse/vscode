#include <bits/stdc++.h>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        string s;
        cin >> s;
        int ans = 0;
        int tmp;
        multiset<int> se;
        for (int i = 0;i<n;i++){
            cin >> tmp;
            if(s[i]=='0')
                se.clear();
            se.insert(-tmp);
            if(s[i]=='1'){
                ans -= *se.begin();
                se.erase(se.begin());
            }
        }

            cout << ans << endl;
    }
}