#include <bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        map<int, int> mp;
        vector<int> ve(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> ve[i];
            mp[ve[i]] = 1;
        }
        if (mp.size() == 1 && mp[k] == 1) {
            cout << "Bob" << endl;
            continue;
        }
        if (mp.size() == 2 && mp[k] == 1) {
            cout << "Bob" << endl;
            continue;
        }
        int fl = 0;
        for (int i = 1; i <= n; i++) {
            if (mp[k ^ ve[i]] == 1) {
                fl = 1;
                break;
            }
        }
        if(mp[k]==1){
        }
        // cout << endl;
        // for (auto [f, s] : mp) {
        //     if(s>0)
        //     cout << f << "|";
        // }
        // cout << endl;
        if (fl) {
            cout << "Alice" << endl;
        } else {
            cout << "Draw" << endl;
        }
    }
}