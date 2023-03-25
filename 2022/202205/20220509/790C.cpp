#include <algorithm>
#include <cstring>
#include <iostream>
using namespace std;
string a;
int sums[100][100];
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        memset(sums, 0, sizeof(sums));
        for (int i = 1; i <= x; i++) {
            cin >> a;
            for (int j = 0; j < y; j++) {
                sums[i][j] = (a[j] - 'a');
                // cout << sums[i][j];
            }
            // cout << endl;
        }
        int ans = 0x3f3f3f;
        for (int i = 1; i < x; i++) {
            for (int j = i + 1; j <= x; j++) {
                int tt = 0;
                for (int k = 0; k < y; k++) {
                    tt += abs(sums[j][k] - sums[i][k]);
                }
                ans = min(ans, tt);
            }
        }
        cout << ans << '\n';
    }
}