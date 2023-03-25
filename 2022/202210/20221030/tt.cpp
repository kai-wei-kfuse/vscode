#include <bits/stdc++.h>

using namespace std;

const int N = 1000010, M = 26;

struct ACAM {
	int tr[N][M], fail[N], qrr[N], id[N];
	int root, idx, t;
	int cnt[N];
	ACAM() {
		clear();
	}
	void clear() {
		memset(tr[0], 0, sizeof tr[0]);
		root = idx = 0;
	}
	
	int newnode() {
		idx ++;
		memset(tr[idx], 0, sizeof tr[idx]);
		return idx; 
	}
	// string version: insert s[x] to trie-tree
	int insert(string s, int x) {
		int p = root;
		for (int i = 0; i < s.size(); i++) {
			int u = s[i] - 'a';
			if (!tr[p][u]) tr[p][u] = newnode();
			p = tr[p][u];
		}
		return id[x] = p;
	}
	// char version
	int insert(char *s, int x) {
		int p = root;
		for (int i = 0; s[i]; i++) {
			int u = s[i] - 'a';
			if(!tr[p][u]) tr[p][u] = newnode();
			p = tr[p][u];
		}
		return id[x] = p;
	}
	// build the acam
	void build() {
		fail[root] = root;
		queue<int> q;
		for (int i = 0; i < M; i++) if (tr[root][i]) q.push(tr[root][i]);
		while(q.size()) {
			int tmp = q.front(); q.pop();
			qrr[t ++] = tmp;
			for (int i = 0; i < M; i++) {
				if (!tr[tmp][i]) {
					tr[tmp][i] = tr[fail[tmp]][i];
				}
				else {
					int p = tr[tmp][i];
					fail[p] = tr[fail[tmp]][i];
					q.push(p);
				}
			}
		}
	}
	// string version
	void solve(string s, int m) {
		int p = root;
		for (int i = 0; i < s.size(); i++) {
			p = tr[p][s[i] - 'a'];
			cnt[p]++;
		}

		for (int i = t - 1; i; i--) {
			cnt[fail[qrr[i]]] += cnt[qrr[i]];
		}

		for (int i = 0; i < m; i++) {
			cout << cnt[id[i]] << '\n';
		}
	}
} acam;

int n;
string s;
void solve () {
	cin >> n;
	for (int i = 0; i < n; i ++) {
		string x; cin >> x;
		acam.insert(x, i);
	}
	acam.build();
	cin >> s;
	acam.solve(s, n);
}

int main() {
	//cin.tie(nullptr)->sync_with_stdio(false);
	solve();
	return 0;
}