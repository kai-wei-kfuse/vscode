#include <iostream>
#include <queue>
typedef long long ll;
using namespace std;
struct xx {
    int x, y, r;
} a[50004], b[50004];
int visa[50004];
queue<xx> Q;
int dist(int xa, int xb, int ya, int yb) {
    return abs(xa - xb) + abs(ya - yb);
}
int main() {
    int n, m;
    ll sum = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y >> a[i].r;
    }
    for (int i = 1; i <= m; i++) {
        cin >> b[i].x >> b[i].y >> b[i].r;
        for (int j = 1; j <= n; j++) {
            if (dist(a[j].x, b[i].x, a[j].y, b[i].y) <= b[i].r &&
                visa[j] == 0) {
                Q.push(a[j]);
                sum++;
                visa[j] = 1;
            }
        }
        Q.push(b[i]);
    }
    while (!Q.empty()) {
        xx tmp = Q.front();
        Q.pop();
        for (int i = 1; i <= n; i++) {
            if (dist(a[i].x, tmp.x, a[i].y, tmp.y) <= tmp.r && visa[i] == 0) {
                Q.push(a[i]);
                sum++;
                visa[i] = 1;
            }
        }
    }
    cout << sum;
    return 0;
}