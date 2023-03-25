#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

vector<int> edge[6005];
int f[2010], e[6010], h[2010], ne[6010], idx;
int n, m, k;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int sg(int x) {
    if (f[x] != -1)
        return f[x];
    set<int> se;
    for (int i = h[x]; ~i; i = ne[i]) {
        int j = e[i];
        se.insert(sg(j));
    }
    for (int i = 0;; i++) {
        if (se.count(i) == 0) {
            f[x] = i;
            return f[x];
        }
    }
}

int main() {
    memset(f, -1, sizeof f);
    memset(h, -1, sizeof h);
    cin >> n >> m >> k;
    int x, y;
    for (int i = 1; i <= m; i++) {
        cin >> x >> y;
        add(x, y);
    }

    int res = 0, tmp;
    for (int i = 1; i <= k; i++) {
        cin >> tmp;
        res ^= sg(tmp);
    }
    if (res)
        cout << "win" << '\n';
    else
        cout << "lose" << '\n';
}