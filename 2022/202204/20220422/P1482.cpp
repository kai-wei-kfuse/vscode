#include <algorithm>
#include <iostream>
using namespace std;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(0);
    int a, b, c, d;
    char xx;
    cin >> a >> xx;
    cin >> b;
    cin >> c >> xx >> d;
    int x, y;
    x = a * c;
    y = b * d;
    int gcd = __gcd(x, y);
    x /= gcd;
    y /= gcd;
    cout << y << ' ' << x;
}
