/*********************************************************************
    ??????:
    ????: 2022-04-02 22:25
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
	int a, b[10];
	scanf("%d", &a);
	int i = 1;
	for ( i = 1; a; i++) {
		b[i] = a % 10;
		a /= 10;
	}
	printf("??%d¦Ë", i - 1);
	for (int j = 1; j < i; j++) {
		printf("%d", b[j]);
	}
	return 0;
}
