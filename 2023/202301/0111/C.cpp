#include <bits/stdc++.h>
using namespace std;

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
const int N = 1005;
int next_[N];

int main() {
    IOS;
    while (1) {
        string a, b;
        cin >> a;
        if (a == "#")
            break;
        cin >> b;
        int n, m;
        n = a.size();
        m = b.size();
        a = "?" + a;
        b = "?" + b;
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && b[i] != b[j + 1])
                j = next_[j];
            if (b[i] == b[j + 1])
                j++;
            next_[i] = j;
        }
        int ans = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            while (j && a[i] != b[j + 1])
                j = next_[j];
            if (a[i] == b[j + 1])
                j++;
            if (j == m) {
                ans++;
                j = 0;
            }
        }
        cout << ans << endl;
    }
}