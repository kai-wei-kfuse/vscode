#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
ll dp[200005];
int main() {
    int n;
    cin >> n;
    while (n--) {
        ll tmp, tmp2;
        cin >> tmp;
        vector<ll> ve;
        for (int i = 1; i <= tmp; i++) {
            cin >> tmp2;
            if (tmp2 < i) {
                ve.push_back(tmp2);
            }
        }
        ll ans = 0;
        int len = ve.size();
        cout << len << endl;
        for (int i = 0; i < len - 1; i++) {
            cout << ve[i] << ' ';
            for (int j = i + 1; j < len; j++) {
                if (ve[i] < ve[j])
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}