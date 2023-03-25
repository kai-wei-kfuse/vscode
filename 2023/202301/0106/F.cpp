#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)

int main() {
    IOS;
    int n, ed, v;
    cin >> n >> ed >> v;
    if (ed < n - 1 || ed > ((n - 2 - 1) * (n - 2 - 1 + 1) / 2 + (n - 1))) {
        cout << "-1" << '\n';
    } else {
        for (int i = 1; i <= n; i++) {
            if (i != v) {
                cout << i << ' ' << v << '\n';
            }
        }  // 连v
        ed -= n - 1;
        int cnt = 0;
        int flag = 0;
        if (v == n) {
            for (int i = 1; i < n - 1; i++) {
                for (int j = i + 1; j < n - 1; j++) {
                    if (cnt < ed) {
                        cnt++;
                        cout << i << ' ' << j << '\n';
                    } else if (cnt == ed) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        } else {
            for (int i = 1; i < n; i++) {
                for (int j = i + 1; j < n; j++) {
                    if (i != v && j != v && cnt < ed) {
                        cnt++;
                        cout << i << ' ' << j << '\n';
                    } else if (cnt == ed) {
                        flag = 1;
                        break;
                    }
                }
                if (flag)
                    break;
            }
        }
    }
    return 0;
}