#include <bits/stdc++.h>  //并查集
using namespace std;
int dsu[10002], size_[10002], rank_[10002];
int find(int x) {
    while (dsu[x] != x) {
        x = dsu[x] = dsu[dsu[x]];  // 路径压缩
    }  // 循环找父节点,parent[i]等于i的时候就是最后的父节点0
    return x;
}
void root(int x, int y) {
    int x_ = find(x);
    int y_ = find(y);
    // 要把两个点合并成一个就找到两个父节点，把其中一个父节点接过去
    // if (size_[x_root] > size_[y_root])  // 启发式合并
    // swap(x_root, y_root);
    if (rank_[x_] > rank_[y_])//按秩合并
        swap(x_, y_);
    if (x_ != y_) {
        dsu[x_] = y_;  // 把x的父节点变成y的父节点，此时树就合并了
        if (rank_[x_] == rank_[y_])
            rank_[y_]++;
        // size_[y_root] += size_[x_root];
    }
}  // 哪个作为哪个的父节点需要按情况而定，可能两个点代表不同的含义
int main() {
    int n, m;
    int c, x, y;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        dsu[i] = i;  // 初始化，自己的父节点就是自己
        size_[i] = 1;
    }  // 初始化也可以每个设为-1，只要可以判断自己是父节点就可以啦
    for (int i = 1; i <= m; i++) {
        scanf("%d", &c);
        if (c == 1) {
            scanf("%d %d", &x, &y);
            root(x, y);  // 合并操作
        } else {
            scanf("%d %d", &x, &y);
            if (find(x) == find(y))
                printf("Y\n");
            else
                printf("N\n");  // 找根节点，如果根节点相等就在同一个集合
        }
    }
}
