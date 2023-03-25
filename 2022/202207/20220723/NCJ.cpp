#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
const int N = 1e6 + 7;
int z[N];
int j[N];
int fact[N];
int inv[N];
int qpow(int x, int y) {
    int base = 1;
    while (y) {
        if (y & 1) {
            base = base * x % mod;
        }
        y >>= 1;
        x = x * x % mod;
    }
    return base;
}
void init() {
    z[0] = 1;
    z[1] = 26;
    for (int i = 2; i < N; i++) {
        z[i] = z[i - 1] * 26 % mod;
    }
    fact[0] = 1;  // 0的阶乘
    for (int i = 1; i < N; i++) {
        fact[i] = fact[i - 1] * i % mod;
    }
    inv[N - 1] = qpow(fact[N - 1], mod - 2);
    for (int i = N - 2; i >= 0; i--) {
        inv[i] = inv[i + 1] * (i + 1) % mod;
    }
}
signed main() {
    init();
    int n;
    cin >> n;
    vector<int> x(n + 1);
    int y = n / 3;
    for (; y >= 0; y--) {
        int s = n - y * 3;  //剩下的字母
        int sum = s + y;    //打包之后 字母+bit的总和
        x[y] = fact[sum] * inv[y] % mod * inv[sum - y] % mod * z[s] % mod;
    }
    for (int i = n - 1; i >= 0; i--) {
        x[i] = (x[i] - x[i + 1] + mod) % mod;
    }
    for (int i = 0; i <= n - 1; i++) {
        x[i] = (x[i] - x[i + 1] + mod) % mod;
    }
    for (int i = 0; i <= n; i++) {
        cout << x[i] << " ";
    }
}