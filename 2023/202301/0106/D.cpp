#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

int dis2(int x_1, int y_1, int x_2, int y_2) {
    return (x_1 - x_2) * (x_1 - x_2) + (y_1 - y_2) * (y_1 - y_2);
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int flag = 0;
        vector<pair<int, int> > a(10), b(2), c(2), en(2);
        cin >> a[0].x >> a[0].y;
        cin >> a[1].x >> a[1].y;
        if (a[0].x == a[1].x && a[0].y == a[1].y)
            flag = 1;
        cin >> a[2].x >> a[2].y;
        cin >> a[3].x >> a[3].y;
        if (a[2].x == a[3].x && a[2].y == a[3].y)
            flag = 1;
        cin >> a[4].x >> a[4].y;
        cin >> a[5].x >> a[5].y;
        if (a[4].x == a[5].x && a[4].y == a[5].y)
            flag = 1;
        // cin >> b[0].x >> b[0].y;
        // cin >> b[1].x >> b[1].y;

        // cin >> c[0].x >> c[0].y;
        // cin >> c[1].x >> c[1].y;
        cout << flag << endl;
        vector<int> vis(3, 0);
        int xl, xl2;
        for (int i = 0; i < 6; i++) {
            for (int j = i + 1; j < 6; j++) {
                if (a[i].x == a[j].x && a[i].y == a[j].y) {
                    // cout << a[i].x << ' ' << a[j].x << "|" << a[i].y << '
                    // '
                    //      << a[j].y << endl;
                    // cout << i << ' ' << j << endl;
                    b[0].x = a[i / 2 * 2].x;
                    b[0].y = a[i / 2 * 2].y;
                    b[1].x = a[i / 2 * 2 + 1].x;
                    b[1].y = a[i / 2 * 2 + 1].y;

                    c[0].x = a[j / 2 * 2].x;
                    c[0].y = a[j / 2 * 2].y;
                    c[1].x = a[j / 2 * 2 + 1].x;
                    c[1].y = a[j / 2 * 2 + 1].y;
                    int x_1, y_1, x_2, y_2;
                    if (b[0] == a[i]) {
                        if (c[0] == a[j]) {
                            x_1 = b[1].x - b[0].x;
                            y_1 = b[1].y - b[0].y;
                            x_2 = c[1].x - c[0].x;
                            y_2 = c[1].y - c[0].y;
                        } else if (c[1] == a[j]) {
                            x_1 = b[1].x - b[0].x;
                            y_1 = b[1].y - b[0].y;
                            x_2 = c[0].x - c[1].x;
                            y_2 = c[0].y - c[1].y;
                        }
                    } else if (b[1] == a[i]) {
                        if (c[0] == a[j]) {
                            x_1 = b[0].x - b[1].x;
                            y_1 = b[0].y - b[1].y;
                            x_2 = c[1].x - c[0].x;
                            y_2 = c[1].y - c[0].y;
                        } else if (c[1] == a[j]) {
                            x_1 = b[0].x - b[1].x;
                            y_1 = b[0].y - b[1].y;
                            x_2 = c[0].x - c[1].x;
                            y_2 = c[0].y - c[1].y;
                        }
                    }
                    xl = x_1 * x_2 + y_2 * y_1;  // 向量
                    if (xl < 0) {
                        flag = 1;
                    }
                    // cout << xl << endl;
                    vis[i / 2] = 1;
                    vis[j / 2] = 1;
                }
            }
        }
        cout << flag << endl;
        for (int i = 0; i < 3; i++) {
            if (vis[i] == 0) {
                en[0].x = a[i * 2].x;
                en[0].y = a[i * 2].y;
                en[1].x = a[i * 2 + 1].x;
                en[1].y = a[i * 2 + 1].y;
            }
        }
        for (int j = 0; j <= 1; j++) {
            for (int i = 0; i <= 1; i++) {
                if (en[j] == b[i]) {
                    flag = 1;
                }
                if (en[j] == c[i]) {
                    flag = 1;
                }
            }
        }
        cout << flag << endl;
        // b
        int f = -1, ff = -1;
        for (int i = 0; i <= 1; i++) {
            if (dis2(en[i].x, en[i].y, b[0].x, b[0].y) +
                    dis2(en[i].x, en[i].y, b[1].x, b[1].y) ==
                dis2(b[i].x, b[i].y, b[1].x, b[1].y)) {
                f = i;
            }
        }
        if (f == -1) {
            flag = 1;
        }
        // c
        if (f == 1) {
            if (dis2(en[0].x, en[0].y, c[0].x, c[0].y) +
                    dis2(en[0].x, en[0].y, c[1].x, c[1].y) ==
                dis2(c[0].x, c[0].y, c[1].x, c[1].y)) {
                ff = 0;
            }
        } else {
            if (dis2(en[1].x, en[1].y, c[0].x, c[0].y) +
                    dis2(en[1].x, en[1].y, c[1].x, c[1].y) ==
                dis2(c[0].x, c[0].y, c[1].x, c[1].y)) {
                ff = 1;
            }
        }
        if (ff == -1) {
            flag = 1;
        }
        cout << flag << endl;
        int lo = max(dis2(c[0].x, c[0].y, c[1].x, c[1].y),
                     dis2(b[0].x, b[0].y, b[1].x, b[1].y));
        if (dis2(en[0].x, en[0].x, en[1].y, en[1].y) * 16 < lo) {
            flag = 1;
        }
        cout << flag << endl;
        if (flag) {
            cout << "NO" << endl;
        } else {
            cout << "YES" << endl;
        }
        // cout << b[0].x << ' ' << b[0].y << endl;
        // cout << b[1].x << ' ' << b[1].y << endl;
        // cout << c[0].x << ' ' << c[0].y << endl;
        // cout << c[1].x << ' ' << c[1].y << endl;
        // cout << en[0].x << ' ' << en[0].y << endl;
        // cout << en[1].x << ' ' << en[1].y << endl;
    }
}