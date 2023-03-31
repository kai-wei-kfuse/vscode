#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
char s[N];
int prev, idx;

struct Pam {
    int trie[N][26], fail[N], len[N], cnt[N], num[N];
    // trie指针，trie指针和字典树类似，指向的回文子串为i节点对应的回文子串两端加上同一个字符ch构成
    // fail指针，失配后跳转到fail指针指向的节点，fail指针指向的是i节点对应的回文子串的最长后缀回文子串（是真后缀），这个匹配过程与kmp有点类似，fail[i]表示节点i失配以后跳转到长度小于该串且以该节点表示回文串的最后一个字符结尾的最长回文串表示的节点
    // 在调用count函数之后，cnt[i]表示i节点对应的回文子串的出现次数的准确值
    // 在调用add函数之后返回num[last]可以得到以i位置的字符为尾的回文串个数
    // len[i]表示节点i表示的回文串的长度
    int S[N];             // S[i]表示第i个字符的编号，S[i] = c - 'a'，c表示第i个字符
    int prev, idx;        // prev表示上一个字符所在的节点，idx表示节点个数
    int k;                // k表示当前字符的编号
    int newnode(int l) {  // 新建节点
        cnt[idx] = 0, len[idx] = l, fail[idx] = 0, num[idx] = 0;
        for (int i = 0; i < 26; ++i)
            trie[idx][i] = 0;
        return idx++;
    }
    void init() {                          // 初始化
        idx = 0, newnode(0), newnode(-1);  // 0表示空串，-1表示虚拟节点
        prev = 0, k = 0;
        S[k] = -1;
        fail[0] = 1;
    }
    int get_fail(int x) {  // 获得失配后的节点
        while (S[k - len[x] - 1] != S[k])
            x = fail[x];
        return x;
    }
    void insert(int c) {
        c = c - 'a';
        S[++k] = c;
        int cur = get_fail(prev);
        if (!trie[cur][c]) {                         // 如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
            int p = newnode(len[cur] + 2);           // 新建节点
            fail[p] = trie[get_fail(fail[cur])][c];  // 和AC自动机一样建立fail指针，以便失配后跳转
            trie[cur][c] = p;
            num[p] = num[fail[p]] + 1;
        }
        prev = trie[cur][c];
        cnt[prev]++;
    }
    void get_cnt() {
        for (int i = idx - 1; i >= 0; --i)// 从叶子节点往根节点更新cnt数组
            cnt[fail[i]] += cnt[i];
    }
} pam;
int main() {
    cin >> s;
    pam.init();
    int last = 0;
    int len = strlen(s);
    for (int i = 0; i < len; ++i) {
        pam.insert(s[i]);
    }
    pam.get_cnt();
    long long ans = 0;
    for (int i = 2; i <= pam.idx; i++) {
        ans = max(ans, pam.cnt[i] * 1LL * pam.len[i]);
    }
    cout << ans;
    return 0;
}
