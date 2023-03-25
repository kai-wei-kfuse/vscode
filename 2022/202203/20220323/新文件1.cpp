#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll mins = 0x3f3f3f;

inline int read() {
	int x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-')
			f = -1;
		c = getchar();
	}
	while (c >= '0' && c <= '9')
		x = x * 10 + c - '0', c = getchar();
	return x * f;
}
ll a[5000005];

int main() {
	int n;
	cin >> n;
	//a[1] = read();
	for (int i = 1; i <= n; i++) {
		a[i] = read();
		a[i] += a[i - 1];
		mins = min(a[i], mins);
	}
	if (mins >= 0)
		cout << "0";
	else
		cout << (-mins);
}