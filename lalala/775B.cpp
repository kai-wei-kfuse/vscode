/*********************************************************************
    程序名:775B
    日期: 2022-03-28 20:48
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	int t;
	while (n--) {
		cin >> t;
		ll tmp;
		ll maxn = 0, sum = 0;
		for (int i = 1; i <= t; i++) {
			cin >> tmp;
			sum += tmp;
			maxn = max(maxn, tmp);
		}
		if (!sum) {
			cout << "0" << endl;
			continue;
		}
		sum -= maxn;
		if (sum >= maxn)
			cout << "1" << endl;
		else
			cout << maxn - sum << endl;
	}
	return 0;
}
