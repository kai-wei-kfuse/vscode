#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    int x0, y0;
    int ax, ay, bx, by;
    int xs, ys, t;
    cin >> x0 >> y0 >> ax >> ay >> bx >> by >> xs >> ys >> t;
    vector<pair<int, int>> v;
    v.push_back({x0, y0});
    while (v.back().first <= 1e16 && v.back().second <= 1e16) {
        v.push_back({v.back().first * ax + bx, v.back().second * ay + by});
    }
    int ans = 0;
    for (int i = 0; i < v.size(); i++) {
        for (int j = i; j < v.size(); j++) {
            int dis =
                abs(v[i].first - v[j].first) + abs(v[i].second - v[j].second);
            int dis1 = abs(v[i].first - xs) + abs(v[i].second - ys);
            int dis2 = abs(v[j].first - xs) + abs(v[j].second - ys);
            if (dis1 + dis <= t || dis2 + dis <= t) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
}