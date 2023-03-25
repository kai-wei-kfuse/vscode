#include <bits/stdc++.h>
using namespace std;
#define int long long

typedef pair<int, int> P;
const int N = 2e5 + 7;
#define fi first
#define se second

void solve() {
    priority_queue<P, vector<P>, greater<P>> q;  //时间和编号
    set<P> se;                                   //人数和编号
    map<int, int> mp;                            //编号，人
    int n, m;
    cin >> n >> m;
    vector<int> a(N);
    vector<P> time(N);

    for (int i = 1; i <= n; i++)
        cin >> time[i].fi >> time[i].se;
    sort(time.begin() + 1, time.begin() + 1 + n);
    vector<int> end(N);

    // init()
    for (int i = 1; i <= m; i++) {
        se.insert({0, i});
        mp[i] = 0;
        end[i] = 0;  //标记结束时间
    }

    for (int i = 1; i <= n; i++) {
        while (q.size()) {
            int fg = 0;
            P p = q.top();
            if (p.fi <= time[i].fi) {
                q.pop();
                int id = p.se;
                int peo = mp[id];  //找到对应的人和编号，然后总数-1，再插入
                se.erase(se.find({peo, id}));
                peo--;
                se.insert({peo, id});
                fg = 1;
                mp[id] = peo;
            }
            if (!fg)
                break;
        }

        int id = (*se.begin()).se;
        if (end[id] <= time[i].fi)  //若比刚开始时间靠前
        {
            end[id] = time[i].fi + time[i].se;
        } else {
            end[id] += time[i].se;
        }
        int peo = mp[id];
        peo++;
        se.erase(*se.begin());
        se.insert({peo, id});
        mp[id] = peo;
        q.push({end[id], id});
        /*         cout << end[id] << " " << id << endl; */
    }
    int ans = 0;
    while (q.size()) {
        P p = q.top();
        ans = max(p.fi, ans);
        q.pop();
    }
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--)
        solve();
}