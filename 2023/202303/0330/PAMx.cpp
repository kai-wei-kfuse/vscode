#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
char s[N];
int prev, idx;

struct Pam {//PAM模版 
    int trie[N][26], fail[N], len[N], cnt[N], num[N];
    int S[N];
    int prev, idx;
    int k;
    int newnode(int l) {
        cnt[idx] = 0, len[idx] = l, fail[idx] = 0, num[idx] = 0;
        for (int i = 0; i < 26; ++i)
            trie[idx][i] = 0;
        return idx++;
    }
    void init() {
        idx = 0, newnode(0), newnode(-1);
        prev = 0, k = 0;
        S[k] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {
        while (S[k - len[x] - 1] != S[k])
            x = fail[x];
        return x;
    }
    void add(int c) {
        c = c - 'a';
        S[++k] = c;
        int cur = get_fail(prev);
        if (!trie[cur][c]) {
            int p = newnode(len[cur] + 2);
            fail[p] = trie[get_fail(fail[cur])][c];
            trie[cur][c] = p;
            num[p] = num[fail[p]] + 1;
        }
        prev = trie[cur][c];
        cnt[prev]++;
    }
    void get_cnt() {
        for (int i = idx - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
    }
} pam;
int main() {
    cin >> s;
    pam.init();
    int last = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        if (i >= 1) s[i] = (s[i] + last - 97) % 26 + 97;
        pam.add(s[i]);
        last = pam.num[pam.prev];
        cout << last << " ";
    }
    return 0;
}
