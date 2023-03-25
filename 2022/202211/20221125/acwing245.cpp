#include <bits/stdc++.h>
using namespace std;

const int N = 5e6 + 5;
vector<int> ve(N);
int n, k;

struct node {
    int l, r;
    int tmax, lmax, rmax, sum;
} tr[4 * N];

void pushup(node& u, node& l, node& r) {
    u.tmax = max(max(l.tmax, r.tmax), l.rmax + r.lmax);
    u.lmax = max(l.lmax, l.sum + r.lmax);
    u.rmax = max(r.rmax, r.sum + l.rmax);
    u.sum = l.sum + r.sum;
}

void pushup(int u) {
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r) {
    if (l == r) {
        tr[u]={l,r,ve[l],ve[l],ve[l],ve[l]};
        return;
    }
    tr[u] = {l, r};
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

node query(int u, int l, int r) {
    if (tr[u].l >= l && tr[u].r <= r)
        return tr[u];
    int mid = tr[u].l + tr[u].r >> 1;
    if (r <= mid)
        return query(u << 1, l, r);
    else if (l > mid)
        return query(u << 1 | 1, l, r);
    else{
        auto R = query(u << 1, l, r);
        auto L=query(u << 1 | 1, l, r); 
        node res;
        pushup(res, R, L);
        return res;
    }
}

void modify(int u,int x,int val){
    if(tr[u].l==x&&tr[u].r==x)
        tr[u] = {x,x,val,val,val,val};
    else{
        int mid = tr[u].l + tr[u].r >> 1;
        if(x<=mid)
            modify(u << 1, x, val);
        else
            modify(u << 1 | 1, x, val);
        pushup(u);
    }
}

int main() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i];
    }
    //cout << "x" <<endl;
    build(1, 1, n);
    //cout << "x" << endl;
    for (int i = 1; i <= k; i++) {
        int q;
        cin >> q;
        if (q == 1) {
            int l, r;
            cin >> l >> r;
            if(l>r)
                swap(l, r);
            cout<<query(1, l, r).tmax<<endl;
        } else {
            int x, y;
            cin >> x >> y;
            modify(1, x, y);
        }
    }
}