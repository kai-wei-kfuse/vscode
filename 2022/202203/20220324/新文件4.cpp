/*********************************************************************
    程序名:
    日期: 2022-03-24 22:36
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;

int main() {
	int n;
	string a;
	cin >> n >> a;
	int len = a.length();
	int sum = 0;
	for (int i = 1; i < len ; i++) {
		if (a[i - 1] == a[i]) {
			if (a[i - 1] == 'R') {
				if (a[i + 1] != 'B')
					a[i] = 'B';
				else if (a[i + 1] != 'G')
					a[i] = 'G';
				sum++;
			} else if (a[i - 1] == 'G') {
				if (a[i + 1] != 'B')
					a[i] = 'B';
				else if (a[i + 1] != 'R')
					a[i] = 'R';
				sum++;
			} else if (a[i - 1] == 'B') {
				if (a[i + 1] != 'G')
					a[i] = 'G';
				else if (a[i + 1] != 'R')
					a[i] = 'R';
				sum++;
			}
		}
	}
	cout << sum << endl;
	cout << a;
	return 0;
}
