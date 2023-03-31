#include <bits/stdc++.h>
using namespace std;
const int N = 30000;
double f[N];
bool not_prime[N + 5];
int prime[N + 5], idx = 0;
int low[N + 5];
void sieve() {
    for (int i = 2; i < N; i++) {
        if (!not_prime[i]) {
            prime[++idx] = i;
            low[i] = i;
        }
        for (int j = 1; j <= idx && i * prime[j] < N; j++) {
            not_prime[i * prime[j]] = 1;
            low[i * prime[j]] = prime[j];
            if (i % prime[j] == 0)
                break;
        }
    }
}
int main() {
    sieve();
    for (int i = 1; i < idx; i++) {
        for (int j = 1; j < N / i; j++) {
            if (j * ln(i) > f)
        }
    }
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
    }
}