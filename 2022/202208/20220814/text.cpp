#include <cstdio>
#include <cstring>
#include <set>

using namespace std;

const int N = 2010, M = 6010;

int n, m, k;
int h[N], e[M], ne[M], idx;
int f[N];

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int sg(int u) {
    if (f[u] != -1)
        return f[u];

    set<int> S;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        S.insert(sg(j));
    }

    for (int i = 0;; i++)
        if (S.count(i) == 0) {
            f[u] = i;
            break;
        }

    return f[u];
}

int main() {
    scanf("%d%d%d", &n, &m, &k);
    memset(h, -1, sizeof h);

    for (int i = 0; i < m; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    memset(f, -1, sizeof f);

    int res = 0;
    for (int i = 0; i < k; i++) {
        int u;
        scanf("%d", &u);
        res ^= sg(u);
    }

    if (res)
        puts("win");
    else
        puts("lose");

    return 0;
}
