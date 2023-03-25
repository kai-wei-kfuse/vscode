#include <iostream>
#include <queue>
using namespace std;
const int mod = 32768;
int tmp;
int vis[32769];
struct xx {
    int x, t;
};

int main() {
    int n;
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> tmp;
        if (vis[tmp]) {
            // cout << tmp << endl;
            printf("%d ", vis[tmp]);
            continue;
        }
        queue<xx> Q;
        Q.push({tmp, 0});
        while (!Q.empty()) {
            xx x = Q.front();
            Q.pop();
            // if (x.t > 15)
            //     continue;
            if (x.x == 0) {
                vis[tmp] = x.t;
                printf("%d ", x.t);
                break;
            }
            if (x.t < 15) {
                Q.push({(x.x + 1) % mod, x.t + 1});
                Q.push({x.x * 2 % mod, x.t + 1});
            }
        }
    }
}