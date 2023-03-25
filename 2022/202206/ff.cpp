#include <bits/stdc++.h>
using namespace std;
#define int long long
struct node {
    int tm, num, mk;
    bool operator>(const node& mm) const { return tm > mm.tm; }
};
set<int> se[5];
priority_queue<node, vector<node>, greater<node>> q;
struct nn {
    int x, a, d, t;
};
const int N = 1e6 + 7;
vector<nn> ve(N);
bool cmp(nn xx, nn yx) {
    return xx.a < yx.a;
}
int cnt;
signed main() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> ve[i].x >> ve[i].a >> ve[i].d >> ve[i].t;
    }
    sort(ve.begin() + 1, ve.begin() + 1 + n, cmp);
    cnt++;
    se[4 - ve[1].x].insert(cnt);
    q.push({ve[1].d, 1, cnt});
    for (int i = 2; i <= n; i++) {
        int t = ve[i].a;
        while (q.size() && q.top().tm < t) {
            node p = q.top();
            q.pop();
            for (int j = 0; j <= 4; j++) {
                if (*se[j].lower_bound(p.mk) == p.mk) {
                    se[j + p.tm].insert(p.mk);
                    se[j].erase(p.mk);
                    break;
                }
            }
        }
        int minn = 1e6 + 7;
        int pos = 5;
        if (ve[i].t == 0) {
            if (se[4].size()) {
                minn = *se[4].begin();
                se[4 - ve[i].x].insert(minn);
                se[4].erase(minn);
                q.push({ve[i].d, i, minn});
            } else {
                cnt++;
                se[4 - ve[i].x].insert(cnt);
                q.push({ve[i].d, i, cnt});
            }

        } else {
            for (int j = ve[i].x; j <= 4; j++) {
                if (se[j].size() && *se[j].begin() < minn) {
                    minn = *se[j].begin();
                    pos = j;
                }
            }
            if (pos == 5) {
                cnt++;
                se[4 - ve[i].x].insert(cnt);
                q.push({ve[i].d, i, cnt});
            } else {
                /*                 int oo = *se[minn].begin();
                                cout << oo << endl; */
                se[pos - ve[i].x].insert(minn);
                se[pos].erase(minn);
                q.push({ve[i].d, i, minn});
            }
        }
        /*   cout << cnt<<endl; */
    }
    cout << cnt;
}