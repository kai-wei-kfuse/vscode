#include <algorithm>
#include <iostream>
#include <queue>
using namespace std;
struct xx {
    int r, l, deep, parent;
} tree[105];
int ans = 0, ans2;
queue<xx> Q;
int main() {
    int n;
    cin >> n;
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        if (tree[x].l == 0)
            tree[x].l = y;
        else
            tree[x].r = y;
        tree[y].parent = x;
    }
    int a, b;
    tree[1].deep = 1;
    cin >> a >> b;
    Q.push(tree[1]);
    while (!Q.empty()) {
        ans2 = max((int)Q.size(), ans2);
        xx tmp = Q.front();
        Q.pop();
        ans = max(ans, tmp.deep);

        if (tmp.l) {
            // cout << tmp.l << endl;
            tree[tmp.l].deep = tmp.deep + 1;
            Q.push(tree[tmp.l]);
        }
        if (tmp.r) {
            tree[tmp.r].deep = tmp.deep + 1;
            Q.push(tree[tmp.r]);
        }
    }
    // dfs(1, 1);
    cout << ans << endl;
    cout << ans2 << endl;
    int d1 = a, d2 = b;
    int ans3 = 0, ans4 = 0;
    while (tree[a].deep != tree[b].deep) {
        if (tree[a].deep > tree[b].deep) {
            a = tree[a].parent;
            ans3++;
        } else {
            b = tree[b].parent;
            ans4++;
        }
    }
    while (a != b) {
        a = tree[a].parent;
        b = tree[b].parent;
        ans3++;
        ans4++;
    }
    cout << (ans3)*2 + ans4 << endl;
    // cout << (tree[a].deep - 1) * 2 + tree[b].deep - 1;
}