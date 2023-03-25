#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > mp(10);
vector<int> vis(10);
int ans = 0;
void dfs(int n, int x, int y) {
    //cout << ans << '|' << endl;
    ans = max(ans, y);
    if (x > 7 || n == 0) {
        return;
    }
    for (int i = x; i <= 7; i++) {
        //cout << n << ' ' << mp[i].first << endl;
        if (mp[i].first <= n && vis[i] == 0) {
            vis[i] = 1;
            dfs(n - mp[i].first, i + 1, y + mp[i].second);
            //cout << n << ' ' << n - mp[i].first << endl;
            vis[i] = 0;
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
    cin >> n;
    dfs(n, 1, 0);
    cout << ans + n * 10;
}