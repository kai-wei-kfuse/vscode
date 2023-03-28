#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 2e6 + 5;

// 字典序只需要比较最长公共前缀的下一个字符即可，所以可以用字典树来维护
int son[N][27], idx, cnt[30][30], num[N * 27];  // cnt[i][j]表示i在j的前面的个数

void insert(string s) {  // 插入字符串 s
    int p = 0;
    for (int i = 0; s[i]; i++) {
        int u = s[i] - 'a' + 1;  // 字符转换为数字
        for (int j = 0; j <= 26; j++) {
            if (son[p][j] && j != u) {        // 有边 p->j 且 j != u   且 j != u 说明 s[i] 与同一层的其他字母不同
                cnt[j][u] += num[son[p][j]];  // j在u的前面
            }
        }
        if (!son[p][u]) {
            son[p][u] = ++idx;
        }
        p = son[p][u];
        num[p]++;  // 统计前缀出现的次数
    }
}

signed main() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        s += (char)('a' - 1);  // 在字符串后面加一个'a'-1
        insert(s);
        // cout << s << endl;
    }
    vector<int> pos(28, 0);  // pos[i]表示字母i在字典序中的位置

    for (int i = 1; i <= q; i++) {
        string x;
        cin >> x;
        int ans = 0;
        for (int j = 0; j < 26; j++) {
            pos[x[j] - 'a' + 1] = j + 1;  // 记录字母在字典序中的位置
        }
        pos[0] = 0;                          // a-1的位置
        for (int j = 0; j <= 26; j++) {      // 枚举字母 j
            for (int k = 0; k <= 26; k++) {  // 枚举字母 k
                if (pos[j] > pos[k]) {       // 如果k在j的前面 说明k的字典序比j小
                    ans += cnt[j][k];        // j在k的前面的个数
                }
            }
        }
        cout << ans << endl;
    }
}
