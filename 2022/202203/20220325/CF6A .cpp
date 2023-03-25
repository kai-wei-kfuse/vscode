/*********************************************************************
    程序名: CF6A Triangle
    日期: 2022-03-25 21:09
*********************************************************************/
#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
typedef long long ll;
using namespace std;
int edge[4];
int edges[5];

int main() {
	cin >> edges[1] >> edges[2] >> edges[3] >> edges[4];
	sort(edges + 1, edges + 5, greater<int >());
	if (edges[1] < edges[2] + edges[3] && edges[1] - edges[2] < edges[3]) {
		cout << "TRIANGLE";
	} else if (edges[2] < edges[3] + edges[4] && edges[2] - edges[3] < edges[4]) {
		cout << "TRIANGLE";
	} else {
		if (edges[1] == edges[2] + edges[3] || edges[2] == edges[3] + edges[4] ) {
			cout << "SEGMENT";
		} else {
			cout << "IMPOSSIBLE";
		}
	}
}
