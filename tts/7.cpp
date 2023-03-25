#include <iostream>
typedef long long ll;
using namespace std;
int vis[2][100005];
ll numl, numh;  //列的数量
ll sum;
int main() {
    ll x, y;
    cin >> x >> y;
    int t;
    cin >> t;
    int c, n;
    while (t--) {
        cin >> c >> n;
        if (vis[c][n] == 0) {
            vis[c][n] = 1;
            sum += (c == 0) ? y : x;
            if (c)
                numl++;
            else
                numh++;
        }
    }
    cout << x * y - (sum - numl * numh);
}