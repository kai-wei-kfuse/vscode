#include<bits/stdc++.h>
using namespace std;
 
const int N = 1e6 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x7f7f7f7f;
string s[N];
vector<int>cost[N], mx[N];
int row[N], col[N], nxt[N];
int get_loop(int a[], int n) {
    nxt[0] = -1;
    for (int i = 1; i < n; i++) {
        int j = nxt[i-1];
        while(a[j+1] != a[i] && j >= 0) j = nxt[j];
        if(a[j+1] == a[i]) nxt[i] = j+1;
        else nxt[i] = -1;
    }
    return n - (nxt[n-1]+1);
}
int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) cost[i].resize(m+2), mx[i].resize(m+2);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> cost[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            row[i] = (233LL * row[i] + s[i][j]) % MOD;
            col[j] = (233LL * col[j] + s[i][j]) % MOD;
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