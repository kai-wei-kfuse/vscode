/*********************************************************************
    程序名:
    日期: 2022-03-31 18:44
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
//vector <int > a;
int a[20];
int solve(int n) {
	int tmp;
	while (n) {
		tmp = n % 10;
		a[tmp]--;
		if (a[tmp] == 0)
			return 0;
		n /= 10;
	}
	return 1;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	a[1] = a[2] = a[3] = a[4] = a[5] = a[6] = a[7] = a[8] = a[9] = a[0] = 2021;
	for (int i = 1; i <= 20210; i++) {
		if (solve(i) == 0) {
			cout << i << endl;
			return 0;
		}
	}
	return 0;
}
