#include <algorithm>
#include <cstring>
#include <iostream>
const int mod = 1e9 + 7;
using namespace std;
int sum = 0;
int num[600];
int dp[40003] = {1};
int tmp, ans = 0;
int main() {
    for (int i = 1; i <= 40000; i++) {
        string a = to_string(i);
        string b = a;
        reverse(b.begin(), b.end());
        if (a == b) {
            num[++sum] = i;
        }
    }
    for (int i = 1; i <= sum; i++) {
        for (int j = num[i]; j <= 40000; j++) {
            dp[j] += dp[j - num[i]];
            dp[j] %= mod;
        }
    }
    int n;
    cin >> n;
    while (n--) {
        ans = 0;
        cin >> tmp;
        cout << dp[tmp] << endl;
    }
}
