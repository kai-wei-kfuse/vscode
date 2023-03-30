#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 100;
const int mod = 1e9 + 7;
int has1[N];
int has2[N];
char s[N];
int p1[N];
int p2[N];
map<pair<int, int>, int> mp;
struct Palindromic_Tree {
    int trie[N][26];
    // trie指针，trie指针和字典树类似，指向的回文子串为i节点对应的回文子串两端加上同一个字符ch构成
    int fail[N];
    // fail指针，失配后跳转到fail指针指向的节点，fail指针指向的是i节点对应的回文子串的最长后缀回文子串（是真后缀），这个匹配过程与kmp有点类似，fail[i]表示节点i失配以后跳转到长度小于该串且以该节点表示回文串的最后一个字符结尾的最长回文串表示的节点
    int cnt[N];
    // 在调用count函数之后，cnt[i]表示i节点对应的回文子串的出现次数的准确值
    int num[N];
    // 在调用add函数之后返回num[last]可以得到以i位置的字符为尾的回文串个数
    int len[N];  // len[i]表示节点i表示的回文串的长度
    int S[N];    // 存放添加的字符,
    int last;    // 指向上一个字符所在的节点，方便下一次add
    int n;       // 字符数组指针，从1开始，到n结束
    int p;  // 节点指针，0指向偶根，1指向奇根，有效编号到p-1
    int newnode(int l) {  // 新建节点
        for (int i = 0; i < 26; ++i)
            trie[p][i] = 0;
        cnt[p] = 0;
        num[p] = 0;
        len[p] = l;
        fail[p] = 0;
        return p++;
    }
    void init() {
        p = 0;
        newnode(0);
        newnode(-1);
        last = 0;
        n = 0;
        S[n] = -1;  // 开头放一个字符集中没有的字符，减少特判
        fail[0] = 1;
    }
    int get_fail(int x)  // 和KMP一样，失配后找一个尽量最长的
    {
        while (S[n - len[x] - 1] != S[n])
            x = fail[x];
        return x;
    }
    void add(int c) {
        c -= 'a';
        S[++n] = c;
        int cur = get_fail(last);  // 通过上一个回文串找这个回文串的匹配位置
        if (!trie[cur][c])
        // 如果这个回文串没有出现过，说明出现了一个新的本质不同的回文串
        {
            int now = newnode(len[cur] + 2);  // 新建节点
            fail[now] = trie[get_fail(fail[cur])][c];
            // 和AC自动机一样建立fail指针，以便失配后跳转
            trie[cur][c] = now;
            num[now] = num[fail[now]] + 1;
        }
        last = trie[cur][c];
        cnt[last]++;
    }
    void get_cnt() {
        for (int i = p - 1; i >= 0; --i)
            cnt[fail[i]] += cnt[i];
    }
} pt;
int ans, k;
void DFS(int x, int len) {
    for (int i = 0; i < 26; i++) {
        if (pt.trie[x][i] == 0)
            continue;
        if (x == 1) {
            has1[pt.trie[x][i]] = (i + 1) % mod;
            has2[pt.trie[x][i]] = (i + 1) % mod;
            mp[{has1[pt.trie[x][i]], has2[pt.trie[x][i]]}]++;
            if (mp[{has1[pt.trie[x][i]], has2[pt.trie[x][i]]}] == k)
                ans++;
            DFS(pt.trie[x][i], len + 1);
        } else {
            has1[pt.trie[x][i]] = (has1[x] * 131 % mod + (i + 1) % mod +
                                   (i + 1) * p1[len + 1] % mod) %
                                  mod;
            has2[pt.trie[x][i]] = (has2[x] * 13331 % mod + (i + 1) % mod +
                                   (i + 1) * p2[len + 1] % mod) %
                                  mod;
            mp[{has1[pt.trie[x][i]], has2[pt.trie[x][i]]}]++;
            if (mp[{has1[pt.trie[x][i]], has2[pt.trie[x][i]]}] == k)
                ans++;
            DFS(pt.trie[x][i], len + 2);
        }
    }
}
signed main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(0);
    p1[0] = p2[0] = 1;
    for (int i = 1; i < N; i++) {
        p1[i] = 131 * p1[i - 1] % mod;
        p2[i] = 13331 * p2[i - 1] % mod;
    }
    cin >> k;
    for (int i = 1; i <= k; i++) {
        pt.init();
        cin >> (s + 1);
        int len = strlen(s + 1);
        for (int i = 1; i <= len; i++)
            pt.add(s[i] - 'a');
        DFS(1, 0);
        DFS(0, 0);
        for (int i = 0; i <= pt.p + 1; i++) {
            has1[i] = 0;
            has2[i] = 0;
        }
    }
    cout << ans << endl;
    return 0;
}
