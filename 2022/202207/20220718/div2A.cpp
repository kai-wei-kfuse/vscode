#include <cstring>
#include <iostream>
using namespace std;
int a[60];
int main() {
    int n, t, m;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        int tmp;
        memset(a, 0, sizeof a);
        for (int i = 1; i <= n; i++) {
            cin >> tmp;
            if (tmp <= m / 2) {
                if (a[tmp] == 0) {
                    a[tmp] = 1;
                } else if (a[tmp]) {
                    a[m - tmp + 1] = 1;
                }
            } else {
                if (a[m - tmp + 1] == 0) {
                    a[m - tmp + 1] = 1;
                } else if (a[m - tmp + 1]) {
                    a[tmp] = 1;
                }
            }
        }
        for (int i = 1; i <= m; i++) {
            if (a[i] == 1) {
                cout << "A";
            } else {
                cout << "B";
            }
        }
        cout << '\n';
    }
}