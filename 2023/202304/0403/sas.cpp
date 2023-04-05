#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;


int wa[maxn], wb[maxn], wv[maxn], ws_[maxn];
//wa[]存储排序后的数组，wb[]存储排序前的数组，wv[]存储排序前的数组，ws_[]存储每个数的个数
int cmp(int* r, int a, int b, int l) {
    return r[a] == r[b] && r[a + l] == r[b + l];
}
void saa(int* r, int* sa, int n, int m) {
    //  r是待排序的数组，sa是排序后的数组，n是待排序的数组长度，m是待排序的数组中的最大值
    int i, j, p, *x = wa, *y = wb, *t;
    //  x是排序前的数组，y是排序后的数组，t是交换指针,r是待排序的数组
    for (i = 0; i < m; i++)
        ws_[i] = 0;
    for (i = 0; i < n; i++)
        ws_[x[i] = r[i]]++;
    for (i = 1; i < m; i++)
        ws_[i] += ws_[i - 1];//这里的ws_是计数排序的计数数组
    for (i = n - 1; i >= 0; i--)
        sa[--ws_[x[i]]] = i;//
    //  
    for (j = 1, p = 1; p < n; j *= 2, m = p) {
        for (p = 0, i = n - j; i < n; i++)
        //  这里的i是后半部分的下标,这里的sa是计数排序的数组,p是后半部分的个数
            y[p++] = i;//这里的y是计数排序的数组
        for (i = 0; i < n; i++)
            if (sa[i] >= j) y[p++] = sa[i] - j;
            //sa[i]-j 作用是找到前半部分的下标
        
        for (i = 0; i < n; i++)
            wv[i] = x[y[i]];
        for (i = 0; i < m; i++)
            ws_[i] = 0;
        for (i = 0; i < n; i++)
            ws_[wv[i]]++;
        for (i = 1; i < m; i++)
            ws_[i] += ws_[i - 1];
        for (i = n - 1; i >= 0; i--)
            sa[--ws_[wv[i]]] = y[i];
        for (t = x, x = y, y = t, p = 1, x[sa[0]] = 0, i = 1; i < n; i++)
            x[sa[i]] = cmp(y, sa[i - 1], sa[i], j) ? p - 1 : p++;
    }
    return;
}
