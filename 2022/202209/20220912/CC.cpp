#include <iostream>
#include <map>
#include <vector>
using namespace std;

vector<pair<int,int> > mp(26);

int main() {
    int t;
    cin >> t;
    while (t--) {
        mp.clear();
        string s;
        cin >> s;
        int len = s.length();
        vector<int> a;
        for (int i = 0; i < len; i++) {
            mp[s[i] - 'a'].first = 1;
            mp[s[i] - 'a'].second = i;
        }
        a.push_back(1);
        int ans = 0;
        cout << abs(s[0] - (s[len - 1])) << ' ';
        int ss = min(s[0] - 'a', s[len - 1] - 'a');
        int tt = max(s[0] - 'a', s[len - 1] - 'a');
        for (int i = ss; i <= tt; i++) {
            //cout << i << ' ';
            if (mp[i].first==1) {
                                // cout << i << ' ';
                a.push_back(mp[i].second+1);
                ans++;
            }
        }
        cout << ans << endl;
        for (auto i : a) {
            cout << i << ' ';
        }
        cout << endl;
    }
}