#include <iostream>
using namespace std;
typedef long long ll;
int n, m, t, x, y, z;
ll a[1000005];
ll tree[5000005], tag[5000005];
void push_down(ll node, ll l, ll r) {  //下推懒标记
    ll mid = (l + r) >> 1;
    tag[node << 1] += tag[node];
    tag[node << 1 | 1] += tag[node];
    tree[node << 1] += tag[node] * (mid - l + 1);
    tree[node << 1 | 1] += tag[node] * (r - (mid + 1) + 1);
    tag[node] = 0;
}
void build_tree(ll node, ll l, ll r) {
    tag[node] = 0;
    if (l == r) {
        tree[node] = a[l];
        return;
    }
    ll left_node = node << 1;       // 2*node
    ll right_node = node << 1 | 1;  // 2*node+1
    ll mid = (l + r) >> 1;          //(l+r)/2
    build_tree(left_node, l, mid);
    build_tree(right_node, mid + 1, r);
    tree[node] = tree[left_node] + tree[right_node];
}
void update_tree(ll node, ll l, ll r, ll xl, ll xr, ll k) {
    if (xl <= l && xr >= r) {
        tree[node] += k * (r - l + 1);
        tag[node] += k;
        return;
    }
    ll left_node = node << 1;       // 2*node
    ll right_node = node << 1 | 1;  // 2*node+1
    ll mid = (l + r) >> 1;          //(l+r)/2
    push_down(node, l, r);
    if (xl <= mid)
        update_tree(left_node, l, mid, xl, xr, k);
    if (xr > mid)
        update_tree(right_node, mid + 1, r, xl, xr, k);
    tree[node] = tree[left_node] + tree[right_node];
}
ll query_tree(ll node, ll l, ll r, ll ql, ll qr) {
    if (ql <= l && qr >= r)
        return tree[node];
    ll left_node = node << 1;       // 2*node
    ll right_node = node << 1 | 1;  // 2*node+1
    ll mid = (l + r) >> 1;          //(l+r)/2
    push_down(node, l, r);
    ll res = 0;
    if (ql <= mid)
        res += query_tree(left_node, l, mid, ql, qr);
    if (qr > mid)
        res += query_tree(right_node, mid + 1, r, ql, qr);
    return res;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
    }
    build_tree(1, 1, n);
    while (m--) {
        scanf("%d", &t);
        if (t == 1) {
            scanf("%lld %lld %lld", &x, &y, &z);
            update_tree(1, 1, n, x, y,
                        z);  //(ll node,ll l,ll r,ll xl,ll xr,ll k)
        } else if (t == 2) {
            scanf("%lld %lld", &x, &y);
            printf("%lld\n", query_tree(1, 1, n, x, y));
        }
    }
}