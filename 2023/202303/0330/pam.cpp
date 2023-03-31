#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
char s[2000001];
int len[2000001], n, num[2000001], fail[2000001], last, cur, pos, trie[2000001][26], tot = 1;
int getfail(int x, int i) {
    while (i - len[x] - 1 < 0 || s[i - len[x] - 1] != s[i])
        x = fail[x];
    return x;
}
int main() {
    scanf("%s", s);
    n = strlen(s);
    fail[0] = 1;
    len[1] = -1;
    for (int i = 0; i <= n - 1; i++) {
        if (i >= 1) s[i] = (s[i] + last - 97) % 26 + 97;
        pos = getfail(cur, i);
        // 找到cur的fail链中能匹配i位的最长回文后缀
        if (!trie[pos][s[i] - 'a']) {
            fail[++tot] = trie[getfail(fail[pos], i)][s[i] - 'a'];
            trie[pos][s[i] - 'a'] = tot;
            len[tot] = len[pos] + 2;
            num[tot] = num[fail[tot]] + 1;
        }  // 不存在建立点，存在直接走过去
        cur = trie[pos][s[i] - 'a'];
        last = num[cur];
        printf("%d ", last);
    }
    return 0;
}