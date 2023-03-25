#include <algorithm>
#include <iostream>
typedef long long ll;
using namespace std;
int x[1000005], y[1000005];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> x[i] >> y[i];
    }
    sort(x + 1, x + m + 1);
    sort(y + 1, y + m + 1);
    ll xx = unique(x + 1, x + m + 1) - x - 1;
    ll yy = unique(y + 1, y + m + 1) - y - 1;
    cout << xx * n + yy * n - xx * yy;
}