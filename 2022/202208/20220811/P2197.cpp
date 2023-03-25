#include <iostream>
using namespace std;
int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int res = 0;
        int x;
        for (int i = 1; i <= n; i++) {
            cin >> x;
            res ^= x;
        }
        if (res) {
            cout << "Yes" << '\n';
        } else {
            cout << "No" << '\n';
        }
    }
}