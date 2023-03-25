#include <bits/stdc++.h>
using namespace std;
vector<int> z(105, 0);
char s[105];
void get_z(char* s, int n) {
    z[1] = n;  // 如果自己匹配自己z[1]肯定是n
    for (int i = 2, l, r = 0; i <= n; i++) {
        if (i <= r)                               // 判断是不是在盒子内
            z[i] = min(z[i - l + 1], r - i + 1);  // 关键部分，通过盒子直接得出LCP长度（可能）
        while (s[1 + z[i]] == s[i + z[i]])        // 暴力枚举位置，此时计算完的LCP是最终的LCP
            z[i]++;
        if (i + z[i] - 1 > r)
            l = i, r = i + z[i] - 1;  // 更新盒子
    }
}
int main() {
    int n;
    cin >> n;
    cin >> s + 1;
    get_z(s, n);
    int maxn = 1;
    for (int i = 1; i <= n; i++) {
        if (z[i] >= i - 1)
            maxn = max(maxn, i - 1);
    }
    cout << n - maxn + 1;
}