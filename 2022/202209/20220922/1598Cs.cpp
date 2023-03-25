#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
#define int long long
signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> ve(n + 1);
        double sum = 0;
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            mp[ve[i]]++;
            sum += ve[i];
        }
        if ((2 * (int)sum) % n != 0) {
            puts("0");
            continue;
        }
        sum = sum / n;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            int x = ve[i];
            int tmp = sum*2 - x;
            if (mp.count(tmp))
                ans += mp[tmp];
            if (x == tmp)
                ans--;
        }
        cout << ans / 2 << endl;
    }
}