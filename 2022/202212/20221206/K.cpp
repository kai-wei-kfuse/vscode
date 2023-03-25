#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e6 + 5;

int son[N][26], cnt[N], tot[N];
int idx, c[26][26];

void insert(string s) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            if (j == i) continue;
            if (son[p][j]) {
                c[i][j] += cnt[son[p][j]];
            }
        }
        if (!son[p][u]) son[p][u] = ++idx;
        p = son[p][u];
        cnt[p]++;
    }
    tot[p]++;
}
int main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        insert(s);
    }
}