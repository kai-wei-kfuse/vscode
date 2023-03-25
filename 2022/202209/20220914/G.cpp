#include <iostream>
using namespace std;

const int N = 1e5 + 7;
int c[N], f[N];   // c[]是花费
int cnt = 1, fa;  // cnt是节点编号

int dfs(int n, int node, int fa) {
    f[node] = fa;  //当前插入的节点
                   // cout << node << ' ' << fa << endl;
    if (n == 1) {
        // f[cnt] = fa;
        c[node] = 1;
        return 1;
    }
    cnt++;
    c[cnt] = 2, f[cnt] = node;  //在这个新节点中插入一个三个节点的二叉树为左子树
    c[++cnt] = 1, f[cnt] = cnt - 1;
    c[++cnt] = 1, f[cnt] = cnt - 2;
    if (n & 1) {  //在当前节点递归右子树
        c[node] = dfs(n / 2, ++cnt, node) + 2;
        return c[node];
    } else {
        c[node] = N;  //无效节点
        return dfs(n / 2, ++cnt, node) + 2;
    }
}

int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 2 << endl;
        cout << 1 << endl;
        cout << 1 << ' ' << 2 << endl;
        return 0;
    }
    dfs(n, 1, -1);
    cout << cnt << endl;
    /* for (int i = 2; i <= cnt;i++){
        cout << i << ' ';
    }
    cout << endl; */
    for (int i = 2; i <= cnt; i++) {
        cout << f[i] << ' ';
    }
    cout << endl;
    for (int i = 1; i <= cnt; i++) {
        cout << c[i] << ' ';
    }
}