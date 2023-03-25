#include <iostream>
#include <map>
#include <vector>
using namespace std;
int main() {
    int x, y, n;
    cin >> x >> y >> n;
    map<int, int> mp;
    vector<pair<int, int> > ve(n + 1);
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        mp[a] = i;
        mp[b] = i;
    }
    int cntx = 1, cnty = 1;
    for (auto i : mp) {
        ve[i.second] = {cntx, 0};
    }
}