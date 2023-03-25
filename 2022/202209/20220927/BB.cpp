#include <bits/stdc++.h>
using namespace std;
#define int long long
int dis[100005]; // dis[1]表示1-2之间的距离
vector<int> ve(100005);

int quary(int a, int b)
{
    return dis[b - 1] - dis[a - 1];
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        ve.clear();
        memset(dis, 0, sizeof(dis));
        int n;
        cin >> n;
        dis[0] = 0;
        for (int i = 1; i < n; ++i)
        {
            cin >> dis[i];
            dis[i] += dis[i - 1];
        }
        for (int i = 1; i <= n / 2; ++i)
        {
            ve[i] = quary(i, n - i + 1);
        }
        int ans = 0;
        int cnt = 0;
        int js = 1;
        for (int i = 1; i <= n; ++i)
        {
            //cout << cnt << " " << ans << endl;
            if(i%2==0)
            {
                cnt += ve[js];
                js++;
            }
            ans += cnt;
            cout << ans;
            if(i!=n)
            {
                cout << " ";
            }
        }
        if(t>=1)
            cout << endl;
    }
}