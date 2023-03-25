#include <bits/stdc++.h>
using namespace std;

#define int long long
const int N = 1000005;
const int mod = 19930726;

int p[N << 1];
char a[N], ma[N << 1];
int vis[N], suf[N];

long long binpow(long long a, long long b) {  // 非递归
    // if(b==0)return 1;
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % mod;  // b&1:取第一位，如果是1说明需要，0说明不需要
        a = a * a % mod;
        b >>= 1;  // 右移，1011 -> 101
    }
    return res;
}

void manacher(char s[], int len) {
    int k = 0;
    ma[k++] = '$';
    ma[k++] = '#';
    for (int i = 0; i < len; i++) {
        ma[k++] = s[i];
        ma[k++] = '#';
    }
    ma[k] = '&';
    int mr = 0, c = 0;
    for (int i = 0; i < k; i++) {
        if (i < mr) {
            p[i] = min(p[(c << 1) - i], p[c] + c - i);
        } else {
            p[i] = 1;
        }
        while (ma[p[i] + i] == ma[i - p[i]])
            p[i]++;
        if (mr < p[i] + i) {
            mr = p[i] + i;
            c = i;
        }
        if (p[i] - 1 > 0 && (p[i] - 1) & 1) {
            vis[p[i] - 1]++;
        }
    }
}

signed main() {
    int n, k;
    cin >> n >> k;
    cin >> a;
    manacher(a, n);
    int ans = 1;
    int sum = 0;
    for (int i = N; i >= 1; i--) {
        if (i % 2 == 0)
            continue;
        sum += vis[i];
        if (k >= sum) {
            ans = ans * binpow(i, sum) % mod;
            k -= sum;
        } else {
            ans = ans * binpow(i, k) % mod;
            k = 0;
            break;
        }
    }
    if (k == 0)
        cout << ans;
    else {
        cout << "-1";
    }
}
