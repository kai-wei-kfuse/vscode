#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int x, y;
    while (n--) {
        cin >> x >> y;
        if (x > y)
            cout << '0' << ' ' << '0' << endl;
        else {
            int a = y / x;
            if (y % x == 0) {
                cout << '1' << ' ' << a << endl;
            } else {
                cout << '0' << ' ' << '0' << endl;
            }
        }
    }
}