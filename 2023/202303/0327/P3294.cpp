#include <bits/stdc++.h>
using namespace std;

#define int long long

const int N = 6e5 + 5;
struct xx {
    int son[26];
    int tag;
    int vis;
} tr[N];
int idx;

void insert(string s) {
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
    }
    tr[p].tag++;
}

int ans = 0;
int dfs(int p) {
    int res = 0;
    for (int i = 0; i < 26; i++) {
        if (tr[p].son[i] && tr[p].vis == 0) {
            tr[p].vis = 1;
            if (tr[p].tag) res++;
            res += dfs(tr[p].son[i]);
        }
    }
    return res;
}

signed main() {
    int n;
    cin >> n;
    vector<string> s(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        reverse(s[i].begin(), s[i].end());
        insert(s[i]);
    }
    dfs(0);
    cout << ans << endl;
}
