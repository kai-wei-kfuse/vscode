#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iomanip>
#include <iostream>
using namespace std;

typedef unsigned long long ull;

ull p = 131;
ull a[1000010], base[1000010], b[1000010];
int n, ans, cnt;
string s;

bool check() {
    if (s[0] == 'E' && s[1] == 'N' && s[2] == 'D')
        return 1;
    return 0;
}

void Hash() {
    memset(base, 0, sizeof(base));
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    base[0] = 1ull;
    for (int i = 0; i < n; i++) {
        base[i + 1] = base[i] * p;
        a[i + 1] = a[i] * p + (s[i] - 'a');  //正序字符串哈希
    }
    for (int i = n - 1; i >= 0; i--)
        b[i + 1] = b[i + 2] * p + (s[i] - 'a');  //倒序字符串哈希
}

void work() {
    for (int i = 1; i <= n; i++) {  //找中心
        int mid = 0, l = 0, r = n;
        while (l <= r) {  //长度奇数
            mid = (l + r) >> 1;
            if (i - mid < 1 || i + mid > n) {
                r = mid - 1;
                continue;
            }
            if (a[i] - a[i - mid - 1] * base[mid + 1] ==
                b[i] - b[i + mid + 1] * base[mid + 1]) {
                ans = max(ans, mid * 2 + 1);
                l = mid + 1;
            } else
                r = mid - 1;
        }
        mid = 0, l = 0, r = n;
        while (l <= r) {  //长度偶数
            mid = (l + r) >> 1;
            if (i - mid + 1 < 1 || i + mid > n) {
                r = mid - 1;
                continue;
            }
            if (a[i] - a[i - mid] * base[mid] ==
                b[i + 1] - b[i + mid + 1] * base[mid]) {
                ans = max(ans, mid * 2);
                l = mid + 1;
            } else
                r = mid - 1;
        }
    }
}
int main() {
    cin >> s;
    n = s.size();
    while (!check()) {
        cnt++;
        ans = 1;
        Hash();
        work();
        printf("Case %d: %d\n", cnt, ans);
        cin >> s;
        n = s.size();
    }
}
