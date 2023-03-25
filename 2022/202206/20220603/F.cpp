#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 1 << '\n' << 1;
    } else if (n == 2) {
        cout << 2 << '\n' << "1 1";
    } else {
        cout << 2 * (n - 2) << '\n';
        for (int i = n - 1; i > 1; i--) {
            cout << i << ' ';
        }
        for (int i = 2; i < n; i++) {
            cout << i << ' ';
        }
    }
}