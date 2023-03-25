#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> parent(1e5 + 7), sz(1e5 + 7);

int find(int x) {
    while (parent[x] != x) {
        x = parent[x] = parent[parent[x]];
    }
    return x;
}

int main() {
    int n;
    cin >> n;
    vector<tuple<int, int, int>> edge(n - 1);
    for (auto& [val, x, y] : edge) {
        cin >> x >> y >> val;
        x--;
        y--;
    }
    sort(edge.begin(), edge.end());
    ll ans = 0;
    for (int i = 0; i < n; i++)
        parent[i] = i, sz[i] = 1;
    for (auto& [val, x, y] : edge) {
        int x_rot = find(x);
        int y_rot = find(y);
        ans += (ll)val * sz[x_rot] * sz[y_rot];
        parent[x_rot] = y_rot;
        sz[y_rot] += sz[x_rot];
    }
    cout << ans << '\n';
}