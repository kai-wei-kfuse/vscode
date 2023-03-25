#include <stdio.h>

struct st {
    int a;
    int b;
    float c;
    char w[10];
    struct st* x;
};

int main() {
    struct st xx, yy, zz;
    xx.a = 1;
    xx.w = "3";
}