#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;
int main() {
    int num;
    printf("数组个数为  ");
    scanf("%d", &num);
    int a[num];
    int i, x, c, j;
    for (i = 0; i <= num - 1; i++) {
        scanf("%d", &x);
        a[i] = x;
    }
    for (i = num - 1; i >= 0; i--) {
        for (j = 0; j <= i; j++) {
            if (a[j] > a[1 + j]) {
                c = a[j];
                a[j] = a[1 + j];
                a[1 + j] = c;
            }
        }
    }
    for (i = 0; i <= num - 1; i++) {
        printf("第%d个数为%d\n", i + 1, a[i]);
    }
}
