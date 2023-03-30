#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 10;
char s[N];
int n, lst, len[N];
int now, tot = 1, fail[N], cnt[N], t[N][26];
// tot 记得赋成 1，已经有两个根节点了

int getfail(int u, int p) {  // 求 u 的fail指针 ，p表示当前插入的是哪个点
    while (p - len[u] - 1 <= 0 || s[p - len[u] - 1] != s[p])
        u = fail[u];
    // 如果当前位置比 u的回文串短或者字符不相等                 就一直跳
    return u;  // 最后不跳了，你就是答案了
}

int insert(char c, int id) {
    int p = getfail(now, id);  // 找到那条路中有 id 位都一样的最长回文子串
    // 这个点就是他爸爸
    if (!t[p][c - 'a']) {  // 爸爸没它这个儿子，新认一个
        fail[++tot] = t[getfail(fail[p], id)][c - 'a'];
        // fail等于((((爸爸的fail那条路上)有 id
        // 位都是一样的回文串)的节点)的同名儿子)
        t[p][c - 'a'] = tot;    // 跟trie树一样
        len[tot] = len[p] + 2;  // 长度等于爸爸+2
        cnt[tot] = cnt[fail[tot]] + 1;  // 回文串数量等于fail的数量加上它自己
    }
    return cnt[now = t[p][c - 'a']];  // 更新它现在的位置，并返回cnt作为答案
}

int main() {
    scanf("%s", s + 1);
    n = strlen(s + 1);
    fail[0] = 1, len[1] = -1;
    // len[i] 表示节点 i 所对应的回文串长度
    for (int i = 1; i <= n; i++) {
        if (i > 1)
            s[i] = (s[i] - 'a' + lst) % 26 + 'a';
        printf("%d ", lst = insert(s[i], i));
    }
    return 0;
}