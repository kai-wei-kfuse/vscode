// P5410 【模板】扩展 KMP（Z 函数）
#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
const int N = 2e7 + 5;
char t[N], s[N];
int z[N], p[N];

void get_z(char* s, int n) {
    z[1] = n;
    for (int i = 2, l, r = 0; i <= n; i++) {
        if (i <= r)
            z[i] = min(z[i - l + 1], r - i + 1);//关键部分，通过盒子直接得出LCP长度（可能）
        while (s[1 + z[i]] == s[i + z[i]])//暴力枚举位置，此时计算完的LCP是最终的LCP
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;//更新盒子
        // printf("i=%d z=%d [%d %d]\n",i,z[i],l,r);
    }
}
void get_p(char* s, int n, char* t, int m) {
    for (int i = 1, l, r = 0; i <= m; i++) {
        if (i <= r)
            p[i] = min(z[i - l + 1], r - i + 1);
        while (1 + p[i] <= n && i + p[i] <= m && s[1 + p[i]] == t[i + p[i]])
            p[i]++;
        if (i + p[i] - 1 > r)
            l = i, r = i + p[i] - 1;
    }
}
int main() {
    scanf("%s%s", t + 1, s + 1);
    int m = strlen(t + 1), n = strlen(s + 1);
    get_z(s, n);
    get_p(s, n, t, m);

    long long ans1 = 0, ans2 = 0;
    for (int i = 1; i <= n; i++)
        ans1 ^= 1LL * i * (z[i] + 1);
    for (int i = 1; i <= m; i++)
        ans2 ^= 1LL * i * (p[i] + 1);
    cout << ans1 << endl << ans2;
    return 0;
}