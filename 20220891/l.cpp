#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int maxn = 3e4 + 7;
bool not_prime[maxn + 5];
int prime[maxn + 5], idx = 0;
int low[maxn + 5];
double f[maxn];
void sieve() {
    for (int i = 2; i <= maxn; i++) {
        if (!not_prime[i]) {
            prime[++idx] = i;
            low[i] = i;
        }
        for (int j = 1; j <= idx && i * prime[j] <= maxn; j++) {
            not_prime[i * prime[j]] = 1;
            low[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}

int main() {
    sieve();
    for (int i = 1; i <= idx; i++) {
        for (int j = 30; j >= prime[i]; j--) {
            for (int k = 1; k <= j / prime[i]; k++) {
                if (j >= k * prime[i]) {
                    f[j] = max(f[j], f[j - k * prime[i]] + k * log(prime[i]));
                }
            }
        }
    }
    int t;
    cin >> t;
    while (t--) {
        ll x;
        cin >> x;
        cout << f[x] << endl;
    }
}