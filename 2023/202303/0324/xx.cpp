#include <cstdio>
#include <cstring>  //双倍经验后不想改回万能头
#define MAX 100005  // 数组一定要开大！我这里RE了③次
int cnt;
int trie[MAX][15], end[MAX];
inline void clean() {
    memset(trie, 0, sizeof(trie));
    memset(end, 0, sizeof(end));
}  // 清空
inline int trie_tree() {
    char s[20];
    scanf("%s", s);  // 直接输入
    int u(0), l(strlen(s)), r(1);
    for (int j(0); j < l; ++j) {
        int v(s[j] - '0');
        if (!trie[u][v])
            trie[u][v] = ++cnt, r = 0;
        u = trie[u][v];
        if (end[u])
            return 1;  // 之前有一个字符串是此字符串前缀
    }
    end[u] = 1;  // 标记一个字符串的末尾
    if (r)
        return 1;  // 此字符串是之前一个字符串的前缀
    return 0;
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        int n, b(0);
        scanf("%d", &n);
        getchar();  // 读掉回车
        cnt = 0;
        for (int i(0); i < n; ++i)
            if (trie_tree())
                b = 1;
        if (b)
            printf("NO\n");  // 只有我想吐槽符合条件输出NO吗？
        else
            printf("YES\n");
        clean();  // 记得清空数组！
    }
}