#include<bits/stdc++.h>
using namespace std;
 
#define int long long
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x7f7f7f7f;
string s[N];
//vector<int>cost[N], mx[N];
int nxt[N];
int get_loop(vector<int >a, int n) {
    int i=2, j=0;
    for(; i<=n; i++) {
        while(j && a[i] != a[j+1]) j = nxt[j];
        if(a[i] == a[j+1]) j++;
        nxt[i] = j;
    }
    return n - nxt[n];
}
signed main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    vector<vector<int>>cost(n, vector<int>(m+2)), mx(n, vector<int>(m+2));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> cost[i][j];
    }
    vector<int>row(n+1), col(m+1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i+1] = (13331 * row[i+1] + s[i][j]) % MOD;
            col[j+1] = (13331 * col[j+1] + s[i][j]) % MOD;
        }
    }
    int a = get_loop(col, m), b = get_loop(row, n);
    deque<int>q;
    for (int i = 0; i < n; i++) {
        q.clear();
        for (int j = 0; j < m; j++) {
            while(!q.empty() && cost[i][q.back()] <= cost[i][j]) q.pop_back();
            q.push_back(j);
            while(!q.empty() && q.front() < j - a + 1) q.pop_front();
            mx[i][j] = cost[i][q.front()];
        }
    }
    int ans = INF;
    for (int j = a-1; j < m; j++) {
        q.clear();
        for (int i = 0; i < n; i++) {
            while(!q.empty() && mx[q.back()][j] <= mx[i][j]) q.pop_back();
            q.push_back(i);
            while(!q.empty() && q.front() < i - b + 1) q.pop_front();
            if(i >= b-1) {
                ans = min(ans, mx[q.front()][j]);
            }
        }
    }
    cout << 1LL * ans * (a+1) * (b+1) << endl;
    return 0;
}