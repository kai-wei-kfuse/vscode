#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("alex.in", "r", stdin);
    freopen("alex.out", "w", stdout);
    double h, w;
    cin >> h >> w;
    if (h < w) {
        swap(h, w);  // h始终大
    }
    double ans1 = h / 3;
    double ans2 = w / 2;  //一定正确
    double ans3 = w * 3;
    if (ans1 <= w && ans1 >= ans2) {
        printf("%.6lf", ans1);
        return 0;
    }
    printf("%.6lf", ans2);
}