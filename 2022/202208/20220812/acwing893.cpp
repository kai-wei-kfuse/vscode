#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int f[100005], a[105];
int n, m, x;

int sg(int x) {
    if (f[x] != -1)
        return f[x];
    set<int> se;
    for (int i = 1; i <= m; i++) {
        if (x - a[i] >= 0)
            se.insert(sg(x - a[i]));
    }
    for (int i = 0;; i++) {
        if (!se.count(i))
            return f[x] = i;
    }
}

int main() {
    cin >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    cin >> n;
    int res = 0;
    memset(f, -1, sizeof f);
    for (int i = 1; i <= n; i++) {
        cin >> x;
        res ^= sg(x);
    }
    if (res)
        puts("Yes");
    else
        puts("No");
}