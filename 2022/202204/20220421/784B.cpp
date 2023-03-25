#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
using namespace std;
// map<int, int> mp;
struct xx {
    int x, y;
} mp[200010];
bool cmp(xx a, xx b) {
    return a.x > b.x;
}
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    int t;
    while (n--) {
        cin >> t;
        memset(mp, 0, sizeof(mp));
        int tmp;
        int maxn = 0;
        for (int i = 1; i <= t; i++) {
            cin >> tmp;
            mp[tmp].x++;
            mp[tmp].y = tmp;
            maxn = max(maxn, tmp);
        }
        sort(mp, mp + maxn + 1, cmp);
        // for (map<int, int>::iterator i = mp.begin(); i != mp.end(); i++) {
        //     if ((*i).second < 3) {
        //         cout << "-1" << '\n';
        //         break;
        //     }
        // }
        // map<int, int>::iterator i = mp.begin();
        // cout << (*i).first << ' ' << (*i).second << endl;
        // if ((*i).second < 3)
        //     cout << "-1" << endl;
        // else
        //     cout << (*i).first << endl;
        // mp.clear();
        if (mp[0].x < 3)
            cout << "-1" << endl;
        else {
            cout << mp[0].y << endl;
        }
    }
}