#include <bits/stdc++.h>
using namespace std;


// 求前缀函数的模板 
inline vector<int> prefix_function(string s) {
	int n = s.size();
    s="?"+s;
	vector<int> pi(n+1);
	for (int i = 2,j=0; i <= n; i++) {
		while (j > 0 && s[i] != s[j+1]) j = pi[j];
		if (s[i] == s[j+1]) j++;
		pi[i] = j;
	}
	return pi;
}

string s;
int n, q; 
int main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);cin.exceptions(ios::badbit | ios::failbit);

	cin >> s;
	vector<int> pi = prefix_function(s);
	n = s.size();
	
	vector<int> vec(n+1);	// 记录所有的border
	int tmp = n;
	while(tmp != 0) {
		vec[tmp]=1;
		tmp = pi[tmp];
	}
	for(int i=1;i<=n;i++){
        vec[i]+=vec[i-1];
    }
	cin >> q;
	while(q--) {
		int x;
		cin >> x;
		cout<<min(vec[n-x],vec[x-1])<<'\n';
	}
	return 0;
}
