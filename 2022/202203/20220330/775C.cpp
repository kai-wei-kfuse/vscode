#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
typedef unsigned long long ll;
using namespace std;
int x, y;
set<int >se;
vector<pair<int, int > > a[1000003];

bool cmp(pair<int, int> a, pair<int, int > b) {
	return a.first < b.first;
}

bool cmp2(pair<int, int> a, pair<int, int > b) {
	return a.second < b.second;
}

int main() {
	cin >> x >> y;
	int tmp;
	for (int i = 1; i <= x; i++) {
		for (int j = 1; j <= y; j++) {
			cin >> tmp;
			se.insert(tmp);
			a[tmp].push_back({i, j});
		}
	}
	ll res = 0;
	int sum = se.size();
	//cout<<sum<<endl;
	for (auto c : se) {
		sort(a[c].begin(), a[c].end(), cmp);
		int len = a[c].size();
		for (int i = 0; i < len; i++) {
			res += (2 * i + 1 - len) * 1LL * a[c][i].first;
		}
		//cout<<res<<endl;
		sort(a[c].begin(), a[c].end(), cmp2);
		for (int i = 0; i < len; i++) {
			res += (2 * i + 1 - len) * 1LL * a[c][i].second;
		}
	}
	cout << res;

}