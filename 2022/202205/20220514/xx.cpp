#include <cstring>
#include <iostream>
using namespace std;
using ll = long long;
struct tmp {
    ll val, l, r, lazy;
} tree[404000];
int vis[35];
int ans;
ll a[200005];

void build_tree(int node, int l, int r) {
    tree[node].lazy = 0;
    tree[node].val = 1;
    tree[node].l = l;
    tree[node].r = r;
    if (l == r)
        return;
    int left_node = node << 1;
    int right_node = node << 1 | 1;
    int mid = (r + l) >> 1;
    build_tree(left_node, l, mid);
    build_tree(right_node, mid + 1, r);
    // tree[node].val=tree[left_node].val+tree[right_node].val;
}
/*
void build_tree(int color,int n){
    for(int i = 1;i <= 4*n;i++){
        tree[i].val = 1;
    }
}*/
void push_down(int node, int l, int r) {
    if (tree[node].lazy) {
        tree[node << 1].lazy = tree[node].lazy;
        tree[node << 1 | 1].lazy = tree[node].lazy;
        tree[node << 1].val = tree[node].lazy;
        tree[node << 1 | 1].val = tree[node].lazy;
        tree[node].lazy = 0;
    }
}
void update_tree(int node, int L, int R, int k) {
    if (L <= tree[node].l && R >= tree[node].r) {
        tree[node].val = k;
        tree[node].lazy = k;
        return;
    }
    int left_node = node << 1;
    int right_node = node << 1 | 1;
    int mid = (tree[node].r + tree[node].l) >> 1;
    push_down(node, tree[node].l, tree[node].r);
    if (L <= mid)
        update_tree(left_node, L, R, k);
    if (mid < R)
        update_tree(right_node, L, R, k);
    if (tree[left_node].val == tree[right_node].val)
        tree[node].val = tree[left_node].val;
    else
        tree[node].val = -1;
}
void query_tree(int node, int a, int b) {
    if (a <= tree[node].l && b >= tree[node].r) {
        // cout<<'['<<tree[node].val<<']';
        if (tree[node].val == 0)
            return;
        if (tree[node].val == -1) {
            push_down(node, tree[node].l, tree[node].r);
            int left_node = node << 1;
            int right_node = node << 1 | 1;
            int mid = (tree[node].r + tree[node].l) >> 1;
            // cout<<mid<<"<- "<<a<<' ';
            if (a <= mid)
                query_tree(left_node, a, b);
            if (mid < b)
                query_tree(right_node, a, b);
        } else {
            if (!vis[tree[node].val]) {
                vis[tree[node].val] = 1;
                // cout<<'|'<<tree[node].val<<' ';
                ans++;
            }
        }
        return;
    }
    push_down(node, tree[node].l, tree[node].r);
    int left_node = node << 1;
    int right_node = node << 1 | 1;
    int mid = (tree[node].r + tree[node].l) >> 1;
    if (a <= mid)
        query_tree(left_node, a, b);
    if (mid < b)
        query_tree(right_node, a, b);
}
int main() {
    ll m, n;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build_tree(1, 1, n);
    for (int i = 1; i <= 22; i++) {
        cout << tree[i] << ' ';
    }
    while (m--) {
        scanf("%d", &t);
        if (t == 2) {
            scanf("%lld", &y);
            update_tree(1, 1, n, 1, n,
                        y);  //(ll node,ll l,ll r,ll xl,ll xr,ll k)
        } else if (t == 1) {
            scanf("%lld %lld", &x, &y);
            update_tree(1, 1, n, x, x, y);
        }
        for (int i = 1; i <= 22; i++) {
            cout << tree[i] << ' ';
        }
        printf("%lld\n", query_tree(1, 1, n, 1, n));
    }
}