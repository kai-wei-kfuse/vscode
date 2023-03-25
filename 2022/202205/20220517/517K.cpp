#include <bits/stdc++.h>
using namespace std;
struct node {
    int u, v, w;
};
int n;
const int N = 2e5 + 7;
int father[N];
int ov[N];
int num[N];
void init() {
    for (int i = 1; i <= n; i++) {
        father[i] = i;
    }
}
int get(int x) {
    if (father[x] == x) {
        return x;
    } else {
        return father[x] = get(father[x]);
    }
}
void merge(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
        father[y] = x;
    }
}
bool cmp(node x, node y) {
    return x.w > y.w;
}
signed main() {
    int t;
    cin >> t;
    while (t--) {
        init();
        set<int> se;
        int m, q;
        cin >> n >> m >> q;
        vector<node> ve;
        for (int i = 1; i <= m; i++) {
            int u, v, w;
            cin >> u >> v >> w;
            ve.push_back({u, v, w});
        }
        sort(ve.begin(), ve.end(), cmp);
        cout << endl;
        for (auto it : ve) {
            cout << it.u << " " << it.v << " " << it.w << endl;
        }
        map<int, int> mp;
        mp[get(ve[0].u)] = 2;
        int o = 1;
        ov[ve[0].w] = o;
        /*         se.insert(get(ve[0].u)); */
        merge(ve[0].u, ve[0].v);
        for (int i = 1; i < m; i++) {
            merge(ve[i].u, ve[i].v);
            if (get(ve[i].u) != ve[i].u) {
                mp[get(ve[i].u)] += 1;
                ov[ve[i].w] += o + mp[get(ve[i].u)];
            } else {
                mp[get(ve[i].u)] = 2;
                ov[ve[i].w] += o + 1;
            }
            /*             cout << mp[get(ve[i].u)] << " "; */
        }
        for (int i = 1; i <= m; i++) {
            cout << ov[i] << " ";
        }
        cout << endl;
    }
}
