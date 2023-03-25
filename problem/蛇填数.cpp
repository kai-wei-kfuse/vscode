#include <stdio.h>
#include<iostream>
#include<cstdio>
#include <string.h>
#define maxn 20
int a[maxn][maxn];

int main() {// 初始化值是为了方便遍历过程中对是否已经填过进行检测
    memset(a, 0, sizeof(a));
    int n, x, y, tot = 0;
    scanf("%d", &n);
    //cin>>n;
    tot = a[x=0][y=n-1]=1;
    while (tot < n * n) {// 注意数组的边界以及填数的边界
        while (x+1<n && !a[x+1][y]) a[++x][y] = ++tot;
        while (y-1>=0 && !a[x][y-1]) a[x][--y] = ++tot;
        while (x-1>=0 && !a[x-1][y]) a[--x][y] = ++tot;
        while (y+1<n && !a[x][y+1]) a[x][++y] = ++tot;
    }

    for (x=0; x<n; x++) {
        for (y=0; y<n; y++)printf("%3d", a[x][y]);
        //cout<<a[x][y];
        printf("\n");
    }
    return 0;
}