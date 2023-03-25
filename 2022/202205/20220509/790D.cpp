#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
int a[205][205], b[205][205];
long long sum1[300], sum2[300];
int xx[] = {1, 1, -1, -1};
int yy[] = {1, -1, 1, -1};
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= x; i++) {
            for (int j = 1; j <= y; j++) {
                int sum = a[i][j];
                for (int k = 0; k < 4; k++) {
                    int u = i, v = j;
                    while (1) {
                        u += xx[k];
                        v += yy[k];
                        if (u < 1 || v < 1 || u > x || v > y)
                            break;
                        sum += a[u][v];
                    }
                }
                // cout << sum << endl;
                ans = max(ans, sum);
                b[i][j] = sum;
            }
        }
        // int tot1 = 0;
        // for (int i = 1; i <= y; i++) {
        //     int sum = 0;
        //     for (int k = i, l = 1; k <= x, l <= y; k++, l++) {
        //         sum += a[l][k];
        //     }
        //     sum1[++tot1] = sum;
        // }
        // for (int i = 2; i <= x; i++) {
        //     int sum = 0;
        //     for (int k = i, l = 1; k <= x, l <= y; k++, l++) {
        //         sum += a[k][l];
        //     }
        //     sum1[++tot1] = sum;
        // }
        // sort(sum1 + 1, sum1 + tot1 + 1, greater<int>());
        // for (int i = 1; i <= tot1; i++) {
        //     cout << sum1[i] << ' ';
        // }
        // cout << endl;
        // int tot2 = 0;
        // for (int i = y; i >= 1; i--) {
        //     int sum = 0;
        //     for (int xx = 1, yy = i; xx <= x, yy >= 1; xx++, yy--) {
        //         sum += a[xx][yy];
        //     }
        //     sum2[++tot2] += sum;
        // }
        // for (int i = 2; i <= x; i++) {
        //     int sum = 0;
        //     for (int xx = i, yy = y; yy >= 1, xx <= x; xx++, yy--) {
        //         sum += a[xx][yy];
        //     }
        //     sum2[++tot2] += sum;
        // }
        // sort(sum2 + 1, sum2 + tot2 + 1, greater<int>());
        // for (int i = 1; i <= tot2; i++) {
        //     cout << sum2[i] << ' ';
        // }
        // cout << endl;

        cout << ans << '\n';
    }
}