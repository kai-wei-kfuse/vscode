#include <algorithm>
#include <iostream>
#include <map>
using namespace std;
int main() {
    int t;
    cin >> t;
    int ca = 1;
    while (t--) {
        int n;
        cin >> n;
        map<int, int> mp;
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            mp[tmp]++;
        }
        int ans = 0;
        int min = mp.begin()->first;
        int la = min + 1;
        ans += la;
        // cout << ans << '|' << endl;
        pair<int, int> last;
        while (mp.begin()->second <= la) {
            //la -= mp.begin()->second;
            //mp[mp.begin()->first + 1] += mp.begin()->second;
            last.first = mp.begin()->first;  //上一个
            last.second = mp.begin()->second;
            mp.erase(mp.begin());
            la/(mp.begin()->first - last.first)*last.second;
            la++;
            ans++;
        }
        cout << "Case #" << ca << ": " << ans << '\n';
        ca++;
    }
}