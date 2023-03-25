#include <cstring>
#include <iostream>
using namespace std;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
int mp[27];
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int tmp, num;
        string a;
        memset(mp, 0, sizeof(mp));
        cin >> tmp;
        cin >> a;
        cin >> num;
        char x;
        for (int i = 1; i <= num; i++) {
            cin >> x;
            mp[x - 'a' + 1] = 1;
        }
        int len = a.length();
        int tot = 0, ltot = 0;
        int ans = 0;
        for (int i = 0; i < len; i++) {
            if (mp[a[i] - 'a' + 1] == 0) {
                tot++;
            } else {
                ans = max(ans, tot);
                // ltot = tot;
                tot = 1;
                // cout << ans << endl;
            }
        }
        cout << ans << '\n';
    }
}