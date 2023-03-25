#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
vector<int> a(N), b(N);
vector<int> next_(N, 0);

#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for (int i = 1; i <= m; i++) {
            cin >> b[i];
        }
        for (int i = 2, j = 0; i <= m; i++) {
            while (j && b[i] != b[j + 1])
                j = next_[j];
            if (b[i] == b[j + 1])
                j++;
            next_[i] = j;
        }
        int fl = 0;
        for (int i = 1, j = 0; i <= n; i++) {
            while (j && a[i] != b[j + 1])
                j = next_[j];
            if (a[i] == b[j + 1])
                j++;
            if (j == m) {
                cout << i - m + 1 << '\n';
                fl = 1;
                break;
            }
        }
        if (!fl)
            cout << "-1" << '\n';
    }
}