#include <bits/stdc++.h>
using namespace std;
// kmp
const int N = 1e6 + 5;
int dep[N];     // dep[i]表示i结点的深度
int fa[N][21];  // fa[i][j]表示i结点跳2^j步到达的结点

void get_next(string s) {
    int len = s.size() - 1;
    dep[0] = 0;
    dep[1] = 1;  // 根结点的深度为1
    fa[0][0] = fa[1][0] = 0;
    for (int i = 2, j = 0; i <= len; i++) {
        while (j && s[i] != s[j + 1])
            j = fa[j][0];
        if (s[i] == s[j + 1]) j++;
        fa[i][0] = j;         // fa[i][0]表示i结点的父亲结点
        dep[i] = dep[j] + 1;  // 求深度
    }
}

int main() {
    string s;
    cin >> s;
    s = "?" + s;  // 从1开始
    get_next(s);
    int n;
    cin >> n;
    int len = s.size();
    for (int i = 1; i <= 20; i++) {              // 倍增预处理
        for (int u = 1; u < len; u++) {          // u表示结点编号
            fa[u][i] = fa[fa[u][i - 1]][i - 1]; 
        }// fa[u][i] = fa[fa[u][i - 1]][i - 1]表示u结点跳2^(i-1)步到达的结点，再跳2^(i-1)步到达的结点 
    }//
    for (int i = 1; i <= n; i++) {
        int p, q;
        cin >> p >> q;
        // 倍增求LCA
        p = fa[p][0];
        q = fa[q][0];
        if (dep[p] < dep[q]) swap(p, q);
        for (int j = 19; j >= 0; j--) {                 // 使p的深度大于q的深度
            if (dep[fa[p][j]] >= dep[q]) p = fa[p][j];  // 使p和q的深度相同
        }
        if (p == q) {  // p和q的深度相同，直接输出
            cout << p << endl;
            continue;
        }
        for (int j = 20; j >= 0; j--) {
            if (fa[p][j] != fa[q][j]) {
                p = fa[p][j];
                q = fa[q][j];  //  p和q的父亲结点不同，向上跳
            }
        }
        cout << fa[p][0] << endl;
    }
}