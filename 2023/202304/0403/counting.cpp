#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
const int W = 100010;

int n, w, a[N], cnt[W], b[N], c[N];
// n为待排序数组长度，w为待排序数组中的最大值
//  a[]存储待排序数组，b[]存储排序后的数组，cnt[]存储每个数的个数

void counting_sort() {            // 计数排序
    memset(cnt, 0, sizeof(cnt));  // 清空计数数组
    for (int i = 1; i <= n; ++i)
        ++cnt[a[i]];  // 计数
    for (int i = 1; i <= w; i++)
        cout << i << ' ';
    cout << endl;
    for (int i = 1; i <= w; i++)
        cout << cnt[i] << " ";
    cout << endl;
    for (int i = 1; i <= w; ++i)
        cnt[i] += cnt[i - 1];  // 计算每个数的排名
    for (int i = 1; i <= w; i++)
        cout << cnt[i] << " ";
    cout << endl;
    for (int i = n; i >= 1; --i) {
        c[i] = cnt[a[i]];//这里c[i]存储的是a[i]的排名
        b[cnt[a[i]]--] = a[i];  // 从后往前 保证稳定性
    }
    for (int i = 1; i <= n; i++)
        cout << c[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << b[i] << " ";
}

signed main() {
    cin >> n >> w;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    counting_sort();
    return 0;
}