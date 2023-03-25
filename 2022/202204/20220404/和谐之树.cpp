/*********************************************************************
    程序名:和谐之树
    日期: 2022-04-04 14:35
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
	int t;
	cin >> t;
	ll tmp;
	while (t--) {
		cin >> tmp;
		ll num = 1, now = 1, last = 0;
		tmp = 2 * tmp - 1;
		//cout << tmp << '=' << endl;
		int flag = 1;
		for (int i = 1; i <= 70; i++) {
			last = num;
			num = num + now * 2;
			now *= 2;
			//cout << num << '|';
			if (tmp <= num ) {
				//cout << now << '|';
				//cout << endl;
				ll tmp2 = tmp - last ;
				//cout << num << '|';
				//cout << tmp2 << '.' << now << ',' << last << endl;
				tmp2 /= 4;
				if (tmp2 == 0) {
					cout << last + 2 << endl;
					flag = 0;
				} else {
					ll x = now;
					ll res = 0;
					//	cout << tmp2 << ' ';
					for (int i = 1; i <= tmp2; i++) {
						x /= 2;
						if (i <= now / 8 )
							res += x;
						if (i == now / 4)
							res += x;
						//cout << res << ' ';
					}
					cout << last + res + 2  << endl;
					flag = 0;
				}

			}
			if (flag == 0)
				break;

		}
	}
	return 0;
}
