#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<vector<char>> a(n + 1, vector<char>(n + 1));
    vector<vector<char>> b(n + 1, vector<char>(n + 1));
    vector<vector<char>> c(n + 1, vector<char>(n + 1));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> b[i][j];
        }
    }
    int flag = 1, ans = 0;
    for (int i = 1; i <= n; i++) {  // 1
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != b[i][j]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {  // 2
        for (int j = 1; j <= n; j++) {
            //  cout << i << ' ' << j << ' '<< n - i + 1<<endl;
            if (a[i][j] != b[j][n - i + 1]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {  // 3
        for (int j = 1; j <= n; j++) {
            // cout << i << ' ' << j <<" "<<n - i + 1<< ' '<< n - j + 1<<endl;
            if (a[i][j] != b[n - i + 1][n - j + 1]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {  // 4
        for (int j = 1; j <= n; j++) {
           // cout << i << ' ' << j << " " << n - i + 1 << endl;
            if (a[i][j] != b[n - j + 1][i]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    //____________________________
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {  //
            //  cout << i << ' ' << j <<" "<<n - i + 1<<' '<<j<<endl;
            c[i][j] = b[n - i + 1][j];
            // cout << c[i][j];
            if (a[i][j] != b[n - i + 1][j]) {
                flag = 0;
            }
        }
        // cout << endl;
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {  //
        for (int j = 1; j <= n; j++) {
            // cout << i << ' ' << j <<" "<<n - i + 1<< ' '<< n - j + 1<<endl;
            if (a[i][j] != c[n - i + 1][n - j + 1]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {  //
        for (int j = 1; j <= n; j++) {
            // cout << i << ' ' << j <<" "<<n - i + 1<<endl;
            if (a[i][j] != c[j][n - i + 1]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    flag = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i][j] != c[n-j+1][i]) {
                flag = 0;
            }
        }
    }
    if (flag) ans = 1;
    if (ans) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}