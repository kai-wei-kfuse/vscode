#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
struct xx {
    int x, y, vis;
};
vector<xx> a[100005];
int vis[100005];
bool cmp(xx a, xx b) {
    if (a.x == b.x)
        return a.y < b.y;
    return a.x > a.x;
}
int main() {
    int n, k, c;
    cin >> n >> k >> c;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        a[x].push_back({x, y, 0});
    }
    int sum = 0;
    sort(a, a + n, cmp);
    // for (int j = 1; j <= n; j++) {
    // }
}