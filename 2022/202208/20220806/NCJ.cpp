#include <iostream>
using namespace std;
int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, B, c, x;
        cin >> a >> B >> c >> x;
        int c1, c2, b = a - B;
        int flag = 0;
        // cout << a << B << c << b;
        if (B == b) {  //相等
            if (x == c) {
                flag = 1;
            }
            if (x == B - c) {
                flag = 1;
            }
        } else if (B != b) {
            if ((x - c) / (B - b) * (B - b) == (x - c) ||
                (x - c) / (b - B) * (b - B) == (x - c)) {
                flag = 1;
            }
            if (((x - b + c) / (B - b) * (B - b) == (x - b + c) &&
                 (x - b + c) / (B - b) > 0) ||
                (x - B + c) / (b - B) * (b - B) == (x - B + c) &&
                    ((x - B + c) / (b - B) > 0)) {
                flag = 1;
            }
            if (x == c || x == B - c || x == b - c) {
                flag = 1;
            }
        }
        if (flag) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}