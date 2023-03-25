#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        // vector<int> ve(n + 1);
        map<int, int> mp;
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            mp[tmp]++;
        }
        if (mp.size() > 2 || mp.size() == n) {
            cout << n << endl;
        } else {
            cout << n / 2 - 1 + 2 << endl;
        }
    }
}