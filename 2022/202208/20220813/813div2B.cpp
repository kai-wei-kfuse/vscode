#include <iostream>
using namespace std;

int a[105];

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        if (n % 2 == 0) {
            for (int i = 1; i <= n; i++) {
                if (i % 2 == 1)
                    cout << i + 1 << ' ';
                else {
                    cout << i - 1 << ' ';
                }
            }
        } else if (n >= 1 && n % 2 == 1) {
            cout << '1' << ' ';
            for (int i = 2; i <= n; i++) {
                if (i % 2 == 1)
                    cout << i - 1 << ' ';
                else {
                    cout << i + 1 << ' ';
                }
            }
        }
        cout << '\n';
    }
}