#include <bits/stdc++.h>
using namespace std;
#define int long long
vector<int> ve((1 << 20) + 5);
signed main() {
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < (1 << n); i++) {
        cin >> ve[i];
        if (ve[i] >= 48 && ve[i] <= 57) {
            mp[ve[i]]++;
        }
    }
    int len = n;
    for (int i = 1; i <= len; i++) {
        if (ve[i] >= 96 && ve[i] <= 114 && ve[i] & 1 == 0) {
            if (mp[ve[i] / 2] >= 2)
                mp[ve[i] / 2] -= 2;
            len++;
            i++;
        } else
            cout << char(ve[i]);
    }
}