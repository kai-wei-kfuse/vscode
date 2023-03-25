#include <iostream>
#include <map>
using namespace std;
map<char, int> mp;
int main() {
    int n;
    cin >> n;
    string a;
    int len;
    while (n--) {
        cin >> len;
        cin >> a;
        int ans = 0;
        // int len = a.length();
        for (int i = 0; i < len; i++) {
            if (mp[a[i]] == 0) {
                mp[a[i]]++;
                ans += 2;
            } else {
                ans++;
            }
        }
        cout << ans << '\n';
        mp.clear();
    }
}