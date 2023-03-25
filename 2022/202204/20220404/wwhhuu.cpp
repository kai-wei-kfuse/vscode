/*********************************************************************
    程序名:
    日期: 2022-04-04 13:28
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
	int tmp = n / 3;
	if (n % 3 == 0) {
		cout << tmp *tmp *tmp;
	} else if (n % 3 == 1) {
		cout << tmp *tmp*(tmp + 1);
	} else if (n % 3 == 2) {
		cout << tmp*(tmp + 1)*(tmp + 1);
	}
	return 0;
}
