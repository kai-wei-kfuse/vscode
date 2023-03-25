/*********************************************************************
    程序名: P1460 [USACO2.1]健康的荷斯坦奶牛 Healthy Holsteins
    日期: 2022-03-23 21:34
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
typedef long long ll;
using namespace std;
int ni[30], now[30];
int a[30][30], vis[30], ans = 0x3f3f3f;
int n, m, sum;
vector<int >aa, bb;

void dfs() {
	int flag = 0;
	// cout<<sum<<endl;
    if(ans<=sum)return;
	memset(now, 0, sizeof(now));
	for (int j = 1; j <= n; j++) {
		for (int i = 1; i <= sum; i++) {
			//
			now[j] += a[aa[i - 1]][j];
		}
		//cout<<now[j]<<' ';
		if (now[j] < ni[j]){
            flag =1;
			break;}
	}
	//cout<<endl;
	if (!flag) {
		if (ans > sum) {
			ans = sum;
			bb.clear();
			for (int i = 1; i <= sum; i++) {
				bb.push_back(aa[i - 1]);
			}
		}
	}
    int x;
    if(sum>=1)x=aa.back();
    else x=1;
	for (int i = x; i <= m; i++) {
		if (!vis[i]) {
			vis[i] = 1;
			sum++;
			aa.push_back(i);
			dfs();
			aa.pop_back();
			sum--;
			vis[i] = 0;
		}
	}
}

int main() {
    std::ios::sync_with_stdio(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> ni[i];
	cin >> m;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	dfs();
	cout << ans << ' ';
	for (vector<int >::iterator i = bb.begin(); i != bb.end(); i++) {
		cout << (*i) << ' ';
	}
	return 0;
}