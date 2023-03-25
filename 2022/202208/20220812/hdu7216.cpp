#include <iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while (n--) {
        int a, b, c;
        cin >> a >> b >> c;
        if (((a - 1) ^ (b - 1) ^ (c - 1)) == 0) {
            cout << "Lose" << '\n';
        } else {
            cout << "Win" << '\n';
        }
    }
}