/*********************************************************************
    程序名:P2866 [USACO06NOV]Bad Hair Day S
    日期: 2022-03-25 16:15
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
ll stack[80005];

int main() {
	int n ;
	cin >> n;
	ll top = 0;
	int tmp;
	ll ans = 0;
	stack[0] = 0x3f3f3f;
	for (int i = 1; i <= n; i++) {
		cin >> tmp;
		while (stack[top] <= tmp && top > 0)
			top--;
		ans += top;
		stack[++top] = tmp;

	}
	cout << ans;
	return 0;
}
