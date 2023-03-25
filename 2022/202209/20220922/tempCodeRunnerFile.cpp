#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > mp;
vector<int> vis;
int ans = 0;
void dfs(int n, int x, int y) {
    if (vis.size() == 7 || x > 7) {
        ans = max(ans, y);
        return;
    }
    for (int i = x; i <= 7; i++) {
        if (mp[i].first <= n && vis.size()<7) {
            vis.push_back(i);
            dfs(n - mp[i].first, i + 1, y + mp[i].second);
            vis.pop_back();
            dfs(n, i + 1, y);
        }
    }
    return;
}
int main() {
    mp[1] = {1, 8};
    mp[2] = {6, 18};
    mp[3] = {28, 28};
    mp[4] = {88, 58};
    mp[5] = {198, 128};
    mp[6] = {328, 198};
    mp[7] = {648, 388};
    int n;  //=100;
    cout << '1';
    cin >> n;
    cout << '2';
    dfs(n, 1, 0);
    cout << ans + n * 10;
}