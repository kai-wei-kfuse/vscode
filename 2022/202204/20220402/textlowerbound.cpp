/*********************************************************************
    程序名:
    日期: 2022-04-02 19:12
*********************************************************************/
#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000 + 10;
const int INF = 2 * int(1e9) + 10;
#define LL long long

int cmd(int a, int b) {
	return a > b;
}

int main() {
	int num[6] = {1, 2, 4, 7, 15, 34};
	sort(num, num + 6);
	cout << "7" << endl;                  //按从小到大排序
	int pos1 = lower_bound(num, num + 6, 7) - num; //返回数组中第一个大于或等于被查数的值
	int pos2 = upper_bound(num, num + 6, 7) - num; //返回数组中第一个大于被查数的值
	cout << pos1 << ":" << num[pos1] << endl;
	cout << pos2 << ":" << num[pos2] << endl;
	sort(num, num + 6, cmd);                  //按从大到小排序
	int pos3 = lower_bound(num, num + 6, 7, greater<int>()) - num; //返回数组中第一个小于或等于被查数的值
	int pos4 = upper_bound(num, num + 6, 7, greater<int>()) - num; //返回数组中第一个小于被查数的值
	cout << pos3 << "啦" << num[pos3] << endl;
	cout << pos4 << ":" << num[pos4] << endl;
	return 0;
}