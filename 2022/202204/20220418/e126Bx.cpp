#include <iostream>
#include <queue>
using namespace std;
const int mod = 32768;
int tmp;
int vis[32769];
struct xx {
    int x, t;
} Q[1000000];

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
        Q[0] = {tmp, 0};
        int l = 0, r = 1;
        while (l != r) {
            xx x = Q[l];
            l++;
            // if (vis[x.x]) {
            //     printf("%d ", vis[tmp] + x.t);
            //     break;
            // }
            if (x.x == 0) {
                // cout << tmp << endl;
                vis[tmp] = x.t;
                printf("%d ", x.t);
                break;
            }
            if (x.t < 15) {
                Q[r++] = {(x.x + 1) % mod, x.t + 1};
                Q[r++] = {x.x * 2 % mod, x.t + 1};
            }
        }
    }
}