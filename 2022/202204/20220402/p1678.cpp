/*********************************************************************
    ������: P1678
    ����: 2022-04-02 14:33
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
int n, m;
int a[100002], b[100002];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	//freopen("in.txt", "r", stdin); //�����ض����������ݽ���in.txt�ļ��ж�ȡ
	//freopen("out.txt", "w", stdout); //����ض���������ݽ�����out.txt�ļ���
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++) {
		cin >> b[i];
	}
	int res1, res2, sum = 0;
	sort(a + 1, a + m + 1);
	//cout << m << ' ' << n << endl;
	for (int i = 1; i <= n; i++) {
		res1 = lower_bound(a + 1, a + m + 1, b[i]) - a;
		//res2 = upper_bound(a + 1, a + m + 1, b[i]) - a;
		//if (a[res1] != b[i])
		//	res1--;
		//cout << a[res1] << ' ' << a[res2] << endl;
		if (res1 == 1)
			sum += a[1] - b[i];
		else {
			if (res1 == m + 1)
				sum += b[i] - a[m];
			else
				sum += min(abs(b[i] - a[res1]), abs(b[i] - a[res1 - 1]));
			//cout << sum << endl;
		}
	}
	cout << sum;
	return 0;
}
