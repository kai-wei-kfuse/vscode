#include <bits/stdc++.h>
using namespace std;
vector<int> vis(1e6);
//#define IOS ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int main() {
    int n;
    //IOS;
    //cin >> n;
    scanf("%d", &n);
    vector<int> q;//存询问(数组)
    queue<pair<int, int>> qu;//存进入的船
    int tot = 0;
    for (int i = 1; i <= n; i++) {
        int tmp;
        // cin >> tmp;
        scanf("%d", &tmp);
        if (tmp == 1) {
            int t, x;
            // cin >> t >> x;
            scanf("%d %d", &t, &x);
            if (vis[x] == 0) {
                qu.push({t, x});//放入数组
                vis[x] = 1;
            } else {
                vis[x] = 0;
            }
        } else if (tmp == 2) {
            int q_;
            // cin >> q_;
            scanf("%d", &q_);
            q.push_back(q_);//放入队列，和放入数组同理
        }
    }
    int cnt = 0;
    for (auto i : q) {//遍历数组q
        while (!qu.empty() && qu.front().first <= i) {
            cnt++;
            qu.pop();
            // cout << cnt << endl;
        }
        // cout << cnt << '\n';
        printf("%d\n", cnt);
    }
    while (!qu.empty()) {
        cnt++;
        qu.pop();
    }
    // cout << cnt << '\n';
    printf("%d\n", cnt);
}
