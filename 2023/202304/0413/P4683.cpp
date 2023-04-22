#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 5;
struct xx {
    int son[26];
    int tag;
    int k;
} trie[N];
int idx;
char s[N];
int n, cnt;
string ans = "";

void insert(char s[]) {
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a';
        if (!trie[p].son[u]) {
            trie[p].son[u] = ++idx;
        }
        p = trie[p].son[u];
    }
    trie[p].tag = 1;
}

void dfs(int x) {
    for (int i = 0; i < 26; i++) {
        if (trie[x].son[i] && trie[trie[x].son[i]].k != -1) {
            ans += char(i + 'a');
            dfs(trie[x].son[i]);
        }
    }
    if (trie[x].tag) {
        cnt++;
        ans += 'P';
    }
    for (int i = 0; i < 26; i++) {
        if (trie[x].son[i] && trie[trie[x].son[i]].k == -1) {
            ans += char(i + 'a');
            dfs(trie[x].son[i]);
        }
    }
    if (cnt != n)
        ans += '-';
}

int main() {
    cin >> n;
    int len = 0;
    char mark[25];
    for (int i = 1; i <= n; i++) {
        cin >> s;
        if (len < strlen(s)) {
            len = strlen(s);
            strcpy(mark, s);
        }
        insert(s);
    }
    int tmp = 0;
    for (int i = 0; mark[i]; i++) {
        int u = mark[i] - 'a';
        tmp = trie[tmp].son[u];
        trie[tmp].k = -1;
    }
    dfs(0);
    int ans_len = ans.length();
    cout << ans_len << endl;
    for (int i = 0; i < ans_len; i++) {
        cout << ans[i] << endl;
    }
}