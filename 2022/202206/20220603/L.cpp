#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define int ll
#define ls(p) ((p) << 1)
#define rs(p) ((p) << 1 | 1)
const int N = 100010;

struct tt {
    int l, r;
    ll la, sum;
    bool li;
} t[4 * N];
int a[N];
bool s[N];
int n, q;

template <typename T>
void read(T& x) {
    x = 0;
    int w = 1;
    char c = getchar();
    while (c < '0' || c > '9') {
        if (c == '-') {
            w = -1;
        }
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    x = x * w;
}

void pushup(int p) {
    /* if (t[p].l == t[p].r) {
        return;
    } */
    t[p].sum = (t[ls(p)].sum + t[rs(p)].sum);
    // t[p].li = t[ls(p)].li && t[rs(p)].li;
}

void build(int p, int l, int r) {
    t[p].l = l, t[p].r = r;
    if (l == r) {
        t[p].sum = a[r];
        // t[p].li = s[r];
        return;
    }
    int mid = (l + r) >> 1;
    build(ls(p), l, mid);
    build(rs(p), mid + 1, r);
    pushup(p);
}
int len(int a) {
    return t[a].r - t[a].l + 1;
}

void lazy(int p) {
    t[ls(p)].sum = t[ls(p)].sum + (t[p].la * (len(ls(p))));
    t[rs(p)].sum = t[rs(p)].sum + (t[p].la * (len(rs(p))));

    t[ls(p)].la = t[p].la;
    t[rs(p)].la = t[p].la;

    t[p].la = 0;
}

ll query(int p, int x, int y) {
    if (x <= t[p].l && y >= t[p].r) {
        return t[p].sum;
    }
    lazy(p);
    int mid = (t[p].l + t[p].r) >> 1;
    ll ans = 0;
    if (x <= mid) {
        ans = ans + query(ls(p), x, y);
    }
    if (y > mid) {
        ans = ans + query(rs(p), x, y);
    }
    return ans;
}

void change1(int p, int x, int y, int ch) {
    if (t[p].l >= x && t[p].r <= y) {
        t[p].li = ch;
        return;
    }
    lazy(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid)
        change1(ls(p), x, y, ch);
    if (y > mid)
        change1(rs(p), x, y, ch);
    t[p].li = t[ls(p)].li && t[rs(p)].li;
}

void change2(int p, int x, int y, int o)  //加法
{
    /* for (int i = 1; i <= 7; ++i) {
        cout << t[i].sum << " ";
    }
    cout << endl;
    for (int i = 1; i <= 7; ++i) {
        cout << t[i].li << " ";
    }
    //-------------------------------------
    cout << endl; */
    if (t[p].l >= x && t[p].r <= y) {
        t[p].sum = (o * (len(p)) + t[p].sum);
        t[p].la += o;
        return;
    }
    lazy(p);
    int mid = (t[p].l + t[p].r) >> 1;
    if (x <= mid)
        change2(ls(p), x, y, o);
    if (y > mid)
        change2(rs(p), x, y, o);
    pushup(p);
}

void psum() {
    for (int i = 1; i <= n; ++i) {
        cout << t[i].sum << " ";
    }
    cout << endl;
}

void pli() {
    for (int i = 1; i <= n; ++i) {
        cout << t[i].li << " ";
    }
    cout << endl;
}

signed main() {
    read(n);
    read(q);
    for (int i = 1; i <= n; ++i) {
        read(a[i]);
    }
    for (int i = 1; i <= n; ++i) {
        read(s[i]);
    }
    build(1, 1, n);
    for (int i = 1; i <= q; ++i) {
        int y, x;
        int l, r;
        read(y);
        if (y == 1) {
            read(x);
            s[x] = 0;
            /* change1(1, x, x, 0);
            for (int i = 4; i <= 7; ++i) {
                cout << t[i].li << " ";
            }
            cout << endl; */
        } else if (y == 2) {
            read(x);
            s[x] = 1;
            /* change1(1, x, x, 1);
            for (int i = 4; i <= 7; ++i) {
                cout << t[i].li << " ";
            }
            cout << endl; */
        } else if (y == 3) {
            read(l);
            read(r);
            read(x);
            int il = l;
            int ir = l;
            /*          for (int i = l; i <= r; i++) {
                         cout << s[i] << " ";
                     } */
            /*  cout << endl; */
            for (int i = l + 1; i <= r; i++) {
                if (s[i] != s[i - 1] && s[i - 1] == 1) {
                    /*     cout << "gg" << endl; */
                    ir = i - 1;
                    /*   cout << "zuo " << il << "you  " << ir << endl; */
                    change2(1, il, ir, x);
                }
                if (s[i] != s[i - 1] && s[i - 1] == 0) {
                    il = i;
                }
            }
            /*             for (int i = l; i <= r; i++) {
                            cout << s[i] << " ";
                        } */
            /*  cout << endl; */
            if (s[r] == 1)
                change2(1, il, r, x);

        } else if (y == 4) {
            read(l);
            read(r);
            cout << query(1, l, r) << endl;
        }
    }
}