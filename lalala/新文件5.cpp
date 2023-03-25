/*********************************************************************
    程序名:
    日期: 2022-04-02 09:56
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int n, m;
vector <int >a (1000005), b;

int right(int h) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] > h)
			sum += a[i] - h;
	}

	if (sum < m)
		return 1;
	else
		return 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		a.push_back(tmp);
	}
	sort(a.begin(), a.end(), greater<int >());
	int l = -1, r = a[0] + 1, mid;
	/*for (int i = 1; i <= n; i++) {
		b[i] = b[i - 1] + a[i];
	}*/
	while (l + 1 != r) {
		mid = l + (r - l) / 2;
		//int p = upper_bound(a.begin(), a.end(), mid, greater<int >()) - a.begin();
		if (right(mid)/*b[p] - mid * (p + 1) > m*/) {
			l = mid;
		} else
			r = mid;
	}
	cout << r << endl;
	return 0;
}