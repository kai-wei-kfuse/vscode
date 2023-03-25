#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        if (x == 1 && y == 1) {
            cout << '0' << '\n';
        } else
            cout << y + x - 2 + min(x, y) << '\n';
    }
}