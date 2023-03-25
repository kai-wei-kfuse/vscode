#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    int t;
    IOS;
    cin >> t;
    vector<int> in_[1005];
    for (int i = 1000; i >= 1; i--) {
        for (int j = 1000; j >= 1; j--) {
            if (__gcd(i, j) == 1) {
                in_[i].push_back(j);
            }
        }
    }
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        vector<int> ve[1005];
        for (int i = 1; i <= n; i++) {
            int tmp;
            cin >> tmp;
            ve[tmp].push_back(i);
        }
        int ans = -1;
        for (int i = 1; i <= 1000;i++){
            for(auto j:in_[i]){
                if(!ve[i].empty()&&!ve[j].empty()){
                    ans = max(ans, ve[i].back() + ve[j].back());
                }
            }
        }

            cout << ans << endl;
    }
}