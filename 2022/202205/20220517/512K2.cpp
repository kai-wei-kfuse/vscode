#include <algorithm>
#include <cstring>
#include <iostream>
#include <map>
#include <vector>
#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
using namespace std;
struct yy {
    int x, n;
} parent[200005], k[200005];
struct xx {
    int x, y, val;
    bool operator<(const xx& m) const {  //定义比较方式，这一步很重要
        return val < m.val;
    };
} a[200005];
int num, indexx[200005];
map<int, int> mp;
bool cmp(xx a, xx b) {
    return a.val > b.val;
}
bool cmp2(xx a, xx b) {
    return a.val < b.val;
}
int find(int x) {
    while (parent[x].x != x) {
        x = parent[x].x = parent[parent[x].x].x;
    }
    return x;
}
void root(int x, int y, int now) {  // x_->y_
    int x_ = find(x);
    int y_ = find(y);
    if (x_ != y_) {
        // indexx[now] += parent[y_].n * parent[x_].n;
        mp[now] += parent[y_].n * parent[x_].n;
        parent[y_].n += parent[x_].n;
        parent[x_].x = parent[y_].x;
    }
}
int main() {
    IOS;
    int t;
    cin >> t;
    while (t--) {
        int n, m, q;
        cin >> n >> m >> q;
        // memset(indexx, 0, sizeof(indexx));
        mp.clear();
        for (int i = 1; i <= m; i++) {
            cin >> a[i].x >> a[i].y >> a[i].val;
            parent[i].x = i;
            parent[i].n = 1;
        }
        sort(a + 1, a + m + 1, cmp);
        for (int i = 1; i <= q; i++) {
            cin >> k[i].x;
            k[i].n = i;
        }
        sort(k + 1, k + q + 1, cmp3);
        // for (int i = 1; i <= m; i++) {
        //     cout << a[i].x << ' ' << a[i].y << ' ' << a[i].val << endl;
        // }
        int now = 0, cnt = 0;
        for (int i = 1; i <= m; i++) {
            // index[cnt + 1] = index[cnt];
            // indexs[now] = index[cnt];
            // cnt++;
            if (now != a[i].val) {
                // indexx[a[i].val] = indexx[now];
                mp[a[i].val] = mp[now];
            }
            now = a[i].val;
            root(a[i].x, a[i].y, now);
        }
        // for (int i = 1; i <= a[1].val; i++) {
        //     cout << indexx[i] << ' ';
        // }
        // cout << endl;
        // for (map<int, int>::iterator i = indexs.begin(); i !=
        // indexs.end();
        //      i++) {
        //     cout << (*i).second << ' ';
        // }
        // cout << endl;
        // cout << endl;
        // for (int i = 1; i <= m; i++) {
        //     cout << index[i] << ' ';
        // }
        // int tmp;
        // sort(a + 1, a + m + 1, cmp2);
        // for (int i = 1; i <= q; i++) {
        //     cin >> tmp;
        //     int pos = lower_bound(a + 1, a + 1 + m, (xx){0, 0, tmp}) - a;
        //     // cout << pos << '\n';
        //     cout << mp[a[pos].val] << '\n';
        // }
    }
}
