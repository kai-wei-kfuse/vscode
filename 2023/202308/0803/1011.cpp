#include <bits/stdc++.h>
#define for(i, s, t) for (int i = s; i <= t; ++i)
using namespace std;
#define ll long long
const int N = 511, mod = 998244353;
const ll inf = 1e18;
int n, m;
int a[N][N];
ll dis[N][N];
int cnt[N][N];
void solve()
{
	cin >> n >> m;
	assert(n <= 500);
	assert(m <= n * (n - 1));
	for (i, 1, n)
		for (j, 1, n)
			a[i][j] = 0, dis[i][j] = inf;
	for (i, 1, n)
		dis[i][i] = 0;
	int x, y, z;
	for (i, 1, m)
	{
		cin >> x >> y >> z;
		assert(1 <= z && z <= 1e9);
		assert(1 <= x && x <= n);
		assert(1 <= y && y <= n);
		a[x][y] = z;
		dis[x][y] = z;
		cnt[x][y] = 1;
	}
	ll mn = inf;
	int c = 0;
	for (k, 1, n)
	{
		for (i, 1, n)
			for (j, 1, n)
			{
				if (dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
					cnt[i][j] = 1ll * cnt[i][k] * cnt[k][j] % mod;
				}
				else if (dis[i][j] == dis[i][k] + dis[k][j])
				{
					cnt[i][j] = (cnt[i][j] + 1ll * cnt[i][k] * cnt[k][j]) % mod;
				}
			}
		for (i, 1, k - 1)
			if (a[k][i])
			{
				if (a[k][i] + dis[i][k] < mn)
				{
					mn = a[k][i] + dis[i][k];
					c = cnt[i][k];
				}
				else if (a[k][i] + dis[i][k] == mn)
				{
					c = (c + cnt[i][k]) % mod;
				}
			}
	}
	if (mn == inf)
		mn = -1, c = -1;
	printf("%lld %d\n", mn, c);
}
int main()
{
	int T;
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	cin >> T;
	while (T--)
		solve();
	return 0;
}
