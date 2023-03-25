#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
typedef long long ll;
int a[1005];
int c[6];
int box[25];
using namespace std;

int main() {
	int n, m, l;
	cin >> n >> m >> l;
	int b = 0, cc = 0, tmp, aa = 1;
	int flag = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	while (1) {
		flag = 0;
		if (cc == 0) {        //枝是空的
			if (b == 0) {     //盒子�?
				tmp = a[aa];  //推送器�?
				c[++cc] = tmp;
				// cout << tmp << endl;
				aa++;
			} else {
				tmp = box[b];
				c[++cc] = tmp;
			}
		} else {                        //枝有叶子
			if (b > 0) {                //盒子不空
				if (box[b] <= c[cc]) {  //盒子最上面满足
					c[++cc] = box[b];
					box[b] = 0;
					b--;
				} else {  //盒子不满�?
					tmp = a[aa];
					if (tmp <= c[cc]) {  //推送器满足
						c[++cc] = tmp;
						aa++;
					} else {  //推送器不满�?
						if (b < m) {
							box[++b] = tmp;  //放盒�?
							aa++;
						} else {       //盒子满了
							flag = 1;  //做好�?
						}
					}
				}
			} else {  //盒子�?
				tmp = a[aa];
				// cout << tmp << endl;
				if (tmp <= c[cc]) {  //推送器满足
					c[++cc] = tmp;
					aa++;
				} else {  //推送器不满�?
					if (b < m) {
						box[++b] = tmp;  //放盒�?
						// cout << tmp << endl;
						aa++;
					} else {       //盒子满了
						flag = 1;  //做好�?
					}
				}
			}
		}
		// for (int i = 1; i <= cc; i++) {
		//     cout << c[i] << ' ';
		// }
		// cout << endl;
		if (flag || cc == l) {
			for (int i = 1; i <= cc; i++) {
				cout << c[i] << '|';
			}
			cout << endl;
			cc = 0;
			flag = 0;
		}
		if (aa > n) {
			for (int i = 1; i <= cc; i++) {
				cout << c[cc] << ' ';
			}
			break;
		}
	}
}