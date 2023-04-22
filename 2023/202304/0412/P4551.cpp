#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1e6 + 5;

struct xx {
    int to, w;
};
vector<xx> edg[N];
vector<int> xor_(N, 0);
int n;

struct xxx {
    int son[2];
} trie[N * 34];
int idx;

void insert(int x) {
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        int u = x >> i & 1;
        if (!trie[p].son[u]) {
            trie[p].son[u] = ++idx;
        }
        p = trie[p].son[u];
    }
}

int query(int x) {
    int res = 0;
    int p = 0;
    for (int i = 31; i >= 0; i--) {
        int u = x >> i & 1;     // 取出二进制下这个数的当前位置
        if (trie[p].son[!u]) {  // 如果这一位可以进行异或就沿着这一条往下走
            res += (1 << i);    // 将这一位的权值加上
            p = trie[p].son[!u];
        } else {  // 否则就沿着另一条路往下走
            p = trie[p].son[u];
        }
    }
    return res;
}

void dfs(int u, int fa) {  // 求出每个点到根节点的异或和
    for (auto i : edg[u]) {
        if (i.to != fa) {
            xor_[i.to] = xor_[u] ^ i.w;
            insert(xor_[i.to]);  // 插入到字典树中
            dfs(i.to, u);
        }
    }
}

signed main() {
    cin >> n;
    for (int i = 1; i < n; i++) {
        int u;
        xx v;
        cin >> u >> v.to >> v.w;
        edg[u].push_back({v.to, v.w});
        edg[v.to].push_back({u, v.w});
    }
    dfs(1, 1);
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        ans = max(ans, query(xor_[i]));
    }
    cout << ans << endl;
}