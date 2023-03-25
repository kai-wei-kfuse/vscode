/*********************************************************************
    ??????:
    ????: 2022-04-02 20:00
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
typedef long long ll;
using namespace std;
map<int, int> se1, se2;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int a[4], b[4];
	int tmp, cnt = 0, cntt = 0;
	for (int i = 1; i <= 3; i++) {
		cin >> tmp;
		a[cnt] == tmp ? a[cnt] = tmp : a[++cnt] = tmp;
		se1[tmp]++;
		cin >> tmp;
		b[cntt] == tmp ? b[cntt] = tmp : b[++cntt] = tmp;
		se2[tmp]++;
	}
	if (se1[a[1]] == 1)
		cout << a[1] << ' ';
	else
		cout << a[2] << ' ';
	if (se2[b[1]] == 1)
		cout << b[1] ;
	else
		cout << b[2] ;
	return 0;
}
