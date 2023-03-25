/*********************************************************************
    程序名:P2032 扫描
    日期: 2022-03-25 17:11
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
typedef long long ll;
using namespace std;
deque <pair<int, int > > q;

int main() {
	int n, m;
	//freopen("A.in", "r", stdin);
	//freopen ("A.out", "w", stdout);
	cin >> n >> m;
	//q.push_back(make_pair(0, 0));

	int tmp;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		while (q.size() > 0 && tmp > q.back().first)
			q.pop_back();
		while (q.size() > 0 &&	i - q.front().second + 1 > m)
			q.pop_front();
		q.push_back(make_pair (tmp, i) );
		if (i >= m) {
			cout << q.front().first ;
			if (i < n)
				cout << endl;
		}

	}
	return 0;
}
