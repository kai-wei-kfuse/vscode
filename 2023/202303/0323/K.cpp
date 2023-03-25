#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;

int son[N][27], idx, cnt[30][30], num[N * 27];

void insert(string s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        
        int u = s[i] - 'a' + 1;
        for (int j = 0; j <= 26; j++) {
            if (son[p][j] && j != u) {
                cnt[j][u] += num[son[p][j]];
            }
        }
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        num[p]++;
    }
}

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s += (char)('a' - 1);
        insert(s);
        // cout << s << endl;
    }
    vector<int> pos(28, 0);

    for (int i = 1; i <= q; i++) {
        string x;
        cin >> x;
        int ans = 0;
        for (int j = 0; j < 26; j++) {
            pos[x[j] - 'a' + 1] = j + 1;
        }
        pos[0] = 0;
        for (int j = 0; j <= 26; j++) {
            for (int k = 0; k <= 26; k++) {
                if (pos[j] > pos[k]) {
                    ans += cnt[j][k];
                }
            }
        }
        cout << ans << endl;
    }
}