#include <bits/stdc++.h>
#include <iostream>
using namespace std;
map<int, pair<int, int>> mp;

int main() {
    int n;
    cin >> n;
    mp[1] = {10, 8};
    mp[6] = {60, 18};
    mp[28] = {280, 28};
    mp[88] = {880, 58};
    mp[198] = {1980, 128};
    mp[328] = {3280, 198};
    mp[648] = {6480, 388};
    int ans = 0;
    auto i = mp.begin();
   // i--;
    //cout << i->first << endl;
    for (; i != mp.end(); i++) {
        cout << n << ' ' << ans << endl;
       // cout << i->first<<endl;
        if (i->first <= n) {
            //cout << "gg" << endl;
            // cout<<i->second.first <<' '<< i->second.second<<endl;
            ans += i->second.first + i->second.second;
            n -= i->first;
        }
    }
   // cout << n << endl;
    // if (n >= 1) {
    //     ans += 8 + 10;
    //     n--;
    // }
    cout << ans + n * 10;
}