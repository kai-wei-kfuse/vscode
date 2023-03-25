#include <bits/stdc++.h>
using namespace std;
// 首先记录xy各有多少点
// 计算最大值是多少
// 然后特判全都在一条线或者每xy都只有一只的情况
// 然后找xy有多少个最大值和多少个次大值
// 再算出总的最大值的方案数和次大值的方案数
typedef long long ll;
#define IOS ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
int main() {
    IOS;
    int t;
    cin >> t;
    int cnt = 1;
    while (t--) {
        int n;
        cin >> n;
        vector<pair<int, int> > ve(n + 1);
        map<int, int> xx, yy;
        for (int i = 1; i <= n; i++) {
            cin >> ve[i].first >> ve[i].second;
            xx[ve[i].first]++;
            yy[ve[i].second]++;
        }
        int m_x = 0, m_y = 0;
        for (auto i : xx) {
            m_x = max(m_x, i.second);
        }
        for (auto i : yy) {
            m_y = max(m_y, i.second);
        }
        cout << "Case " << cnt++ << ": ";
        if (xx.size() == 1 || yy.size() == 1) {
            cout << n << ' ' << 1 << endl;
            continue;
        }
        if (m_x == 1 && m_y == 1) {
            cout << 2 << ' ' << 1ll * n * (n - 1) / 2 << endl;
            continue;
        }
        int cn_x = 0, cn_y = 0, n_x = 0, n_y = 0;  // 最大值的数量和次大值的数量
        for (auto i : xx) {
            if (i.second == m_x)
                n_x++;
            else if (i.second == m_x - 1)
                cn_x++;
        }
        for (auto i : yy) {
            if (i.second == m_y)
                n_y++;
            else if (i.second == m_y - 1)
                cn_y++;
        }
        // cout << n_x << ' ' << n_y << ' ' << cn_x << ' ' << cn_y << endl;
        ll maxn = 1ll * n_x * n_y;
        ll cmaxn = 1ll * n_x * cn_y + 1LL * n_y * cn_x;
        // cout << maxn << ' ' << cmaxn << endl;
        for (int i = 1; i <= n; i++) {
            if (xx[ve[i].first] + yy[ve[i].second] == m_x + m_y) {
                maxn--;
                cmaxn++;
            } else if (xx[ve[i].first] + yy[ve[i].second] == m_x + m_y - 1) {
                cmaxn--;
            }
        }
        // cout << maxn << ' ' << cmaxn << endl;

        if (maxn) {
            cout << m_x + m_y << ' ' << maxn << endl;
        } else {
            cout << m_x + m_y - 1 << ' ' << cmaxn << endl;
        }
    }
}