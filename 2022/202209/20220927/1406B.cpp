#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<ll> a(n+1);
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin>>a[i];
        }
        ll ans = -0x3f3f3f3f3f3f3f3f, res = 1;
        sort(a.begin() + 1, a.end());
        int front_ = 5, back_ = 0;
        while(front_>=0){
            res = 1;
            for (int i = 1; i <= front_;i++){
                res *= a[i];
            }
            for (int i = n; i > n - back_;i--){
                res *= a[i];
            }
            front_--;
            back_++;
            ans = max(ans, res);
        }
        cout << ans << endl;
    }
}