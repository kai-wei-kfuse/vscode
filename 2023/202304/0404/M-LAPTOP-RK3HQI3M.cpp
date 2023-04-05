#include <bits/stdc++.h>
using namespace std;

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a(m + 1), d(m + 1);
    for (int i = 1; i <= m; i++) {
        cin >> a[i];
        d[i] = a[i];
    }
    reverse(d.begin() + 1, d.end());
    vector<vector<char> > b(n + 1, vector<char>(m * 2 + 2));
    vector<vector<char> > c(n + 1, vector<char>(m * 2 + 2));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> b[i][j];
            c[i][j] = b[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m + 1; j <= m * 2; j++) {
            b[i][j] = b[i][j - m];
            c[i][j] = c[i][j - m];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            // cout << b[i][j];
            int flag = 1;
            for (int k = 1; k <= m; k++) {
                if (a[k] == '1' && b[i][j + k - 1] == '1') {
                    flag = 0;
                    break;
                }
            }
            // cout << flag << endl;
            if (flag) {
                for (int k = 1; k <= m; k++) {
                    if (a[k] == '1') {
                        c[i][j + k - 1] = '2';
                        break;
                    }
                }
            }
            int flag1 = 1;
            for (int k = 1; k <= m; k++) {
                if (d[k] == '1' && b[i][j + k - 1] == '1') {
                    flag1 = 0;
                    break;
                }
            }
            if (flag1) {
                for (int k = 1; k <= m; k++) {
                    if (d[k] == '1') {
                        c[i][j + k - 1] = '2';
                        break;
                    }
                }
            }
        }
        // cout << endl;
    }
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= 2 * m; j++) {
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    queue<pair<int, int> > q;
    vector<vector<int> > vis(n + 1, vector<int>(m * 2 + 2, 0));
    for (int i = 1; i <= 2 * m; i++) {
        if (c[1][i] == '2') {
            q.push(make_pair(1, i));
            vis[1][i] = 1;
        }
    }
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int xx = p.first, yy = p.second;
        if (xx == n) {
            cout << "Y" << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int xxx = xx + x[i], yyy = yy + y[i];
            if (xxx >= 1 && xxx <= n && yyy >= 1 && yyy <= 2 * m && c[xxx][yyy] == '2' && !vis[xxx][yyy]) {
                q.push(make_pair(xxx, yyy));
                vis[xxx][yyy] = 1;
            }
        }
    }
    cout << "N" << endl;
    // for (int i = 1; i <= n; i++) {
    //     for (int j = 1; j <= 2 * m; j++) {
    //         cout << b[i][j];
    //     }
    //     cout << endl;
    // }
    
}