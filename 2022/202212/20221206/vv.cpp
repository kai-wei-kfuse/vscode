#include <stdio.h>
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
    for (i = 0; i < num - 1; i++) {
        for (j = 1; j < num; j++) {
            for (; a[i] > a[i + j];) {
                c = a[i];
                a[i] = a[i + j];
                a[i + j] = c;
            }
        }
    }

    for (i = 0; i <= num - 1; i++) {
        printf("第%d个数为%d\n", i + 1, a[i]);
    }
}