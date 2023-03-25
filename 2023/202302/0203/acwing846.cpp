#include <bits/stdc++.h>
using namespace std;

vector<int> edge[100005];
vector<int> vis1(100005, 0), num(100005, 0);

int dfs(int x) {  // 深搜
    cout << x << ' ';
    num[x]++;
    for (int i = 0; i < edge[x].size(); i++) {
        if (vis1[edge[x][i]] == 0) {
            vis1[edge[x][i]] = 1;
            num[x] += dfs(edge[x][i]);
        }
    }
    return num[x];
}
int main() {
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int x, y;
        cin >> x >> y;
        edge[x].push_back(y);
        edge[y].push_back(x);
    }
    dfs(1);
    cout << endl;
    for (int i = 1; i <= n; i++) {
        cout << num[i] << ' ';
    }
}