#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
priority_queue<ll, vector<ll>, greater<ll> > Q;
int main() {
    int t;
    cin >> t;
    ll res = 0;
    while (t--) {
        int tmp, x;
        cin >> tmp;
        
        if (tmp == 1) {
            cin >> x;
            Q.push(x - res);
        }
        if (tmp == 2) {
            cin >> x;
            res += x;
        }
        if (tmp == 3) {
            ll ans = Q.top() + res;
            cout << ans<< '\n';
            Q.pop();
        }
    }
}