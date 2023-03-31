#include <bits/stdc++.h>
using namespace std;
const long long mod = 1e9 + 7;
const int N = 100025;
const int MAXK = 15;
int n, m, q, k;
long long l, r, a[N], ki[MAXK], coef1[MAXK], coef2[MAXK];
void P(long long a[], int len, int cnt = 1) {
    while (cnt--) {
        for (int i = 1; i <= len; ++i) {
            a[i] += a[i - 1];
            if (a[i] >= mod)
                a[i] -= mod;
        }
    }
}
void D(long long a[], int len, int cnt = 1) {
    while (cnt--) {
        for (int i = len; i; --i) {
            a[i] -= a[i - 1];
            if (a[i] < 0)
                a[i] += mod;
        }
    }
}
long long f(long long x, long long a[], int k) {
    long long ret = 0;
    long long base = 1;
    for (int i = k; i >= 0; --i) {
        ret += base * a[i] % mod;
        if (ret >= mod)
            ret -= mod;
        base = base * x % mod;
    }
    return ret;
}
long long g(long long x, long long a[], int k, long long l, long long r) {
    return (mod - f(x + r - l + 1, a, k)) % mod;
}
int main() {
    scanf("%d %d %d", &n, &m, &q);
    for (int i = 1; i <= n; ++i) {
        scanf("%lld", &a[i]);
    }
    D(a, n, 6);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    while (m--) {
        scanf("%lld %lld %d", &l, &r, &k);
        for (int i = 0; i <= k; ++i) {
            scanf("%lld", &ki[i]);
        }
        for (int i = 1; i <= 10; ++i) {
            coef1[i] = f(i, ki, k);
            coef2[i] = g(i, ki, k, l, r);
        }
        D(coef1, 10, 6);
        D(coef2, 10, 6);
        for (int i = 1; i <= 10; ++i) {
            a[l + i - 1] += coef1[i];
            if (a[l + i - 1] >= mod)
                a[l + i - 1] -= mod;
            a[r + i] += coef2[i];
            if (a[r + i] >= mod)
                a[r + i] -= mod;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    P(a, n, 7);
    for (int i = 1; i <= n; i++) {
        cout << a[i] << ' ';
    }
    cout << endl;
    while (q--) {
        scanf("%lld %lld", &l, &r);
        printf("%lld\n", ((a[r] - a[l - 1]) % mod + mod) % mod);
    }
    return 0;
}

/*
10 2 11
1000 1000 1000 100000 1000 1000 10000 10000 10000 100000
1 10 0 100
1 10 1 1 0
1 1
2 2
3 3
4 4
5 5
6 6
7 7
8 8
9 9
10 10
1 10
*/
