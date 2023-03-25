#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 100010;

int n;
int col[N], cnt[N], sz[N], hson[N];
// col：节点颜色，cnt：颜色数量，sz：子树大小，hson：重儿子编号
ll ans[N], sum;
int maxn, flag, son_;
vector<int> tr[N];

void dfs0(int u, int fa) {  //求轻重儿子
    sz[u] = 1;
    for (auto v : tr[u]) {
        // cout << v << ' ';
        if (v == fa)
            continue;
        dfs0(v, u);
        sz[u] += sz[v];
        if (sz[v] > sz[hson[u]])
            hson[u] = v;
    }
}

void update(int u, int fa, int val) {
    int c = col[u];
    cnt[c] += val;
    if (cnt[c] > maxn) {
        maxn = cnt[c];
        sum = c;
    } else if (cnt[c] == maxn) {
        sum += c;
    }
    for (auto i : tr[u]) {
        if (i == fa || i == son_)  //不求重儿子
            continue;
        update(i, u, val);
    }
}

void dfs1(int u, int fa, bool keep) {
    for (auto v : tr[u]) {  //正常搜索，不搜重儿子，keep代表是否是重儿子
        if (v == fa || v == hson[u])
            continue;
        dfs1(v, u, 0);  //
    }
    if (hson[u]) {  //存在重儿子则求重儿子，且不清空答案
        dfs1(hson[u], u, 1);
        son_ = hson[u];  //记录重儿子
    }
    update(u, fa, 1);
    //求所有节点的贡献（此时重儿子已经求了，所以不遍历重儿子）
    ans[u] = sum;
    son_ = 0;
    if (keep == 0) {  // keep=0说明为轻儿子，还原现场
        update(u, fa, -1);
        // memset(cnt, 0, sizeof cnt);
        sum = 0, maxn = 0;  //清空答案,消除影响
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> col[i];
    }
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        tr[x].push_back(y);
        tr[y].push_back(x);
    }
    dfs0(1, -1);
    dfs1(1, -1, 1);
    // for (int i = 1; i <= n; i++) {
    //     cout << sz[i] << ' ';
    // }
    // cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << ans[i] << ' ';
    }
}