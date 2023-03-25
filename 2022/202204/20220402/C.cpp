/*********************************************************************
    程序名:
    日期: 2022-04-02 20:56
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
priority_queue<int>q;
int a[200015];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n, k, x;
	cin >> n >> k >> x;
	ll sum = 0;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	int cnt = 1;
	sort(a + 1, a + 1 + n, greater<int >());
	while (1) {
		if (a[cnt] < x || cnt > n) {
			if (a[1] > x)
				cnt = 1;
			else
				break;
		}
		if (k == 0)
			break;
		a[cnt] -= x;
		k--;
		cnt++;
	}
	cnt = 1;
	sort(a + 1, a + 1 + n, greater<int >());
	while (1) {
		// sort(a + 1, a + 1 + n, greater<int >());
		if (k == 0 || cnt > n )
			break;
		a[cnt] = 0;
		k--;
		cnt++;

	}
	for (int i = 1; i <= n; i++) {
		sum += a[i];
	}
	cout << sum;
	return 0;
}
