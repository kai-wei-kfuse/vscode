#include <cstring>
#include <iostream>
const int mod = 1e9 + 7;
using namespace std;
int dp[1005], num[1005];
int a[1005], val[1005];
int main() {
    int N, V;
    cin >> N >> V;
    for (int i = 1; i <= N; i++) {
        cin >> a[i] >> val[i];
    }
    for (int i = 0; i <= V; i++) {
        num[i] = 1;
    }
    for (int i = 1; i <= N; i++) {
        for (int j = V; j >= a[i]; j--) {
            if (dp[j - a[i]] + val[i] > dp[j]) {
                dp[j] = dp[j - a[i]] + val[i];
                num[j] = num[j - a[i]];
            } else if (dp[j - a[i]] + val[i] == dp[j]) {
                num[j] = (num[j] + num[j - a[i]]) % mod;
            }
        }
    }
    cout << num[V];
}