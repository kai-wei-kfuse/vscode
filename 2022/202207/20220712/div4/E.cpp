#include <iostream>
using namespace std;
char a[105][105];
int main() {
    int n;
    cin >> n;
    while (n--) {
        int tmp;
        cin >> tmp;
        for (int i = 1; i <= tmp; i++) {
            for (int j = 1; j <= tmp; j++) {
                cin >> a[i][j];
            }
        }
        int ans = 0;
        for (int i = 1; i <= tmp / 2; i++) {
            for (int j = 1; j <= tmp / 2 + tmp % 2; j++) {
                int tmp2 = a[i][j] - '0' + a[j][tmp - i + 1] - '0' +
                           a[tmp - i + 1][tmp - j + 1] - '0' +
                           a[tmp - j + 1][i] - '0';
                // cout << i << ' ' << j << '|' << j << ' ' << tmp - i + 1 <<
                // '|'
                //      << tmp - i + 1 << ' ' << tmp - j + 1 << "|" << tmp - i +
                //      1
                //      << ' ' << j << endl;
                // cout << tmp2 << endl;
                if (tmp2 >= 2) {
                    ans += 4 - tmp2;
                } else {
                    ans += tmp2;
                }
            }
        }
        cout << ans << '\n';
    }
}