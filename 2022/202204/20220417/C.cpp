#include <iostream>
using namespace std;
int main() {
    double a;
    int b, c;
    cin >> a >> b >> c;
    double x = 2.455, y = 1.26;
    if (b == 0) {
        double ans = x * a;
        printf("%.2lf", ans);
        if (ans / c > 1) {
            cout << " T_T";
        } else {
            cout << " ^_^";
        }
    }
    if (b == 1) {
        double ans = y * a / c;
        printf("%.2lf", ans);
        if (ans / c > 1) {
            cout << " T_T";
        } else {
            cout << " ^_^";
        }
    }
}