#include <cmath>
#include <iostream>
using namespace std;
int x[50000];
int main() {
    char a;
    int sum0 = 0, sum1 = 0, cnt = 0, num = 0;
    while (cin >> a) {
        if (a == '1') {
            if (num == 0)
                x[++cnt] = 0;
            if (sum0) {
                x[++cnt] = sum0;
            }
            sum1++;
            sum0 = 0;
        }
        if (a == '0') {
            if (sum1) {
                x[++cnt] = sum1;
            }
            sum0++;
            sum1 = 0;
        }
        num++;
    }
    if (sum1)
        x[++cnt] = sum1;
    if (sum0)
        x[++cnt] = sum0;
    cout << sqrt(num) << ' ';
    for (int i = 1; i <= cnt; i++) {
        cout << x[i] << ' ';
    }
}