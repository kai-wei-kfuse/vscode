#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, y;
        cin >> x >> y;
        int tmp = 0, sum = 0;
        for (int i = 1; i <= x; i++) {
            cin >> tmp;
            sum += tmp;
        }
        if (y >= sum)
            cout << "0" << '\n';
        else
            cout << sum - y << '\n';
    }
}