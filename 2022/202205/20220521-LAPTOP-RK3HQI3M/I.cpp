#include <iostream>
using namespace std;
struct xx {
    int x, y;
};
int main() {
    int n, r, x, y;
    cin >> n >> r;
    cin >> x >> y;
    char a;
    int xi, yi, wi, flag = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a >> xi >> yi >> wi;
        if (a == 'U') {
            if ((abs(xi - x) <= r && y >= yi && y <= yi + wi) ||
                abs(xi - x) + abs(yi - y) <= r ||
                abs(xi - x) + abs(yi + wi - y) <= r)
                flag = 1;
        } else if (a == 'D') {
            if ((abs(xi - x) <= r && y <= yi && y >= yi - wi) ||
                abs(xi - x) + abs(yi - y) <= r ||
                abs(xi - x) + abs(yi - wi - y) <= r)
                flag = 1;
        } else if (a == 'L') {
            if ((abs(yi - y) <= r && x >= xi - wi && x <= xi) ||
                abs(xi - x) + abs(yi - y) <= r ||
                abs(xi - wi - x) + abs(yi - y) <= r)
                flag = 1;
        } else if (a == 'R') {
            if ((abs(yi - y) <= r && x >= xi && x <= xi + wi) ||
                abs(xi - x) + abs(yi - y) <= r ||
                abs(xi + wi - x) + abs(yi - y) <= r)
                flag = 1;
        }
    }
    if (flag)
        cout << "YES";
    else
        cout << "NO";
}