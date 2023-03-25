#include <bits/stdc++.h>
using namespace std;
int main() {
    for (int n = 2; n <= 10; n++) {
        for (int m = 2; m <= 10; m++) {
            /*             if(n!=m)
                            continue; */
            /*     int n, m;
                cin >> n >> m; */
            int cnt = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    /*             cout << i << " " << j << endl; */
                    for (int k = 1; k <= n; k++) {
                        for (int l = 1; l <= m; l++) {
                            /*                     cout << "gg"; */
                            int x = 2 * k - i;
                            int y = 2 * l - j;
                            /*                     cout << x << " " << y <<
                               endl; cout << n << " " << m << endl; cout <<
                               (x!=i) << endl; */
                            if (x == i && y == j)
                                continue;
                            if (x <= n && x >= 1 && y <= m && y >= 1) {
                                /*                         cout << "ggsd" <<
                                 * endl;
                                 */
                                cnt++;
                            }
                        }
                    }
                }
            }
            /*     cout << n << " " << m << endl; */
            cout << cnt / 2 << " ";
        }
        cout << endl;
    }
        /*     } */
    }