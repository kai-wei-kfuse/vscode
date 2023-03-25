#include <algorithm>
#include <cstring>
#include <iostream>

using namespace std;

typedef long long LL;
const int N = 100010, M = N * 2;

int n;
int h[N], e[M], ne[M], idx;  // 邻接表
int color[N], cnt[N], sz[N], son[N];
LL ans[N], sum;
int mx, flag;

void add(int a, int b) {
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs_son(int u, int father) {
    sz[u] = 1;
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        // cout << j << ' ';
        if (j == father)
            continue;
        sz[u] += dfs_son(j, u);
        if (sz[j] > sz[son[u]])
            son[u] = j;
    }
    // cout << son[u] << endl;
    return sz[u];
}

void update(int u, int father, int sign) {
    int c = color[u];
    cnt[c] += sign;
    if (cnt[c] > mx)
        mx = cnt[c], sum = c;
    else if (cnt[c] == mx)
        sum += c;

    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father || j == flag)
            continue;
        update(j, u, sign);
    }
}

void dfs(int u, int father, int op) {
    for (int i = h[u]; ~i; i = ne[i]) {
        int j = e[i];
        if (j == father || j == son[u])
            continue;
        dfs(j, u, 0);
    }

    if (son[u]) {
        dfs(son[u], u, 1);
        flag = son[u];
    }
    update(u, father, 1);

    ans[u] = sum;
    flag = 0;
    if (!op)
        update(u, father, -1), sum = mx = 0;
    // for (int i = 1; i <= n; i++) {
    //     cout << cnt[i] << ' ';
    // }
    // cout << endl;
}

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &color[i]);
    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b), add(b, a);
    }

    dfs_son(1, -1);
    dfs(1, -1, 1);

    for (int i = 1; i <= n; i++)
        printf("%lld ", ans[i]);
    // for (int i = 1; i <= n;i++){
    //     cout << sz[i] << ' ';
    // }
    // cout << endl;
    // for (int i = 1; i <= n;i++){
    //     cout << son[i] << ' ';
    // }
    // cout << endl;
    return 0;
}
