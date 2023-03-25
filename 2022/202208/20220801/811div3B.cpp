#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int n, t;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<int> ve(n + 1);
        map<int, int> mp;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
        }
        int ans = 0;
        for (int i = n; i >= 1; i--) {
            if (mp[ve[i]] == 0)
                mp[ve[i]] = 1;
            else {
                ans = i;
                break;
            }
        }
        cout << ans << '\n';
    }
}