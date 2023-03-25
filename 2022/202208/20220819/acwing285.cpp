#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> edge[6010], has_father(6010), happy(6010);
int dp[6010][2];
int n;

void dfs(int root) {
    dp[root][1] = happy[root];
    for (int k = 0; k < edge[root].size(); k++) {
        int j = edge[root][k];
        dfs(j);
        dp[root][1] += dp[j][0];
        dp[root][0] += max(dp[j][0], dp[j][1]);
    }
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> happy[i];
    }
    int x, y;
    for (int i = 1; i < n; i++) {
        cin >> x >> y;
        edge[y].push_back(x);
        has_father[x] = 1;
    }
    int root = 1;
    while (has_father[root])
        root++;
    dfs(root);
    cout << max(dp[root][0], dp[root][1]);
}