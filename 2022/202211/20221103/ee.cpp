#include <bits/stdc++.h>
using namespace std;
int main() {
    int n, mod;
    cin >> n >> mod;
    int t;
    cin >> t;
    vector<int> ve(n + 1),vis(n+1,0);
    int tmp = 0;
    for (int i = 1; i <= t; i++) {
        int x, y;
        cin >> x >> y;
        ve[x] = y;
        vis[x] = 1;
        tmp += y;
    }
    int flag = 0;
    if (ve[1] == 0 && n > 1) {
        ve[1] = 1;
        tmp++;
        flag = 1;
    }
    int ii = n;
    while (tmp % 9 != mod && ii >= 1) {
        if ((ve[ii] == 0 || (ii == 1 && flag == 1))&&vis[ii]!=1) {
            while (ve[ii] < 9 && tmp % 9 != mod) {
                tmp++;
                ve[ii]++;
                // for (int i = 1; i <= n; i++) {
                //     cout << ve[i];
                // }
                // cout << endl;
            }
        }
        // cout << "gg" << endl;
        ii--;
    }
    for (int i = 1; i <= n; i++) {
        cout << ve[i];
    }
}