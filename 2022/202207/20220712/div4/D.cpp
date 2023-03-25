#include <cstring>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
string a[100005];
int ans[100005];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        memset(ans, 0, sizeof ans);
        cin >> tmp;
        map<string, int> mp;
        for (int i = 1; i <= tmp; i++) {
            cin >> a[i];
            mp[a[i]] = i;
        }
        int flag1 = 0, flag2 = 0;
        for (int i = 1; i <= tmp; i++)
            for (int j = 1; j <= tmp; j++) {
                ans[mp[str(a[i], 0, j)]] = 1;
                ans[mp[]] = 1;
            }
        for (int i = 1; i <= tmp; i++) {
            cout << ans[i];
        }
        mp.clear();
        cout << '\n';
    }
}