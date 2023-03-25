#include <cstdlib>
#include <iostream>
using namespace std;
struct xx {
    int x, k;
} a[30];
int n;
int x, y;
void dfs(int p) {
    int now = 2 * n, y = n;
    for (int i = p % now; i <= 2 * n;) {
        if (i == 0)
            i = now;
        if (a[i].k == 1) {
            return;
        } else {
            if (--y == 0) {
                cout << p << '\n';
                exit(0);
            }
        }
        i = (--i + p) % (--now);
    }
}
int main() {
    cin >> n;
    x = y = n;
    for (int i = 1; i <= n; i++) {
        a[i].k = 1;
    }
    for (int i = x + 1; i < 10000000; i++) {
        // cout << i << ":" << endl;
        dfs(i);
    }
}