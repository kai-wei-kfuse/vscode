#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
int n, a[66], d, len[60], sum, pre[60];
void dfs(int u, int m, int p) {
    // m是指要拼的长棍数量,u是当前长棍剩下的长度,全局变量d是枚举的每根长棍的长度
    if (u == 0) {
        dfs(d, m - 1, a[n]);
        //拼完当前长棍就拼下一条长棍，此时又要从长的棍开始选
        return;
    }
    if (m == 0) {
        printf("%d", d);  //因为是从小到大枚举的，所以如果成功直接输出
        exit(0);  //直接退出程序
    }
    p = (p < u) ? p : u;
    //如果剩下的长度比所选木棍长度短，那只能找比剩下长度长的短木棍
    while (p && len[p] == 0)
        p--;  //如果没有当前长度的短木棍，就要往前找短的，直到找到有
    while (p) {  //这里不是循环枚举短木棍
        if (len[p]) {
            len[p]--;
            dfs(u - p, m, p);
            len[p]++;
            if (u == p || u == d)  //剪枝
                return;
        }
        p = pre[p];  //直接赋值，比p短的短木棍长度
    }
}
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        ++len[a[i]];  //类似于map，记录不同程度的木棍数量，因为数量少，直接数组
        sum += a[i];  //求总长
    }
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) {
        if (a[i] != a[i - 1])
            pre[a[i]] = a[i - 1];
        //预处理，便于后面快速找到比这一木棍小的木棍，不用每次都循环找，只要直接赋值即可
    }
    for (d = a[n]; (d << 1) <= sum; d++) {  //枚举到总和的1/2即可
        if (sum % d == 0) {
            if (d >= a[n])              //不能小于最长的木棍
                dfs(d, sum / d, a[n]);  //从最长的a[n]往下枚举短木棍
        }
    }
    printf("%d", sum);  //只从一根切出来的情况
}