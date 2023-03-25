#include <algorithm>
#include <iostream>
using namespace std;
int v[105], val[105], dp[105];
int main() {
    int n, V;
    cin >> n >> V;
    int num;
    for (int i = 1; i <= n; i++) {
        cin >> num;
        for (int j = 1; j <= num; j++) {
            cin >> v[j] >> val[j];
        }
        for (int j = V; j >= 0; j--) {
            for (int k = 1; k <= num; k++)
                if (j >= v[k])
                    dp[j] = max(dp[j], dp[j - v[k]] + val[k]);
        }
    }
    cout << dp[V];
}