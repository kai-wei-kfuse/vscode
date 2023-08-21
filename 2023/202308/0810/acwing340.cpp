#include <bits/stdc++.h>
using namespace std;

#define int long long

struct xx
{
    int x, val;
};

vector<xx> edg[1005];

signed main()
{
    int n, m, k;
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
    {
        int x, y, val;
        cin >> x >> y >> val;
        edg[x].push_back({y, val});
        edg[y].push_back({x, val});
    }

    deque<int> dq;
    auto chack = [&](int x) -> int
    {
        dq.push_back(1);
        vector<int> vis(n + 1);
        vector<int> dist(n + 1, 2e9);
        // vis[1] = 1;
        dist[1] = 0;
        while (!dq.empty())
        {
            int pos = dq.front();
            dq.pop_front();
            if (vis[pos])
                continue;
            vis[pos] = 1;
            for (auto i : edg[pos])
            {
                if (i.val > x)
                {
                    if (dist[i.x] > dist[pos] + 1)
                    {
                        dist[i.x] = dist[pos] + 1;
                        dq.push_back(i.x);
                    }
                }
                else if (i.val <= x)
                {
                    if (dist[i.x] > dist[pos])
                    {
                        dist[i.x] = dist[pos];
                        dq.push_front(i.x);
                    }
                }
            }
        }
        // if (x == 4)
        // {
        //     cout << dist[n] << "? " << endl;
        // }
        return dist[n] <= k;
    };
    int l = 0, r = 1e6 + 5;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        //cout << mid << endl;
        if (chack(mid))
            r = mid;
        else
            l = mid + 1;
    }
    if(r==1e6+5) r=-1;
    cout << r << endl;
}