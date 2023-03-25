#include <iostream>
using namespace std;
int n, m, sum;
int chack(double x) {
    double ans = 0, tmp = m;
    for (int i = 1; i <= sum; i++) {
        tmp *= (1.0 / (1.0 + x));
        ans += tmp;
    }
    return ans >= n;
}
int main() {
    cin >> n >> m >> sum;
    double l = 0, r = 5, mid;
    while (r - l > 0.0001) {
        mid = (r + l) / 2;
        if (chack(mid))
            l = mid;
        else
            r = mid;
    }
    l *= 100;
    printf("%.1lf", l);
}
