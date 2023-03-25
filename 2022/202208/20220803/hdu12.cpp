#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <vector>
using namespace std;

const int N = 200005;
typedef pair<int, int> PII;

void solve() {
    int n, m;
    cin >> n >> m;
    priority_queue<PII, vector<PII>, greater<PII> > Q;
    set<PII> se;
    vector<PII> ve, p(n + 1);
    vector<int> end(N), mp(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i].first >> p[i].second;
    }
    sort(p.begin() + 1, p.begin() + n + 1);
    for (int i = 1; i <= m; i++) {
        se.insert({0, i});
        end[i] = 0;
        mp[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        while (!Q.empty()) {
            PII one = Q.top();
            if (p[i].first >= one.first) {
                Q.pop();
                int id = one.second;
                int num = mp[id];
                se.erase(se.find({num, id}));
                num--;
                se.insert({num, id});
                mp[id] = num;
            } else {
                break;
            }
        }
        int id = (*se.begin()).second;
        if (end[id] <= p[i].first) {
            end[id] = p[i].first + p[i].second;
        } else {
            end[id] = end[id] + p[i].second;
        }
        int num = mp[id];
        se.erase(se.find({num, id}));
        num++;
        se.insert({num, id});
        mp[id] = num;
        Q.push({end[id], id});
    }
    int ans = 0;
    while (!Q.empty()) {
        PII tmp = Q.top();
        ans = max(ans, tmp.first);
        Q.pop();
    }
    cout << ans;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}