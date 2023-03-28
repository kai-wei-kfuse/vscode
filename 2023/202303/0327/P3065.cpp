#include <bits/stdc++.h>
using namespace std;

// 2023.03.27
// P3065
// 输出一个题解
// https://www.luogu.com.cn/problem/P3065
// 字典树

const int N = 3e5 + 5;
struct xx {
    int son[26];
    int tag;  // 标记是否 为单词结尾
} tr[N];
int idx;
vector<int> edg[26];
int ins[26];

void insert(string s) {  // 插入单词 s 到字典树中
    int p = 0;
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        if (!tr[p].son[u]) {
            tr[p].son[u] = ++idx;
        }
        p = tr[p].son[u];
    }
    tr[p].tag++;  // 标记单词结尾
}

int query(string s) {
    int p = 0;
    memset(ins, 0, sizeof ins);
    for (int i = 0; i < 26; i++)
        edg[i].clear();
    for (int i = 0; i < s.size(); i++) {
        int u = s[i] - 'a';
        for (int j = 0; j < 26; j++) {
            if (tr[p].son[j] && j != u) {  // 有边 p->j 且 j != u   且 j != u 说明 s[i] 与同一层的其他字母不同
                edg[u].push_back(j);       // 建图 u -> j u是s[i] j是同一层的其他字母
                                           // cout << u << " " << j << endl;
                ins[j]++;                  // 入度 + 1
            }
        }
        if (tr[p].tag) {  // 如果 p 是单词结尾 则说明有单词前缀与 s 相同
            return 0;
        }
        p = tr[p].son[u];  // 向下走
    }
    // 拓扑排序
    queue<int> q;
    for (int i = 0; i < 26; i++) {
        if (!ins[i]) {
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int i = 0; i < edg[u].size(); i++) {
            int v = edg[u][i];
            ins[v]--;
            if (!ins[v]) {
                q.push(v);
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (ins[i]) {
            return 0;
        }
    }
    return 1;  // 拓扑排序完毕 说明没有环
}

int main() {
    int n;
    cin >> n;
    string s[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> s[i];
        insert(s[i]);
    }
    int ans = 0;
    vector<int> res(n + 1);  // 记录答案
    for (int i = 1; i <= n; i++) {
        if (query(s[i])) {
            ans++;
            res[i] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
        if (res[i])
            cout << s[i] << endl;
    cout << ans << endl;
}