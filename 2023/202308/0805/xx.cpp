#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ios ios::sync_with_stdio(false), cin.tie(0), cout.tie(0)
int n, k;
vector<int> a(1005);
int chack(int x)
{
    vector<int> b = a;
    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        maxn = max(maxn, b[i]);
    }
    if (maxn >= x)
    {
        return 1;
    }
    for (int i = 1; i <= n; i++)
    {
        int p = k;
        int fg = 0;
        int last = x;
        for (int j = i; j <= n; j++)
        {
            if (b[j] < last)
            {
                if (p >= last - b[j])
                {
                    p -= (last - b[j]);
                }
                else
                {
                    break;
                }
            }
            else
            {
                fg = 1;
                break;
            }
            last--;
        }
        if (fg)
        {
            return 1;
        }
    }
    return 0;
}
signed main()
{
    ios;
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        int maxn = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> a[i];
            maxn = max(maxn, a[i]);
        }
        int l = 1, r = maxn + 2000;
        while (l < r)
        {
            int mid = (l + r + 1) / 2;
            if (chack(mid))
            {
                l = mid;
            }
            else
            {
                r = mid - 1;
            }
        }
        cout << l << '\n';
    }
}