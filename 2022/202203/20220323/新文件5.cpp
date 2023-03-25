/*********************************************************************
    程序名:
    日期: 2022-03-23 17:49
*********************************************************************/
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>
#define foru(i,x,y) for(int i=x;i<=y;++i)
#define ford(i,x,y) for(int i=x;i>=y;--i)
#define fora(i,x,y) for(int i=x;i<y;++i)
using namespace std;

const int maxn = 1000;

struct bign {
	public:
		int len;
		int dig[100010];

		void operator++() {
			dig[0]++;
			int i = 0;
			while (dig[i] >= 10) {
				dig[i] -= 10;
				dig[++i]++;
			}
			if (i > len)
				len = i;
		}

		HIGH() {
			len = 0;
			dig[0] = dig[1] = 0;
		}

		bool operator <(bign a) {
			if (a.len != len)
				return len < a.len;
			ford(i, len, 0) {
				if (a.dig[i] != dig[i])
					return dig[i] < a.dig[i];
			}
			return false;
		}

		void operator=(int a) {
			len = 0;
			while (a) {
				dig[len++] = a % 10;
				a /= 10;
			}
			if (len)
				--len;
		}
		void operator=(string s) {
			len = s.size() - 1;
			ford(i, len, 0) {
				dig[i] = s[len - i] - '0';
			}
		}

		void output() {
			ford(i, len, 0) {
				cout << dig[i];
			}
		}
};

int solve(int ans) {

	while (ans >= 10) {
		int tmp = 0;
		while (ans) {
			tmp += ans % 10;
			ans /= 10;
		}
		ans = tmp;
	}
	return ans;
}

void deal(int &a) {
	if (a < 10)
		return;
	int tmp = 0;

	while (a) {
		tmp += a % 10;
		a /= 10;
	}
	a = tmp;
	deal(a);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	string x, y;
	cin >> x >> y;
	bign a, b;
	a = x;
	b = y;
	++b;
	//cin >> a >> b;
	int ans = 1;
	int tmp;
	while (a < b) {
		tmp = 0;
		//cout << a.len << endl;
		for (int i = a.len ; i >= 0; i--) {
			tmp += a.dig[i];
		}
		//cout << tmp << endl;
		ans *= tmp;

		//ans = solve(ans);
		deal(ans);
		if (ans == 9)
			break;
		//cout << a << ' ';
		++a;

	}
	cout << ans;

	return 0;
}
