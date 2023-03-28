#include <bits/stdc++.h>
using namespace std;

#define IOS                      \
    ios::sync_with_stdio(false); \
    cin.tie(0);                  \
    cout.tie(0);
const int N = 3e6 + 5;
struct xx {  // 字典树的结构体
    int son[62];// 0-25是小写字母 26-35是数字 36-61是大写字母
    int tag;
} tr[N];
int idx;
char a[N];

inline void insert(char s[]) {  // 插入单词
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int u;
        if (s[i] <= 'Z' && s[i] >= 'A') {         // 大写字母
            u = s[i] - 'A' + 36;                  // 大写字母的ASCII码减去A的ASCII码再加上36
        } else if (s[i] <= 'z' && s[i] >= 'a') {  // 小写字母
            u = s[i] - 'a';
        } else {  // 数字
            u = s[i] - '0' + 26;
        }
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
        tr[p].tag++;
    }
}

inline int query(char s[]) {  // 查询单词
    int p = 0;
    int len = strlen(s);
    for (int i = 0; i < len; i++) {
        int u;
        if (s[i] <= 'Z' && s[i] >= 'A') {
            u = s[i] - 'A' + 36;
        } else if (s[i] <= 'z' && s[i] >= 'a') {
            u = s[i] - 'a';
        } else {
            u = s[i] - '0' + 26;
        }
        if (!tr[p].son[u]) {
            return 0;  //  不存在
        }
        // cout<<tr[p].tag<<endl;
        p = tr[p].son[u];
    }
    return tr[p].tag;  // 返回单词的个数
}

int main() {
    IOS int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        for (int i = 0; i < n; i++) {
            cin >> a;
            insert(a);
        }
        int ans = 0;
        for (int i = 1; i <= m; i++) {
            cin >> a;
            cout << query(a) << '\n';
        }
        for (int i = 0; i <= idx; i++) {  // 初始化
            for (int j = 0; j < 62; j++) {
                tr[i].son[j] = 0;
            }
            tr[i].tag = 0;
        }
        idx = 0;
    }
}