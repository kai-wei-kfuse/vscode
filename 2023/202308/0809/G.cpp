#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mod = 998244353;

int binpow(int a, int b) {  // 非递归
    // if(b==0)return 1;
    int res = 1;
    while (b > 0) {
        if (b & 1) res = res * a % mod;  // b&1:取第一位，如果是1说明需要，0说明不需要
        a = a * a % mod;
        b >>= 1;  // 右移，1011 -> 101
    }
    return res % mod;
}

struct xx {
    int x, y, val;
    bool operator<(const xx& a) const {
        return val < a.val;
    }
};

struct Dsu {
    vector<int> dsu;
    vector<int> size;  // 集合的大小
    // vector<int> rank;//集合的秩
    Dsu(int n)
        : dsu(n + 1), size(n + 1, 1) /*rank(n + 1, 1)*/ {
        for (int i = 1; i <= n; i++) {
            dsu[i] = i;
        }
    }
    int find(int x) {
        while (dsu[x] != x) {
            x = dsu[x] = dsu[dsu[x]];  // 路径压缩
        }                              // 循环找父节点,parent[i]等于i的时候就是最后的父节点0
        return x;
    }
    int find_(int x) {  // 递归方法路径压缩
        if (dsu[x] != x) {
            dsu[x] = find(dsu[x]);
        }
        return dsu[x];
    }
    void merge(int x, int y) {
        int x_ = find(x), y_ = find(y);
        //  if (rank_[x_] > rank_[y_])//按秩合并
        // swap(x_, y_);
        if (x_ != y_) {
            dsu[x_] = y_;
            //  if (rank_[x_] == rank_[y_])
            // rank_[y_]++;
            size[y_] += size[x_];
        }
    }
};

signed main() {
    int t;
    cin >> t;
    while (t--) {
        int n, maxn;
        cin >> n >> maxn;
        Dsu dsu(n);
        vector<xx> edg;
        for (int i = 1; i < n; i++) {
            int x, y, val;
            cin >> x >> y >> val;
            edg.push_back({x, y, val});
        }
        sort(edg.begin(), edg.end());
        int mx = 0, ans = 1;
        for (auto [x, y, val] : edg) {
            int tmp = dsu.size[dsu.find(x)] * dsu.size[dsu.find(y)] - 1;
            ans = (ans * binpow((maxn - val + 1), tmp)) % mod;
            dsu.merge(x, y);
        }
        cout << ans << endl;
    }
}