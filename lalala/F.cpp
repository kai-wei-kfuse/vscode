#include <iostream>
typedef long long ll;
using namespace std;
ll a[502][502];
ll b[502][502];
int n, m, k;
ll sum = 0;
void dfs(int u, int v, int x, int y) {
    int flag = 0;
    for (int i = u; i <= x; i++) {
        for (int j = v; j <= y; j++) {
            if (a[i][j] > k) {
                break;  //剪枝2号
                y = j;
            }
            if (b[i][j] - b[i][v - 1] - b[u - 1][j] + b[u - 1][v - 1] <= k) {
                sum++;
                // cout << u << ' ' << v << '|' << i << ' ' << j << endl;
            } else {
                flag = 1;
                break;  //剪枝3号
            }
        }
        if (flag)
            break;
    }
}
int main() {
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            b[i][j] =
                b[i - 1][j] + b[i][j - 1] - b[i - 1][j - 1] + a[i][j];  //前缀和
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (a[i][j] <= k)  //一号剪枝
                dfs(i, j, n, m);
        }
    }
    cout << sum;
    return 0;
}