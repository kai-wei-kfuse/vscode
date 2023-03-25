#include <iostream>  //B
#include <map>
using namespace std;

int a[100005];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        map<int, pair<int, int> > mp;
        int tmp;
        for (int i = 1; i <= n; i++) {
            cin >> a[i];
            if (mp[i].second == 0) {
                mp[i].second == 0;
            }
            if (mp[a[i]].first == 0 ||
                (mp[a[i]].first > 0 && (i - mp[a[i]].second - 1) % 2 == 0)) {
                mp[a[i]].first++;
                mp[a[i]].second = i;
            }
        }
        for (auto i : mp) {
            cout << i.second.first << ' ';
        }
        cout << '\n';
    }
}