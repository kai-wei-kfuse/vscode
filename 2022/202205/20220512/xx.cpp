#include <bits/stdc++.h>
const double pi = 3.1415926535897932384626433832795028841971693993751;
using namespace std;
int main() {
    double d1 = sqrt(3.0 / 4.0 - sqrt(3) / 2.0 + 1 * 1.0 * 1);
    double ans = 0.5 * atan(tan(pi / 2.0 - atan(d1 / 0.5) -
                                atan((sqrt(3) - 1) / 2.0 * 1))) +
                 d1;
    printf("%.11lf", ans);
}