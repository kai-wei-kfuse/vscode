/*********************************************************************
    程序名:
    日期: 2022-03-25 21:38
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
string a[25], b[25];

int main() {

	int n;
	cin >> n;
	while (n--) {//1.2>>3.4//l:34,12
		int m;
		cin >> m;
		for (int i = 1; i <= m; i++) {
			cin >> a[i];
		}
		for (int j = 1; j <= m; j++) {
			cin >> b[j];
		}
		for (int i = 1; i <= m; i++) {
			int lena = a[i].length() - 1;
			int lenb = b[i].length() - 1;
			if (i < m) {

				if (a[i][lena] == '1' || a[i][lena] == '2')
					if (b[i][lenb] != '3' && b[i][lenb] != '4') {
						cout << "NO" << endl;
						break;
					}
				if (a[i][lena] == '3' || a[i][lena] == '4')
					if (b[i][lenb] != '1' && b[i][lenb] != '2') {
						cout << "NO" << endl;
						break;
					}
			} else {

				if (a[m][lena] != '3' && a[m][lena] != '4') {
					cout << "NO" << endl;
					break;
				}
				if (b[m][lenb] != '1' && b[m][lenb] != '2') {
					cout << "NO" << endl;
					break;
				}
				cout << "YES" << endl;
			}
		}


	}

	return 0;
}
