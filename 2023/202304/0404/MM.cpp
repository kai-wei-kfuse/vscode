#include <bits/stdc++.h>
using namespace std;

int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};

int main() {
    int n, m;
    cin >> n >> m;
    vector<char> a(m), d(m);
    int f = 0;
    for (int i = 0; i < m; i++) {
        cin >> a[i];
        if (a[i] != '0') {
            f = 1;
        }
        d[i] = a[i];
    }
    if(!f){
        cout << "Y" << endl;
        return 0;
    }
    reverse(d.begin(), d.end());
    vector<vector<char> > b(n, vector<char>(m));
    vector<vector<char> > c(n, vector<char>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> b[i][j];
            c[i][j] = b[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // cout << b[i][j];
            int flag = 1;
            for (int k = 0; k < m; k++) {
                if (a[k] == '1' && b[i][(j + k) % m] == '1') {
                    flag = 0;
                    break;
                }
            }
            // cout << flag << endl;
            if (flag) {
                for (int k = 0; k < m; k++) {
                    if (a[k] == '1') {
                        c[i][(j + k) % m] = '2';
                        break;
                    }
                }
            }
        }
        // cout << endl;
    }
    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    queue<pair<int, int> > q, q1;
    vector<vector<int> > vis(n + 1, vector<int>(m + 2, 0)),
        vis1(n + 1, vector<int>(m + 2, 0));
    for (int i = 0; i < m; i++) {
        if (c[0][i] == '2') {
            q.push(make_pair(0, i));
            vis[0][i] = 1;
        }
    }
    while (!q.empty()) {
        pair<int, int> p = q.front();
        q.pop();
        int xx = p.first, yy = p.second;
        if (xx == n - 1) {
            cout << "Y" << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int xxx = xx + x[i], yyy = (yy + y[i] + m) % m;
            if (xxx >= 0 && xxx < n && yyy >= 0 && yyy < m &&
                c[xxx][yyy] == '2' && !vis[xxx][yyy]) {
                q.push(make_pair(xxx, yyy));
                vis[xxx][yyy] = 1;
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int flag1 = 1;
            for (int k = 0; k < m; k++) {
                if (d[k] == '1' && b[i][(j + k) % m] == '1') {
                    flag1 = 0;
                    break;
                }
            }
            if (flag1) {
                for (int k = 0; k < m; k++) {
                    if (d[k] == '1') {
                        c[i][(j + k) % m] = '3';
                        break;
                    }
                }
            }
        }
    }

    // for (int i = 0; i < n; i++) {
    //     for (int j = 0; j < m; j++) {
    //         cout << c[i][j];
    //     }
    //     cout << endl;
    // }
    for (int i = 0; i < m; i++) {
        if (c[0][i] == '3') {
            q1.push(make_pair(0, i));
            vis1[0][i] = 1;
        }
    }
    while (!q1.empty()) {
        pair<int, int> p = q1.front();
        q1.pop();
        int xx = p.first, yy = p.second;
        if (xx == n - 1) {
            cout << "Y" << endl;
            return 0;
        }
        for (int i = 0; i < 4; i++) {
            int xxx = xx + x[i], yyy = (yy + y[i] + m) % m;
            if (xxx >= 0 && xxx < n && yyy >= 0 && yyy < m &&
                c[xxx][yyy] == '3' && !vis1[xxx][yyy]) {
                q1.push(make_pair(xxx, yyy));
                vis1[xxx][yyy] = 1;
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