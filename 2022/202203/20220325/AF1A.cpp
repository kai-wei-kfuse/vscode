/*********************************************************************
    程序名: CF1A
    日期: 2022-03-25 20:56
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	ll x, y, z;
	cin >> x >> y >> z;
	cout << (x % z == 0 ? x / z : x / z + 1 ) * (y % z == 0 ? y / z : y / z + 1);
	return 0;
}
