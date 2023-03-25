#include <cstring>
#include <iostream>
#include <set>
using namespace std;

int f[105];

int sg(int x) {
    if (f[x] != -1)
        return f[x];
    set<int> se;
    for (int i = 0; i < x; i++) {
        for (int j = i; j < x; j++) {
            se.insert(sg(i) ^ sg(j));
        }
    }
    for (int i = 0;; i++) {
        if (!se.count(i)) {
            return f[x] = i;
        }
    }
}

int main() {
    int n;
    cin >> n;
    memset(f, -1, sizeof f);
    int x, res = 0;
    for (int i = 1; i <= n; i++) {
        cin >> x;
        res ^= sg(x);
    }
    if (res)
        puts("Yes");
    else
        puts("No");
}