/*********************************************************************
    程序名: B
    日期: 2022-04-02 20:43
*********************************************************************/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
typedef long long ll;
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    double x, y;
    double a, b;
    cin >> x >> y;
    double tmp = x * x + y * y;
    a = x * x / tmp;
    b = y * y / tmp;
    printf("%.12lf %.12lf", sqrt(a), sqrt(b));
    return 0;
}
